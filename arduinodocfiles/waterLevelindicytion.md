# Water Level Indicator & Controller

## 📌 Overview

Monitors water level in a tank using sensors and automatically controls a pump to fill or stop filling, with LED/LCD level display.

---

## 🧰 Components Required

- Arduino Uno
- Water Level Sensor or Float Switches (x4)
- Relay Module
- Submersible Water Pump
- LED Bar (4 LEDs)
- Buzzer
- LCD I2C Display
- Jumper Wires
- Power Supply

---

## 🔌 Circuit Connections

- Level Sensor 1 → A0, Sensor 2 → A1, Sensor 3 → A2, Sensor 4 → A3
- Relay IN → Pin 8 (pump control)
- LED 1 → Pin 4, LED 2 → Pin 5, LED 3 → Pin 6, LED 4 → Pin 7
- Buzzer → Pin 9
- LCD SDA → A4, SCL → A5

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Resistive Water Sensor** | Exposed traces sensor whose resistance varies with water contact level, read via analog pin. |
| **Float Switch** | Mechanical switch closing/opening circuit based on water buoyancy to indicate discrete level points. |
| **Pump Control Logic** | Auto-start pump when level < minimum, auto-stop when level reaches maximum to prevent overflow. |
| **Overflow Prevention** | Pump shutoff and alarm trigger when sensor at maximum level detects water. |
| **Dry Run Protection** | Preventing pump operation when tank is empty to avoid pump damage from no-load running. |

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
