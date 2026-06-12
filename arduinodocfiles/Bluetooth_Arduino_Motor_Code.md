# Bluetooth Controlled DC Motor

## 📌 Overview

Controls a DC motor direction and speed wirelessly using a Bluetooth module (HC-05/HC-06) paired with a smartphone app, useful for remote robotics and car projects.

---

## 🧰 Components Required

- Arduino Uno
- HC-05 or HC-06 Bluetooth Module
- L298N or L293D Motor Driver
- DC Motor (x2 optional)
- 9V Battery / 12V Adapter
- Jumper Wires
- Breadboard

---

## 🔌 Circuit Connections

- HC-05 TX → Arduino RX (Pin 0 or SoftwareSerial Pin)
- HC-05 RX → Arduino TX (via voltage divider 1kΩ + 2kΩ)
- HC-05 VCC → 5V, GND → GND
- L298N IN1 → Pin 5, IN2 → Pin 6
- L298N ENA → Pin 9 (PWM)
- Motor A → L298N OUT1 & OUT2
- L298N 12V → External Supply, GND → Common GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **HC-05 Bluetooth Module** | Serial Bluetooth module for 2.4GHz wireless UART communication, supports master/slave modes. |
| **L298N Motor Driver** | Dual H-Bridge IC that enables bidirectional control of two DC motors with PWM speed control. |
| **H-Bridge** | Electronic circuit that allows voltage to be applied across a load in either direction, enabling motor reversal. |
| **PWM (Pulse Width Modulation)** | Technique to control analog output using digital pulses; duty cycle determines average voltage and motor speed. |
| **SoftwareSerial** | Arduino library enabling serial communication on any digital pins, freeing hardware UART for debugging. |

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
