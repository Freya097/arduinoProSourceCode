# Eye Blink Vehicle Control

## 📌 Overview

Assistive technology project detecting eye blink patterns using an IR-based eye sensor to control vehicle direction — enabling hands-free driving for differently-abled users.

---

## 🧰 Components Required

- Arduino Uno
- IR Eye Blink Sensor (TCRT5000 or dedicated module)
- L298N Motor Driver
- DC Motors (x2)
- Car Chassis
- LCD Display
- 9V Battery
- Jumper Wires

---

## 🔌 Circuit Connections

- Eye Sensor OUT → Digital Pin 2 (interrupt)
- L298N IN1 → Pin 5, IN2 → Pin 6
- L298N IN3 → Pin 7, IN4 → Pin 8
- ENA → Pin 9, ENB → Pin 10 (PWM)
- LCD SDA → A4, SCL → A5
- Motor power → External 9V

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **TCRT5000** | Reflective IR sensor detecting eye proximity and movement by measuring IR reflectance from eyelid. |
| **Blink Pattern Recognition** | Decoding single/double/long blinks via timing intervals to map to forward, turn, and stop commands. |
| **Assistive Technology** | Devices and systems designed to help people with disabilities perform tasks they find difficult. |
| **Finite State Machine** | Programming model tracking blink sequence states (idle, blinking, counting) for command detection. |
| **Debounce Timer** | Ignoring rapid multiple blink detections within a short window to avoid accidental commands. |

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
