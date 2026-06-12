# BLE Controlled Car (Bluetooth Low Energy)

## 📌 Overview

Wireless RC car controlled via BLE using NUS (Nordic UART Service) profile, controllable from a smartphone app over Bluetooth 4.0+.

---

## 🧰 Components Required

- ESP32 (with built-in BLE)
- L298N Motor Driver
- DC Motors (x2)
- Robot Car Chassis
- Li-Po Battery 7.4V or 2x 18650
- Voltage Regulator (5V for ESP32)
- Jumper Wires

---

## 🔌 Circuit Connections

- L298N IN1 → ESP32 GPIO 27, IN2 → GPIO 26
- L298N IN3 → GPIO 25, IN4 → GPIO 33
- L298N ENA → GPIO 14 (PWM), ENB → GPIO 12 (PWM)
- L298N 12V → Battery+, GND → Battery-
- ESP32 5V → L298N 5V output, GND → Common

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **BLE (Bluetooth Low Energy)** | Low-power wireless protocol for short-range communication, ideal for battery-powered IoT devices. |
| **NUS (Nordic UART Service)** | BLE GATT service emulating serial UART using TX/RX characteristics for bidirectional data transfer. |
| **GATT (Generic Attribute Profile)** | BLE framework defining how data is organized and exchanged between client and server devices. |
| **BLE Server** | ESP32 acting as BLE peripheral advertising services and responding to connected client commands. |
| **Motor Direction Control** | Setting IN1/IN2 pin states HIGH/LOW to control forward, backward, left, right, and stop. |

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
