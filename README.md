# STM32 Ultrasonic Distance Sensor with I2C LCD Display

This project demonstrates how to measure distances using an ultrasonic sensor (HC-SR04 or compatible) with an STM32 microcontroller. The distance readings are displayed on an I2C LCD module.

## Features

- Utilizes STM32 HAL library for efficient hardware control.
- Measures distance using the pulse-echo technique with an ultrasonic sensor.
- Displays distance readings on a user-friendly I2C LCD screen.
- Includes basic error handling for out-of-range measurements.

## Hardware Requirements

- STM32 microcontroller (e.g., STM32F4)
- HC-SR04 ultrasonic distance sensor (or compatible)
- I2C LCD display module (e.g., 16x2 LCD)
- Jumper wires

## Software Requirements

- STM32CubeIDE or your preferred STM32 development environment
- STM32 HAL library
- I2C LCD library for STM32 (included or install separately)

## Wiring

1. **Ultrasonic Sensor:**
   - `VCC` -> STM32's 5V pin
   - `TRIG` -> `GPIOC PIN 12` (or your chosen pin)
   - `ECHO` -> `GPIOC PIN 13` (or your chosen pin)
   - `GND` -> STM32's GND pin
2. **I2C LCD:**
   - `VCC` -> STM32's 5V pin
   - `SDA` -> STM32's SDA pin (often `PB7`)
   - `SCL` -> STM32's SCL pin (often `PB6`)
   - `GND` -> STM32's GND pin

## Configuration

1. **STM32CubeMX:**
   - Initialize the project using STM32CubeMX (or your IDE's equivalent).
   - Enable the GPIO pins for the ultrasonic sensor and the I2C peripheral.
   - Configure the clock and other settings as needed.
2. **Code:**
   - Copy the provided C++ code into your project.
   - Update the pin definitions (if you used different pins) in the code.
   - Include your I2C LCD library and ensure it's configured correctly.

## Usage

1. Build and upload the code to your STM32 microcontroller.
2. Power on your STM32 board.
3. The LCD should display the measured distance in centimeters.
4. If the sensor cannot detect an object within its range, the LCD will show "Out of range."


## Customization

- **Pin Configuration:**  Adjust the `TRIG_PIN`, `TRIG_PORT`, `ECHO_PIN`, and `ECHO_PORT` to match your actual pin assignments.
- **LCD Library:**  Use a different I2C LCD library if you prefer, making sure to update the code accordingly.
- **Display Options:** Customize how the distance is displayed on the LCD (e.g., units, formatting).
- **Additional Features:**  Consider adding features like:
    - Smoothing or filtering distance readings.
    - Logging distance data to an SD card or sending it over a network.

Let me know if you have any other questions!
