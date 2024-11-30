# Multi-Layer-Farm-Guard

This project is designed to protect farms using a multi-layer sensor-based system. It incorporates ultrasonic sensors for distance measurement, infrared (IR) sensors for motion detection, and a camera-based system to send images to a Telegram bot for monitoring. The system is designed to detect obstacles or motion and trigger alerts via a buzzer, while sending images through the ESP32-CAM to keep you informed in real-time.

## Live Model

![Demo Model](images/Demo%20Model.jpg)

## Features

- **Ultrasonic Sensors**: Measure distances to detect obstacles.
- **IR/PIR Sensors**: Detect motion in two different locations.
- **Buzzer**: Alerts when motion or obstacles are detected.
- **ESP32-CAM**: Captures and sends real-time images to Telegram when motion is detected.
- **BME280 Sensor**: Monitors temperature and humidity to provide environmental readings.
- **Telegram Integration**: Sends alerts and images directly to Telegram.

## Components

- ESP32-CAM
- Ultrasonic Sensors (HC-SR04)
- IR/PIR Sensors (for motion detection)
- BME280 Sensor (for environmental readings)
- Buzzer
- Jumper wires
- Power supply

## Circuit Diagram

Please refer to the schematic for wiring the sensors:

- **Ultrasonic Sensor 1**: TRIG_PIN_1 (6), ECHO_PIN_1 (2)
- **Ultrasonic Sensor 2**: TRIG_PIN_2 (7), ECHO_PIN_2 (3)
- **IR Sensor 1**: IR_PIN_1 (4)
- **IR Sensor 2**: IR_PIN_2 (5)
- **Buzzer**: BUZZER_PIN (13)
- **ESP32-CAM**: Camera wiring as per ESP32-CAM specs
- **BME280 Sensor**: I2C interface (SDA: 14, SCL: 15)

## Software Libraries

- **WiFi**: For connecting to the network.
- **WiFiClientSecure**: Secure connection for Telegram communication.
- **ESP32 Camera**: Library for controlling the ESP32 camera module.
- **UniversalTelegramBot**: Sends images and messages to Telegram.
- **BME280**: For reading temperature and humidity.

## Code Explanation

### Sensor Setup

The following sensors are used for detection:
- **Ultrasonic Sensors**: Measure distance and alert if an object is within 20 cm.
- **IR Sensors**: Detect motion, replacing the PIR sensors.
- **Buzzer**: Activated when any of the sensors are triggered.

The code uses the following pin definitions:
```cpp
#define TRIG_PIN_1 6 
#define ECHO_PIN_1 2
#define TRIG_PIN_2 7
#define ECHO_PIN_2 3
#define IR_PIN_1 4
#define IR_PIN_2 5
#define BUZZER_PIN 13
