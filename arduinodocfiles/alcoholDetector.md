# Portable Alcohol Detector

## 📌 Overview

Standalone breathalyzer device using MQ-3 sensor with LED bar graph or LCD display showing alcohol level with safe/warning/danger zones.

---

## 🧰 Components Required

- Arduino Nano or Uno
- MQ-3 Alcohol Gas Sensor
- LED Bar (Red/Yellow/Green x3 each)
- Buzzer
- 16x2 LCD or OLED
- 220Ω Resistors
- 9V Battery + Clip
- Enclosure Box

---

## 🔌 Circuit Connections

- MQ-3 Analog Out → A0
- MQ-3 VCC → 5V (must preheat 20s)
- Green LEDs → Pins 3,4,5
- Yellow LEDs → Pins 6,7,8
- Red LEDs → Pins 9,10,11
- Buzzer → Pin 12
- LCD SDA → A4, SCL → A5

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Breathalyzer** | Device estimating blood alcohol level by measuring alcohol vapor concentration in exhaled breath. |
| **LED Bar Graph** | Visual meter using rows of LEDs to indicate signal level; green=safe, yellow=caution, red=danger. |
| **Warm-Up Indication** | LED or display message during the MQ-3 preheat period before reliable readings are available. |
| **Analog Mapping** | Arduino map() function scaling raw ADC values (0-1023) to meaningful alcohol level percentage. |
| **Sensitivity Calibration** | Adjusting threshold values in code based on sensor datasheet Rs/R0 ratio for accuracy. |

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
