# Arduino Radar System

## 📌 Overview

Ultrasonic radar using servo-mounted HC-SR04 sensor sweeping 180° and displaying detected objects on a Processing/Serial radar visualization.

---

## 🧰 Components Required

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- USB Cable (for Processing visualization)
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- HC-SR04 TRIG → Digital Pin 10
- HC-SR04 ECHO → Digital Pin 11
- HC-SR04 VCC → 5V, GND → GND
- Servo Signal → Digital Pin 9
- Servo VCC → 5V (external recommended), GND → Common

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **HC-SR04** | Ultrasonic distance sensor using 40kHz sound pulses to measure distances from 2cm to 400cm. |
| **Pulse Echo Timing** | Measuring time between ultrasonic trigger pulse and echo return; distance = (time × 0.0343cm/µs) / 2. |
| **Servo Sweep** | Moving servo from 15° to 165° in increments, pausing at each angle for a distance measurement. |
| **Processing IDE** | Java-based visualization software receiving Arduino serial data to render 2D radar display. |
| **Scan Angle Resolution** | Degree increment per step in servo sweep — smaller steps give finer object position resolution. |

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
