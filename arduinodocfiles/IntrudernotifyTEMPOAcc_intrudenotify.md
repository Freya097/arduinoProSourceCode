# Intruder Detection & Notification System

## 📌 Overview

Detects unauthorized entry using PIR motion sensor and accelerometer, then sends alert via GSM SMS or buzzer alarm.

---

## 🧰 Components Required

- Arduino Uno
- PIR Motion Sensor (HC-SR501)
- MPU6050 Accelerometer/Gyroscope
- GSM Module SIM800L (optional)
- Buzzer
- LED
- SIM Card
- Jumper Wires

---

## 🔌 Circuit Connections

- PIR OUT → Digital Pin 2 (Interrupt)
- MPU6050 SDA → A4, SCL → A5
- SIM800L TX → Pin 10, RX → Pin 11
- Buzzer → Digital Pin 8
- LED → Digital Pin 13
- PIR VCC → 5V, MPU6050 VCC → 3.3V

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **PIR Sensor (HC-SR501)** | Passive Infrared sensor detecting changes in infrared radiation emitted by warm bodies in its field of view. |
| **MPU6050** | 6-axis IMU combining 3-axis accelerometer and 3-axis gyroscope, detecting tilt, vibration, and movement. |
| **GSM SIM800L** | Compact GSM/GPRS module enabling SMS and voice calls from Arduino for remote notifications. |
| **Interrupt Pin** | Arduino external interrupt (Pin 2/3) that immediately triggers ISR on PIR signal change. |
| **Tamper Detection** | Accelerometer-based monitoring for physical disturbance of the security device itself. |

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
