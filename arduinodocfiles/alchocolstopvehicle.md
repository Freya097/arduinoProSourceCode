# Alcohol Detection Vehicle Stop System

## 📌 Overview

Detects alcohol on driver's breath using MQ-3 sensor and automatically stops the vehicle motor, preventing drunk driving accidents.

---

## 🧰 Components Required

- Arduino Uno
- MQ-3 Alcohol Sensor
- L298N Motor Driver
- DC Motors (x2)
- Buzzer
- LCD Display
- LEDs (Red/Green)
- 9V Battery
- Jumper Wires

---

## 🔌 Circuit Connections

- MQ-3 Analog Out → A0
- L298N IN1 → Pin 5, IN2 → Pin 6 (Motor A)
- L298N IN3 → Pin 7, IN4 → Pin 8 (Motor B)
- L298N ENA → Pin 9, ENB → Pin 10 (PWM)
- Buzzer → Pin 11
- Red LED → Pin 12, Green LED → Pin 13
- LCD SDA → A4, SCL → A5

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Blood Alcohol Threshold** | Predefined analog sensor value mapped to legal BAC limit (0.08% in most regions) triggering motor stop. |
| **Motor Inhibit Logic** | Software flag that prevents motor control PWM output when alcohol is detected above threshold. |
| **MQ-3 Calibration** | Baseline sensor resistance (R0) measured in clean air used to calculate alcohol concentration ratio. |
| **Fail-Safe Design** | System defaults to motors stopped state; requires confirmed sober reading to enable driving. |
| **BAC (Blood Alcohol Content)** | Measure of alcohol in bloodstream; MQ-3 provides a breath correlation for estimation. |

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
