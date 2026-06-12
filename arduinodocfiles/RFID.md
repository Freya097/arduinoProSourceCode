# RFID Reader System

## 📌 Overview

Reads RFID card/tag UIDs using an RC522 module and displays identity information on LCD, useful for attendance and identification systems.

---

## 🧰 Components Required

- Arduino Uno
- RFID Reader RC522 Module
- RFID Cards/Tags (13.56MHz)
- 16x2 LCD Display (I2C)
- Buzzer
- LED
- Jumper Wires

---

## 🔌 Circuit Connections

- RC522 SDA → Pin 10
- RC522 SCK → Pin 13
- RC522 MOSI → Pin 11
- RC522 MISO → Pin 12
- RC522 RST → Pin 9
- RC522 VCC → 3.3V (NOT 5V!)
- RC522 GND → GND
- LCD SDA → A4, SCL → A5

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **RFID (Radio Frequency Identification)** | Technology using electromagnetic fields to automatically identify tags attached to objects. |
| **RC522 Module** | NXP MFRC522-based RFID reader operating at 13.56MHz using SPI communication with Arduino. |
| **UID (Unique Identifier)** | 4 or 7-byte unique code embedded in each RFID card used to distinguish individual tags. |
| **SPI (Serial Peripheral Interface)** | 4-wire synchronous serial protocol used by RC522 for fast data transfer with Arduino. |
| **Mifare Classic** | Common RFID card standard with 1KB EEPROM storage and UID-based authentication. |

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
