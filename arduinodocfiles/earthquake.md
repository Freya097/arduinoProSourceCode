# Earthquake Detection System

## 📌 Overview

Detects seismic vibrations using a vibration sensor or accelerometer and triggers alerts with buzzer, display, and optional SMS notification.

---

## 🧰 Components Required

- Arduino Uno
- MPU6050 Accelerometer/Gyroscope
- SW-420 Vibration Sensor
- Buzzer
- LCD I2C Display
- LEDs
- GSM Module (optional)
- Jumper Wires

---

## 🔌 Circuit Connections

- MPU6050 SDA → A4, SCL → A5 (I2C)
- SW-420 DO → Digital Pin 2 (interrupt)
- SW-420 AO → A0
- Buzzer → Pin 8
- LED → Pin 13
- LCD SDA → A4, SCL → A5 (shared I2C)

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **MPU6050** | 6-DOF IMU sensor measuring 3-axis acceleration and 3-axis angular velocity via I2C interface. |
| **SW-420 Vibration Sensor** | Spring-based vibration switch outputting digital HIGH on detecting mechanical vibration above threshold. |
| **Richter Scale Simulation** | Mapping accelerometer magnitude values to approximate Richter scale categories for display. |
| **Seismic Threshold** | Minimum acceleration vector magnitude (√ax²+ay²+az²) triggering earthquake alert. |
| **Debounce Filtering** | Ignoring vibrations shorter than a minimum duration to distinguish earthquakes from minor shocks. |

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
