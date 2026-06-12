# PIR Motion Detector & Alert System

## 📌 Overview

Detects human motion using a PIR sensor and triggers an alarm with LED and buzzer alerts, with optional logging to Serial or SD card.

---

## 🧰 Components Required

- Arduino Uno
- PIR Motion Sensor HC-SR501
- Buzzer
- Red LED
- Green LED
- 220Ω Resistors
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- PIR OUT → Digital Pin 2 (or interrupt pin)
- PIR VCC → 5V, GND → GND
- Red LED (alarm) → Pin 13 with 220Ω
- Green LED (standby) → Pin 12 with 220Ω
- Buzzer → Pin 8

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **PIR (Passive Infrared)** | Sensor detecting infrared radiation variations caused by warm moving objects like humans and animals. |
| **Fresnel Lens** | Plastic lens on PIR sensor focusing infrared radiation onto the pyroelectric element for wider detection angle. |
| **Sensitivity Adjustment** | Potentiometer on HC-SR501 adjusting detection range from 3 to 7 meters. |
| **Time Delay Pot** | Sets how long the PIR output stays HIGH after motion stops (0.3s to 5 minutes). |
| **Retriggering Mode** | H mode: re-triggers while motion continues; L mode: one fixed pulse per detection event. |

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
