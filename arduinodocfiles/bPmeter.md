# Blood Pressure Meter

## 📌 Overview

Simulates or demonstrates a blood pressure measurement display system using pulse sensor data to calculate systolic and diastolic estimates.

---

## 🧰 Components Required

- Arduino Uno
- Pulse Sensor Amped
- OLED Display 0.96" (SSD1306)
- Buzzer
- Push Button
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- Pulse Sensor Signal → A0
- Pulse Sensor VCC → 3.3V or 5V, GND → GND
- OLED SDA → A4, SCL → A5
- Button → Pin 2 (10kΩ pull-up)
- Buzzer → Pin 8

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Systolic Pressure** | Maximum arterial pressure during heart contraction (normal: ~120 mmHg). |
| **Diastolic Pressure** | Minimum arterial pressure when heart relaxes between beats (normal: ~80 mmHg). |
| **PPG Waveform** | Photoplethysmography signal whose peaks and troughs correlate with systolic and diastolic pressure phases. |
| **Pulse Transit Time (PTT)** | Time for pulse wave to travel between two body points; inversely related to blood pressure. |
| **Oscillometric Method** | Standard BP measurement technique using cuff pressure oscillations; Arduino simulation approximates this. |

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
