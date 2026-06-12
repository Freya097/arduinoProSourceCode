# ESP32-CAM Web Camera

## 📌 Overview

Wireless IP camera using ESP32-CAM module streaming live video over Wi-Fi accessible from any browser on the local network.

---

## 🧰 Components Required

- ESP32-CAM Module (AI Thinker)
- FTDI USB-to-Serial Adapter (for programming)
- OV2640 Camera Module (usually included)
- MicroSD Card (optional recording)
- 5V 2A Power Supply
- Jumper Wires
- Antenna (for better Wi-Fi range)

---

## 🔌 Circuit Connections

Programming connections (FTDI):
- ESP32 GND → FTDI GND
- ESP32 5V → FTDI VCC (5V)
- ESP32 U0R → FTDI TX
- ESP32 U0T → FTDI RX
- ESP32 IO0 → GND (flash mode only)

Operating: 5V supply to VCC/GND only

> ⚠️ Always double-check voltage levels before powering up. Ensure common GND between all modules.

---

## 📖 Key Definitions

| Term | Definition |
|------|------------|
| **ESP32-CAM** | ESP32 module with integrated OV2640 camera, microSD slot, and onboard LED flash for IoT vision applications. |
| **OV2640** | 2-megapixel CMOS camera sensor supporting JPEG compression, multiple resolutions up to 1600×1200. |
| **MJPEG Streaming** | Continuous JPEG frame delivery over HTTP for browser-viewable live video without special software. |
| **Access Point Mode** | ESP32 creating its own Wi-Fi network for camera access without an existing router. |
| **IO0 Flash Mode** | Pulling GPIO0 LOW during boot puts ESP32 into download mode for firmware flashing via UART. |

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
