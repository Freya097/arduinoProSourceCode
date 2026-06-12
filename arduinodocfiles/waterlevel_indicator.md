# Simple Water Level Indicator

## 📌 Overview

Basic water level monitoring using conductive probes at different heights, lighting up corresponding LEDs to show the current water level visually.

---

## 🧰 Components Required

- Arduino Uno or NE555 (discrete version)
- Copper Wire Probes (x5)
- LEDs (5 colors)
- 220Ω Resistors (x5)
- Buzzer
- BC547 Transistors (x5, for discrete version)
- Jumper Wires

---

## 🔌 Circuit Connections

- Probe 1 (Empty) → Pin 2
- Probe 2 (25%) → Pin 3
- Probe 3 (50%) → Pin 4
- Probe 4 (75%) → Pin 5
- Probe 5 (Full) → Pin 6
- LEDs with 220Ω → Pins 8,9,10,11,12
- Buzzer → Pin 13 (Full alert)

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Conductive Probe** | Bare wire placed at specific tank heights; water contact completes circuit to Arduino digital input. |
| **INPUT_PULLUP** | Arduino internal pull-up resistor making unpowered pin read HIGH; water contact pulls it LOW. |
| **Level Percentage** | Mapping number of active probes to percentage (0%, 25%, 50%, 75%, 100%) for display. |
| **Electrolysis** | Gradual electrode corrosion from DC current through water; mitigated by using AC or intermittent sensing. |
| **LED Bar Display** | Sequential LED lighting corresponding to water level — more LEDs lit means higher water level. |

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
