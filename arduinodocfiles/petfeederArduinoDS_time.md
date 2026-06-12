# Pet Feeder with DS1307 Timer

## 📌 Overview

Automatic pet feeder using DS1307 RTC for scheduled feeding times with servo-controlled food gate and LCD display.

---

## 🧰 Components Required

- Arduino Uno
- DS1307 RTC Module
- Servo Motor SG90
- 16x2 LCD I2C
- Push Buttons
- CR2032 Coin Cell (for RTC backup)
- Food Dispenser Mechanism
- 5V Power Supply

---

## 🔌 Circuit Connections

- DS1307 SDA → A4, SCL → A5
- Servo Signal → Pin 9
- LCD SDA → A4, SCL → A5
- Time Set Button → Pin 2, Manual Feed → Pin 3
- DS1307 VCC → 5V, Battery → VBAT pin

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **DS1307** | I2C real-time clock IC maintaining time in BCD format with 56 bytes of NV SRAM and battery backup. |
| **BCD (Binary Coded Decimal)** | Encoding where each decimal digit is represented by 4-bit binary — used by DS1307 for time storage. |
| **VBAT Backup** | CR2032 coin cell keeps DS1307 running during main power loss, maintaining accurate time. |
| **Servo Open/Close Angle** | Two servo positions defined in code for dispensing gate: open (e.g., 90°) and closed (0°). |
| **Time Comparison Logic** | Reading current RTC time and comparing hour/minute fields against stored feeding schedule. |

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
