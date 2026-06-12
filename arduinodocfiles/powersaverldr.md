# Power Saver with LDR

## 📌 Overview

Automatically turns off lights and devices when ambient light is sufficient, saving electricity using LDR-based auto-switching with relay.

---

## 🧰 Components Required

- Arduino Uno
- LDR (Light Dependent Resistor)
- 10kΩ Resistor
- Relay Module
- LED / Light Bulb
- LCD Display (optional)
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- LDR + 10kΩ voltage divider → A0
- Relay IN → Digital Pin 7
- Relay COM → AC Live, NO → Light
- LCD SDA → A4, SCL → A5 (optional)
- VCC → 5V, GND → GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **LDR (Photoresistor)** | Semiconductor whose resistance inversely varies with light intensity (dark: ~1MΩ, bright: ~100Ω). |
| **Voltage Divider** | LDR and fixed resistor forming a potential divider; output voltage varies with light level. |
| **Hysteresis** | Two different threshold values for ON and OFF switching to prevent relay chattering near threshold. |
| **Relay Chattering** | Rapid ON/OFF switching when sensor value oscillates near threshold — prevented by hysteresis band. |
| **Energy Monitoring** | Optional current sensor addition to log power savings data over time. |

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
