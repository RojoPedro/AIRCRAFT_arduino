// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.4.2
// LVGL version: 9.1.0
// Project name: Gauge2

#include "ui.h"

void ui_Screen2_screen_init(void)
{
    ui_Screen2 = lv_obj_create(NULL);
    lv_obj_remove_flag(ui_Screen2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags

    ui_HorLine1 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_HorLine1, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_HorLine1, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_HorLine1, 5);
    lv_obj_set_y(ui_HorLine1, -7);
    lv_obj_set_align(ui_HorLine1, LV_ALIGN_CENTER);
    lv_label_set_text(ui_HorLine1, "________________________________________________________________________");

    ui_VertLine = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_VertLine, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_VertLine, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_VertLine, 0);
    lv_obj_set_y(ui_VertLine, 118);
    lv_obj_set_align(ui_VertLine, LV_ALIGN_CENTER);
    lv_label_set_text(ui_VertLine, "|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|\n|");
    lv_obj_set_style_text_letter_space(ui_VertLine, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_text_line_space(ui_VertLine, -2, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFuelPressure = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_LabelFuelPressure, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelFuelPressure, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelFuelPressure, -2);
    lv_obj_set_y(ui_LabelFuelPressure, -46);
    lv_obj_set_align(ui_LabelFuelPressure, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelFuelPressure, "FUEL PRESSURE");
    lv_obj_set_style_text_font(ui_LabelFuelPressure, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelRight = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_LabelRight, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelRight, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelRight, 67);
    lv_obj_set_y(ui_LabelRight, 68);
    lv_obj_set_align(ui_LabelRight, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelRight, "RIGHT");
    lv_obj_set_style_text_font(ui_LabelRight, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelLeft = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_LabelLeft, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelLeft, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelLeft, -85);
    lv_obj_set_y(ui_LabelLeft, 67);
    lv_obj_set_align(ui_LabelLeft, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelLeft, "LEFT");
    lv_obj_set_style_text_font(ui_LabelLeft, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelFuelPressureValue = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_LabelFuelPressureValue, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_LabelFuelPressureValue, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_LabelFuelPressureValue, 1);
    lv_obj_set_y(ui_LabelFuelPressureValue, -125);
    lv_obj_set_align(ui_LabelFuelPressureValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelFuelPressureValue, "14.7");
    lv_obj_set_style_text_font(ui_LabelFuelPressureValue, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_labelpsi = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_labelpsi, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_labelpsi, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_labelpsi, 218);
    lv_obj_set_y(ui_labelpsi, -25);
    lv_obj_set_align(ui_labelpsi, LV_ALIGN_CENTER);
    lv_label_set_text(ui_labelpsi, "psi");
    lv_obj_set_style_text_font(ui_labelpsi, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ArcFuelRight = lv_arc_create(ui_Screen2);
    lv_obj_set_width(ui_ArcFuelRight, 480);
    lv_obj_set_height(ui_ArcFuelRight, 480);
    lv_obj_set_x(ui_ArcFuelRight, 7);
    lv_obj_set_y(ui_ArcFuelRight, -1);
    lv_obj_set_align(ui_ArcFuelRight, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_ArcFuelRight, 0, 40);
    lv_arc_set_value(ui_ArcFuelRight, 38);
    lv_arc_set_bg_angles(ui_ArcFuelRight, 10, 90);
    lv_obj_set_style_arc_width(ui_ArcFuelRight, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcFuelRight, false, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcFuelRight, lv_color_hex(0x2095F6), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcFuelRight, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcFuelRight, 30, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcFuelRight, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcFuelRight, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcFuelRight, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_ArcFuelLeft = lv_arc_create(ui_Screen2);
    lv_obj_set_width(ui_ArcFuelLeft, 480);
    lv_obj_set_height(ui_ArcFuelLeft, 480);
    lv_obj_set_x(ui_ArcFuelLeft, -6);
    lv_obj_set_y(ui_ArcFuelLeft, -1);
    lv_obj_set_align(ui_ArcFuelLeft, LV_ALIGN_CENTER);
    lv_arc_set_range(ui_ArcFuelLeft, 0, 40);
    lv_arc_set_value(ui_ArcFuelLeft, 10);
    lv_arc_set_bg_angles(ui_ArcFuelLeft, 0, 80);
    lv_arc_set_mode(ui_ArcFuelLeft, LV_ARC_MODE_REVERSE);
    lv_arc_set_rotation(ui_ArcFuelLeft, 90);
    lv_obj_set_style_arc_width(ui_ArcFuelLeft, 30, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcFuelLeft, false, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_set_style_arc_color(ui_ArcFuelLeft, lv_color_hex(0xF64C18), LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_opa(ui_ArcFuelLeft, 255, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_width(ui_ArcFuelLeft, 30, LV_PART_INDICATOR | LV_STATE_DEFAULT);
    lv_obj_set_style_arc_rounded(ui_ArcFuelLeft, false, LV_PART_INDICATOR | LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(ui_ArcFuelLeft, lv_color_hex(0xFFFFFF), LV_PART_KNOB | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ArcFuelLeft, 0, LV_PART_KNOB | LV_STATE_DEFAULT);

    ui_BarFuelPressure = lv_bar_create(ui_Screen2);
    lv_bar_set_range(ui_BarFuelPressure, 11, 17);
    lv_bar_set_value(ui_BarFuelPressure, 14, LV_ANIM_OFF);
    lv_bar_set_start_value(ui_BarFuelPressure, 0, LV_ANIM_OFF);
    lv_obj_set_width(ui_BarFuelPressure, 413);
    lv_obj_set_height(ui_BarFuelPressure, 10);
    lv_obj_set_x(ui_BarFuelPressure, -4);
    lv_obj_set_y(ui_BarFuelPressure, -23);
    lv_obj_set_align(ui_BarFuelPressure, LV_ALIGN_CENTER);

    //Compensating for LVGL9.1 draw crash with bar/slider max value when top-padding is nonzero and right-padding is 0
    if(lv_obj_get_style_pad_top(ui_BarFuelPressure, LV_PART_MAIN) > 0) lv_obj_set_style_pad_right(ui_BarFuelPressure,
                                                                                                      lv_obj_get_style_pad_right(ui_BarFuelPressure, LV_PART_MAIN) + 1, LV_PART_MAIN);
    ui_label01 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_label01, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label01, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_label01, -224);
    lv_obj_set_y(ui_label01, 14);
    lv_obj_set_align(ui_label01, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label01, "01");
    lv_obj_set_style_text_font(ui_label01, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_label02 = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_label02, LV_SIZE_CONTENT);   /// 1
    lv_obj_set_height(ui_label02, LV_SIZE_CONTENT);    /// 1
    lv_obj_set_x(ui_label02, 222);
    lv_obj_set_y(ui_label02, 14);
    lv_obj_set_align(ui_label02, LV_ALIGN_CENTER);
    lv_label_set_text(ui_label02, "02");
    lv_obj_set_style_text_font(ui_label02, &lv_font_montserrat_12, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelLeftValue = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_LabelLeftValue, 56);
    lv_obj_set_height(ui_LabelLeftValue, 40);
    lv_obj_set_x(ui_LabelLeftValue, -80);
    lv_obj_set_y(ui_LabelLeftValue, 93);
    lv_obj_set_align(ui_LabelLeftValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelLeftValue, "28");
    lv_obj_set_style_text_font(ui_LabelLeftValue, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_LabelRightValue = lv_label_create(ui_Screen2);
    lv_obj_set_width(ui_LabelRightValue, 57);
    lv_obj_set_height(ui_LabelRightValue, 40);
    lv_obj_set_x(ui_LabelRightValue, 73);
    lv_obj_set_y(ui_LabelRightValue, 96);
    lv_obj_set_align(ui_LabelRightValue, LV_ALIGN_CENTER);
    lv_label_set_text(ui_LabelRightValue, "38");
    lv_obj_set_style_text_font(ui_LabelRightValue, &lv_font_montserrat_38, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_puntini2 = lv_obj_create(ui_Screen2);
    lv_obj_set_width(ui_puntini2, 126);
    lv_obj_set_height(ui_puntini2, 32);
    lv_obj_set_x(ui_puntini2, 0);
    lv_obj_set_y(ui_puntini2, 164);
    lv_obj_set_align(ui_puntini2, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_puntini2, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_GESTURE_BUBBLE | LV_OBJ_FLAG_SNAPPABLE |
                       LV_OBJ_FLAG_SCROLLABLE | LV_OBJ_FLAG_SCROLL_ELASTIC | LV_OBJ_FLAG_SCROLL_MOMENTUM |
                       LV_OBJ_FLAG_SCROLL_CHAIN);     /// Flags
    lv_obj_set_style_radius(ui_puntini2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_puntini2, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_puntini2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_puntini2, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_puntini2, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel11 = lv_obj_create(ui_puntini2);
    lv_obj_set_width(ui_Panel11, 15);
    lv_obj_set_height(ui_Panel11, 15);
    lv_obj_set_x(ui_Panel11, -10);
    lv_obj_set_y(ui_Panel11, 0);
    lv_obj_set_align(ui_Panel11, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Panel11, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel11, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel11, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel11, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel11, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel2 = lv_obj_create(ui_puntini2);
    lv_obj_set_width(ui_Panel2, 15);
    lv_obj_set_height(ui_Panel2, 15);
    lv_obj_set_x(ui_Panel2, -30);
    lv_obj_set_y(ui_Panel2, 0);
    lv_obj_set_align(ui_Panel2, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Panel2, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel2, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel2, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel2, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel2, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel8 = lv_obj_create(ui_puntini2);
    lv_obj_set_width(ui_Panel8, 15);
    lv_obj_set_height(ui_Panel8, 15);
    lv_obj_set_x(ui_Panel8, 10);
    lv_obj_set_y(ui_Panel8, 0);
    lv_obj_set_align(ui_Panel8, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Panel8, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel8, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel8, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel8, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel8, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_Panel9 = lv_obj_create(ui_puntini2);
    lv_obj_set_width(ui_Panel9, 15);
    lv_obj_set_height(ui_Panel9, 15);
    lv_obj_set_x(ui_Panel9, 30);
    lv_obj_set_y(ui_Panel9, 0);
    lv_obj_set_align(ui_Panel9, LV_ALIGN_CENTER);
    lv_obj_remove_flag(ui_Panel9, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_radius(ui_Panel9, 7, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(ui_Panel9, lv_color_hex(0x4D4D4D), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_Panel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_color(ui_Panel9, lv_color_hex(0x101418), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_border_opa(ui_Panel9, 255, LV_PART_MAIN | LV_STATE_DEFAULT);

    ui_ButtonToScn3 = lv_button_create(ui_Screen2);
    lv_obj_set_width(ui_ButtonToScn3, 480);
    lv_obj_set_height(ui_ButtonToScn3, 480);
    lv_obj_set_align(ui_ButtonToScn3, LV_ALIGN_CENTER);
    lv_obj_add_flag(ui_ButtonToScn3, LV_OBJ_FLAG_SCROLL_ON_FOCUS);     /// Flags
    lv_obj_remove_flag(ui_ButtonToScn3, LV_OBJ_FLAG_SCROLLABLE);      /// Flags
    lv_obj_set_style_bg_color(ui_ButtonToScn3, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(ui_ButtonToScn3, 0, LV_PART_MAIN | LV_STATE_DEFAULT);

    lv_obj_add_event_cb(ui_ButtonToScn3, ui_event_ButtonToScn3, LV_EVENT_ALL, NULL);

}
