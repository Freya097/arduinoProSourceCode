# Home Automation System

## 📌 Overview

Controls household appliances such as lights, fans, and AC units via relay modules using voice commands, mobile app, or physical switches.

---

## 🧰 Components Required

- Arduino Uno / ESP8266 / ESP32
- 4-Channel Relay Module
- HC-05 Bluetooth Module or ESP8266 Wi-Fi
- Push Buttons (x4)
- LED indicators
- AC Bulbs / Appliances (load)
- 5V Power Supply
- Jumper Wires

---

## 🔌 Circuit Connections

- Relay IN1 → Pin 5, IN2 → Pin 6, IN3 → Pin 7, IN4 → Pin 8
- Relay VCC → 5V, GND → GND
- Relay COM → Neutral wire, NO → Appliance
- HC-05 TX → Pin 10, RX → Pin 11 (SoftwareSerial)
- Buttons → Pins 2,3,4,A0 with pull-up resistors

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Relay Module** | Electrically isolated switch enabling microcontrollers to safely control 230V AC appliances. |
| **Normally Open (NO)** | Relay contact that remains open (circuit off) until energized; the load is off by default. |
| **Normally Closed (NC)** | Relay contact that remains closed (circuit on) until energized; the load is on by default. |
| **Opto-isolation** | Using an optocoupler to electrically separate the Arduino circuit from the high-voltage AC side. |
| **BLYNK / MQTT** | IoT platforms providing cloud connectivity and mobile dashboards for remote appliance control. |

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
