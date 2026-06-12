# Advanced Agriculture Tech System

## 📌 Overview

Comprehensive smart farming solution integrating multiple sensors (soil, weather, light) with automated irrigation and cloud data logging.

---

## 🧰 Components Required

- ESP32 or Arduino Mega
- Capacitive Soil Moisture Sensor
- DHT22 Temperature & Humidity Sensor
- BH1750 Light Intensity Sensor
- pH Sensor Module
- Peristaltic Water Pump
- OLED Display 0.96"
- 4-Channel Relay
- Solar Panel + Li-Ion Battery (optional)
- Jumper Wires

---

## 🔌 Circuit Connections

- Soil Moisture → A0
- DHT22 → Pin 4
- BH1750 SDA → A4, SCL → A5
- pH Sensor Analog → A1
- Relay IN1-IN4 → Pins 5,6,7,8
- OLED SDA → A4, SCL → A5 (shared I2C bus)

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Capacitive Soil Sensor** | Measures soil moisture via capacitance change; more durable and accurate than resistive probes. |
| **BH1750** | 16-bit I2C ambient light sensor measuring illuminance in lux for crop light monitoring. |
| **pH Sensor** | Electrochemical sensor measuring soil or water acidity (0-14 pH) using a glass electrode. |
| **Peristaltic Pump** | Precise liquid pump using rotating rollers on tubing; ideal for controlled nutrient delivery. |
| **Data Logging** | Periodic recording of sensor values with timestamps to SD card or cloud for trend analysis. |

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
