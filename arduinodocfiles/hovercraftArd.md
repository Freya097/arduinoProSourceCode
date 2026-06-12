# Arduino Hovercraft

## 📌 Overview

A miniature hovercraft using two fans — one for lift and one for thrust — controlled by a remote via Bluetooth or RF for directional movement.

---

## 🧰 Components Required

- Arduino Uno or Nano
- DC Fans / Brushless Motors (x2)
- L298N or MOSFET Driver
- HC-05 Bluetooth Module
- Servo Motor (rudder/direction)
- Li-Po Battery 3.7V or 7.4V
- Hovercraft Frame (DIY/foam)
- Jumper Wires

---

## 🔌 Circuit Connections

- Lift Fan MOSFET Gate → Pin 9 (PWM)
- Thrust Fan MOSFET Gate → Pin 10 (PWM)
- Servo Signal → Pin 6
- HC-05 TX → Pin 3, RX → Pin 4 (SoftwareSerial)
- Battery → All power rails with common GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Hovercraft Principle** | Vehicle riding on cushion of pressurized air created by lift fan blowing down through skirt, reducing friction. |
| **Lift Fan** | Downward-facing fan inflating the air skirt below the craft to create the hovering cushion. |
| **Thrust Fan** | Horizontally-mounted fan providing forward propulsion; directional control via rudder or differential thrust. |
| **MOSFET (N-Channel)** | High-efficiency transistor switching large motor currents using low microcontroller GPIO voltage as gate signal. |
| **PWM Speed Control** | Varying fan speed via PWM duty cycle to control lift height and thrust force. |

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
