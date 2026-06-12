# RFID Door Lock System

## 📌 Overview

Secure door access control using RFID cards where only authorized UIDs unlock a solenoid lock or servo-based door mechanism.

---

## 🧰 Components Required

- Arduino Uno
- RFID RC522 Module
- RFID Cards/Tags
- Servo Motor or Solenoid Lock
- 16x2 LCD (I2C)
- Green & Red LEDs
- Buzzer
- 12V Power Supply (for solenoid)
- Relay Module (for solenoid)
- Jumper Wires

---

## 🔌 Circuit Connections

- RC522: SDA→10, SCK→13, MOSI→11, MISO→12, RST→9, VCC→3.3V
- Servo Signal → Pin 6 (or Relay IN → Pin 7 for solenoid)
- Green LED → Pin 4, Red LED → Pin 5 (220Ω each)
- Buzzer → Pin 8
- LCD SDA → A4, SCL → A5

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Access Control** | System granting or denying entry based on verified identity via RFID card authentication. |
| **Whitelist Array** | Array in Arduino program storing authorized card UIDs compared against scanned UID for access decision. |
| **Solenoid Lock** | Electromechanical lock that retracts its bolt when energized, used for electric door/drawer locking. |
| **EEPROM Storage** | Non-volatile Arduino memory for storing authorized UIDs that persist after power cycle. |
| **Fail-Secure vs Fail-Safe** | Fail-secure: lock stays locked on power loss; Fail-safe: lock opens on power loss for emergency exit. |

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
