# Heart Rate Monitor

## 📌 Overview

Measures heart rate (BPM) using a pulse sensor placed on fingertip or earlobe, displaying live readings on an LCD or Serial Monitor.

---

## 🧰 Components Required

- Arduino Uno
- Pulse Sensor (PulseSensor Amped)
- 16x2 LCD or OLED Display
- LED (indicator)
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- Pulse Sensor Signal (S) → A0
- Pulse Sensor VCC → 3.3V or 5V
- Pulse Sensor GND → GND
- LED → Digital Pin 13 (built-in or external with 220Ω)
- LCD SDA → A4, SCL → A5

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Pulse Sensor** | Photoplethysmography (PPG) sensor using an LED and photodetector to measure blood volume changes. |
| **BPM (Beats Per Minute)** | Heart rate metric calculated by counting peaks in the pulse waveform over 60 seconds. |
| **PPG (Photoplethysmography)** | Non-invasive optical technique detecting blood volume pulses in peripheral circulation. |
| **Signal Peak Detection** | Algorithm identifying maximum amplitude points in the pulse waveform to count heartbeats. |
| **Interrupt-Driven Sampling** | Using Timer ISR to sample the analog pulse sensor at fixed 2ms intervals for accuracy. |

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
