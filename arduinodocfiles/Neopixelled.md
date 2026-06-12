# NeoPixel LED Interactive Display

## 📌 Overview

An interactive NeoPixel display responding to sensor inputs (sound, touch, or buttons) to create dynamic lighting effects.

---

## 🧰 Components Required

- Arduino Uno
- WS2812B NeoPixel Matrix or Strip
- Sound Sensor Module (KY-038) or Touch Sensor
- Push Buttons
- 5V 2A Power Supply
- 470Ω Resistor
- 1000µF Capacitor
- Jumper Wires

---

## 🔌 Circuit Connections

- NeoPixel DIN → 470Ω → Digital Pin 6
- Sound Sensor Analog → A0
- Sound Sensor Digital → Pin 2
- Button → Pin 4 (with 10kΩ pull-up)
- External 5V → NeoPixel VCC, Common GND

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **Sound Sensor KY-038** | Microphone module outputting analog amplitude and digital threshold trigger for sound-reactive projects. |
| **Reactive Animation** | LED pattern that changes in real-time based on ambient sound amplitude or frequency. |
| **Pixel Indexing** | Addressing individual LEDs in a strip using zero-based index for precise color assignment. |
| **Brightness Control** | Global brightness scaling (0-255) in software to reduce power consumption and eye strain. |
| **Color Palette** | Predefined set of colors cycled through to create themed lighting sequences. |

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
