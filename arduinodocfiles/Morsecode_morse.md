# Morse Code Encoder/Decoder

## 📌 Overview

Translates text input into Morse code audio/visual output via buzzer and LED, and optionally decodes incoming Morse signals back to text.

---

## 🧰 Components Required

- Arduino Uno
- Push Button (for input)
- Buzzer (active or passive)
- LED
- 16x2 LCD or Serial Monitor
- 220Ω Resistor
- 10kΩ Resistor
- Jumper Wires

---

## 🔌 Circuit Connections

- Button → Digital Pin 2 (with 10kΩ pull-down)
- Buzzer → Digital Pin 8
- LED → Digital Pin 13 (with 220Ω resistor)
- LCD SDA → A4, SCL → A5
- VCC → 5V, GND → GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Morse Code** | Encoding system representing characters as sequences of dots (short signals) and dashes (long signals). |
| **Dot (Dit)** | Short signal in Morse code, typically 1 unit of time duration. |
| **Dash (Dah)** | Long signal in Morse code, typically 3 units of time duration. |
| **Timing Logic** | Measuring button press duration and gaps to distinguish dots, dashes, letter breaks, and word breaks. |
| **Character Map Array** | Lookup table in Arduino program memory mapping characters to their Morse code string equivalents. |

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
