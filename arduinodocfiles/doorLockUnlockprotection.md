# Smart Door Lock with Protection

## 📌 Overview

Keypad-based door lock with RFID backup and intrusion detection; locks after failed attempts and sends alert notifications.

---

## 🧰 Components Required

- Arduino Uno
- 4x4 Matrix Keypad
- RFID RC522 Module
- Servo Motor (door mechanism)
- LCD I2C Display
- Buzzer
- Red & Green LEDs
- Jumper Wires

---

## 🔌 Circuit Connections

- Keypad Rows → Pins 9,8,7,6; Cols → Pins 5,4,3,2
- RC522: SDA→10, SCK→13, MOSI→11, MISO→12, RST→A0, VCC→3.3V
- Servo → Pin A1
- LCD SDA → A4, SCL → A5
- Buzzer → Pin A2, Green LED → A3, Red LED → Pin A4

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **4x4 Matrix Keypad** | 16-key input device using row-column scanning with 8 wires to detect key presses. |
| **PIN Authentication** | Numeric password entered via keypad compared against stored password in EEPROM. |
| **Lockout Mechanism** | After N failed attempts, system locks for a timeout period and triggers alarm. |
| **Dual Authentication** | Requiring both RFID card and PIN for high-security access, combining two factors. |
| **EEPROM Password Storage** | Storing and retrieving PIN in non-volatile EEPROM so it persists between power cycles. |

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
