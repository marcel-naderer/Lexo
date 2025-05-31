# Lexo Arduino Library

**Lexo** is an open-source Arduino library developed for the **Lexo Exoskeleton**, providing a simple API to control and monitor a range of sensors and actuators such as:

- IMU (via I²C)
- EMG sensor
- Force sensors
- Magnetic angle encoder (AS5600 via I²C)
- INA219 current sensors (for motor and battery)
- Push buttons
- Vibration motors
- RGB LEDs
- Motor control (PWM + direction)
- Buzzer

---

## Features

- Abstracted pin management with default configuration and override support
- Built-in support for I²C-based peripherals (AS5600, INA219)
- Lightweight and ESP32-compatible
- Includes example sketches for easy testing
