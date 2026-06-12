# Heartbeat Monitor with I2C LCD

## 📌 Overview

Pulse sensor-based heart rate monitor displaying live BPM readings on an I2C LCD with a pulsing LED indicator synchronized with heartbeat.

---

## 🧰 Components Required

- Arduino Uno
- Pulse Sensor Amped
- I2C LCD 16x2 (PCF8574)
- LED (heartbeat indicator)
- 220Ω Resistor
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- Pulse Sensor Signal → A0
- Pulse Sensor VCC → 3.3V, GND → GND
- LCD SDA → A4, SCL → A5
- LED → Digital Pin 13 (220Ω)
- I2C address: 0x27 (typical)

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **I2C Protocol** | Two-wire serial communication (SDA + SCL) allowing multiple devices to share the same bus via addresses. |
| **PCF8574** | I2C I/O expander IC on LCD backpack converting I2C signals to parallel LCD interface. |
| **BPM Calculation** | Counting time between successive pulse peaks and dividing 60,000ms by that interval. |
| **Timer ISR** | Interrupt Service Routine triggered every 2ms to consistently sample pulse sensor analog value. |
| **LCD Refresh Rate** | Display update frequency — too fast causes flicker; typically updated every 1 second for BPM. |

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
