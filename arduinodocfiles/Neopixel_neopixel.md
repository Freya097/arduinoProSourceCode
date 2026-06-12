# NeoPixel LED Strip Effects

## 📌 Overview

Controls addressable WS2812B NeoPixel LEDs to produce colorful animations, rainbow effects, and reactive lighting patterns.

---

## 🧰 Components Required

- Arduino Uno
- WS2812B NeoPixel LED Strip or Ring
- 1000µF Capacitor (across power supply)
- 470Ω Resistor (data line)
- 5V 2A+ Power Supply
- Jumper Wires

---

## 🔌 Circuit Connections

- NeoPixel DIN → 470Ω resistor → Digital Pin 6
- NeoPixel VCC → External 5V (NOT Arduino 5V for >10 LEDs)
- NeoPixel GND → Common GND with Arduino
- 1000µF capacitor across VCC and GND (near strip)

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **WS2812B** | Addressable RGB LED with integrated controller IC, allowing each LED to be individually color-controlled. |
| **Addressable LED** | LED with built-in driver receiving color data via single-wire serial protocol in a daisy-chain configuration. |
| **FastLED / Adafruit NeoPixel Library** | Arduino libraries providing high-level functions for controlling addressable LED strips and rings. |
| **HSV Color Model** | Hue-Saturation-Value color space used to create smooth color transitions and rainbow animations. |
| **Data Decoupling Resistor** | 470Ω resistor on data line prevents ringing and signal reflections at high data rates. |

---

## 🚀 How It Works

1. Power up the circuit and upload the Arduino/ESP code.
2. Initialize all sensors and modules in `setup()`.
3. Continuously read sensor data in the `loop()` function.
4. Apply control logic to outputs (relay, motor, display, buzzer).
5. Monitor via Serial Monitor or display for live feedback.

---

## 💡 Applications

- **Education:** STEM learning and electronics fundamentals
- **Prototyping:** Proof-of-concept for real-world embedded systems
- **Competition:** Science fairs and robotics exhibitions

---

*Generated for Arduino / ESP32 MicroPython Curriculum | Tamil Nadu STEM Education*
