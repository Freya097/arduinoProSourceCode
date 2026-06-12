# IoT Smart Street Light System

## 📌 Overview

Automatically controls street lights based on ambient light (LDR) and motion detection (PIR), reducing energy consumption with IoT monitoring.

---

## 🧰 Components Required

- Arduino / ESP8266 / ESP32
- LDR (Light Dependent Resistor)
- PIR Motion Sensor
- Relay Module
- High-Power LED / Street Light
- 10kΩ Resistor (LDR voltage divider)
- Wi-Fi Module (for IoT version)
- Jumper Wires

---

## 🔌 Circuit Connections

- LDR + 10kΩ voltage divider → A0
- PIR OUT → Digital Pin 2
- Relay IN → Digital Pin 7
- Relay load: Street Light via COM & NO
- ESP8266 TX/RX for cloud upload
- VCC → 5V, GND → GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **LDR (Light Dependent Resistor)** | Photoresistor whose resistance decreases as ambient light intensity increases, used for dusk/dawn detection. |
| **Voltage Divider** | Two resistors in series to produce a voltage proportional to LDR resistance for analog reading. |
| **Adaptive Dimming** | Adjusting street light brightness using PWM based on detected ambient light or activity level. |
| **IoT Dashboard** | Cloud-based interface (e.g., ThingSpeak, Blynk) displaying energy usage and light status remotely. |
| **Energy Harvesting** | Combining solar panels with smart control to power street lights off-grid. |

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
