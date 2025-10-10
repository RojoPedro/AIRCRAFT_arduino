# ✈️ Flight Visualizer ESP32

An **Arduino-based** project built on the **ESP32** platform, developed upon request from **Alpi Aviation**.  
This device acts as a **digital flight visualizer** designed to be mounted on the **cockpit dashboard of a light aircraft**, representing the **first digital flight assistant** available for ultralight planes.

---

## 🚀 Project Overview

The device interfaces with the aircraft’s onboard control unit to display real-time flight information, providing the pilot with a modern, intuitive interface.  
It is designed to enhance flight awareness, reduce cognitive load, and make essential data easier to read and interpret.

---

## 🧭 Main Features

- **Real-time flight data visualization**  
  Displays key flight parameters such as:
  - Flap inclination  
  - Altitude  
  - Fuel level  
  - Landing gear status  
  - Other critical flight metrics  

- **Integrated voice interaction**  
  Activated by **pressing the device** (analog button), allowing the pilot to both receive spoken updates and communicate with the digital assistant.

- **LVGL-based graphical interface**  
  The entire user interface is built using **[LVGL](https://lvgl.io/)**, an open-source graphics library optimized for embedded microcontrollers.

---

## ⚙️ Hardware & Software

- **Main board:** ESP32  
- **Language:** Arduino C++  
- **Graphics framework:** LVGL  
- **Input:** Analog button (touch/press)  
- **Output:** TFT display and voice assistant (audio input/output)

---

## 🧩 Project Status

The project has been **successfully delivered to Alpi Aviation** and is currently **being implemented** into their ultralight aircraft systems.

---

## 🛠️ Developers

Developed for **Alpi Aviation**  
Software development and interface design by:  
**Pedro Rojo, David Tesserin, Alberto Botter, Raffaella Reccini, Raffaele Petito**

---

## 📄 License

This project is released under the **MIT License**.  
See the [`LICENSE`](LICENSE) file for details.

---

> “Bringing the lightness of flight to the cockpit.”  
> — *Flight Visualizer Team*
