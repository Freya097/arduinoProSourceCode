# Alexa Voice Command Controller

## 📌 Overview

Controls ESP8266/ESP32 devices using Amazon Alexa voice commands through Espalexa or SinricPro library over Wi-Fi.

---

## 🧰 Components Required

- ESP8266 NodeMCU or ESP32
- Relay Module (1-4 channel)
- LED or Appliance
- Wi-Fi Router (2.4GHz)
- Amazon Echo Device or Alexa App
- 5V Power Supply
- Jumper Wires

---

## 🔌 Circuit Connections

- Relay IN → ESP8266 D1 (GPIO5)
- Relay VCC → 5V, GND → GND
- Relay NO → Load, COM → Power
- ESP8266 VIN → 5V via USB or adapter

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Espalexa Library** | Arduino library emulating Philips Hue bulb API to integrate ESP devices with Amazon Alexa locally. |
| **mDNS (Multicast DNS)** | Protocol allowing devices to be discovered by name (e.g., 'esp-light.local') on local network. |
| **UPnP (Universal Plug and Play)** | Network protocol used by Espalexa for Alexa device discovery without cloud dependency. |
| **Voice Command Parsing** | Alexa processing natural language ('turn on the lamp') to identify device and action. |
| **Local vs Cloud Control** | Espalexa works locally on LAN; SinricPro uses cloud — local is faster but requires same network. |

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
