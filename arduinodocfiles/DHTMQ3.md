# Temperature, Humidity & Alcohol Detection System

## 📌 Overview

Combines DHT sensor (temperature/humidity) with MQ-3 alcohol gas sensor for environmental and breath alcohol monitoring applications.

---

## 🧰 Components Required

- Arduino Uno
- DHT11 or DHT22 Sensor
- MQ-3 Alcohol Gas Sensor
- 16x2 LCD or OLED Display
- Buzzer
- LED
- 10kΩ Resistor
- Jumper Wires

---

## 🔌 Circuit Connections

- DHT11 Data → Digital Pin 7 (with 10kΩ pull-up to 5V)
- MQ-3 Analog Out → A0
- MQ-3 Digital Out → Digital Pin 8
- LCD SDA → A4, SCL → A5
- Buzzer → Digital Pin 9
- LED → Digital Pin 10 (220Ω resistor)
- All VCC → 5V, GND → GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **DHT11** | Digital sensor measuring ambient temperature (0-50°C) and relative humidity (20-80%) with ±2°C accuracy. |
| **MQ-3 Sensor** | Electrochemical gas sensor sensitive to alcohol (ethanol) vapors; outputs both analog and digital signals. |
| **Preheat Time** | MQ-3 requires 20-second warm-up before readings stabilize due to its heating element. |
| **Threshold Detection** | Comparing analog sensor value against a predefined limit to trigger alerts or actions. |
| **Relative Humidity** | Percentage of water vapor in air relative to maximum possible at that temperature. |

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
