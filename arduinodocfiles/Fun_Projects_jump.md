# Jump Game (Arduino LED/Buzzer)

## 📌 Overview

A fun interactive Arduino game where a player presses a button to make a character 'jump' over obstacles displayed on LEDs or OLED, with increasing difficulty.

---

## 🧰 Components Required

- Arduino Uno
- Push Button
- OLED Display 0.96" (SSD1306) or LED Array
- Buzzer
- 10kΩ Resistor (pull-down)
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- Button → Digital Pin 2 (with 10kΩ pull-down to GND)
- OLED SDA → A4, SCL → A5
- Buzzer → Digital Pin 8
- Power → 5V, GND → GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Game Loop** | Continuous loop in firmware that updates game state, reads inputs, and refreshes display every frame. |
| **Collision Detection** | Logic checking overlap between player character position and obstacle position to determine game-over. |
| **Debouncing** | Filtering rapid multiple signals from a button press to register only a single clean input event. |
| **Sprite** | A small bitmap image representing the player or obstacle drawn on the OLED frame buffer. |
| **Difficulty Scaling** | Increasing obstacle speed or frequency over time to make the game progressively harder. |

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
