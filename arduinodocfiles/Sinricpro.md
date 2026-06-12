# SinricPro Smart Home (Alexa/Google Home)

## 📌 Overview

Connects ESP8266/ESP32 to SinricPro cloud platform to control appliances via Amazon Alexa or Google Home voice commands over Wi-Fi.

---

## 🧰 Components Required

- ESP8266 (NodeMCU) or ESP32
- Relay Module (1 to 4 channel)
- Appliances (lights, fan)
- Wi-Fi Router
- 5V Power Supply
- Jumper Wires

---

## 🔌 Circuit Connections

- Relay IN1 → ESP8266 D1 (GPIO5)
- Relay IN2 → ESP8266 D2 (GPIO4)
- Relay VCC → 5V, GND → GND
- ESP8266 powered via USB or Vin
- Relay COM → Live wire, NO → Appliance

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **SinricPro** | Cloud IoT platform providing ready-made device API for Alexa, Google Home, and app-based control of ESP modules. |
| **WebSocket** | Full-duplex communication protocol used by SinricPro library for real-time cloud-device messaging. |
| **Device ID & API Key** | Unique identifiers from SinricPro portal used to authenticate and link hardware to cloud account. |
| **Alexa Skill** | Voice interface extension linking Alexa to SinricPro cloud to control registered smart devices. |
| **OTA Update** | Over-The-Air firmware update capability of ESP8266/ESP32 allowing wireless code uploads. |

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
