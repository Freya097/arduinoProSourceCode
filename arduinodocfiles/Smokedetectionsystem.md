# Smoke & Fire Detection System

## 📌 Overview

Detects smoke and gas using MQ-2 sensor and triggers an alarm with buzzer, LED, and optional GSM notification for fire safety.

---

## 🧰 Components Required

- Arduino Uno
- MQ-2 Smoke & Gas Sensor
- Buzzer
- Red LED
- 16x2 LCD Display
- GSM Module SIM800L (optional)
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- MQ-2 Analog Out → A0
- MQ-2 Digital Out → Digital Pin 2
- MQ-2 VCC → 5V, GND → GND
- Buzzer → Pin 8
- Red LED → Pin 13 (220Ω)
- LCD SDA → A4, SCL → A5

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **MQ-2 Sensor** | Semiconductor gas sensor sensitive to LPG, smoke, alcohol, propane, hydrogen, methane, and CO. |
| **Heating Element** | Internal coil in MQ sensor that heats the sensing material, requiring 20-30 second preheat. |
| **Analog Threshold** | Analog voltage level set in code above which an alarm is triggered for smoke/gas detection. |
| **Dual Output** | MQ-2 provides both analog (concentration level) and digital (threshold crossed) outputs simultaneously. |
| **False Positive Prevention** | Adding delays and averaging multiple readings to avoid false alarms from transient gas exposure. |

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
