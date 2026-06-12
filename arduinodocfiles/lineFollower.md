# Line Following Robot

## 📌 Overview

Autonomous robot that follows a black line on white surface using IR sensors, adjusting motor direction to stay on track.

---

## 🧰 Components Required

- Arduino Uno
- IR Sensor Array (TCRT5000 x2-5) or QTR Sensor
- L298N Motor Driver
- DC Gear Motors (x2)
- Robot Chassis with wheels
- 9V or 7.4V Li-Po Battery
- Jumper Wires

---

## 🔌 Circuit Connections

- Left IR Sensor OUT → Pin 2
- Center IR Sensor OUT → Pin 3
- Right IR Sensor OUT → Pin 4
- L298N IN1 → Pin 5, IN2 → Pin 6 (Left motor)
- L298N IN3 → Pin 7, IN4 → Pin 8 (Right motor)
- ENA → Pin 9, ENB → Pin 10 (PWM speed)

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **TCRT5000 IR Sensor** | Reflective IR sensor pair that detects surface color — white reflects, black absorbs IR, giving HIGH/LOW output. |
| **Differential Drive** | Robot steering by varying speed/direction of left and right motors independently. |
| **PID Control** | Proportional-Integral-Derivative algorithm for smooth line following by calculating error from sensor array. |
| **Dead Reckoning** | Lost-line recovery using last known turn direction to search for the line again. |
| **Sensor Calibration** | Reading sensor values over black and white surfaces to set optimal detection threshold for environment. |

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
