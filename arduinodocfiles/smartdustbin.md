# Smart Dustbin

## 📌 Overview

Touchless automatic dustbin that opens its lid using servo when hand is detected nearby via ultrasonic sensor, then closes after delay.

---

## 🧰 Components Required

- Arduino Uno
- HC-SR04 Ultrasonic Sensor
- SG90 Servo Motor
- 9V Battery
- Dustbin / Container
- Jumper Wires

---

## 🔌 Circuit Connections

- HC-SR04 TRIG → Pin 9, ECHO → Pin 10
- Servo Signal → Pin 6
- HC-SR04 VCC → 5V, GND → GND
- Servo VCC → 5V, GND → GND
- Arduino powered by 9V battery

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Proximity Detection** | Triggering action when measured distance falls below a threshold (e.g., hand within 15cm of sensor). |
| **Servo Lid Control** | Servo at 0° = lid closed, 90° = lid open; timed return to closed position after ~3 seconds. |
| **Touchless Hygiene** | No physical contact required for lid operation, preventing germ spread in medical/public environments. |
| **Auto-Close Timer** | millis()-based non-blocking delay returning lid to closed position after fixed duration. |
| **Debounce Hysteresis** | Ignoring sensor readings between close/open distance bands to prevent lid flickering. |

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
