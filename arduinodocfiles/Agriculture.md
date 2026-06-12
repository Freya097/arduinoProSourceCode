# Smart Agriculture Monitoring System

## 📌 Overview

An IoT-based agriculture system that monitors soil moisture, temperature, and humidity to automate irrigation and help farmers make data-driven decisions.

---

## 🧰 Components Required

- Arduino Uno / ESP8266 / ESP32
- Soil Moisture Sensor (YL-69 or capacitive)
- DHT11/DHT22 Temperature & Humidity Sensor
- 5V Relay Module
- Water Pump (5V or 12V)
- 16x2 LCD Display (I2C)
- Jumper Wires
- Power Supply

---

## 🔌 Circuit Connections

- Soil Moisture Sensor Analog Out → A0
- DHT11 Data Pin → Digital Pin 7
- Relay IN → Digital Pin 8
- Relay COM → Water Pump (+)
- LCD SDA → A4, SCL → A5
- All VCC → 5V, GND → GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Soil Moisture Sensor** | Measures the volumetric water content in soil using resistance or capacitance variation between two probes. |
| **DHT11/DHT22** | Digital temperature and humidity sensors with single-wire serial interface, DHT22 offering higher accuracy. |
| **Relay Module** | An electrically operated switch that allows a low-power microcontroller to control high-power devices like pumps. |
| **Precision Agriculture** | Technology-driven farming approach using sensors and automation to optimize resource usage and crop yield. |
| **Irrigation Automation** | Automated control of water supply based on real-time sensor data to prevent under/overwatering. |

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
