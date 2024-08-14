//Makerfabs MTE21R0 board-template main source file

#include <Wire.h>
#include <Arduino_GFX_Library.h>
#include "touch.h"
#include <lvgl.h>
#include <ui.h>

/*Don't forget to set Sketchbook location in File/Preferences to the path of your UI project (the parent foder of this INO file)*/


enum BoardConstants {
    LVGL_BUFFER_RATIO = 10,
    I2C_SDA_PIN=17, I2C_SCL_PIN=18,
    TOUCH_RST=-1, // 38
    TOUCH_IRQ=-1, // 0
    TFT_BL=38,
    BUTTON_PIN=14,
    ENCODER_CLK=13, // CLK
    ENCODER_DT=10, // DT
};


static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 480;

enum { SCREENBUFFER_SIZE_PIXELS = screenWidth * screenHeight / LVGL_BUFFER_RATIO };
static lv_color_t buf [SCREENBUFFER_SIZE_PIXELS];

Arduino_ESP32RGBPanel *bus = new Arduino_ESP32RGBPanel(
    1 /* CS */, 46 /* SCK */, 0 /* SDA */,
    2 /* DE */, 42 /* VSYNC */, 3 /* HSYNC */, 45 /* PCLK */,
    11 /* R0 */, 15 /* R1 */, 12 /* R2 */, 16 /* R3 */, 21 /* R4 */,
    39 /* G0/P22 */, 7 /* G1/P23 */, 47 /* G2/P24 */, 8 /* G3/P25 */, 48 /* G4/P26 */, 9 /* G5 */,
    4 /* B0 */, 41 /* B1 */, 5 /* B2 */, 40 /* B3 */, 6 /* B4 */
);

// Uncomment for 2.1" round display
Arduino_ST7701_RGBPanel *gfx = new Arduino_ST7701_RGBPanel(
    bus, GFX_NOT_DEFINED /* RST */, 0 /* rotation */,
    false /* IPS */, 480 /* width */, 480 /* height */,
    st7701_type5_init_operations, sizeof(st7701_type5_init_operations),
    true /* BGR */,
    10 /* hsync_front_porch */, 8 /* hsync_pulse_width */, 50 /* hsync_back_porch */,
    10 /* vsync_front_porch */, 8 /* vsync_pulse_width */, 20 /* vsync_back_porch */);

//HARDWARE VARIABLES
// Debounce time in milliseconds
const unsigned long debounceDelay = 50;
unsigned long lastDebounceTime = 0;

//Encoder state-variables:
int counter = 0;
int State;
int old_State;
int move_flag = 0;
int button_flag = 0;
int flesh_flag = 1;
int currentScreen = 0;

//PLANE STATS
int waterLevel = 60;
int oilLevel = 0;
int leftValue = 28;

//DEBUG VARIABLES (NOT NEEDED IN FINAL BUILD)
int debugCounter = 0;
bool waterDirection = true;
bool oilDirection = true;
bool leftDirection = true;

int gear = 0;



void setup ()
{
    USBSerial.begin( 115200 ); /* prepare for possible serial debug */

    String LVGL_Arduino = "Hello Arduino! ";
    LVGL_Arduino += String('V') + lv_version_major() + "." + lv_version_minor() + "." + lv_version_patch();

    pin_init();
    gfx->begin();

    lv_init();

    static lv_disp_t* disp;
    disp = lv_display_create( screenWidth, screenHeight );
    lv_display_set_buffers( disp, buf, NULL, SCREENBUFFER_SIZE_PIXELS * sizeof(lv_color_t), LV_DISPLAY_RENDER_MODE_PARTIAL );
    lv_display_set_flush_cb( disp, my_disp_flush );

    static lv_indev_t* indev;
    indev = lv_indev_create();
    lv_indev_set_type( indev, LV_INDEV_TYPE_POINTER );
    lv_indev_set_read_cb( indev, my_touchpad_read );

    static lv_indev_t* indev2;
    indev2 = lv_indev_create();
    lv_indev_set_type( indev2, LV_INDEV_TYPE_ENCODER );
    lv_indev_set_read_cb( indev2, my_encoder_read );


    lv_tick_set_cb( my_tick_get_cb );


    ui_init();

    USBSerial.println( F("Setup done") );


    xTaskCreatePinnedToCore( Task_TFT, "Task_TFT", 20480, NULL, 3, NULL, 0 );
}


void loop ()
{
  parseFlightDataCSV();
  //parseScreenChangeCSV();
  
  
  
  //DEBUG
  //fakeLoopCSV();
  //USBSerial.print(F(availableMemory));
  delay(100);
}


void refreshUI(){
  if(currentScreen==0){
    //Non fare nulla
  } else if(currentScreen==1){
    updateScreen1();
  } else if (currentScreen==2){
    updateScreen2();
  } else if (currentScreen==3){
    updateScreen3();
  } else if (currentScreen==4){
    updateScreen4();
  }
}

void changeScreen(int screenNumber){
  switch(screenNumber){
    case 1:
      lv_scr_load(ui_Screen1);
      currentScreen=1;
      break;
    case 2:
      lv_scr_load(ui_Screen2);
      currentScreen=2;
      break;
    case 3:
      lv_scr_load(ui_Screen3);
      currentScreen=3;
      break;
    case 4:
      lv_scr_load(ui_Screen4);
      currentScreen=4;
      break;
  }
}

// ------------------------------ CSV FUNCTION --- CSV FUNCTIONS --- CSV FUNCTIONS --- CSV FUNCTIONS --------------------------------
//FAKES NEW DATA IF NEEDED (call inside the loop with a delay)
void fakeLoopCSV(){
  oilVariance();
  waterVariance();
  leftVariance();
  //if(debugCounter%80==0)gear=0;
  //else gear=1;
}

void parseFlightDataCSV(){
  if (USBSerial.available() > 0) {
    // Read the incoming string
    String inputString = USBSerial.readStringUntil('\n');

    // Parse the CSV string into individual variables
    int firstComma = inputString.indexOf(',');
    int secondComma = inputString.indexOf(',', firstComma + 1);
    int thirdComma = inputString.indexOf(',', secondComma + 1);

    //var0 = inputString.substring(0, firstComma).toFloat(); // Time (s)
    //var1 = inputString.substring(firstComma + 1, secondComma).toFloat(); // Speed (km/h)
    oilLevel = inputString.substring(secondComma + 1, thirdComma).toInt(); // Fuel (liters)
    waterLevel = inputString.substring(thirdComma + 1).toInt(); // water

    refreshUI();
    USBSerial.println(waterLevel);
  }
}

//READ INCOMING SCREEN CHANGE CALLS (OR UI REFRESHES)
void parseScreenChangeCSV(){
  if (USBSerial.available() > 0) { // Controlla se ci sono dati disponibili
    
    int serialParameter = USBSerial.parseInt();
    if(serialParameter>0 && serialParameter<=4) changeScreen(serialParameter);
    else refreshUI();
    //si passano solo i numeri.
  }
}

// ------------------------------ TEST FUNCTIONS --- TEST FUNCTIONSS --- TEST FUNCTIONSS --- TEST FUNCTIONSS --------------------------------
//TEST FUNCTIONS
void waterVariance(){
  if(waterDirection) waterLevel+=2;
  else waterLevel-=2;
  if(waterLevel>=200||waterLevel<=60)waterDirection=!waterDirection;
}
void oilVariance(){
  if(oilDirection)oilLevel+=4;
  else oilLevel-=4;
  if(oilLevel>=180||oilLevel<=0)oilDirection=!oilDirection;
}
void leftVariance(){
  if(leftDirection)leftValue+=3;
  else leftValue-=3;
  if(leftValue>=30||leftValue<=10)leftDirection=!leftDirection;
}

// FREE RAM check for debugging. SRAM for ATmega328p = 2048Kb.
int availableMemory() {
    // Use 1024 with ATmega168
    int size = 2048;
    byte *buf;
    while ((buf = (byte *) malloc(--size)) == NULL);
        free(buf);
    return size;
}

void updateScreen1(){
    //lv_label_set_text_fmt(ui_LabelWaterValue, "%d°",waterLevel);
    lv_arc_set_value(ui_ArcWater, waterLevel);
  
    //lv_label_set_text_fmt(ui_LabelOilValue, "%d°",oilLevel);
    lv_arc_set_value(ui_ArcOil, oilLevel);  
    USBSerial.println(F("UpdateScreen1"));
}

void updateScreen2(){
  lv_arc_set_value(ui_ArcFuelLeft, leftValue);
  //lv_label_set_text_fmt(ui_LabelLeftValue, "%d", leftValue);
  USBSerial.println(F("UpdateScreen2"));
}

void updateScreen3(){
  updatePanelGear(gear);
  //Update flap
  //Update tutto
   USBSerial.println(F("UpdateScreen3"));
}

void updateScreen4(){
}

void updateScreen5(){
}

//OUR FUNCTIONS 
void updateWater(int newvalue)
{
    lv_arc_set_value(ui_ArcWater, newvalue);
    lv_label_set_text_fmt(ui_LabelWaterValue, "%d°", newvalue);
}

void updateOil(int newvalue)
{
    lv_arc_set_value(ui_ArcOil, newvalue);
    lv_label_set_text_fmt(ui_LabelOilValue, "%d", newvalue);
}

void updateFuelPressure(float newvalue)
{
    lv_bar_set_value(ui_BarFuelPressure, newvalue, LV_ANIM_ON);
    lv_label_set_text_fmt(ui_LabelFuelPressureValue, "%d", newvalue);
}

void updateArcFuelRight(int newvalue)
{
    lv_arc_set_value(ui_ArcFuelRight, newvalue);
    lv_label_set_text_fmt(ui_LabelRightValue, "%d", newvalue);
}

void updateArcFuelLeft(int newvalue)
{
    lv_arc_set_value(ui_ArcFuelLeft, newvalue);
    lv_label_set_text_fmt(ui_LabelLeftValue, "%d", newvalue);
}

void updateFlap(int newvalue)
{
    lv_arc_set_value(ui_ArcFlap, newvalue);
    lv_arc_set_value(ui_ArcFlapAngle, newvalue);
    lv_label_set_text_fmt(ui_LabelPositionValue, "%d", newvalue);
}

void updateSpeed(int newvalue)
{
    lv_arc_set_value(ui_ArcSpeed, newvalue);
    lv_label_set_text_fmt(ui_LabelSpeedValue, "%d", newvalue);
}

void updatePanelGear(int newposition)
{
    if (newposition == 0)
    {
        lv_obj_set_style_bg_color(ui_PanelGearColor, lv_color_hex(0x00FF00), 0);
        lv_label_set_text_fmt(ui_LabelFlapDown, "UP");
    }
    else if (newposition == 1)
    {
        lv_obj_set_style_bg_color(ui_PanelGearColor, lv_color_hex(0xFF0000), 0);
        lv_label_set_text_fmt(ui_LabelFlapDown, "DOWN");
    }
}

void updateSpeed1(int newvalue)
{
    lv_label_set_text_fmt(ui_LabelSpeedValue1, "%d", newvalue);
    lv_arc_set_value(ui_ArcSpeed1, newvalue);
}
void updateAltitudeValue(int newvalue)
{
    lv_label_set_text_fmt(ui_LabelAltitudeValue, "%d", newvalue);
}
void updateQNHValue(int newvalue)
{
    lv_label_set_text_fmt(ui_LabelQNHValue, "%d", newvalue);
}

// ------------------------------------------------------------------------------------- default

void Task_TFT (void *pvParameters)
{
    while (1) {
        lv_timer_handler();
        vTaskDelay(10);
    }
}

//------------------------------------------------------------------------ default

/*Set tick routine needed for LVGL internal timings*/
static uint32_t my_tick_get_cb (void) { return millis(); }


void pin_init ()
{
    pinMode( TFT_BL, OUTPUT );
    digitalWrite( TFT_BL, HIGH );

    pinMode( ENCODER_CLK, INPUT_PULLUP );
    pinMode( ENCODER_DT, INPUT_PULLUP );
    old_State = digitalRead( ENCODER_CLK );

    attachInterrupt( ENCODER_CLK, encoder_irq, CHANGE );

    Wire.begin( I2C_SDA_PIN, I2C_SCL_PIN );
}

/* Display flushing */
void my_disp_flush (lv_display_t *disp, const lv_area_t *area, uint8_t *pixelmap)
{
    uint32_t w = ( area->x2 - area->x1 + 1 );
    uint32_t h = ( area->y2 - area->y1 + 1 );

    gfx->draw16bitRGBBitmap( area->x1, area->y1, (uint16_t*) pixelmap, w, h );

    lv_disp_flush_ready( disp );
}

/*Read the touchpad*/
void my_touchpad_read (lv_indev_t *indev_driver, lv_indev_data_t *data)
{
    int touchX = 0, touchY = 0;

    if ( read_touch( &touchX, &touchY ) == 1 ) {
        data->state = LV_INDEV_STATE_PR;

        data->point.x = (uint16_t) touchX;
        data->point.y = (uint16_t) touchY;
    }
    else {
        data->state = LV_INDEV_STATE_REL;
    }
}

void my_encoder_read (lv_indev_t *drv, lv_indev_data_t *data)
{
  static int lastButtonState = HIGH; // Previous state of the button

    int buttonState = digitalRead(BUTTON_PIN);

    // Check if the button state has changed
    if (buttonState != lastButtonState) {
        lastDebounceTime = millis(); // Reset the debounce timer
    }

    // Only change the state if the debounce delay has passed
    if ((millis() - lastDebounceTime) > debounceDelay) {
        if (buttonState == LOW && button_flag == 0) {
            // Button is pressed
            button_flag = 1;
            flesh_flag = 0;
            USBSerial.println(F("Button PRESS"));

        } else if (buttonState == HIGH && button_flag == 1) {
            // Button is released
            button_flag = 0;
            flesh_flag = 1;
            USBSerial.println(F("Button RELEASE"));

            currentScreen++;
            if(currentScreen>4){
              currentScreen=1;
            }
            changeScreen(currentScreen);
        }
    }

    lastButtonState = buttonState; // Save the current state as the last state
}

void encoder_irq()
{
    State = digitalRead( ENCODER_CLK );
    if (State != old_State)
    {
        if ( digitalRead(ENCODER_DT) == State ) {
            counter++;
        } else {
            counter--;
        }
    }
    old_State = State; // the first position was changed
}

void changeScreenTo0(lv_event_t * e){
  currentScreen=0;
}

void changeScreenTo1(lv_event_t * e){
  currentScreen=1;
}

void changeScreenTo2(lv_event_t * e){
  currentScreen=2;
}

void changeScreenTo3(lv_event_t * e){
  currentScreen=3;
}

void changeScreenTo4(lv_event_t * e){
  currentScreen=4;
}

//counter++;
  //          if(counter==5){
    ////      }
        //    changeScreen(counter);
