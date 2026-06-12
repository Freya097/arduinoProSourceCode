# Automated Car Parking System with LCD

## 📌 Overview

Simulates a smart car parking system using IR sensors to detect vehicle entry/exit and displays available slot count on an LCD screen in real time.

---

## 🧰 Components Required

- Arduino Uno
- IR Sensor Modules (x2 minimum)
- 16x2 LCD Display (I2C or parallel)
- Servo Motor (optional barrier gate)
- LED indicators (Red/Green)
- Buzzer
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- IR Sensor 1 (Entry) OUT → Digital Pin 2
- IR Sensor 2 (Exit) OUT → Digital Pin 3
- LCD SDA → A4, SCL → A5 (I2C)
- Servo Signal → Digital Pin 9
- Green LED → Pin 10, Red LED → Pin 11 (with 220Ω resistors)
- Buzzer → Pin 12
- All VCC → 5V, GND → GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **IR Sensor** | Infrared proximity sensor that detects objects by emitting and receiving IR light; active LOW when triggered. |
| **I2C LCD** | LCD display with PCF8574 I2C backpack, reducing pin usage to only SDA and SCL lines. |
| **Servo Motor** | Position-controlled motor used here as a barrier gate arm, controlled via PWM signals. |
| **Slot Counter Logic** | Software counter that increments/decrements based on entry/exit sensor triggers to track available spaces. |
| **Real-time Display** | Continuous LCD update showing live parking availability without requiring user input. |

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
