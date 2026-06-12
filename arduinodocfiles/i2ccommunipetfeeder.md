# Automated Pet Feeder (I2C Communication)

## 📌 Overview

Timed automatic pet feeder using servo motor to dispense food at programmed intervals, with I2C RTC for accurate scheduling and LCD display.

---

## 🧰 Components Required

- Arduino Uno
- DS3231 RTC Module (I2C)
- Servo Motor
- I2C LCD 16x2
- Push Buttons (Set time/feed)
- Food Container + Servo-driven gate
- Jumper Wires
- 5V Power Adapter

---

## 🔌 Circuit Connections

- DS3231 SDA → A4, SCL → A5
- LCD SDA → A4, SCL → A5 (same I2C bus, different address)
- Servo Signal → Pin 9
- Set Button → Pin 2, Feed Button → Pin 3
- DS3231 VCC → 3.3V/5V, GND → GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **DS3231 RTC** | High-accuracy real-time clock IC with temperature compensation, I2C interface, and coin cell battery backup. |
| **I2C Bus Sharing** | Multiple I2C devices (RTC at 0x68, LCD at 0x27) sharing SDA/SCL lines using unique addresses. |
| **Servo Sweep** | Moving servo from closed angle to open angle briefly to release a measured food portion. |
| **Feeding Schedule** | Array of time structs stored in EEPROM defining when daily automatic feeding should occur. |
| **UNIX Timestamp** | Seconds elapsed since Jan 1, 1970 used for easy time comparison in scheduling logic. |

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
