# Self-Driving Obstacle Avoidance Car

## 📌 Overview

Autonomous robot car using ultrasonic sensor to detect obstacles and automatically navigate around them without human input.

---

## 🧰 Components Required

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo (sensor mount)
- L298N Motor Driver
- DC Gear Motors (x2)
- Robot Chassis + Wheels
- 7.4V Li-Po Battery
- Jumper Wires

---

## 🔌 Circuit Connections

- HC-SR04 TRIG → Pin 12, ECHO → Pin 11
- Servo Signal → Pin 10
- L298N IN1 → Pin 5, IN2 → Pin 6
- L298N IN3 → Pin 7, IN4 → Pin 8
- ENA → Pin 9, ENB → Pin 3 (PWM)
- L298N 12V → Battery, 5V → Arduino Vin

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Obstacle Avoidance Algorithm** | Logic: if front distance < threshold, stop, scan left and right, turn toward side with greater clearance. |
| **Sensor Sweep** | Rotating ultrasonic sensor left/right on servo to measure distances at multiple angles for navigation decision. |
| **Clearance Distance** | Minimum safe distance threshold (e.g., 20cm) triggering obstacle avoidance routine. |
| **Differential Steering** | Controlling left and right motor speeds independently for turning without a steering servo. |
| **Dead-End Recovery** | Executing 180° turn when no clear path is found on either side during obstacle avoidance. |

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
