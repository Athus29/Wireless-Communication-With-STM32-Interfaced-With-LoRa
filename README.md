# Wireless-Communication-With-STM32-Interfaced-With-LoRa
![STM32](https://img.shields.io/badge/STM32-Microcontroller-blue)
![LoRa](https://img.shields.io/badge/LoRa-Long--Range-green)
![Embedded C](https://img.shields.io/badge/Language-Embedded--C-yellow)

## Overview

This project implements a **wireless communication system** using the STM32 microcontroller interfaced with a **LoRa (Long Range)** module. The system is designed to transmit text and sensor data wirelessly over long distances using the LoRa module, operating in the sub-gigahertz frequency range. The project demonstrates the capabilities of LoRa for long-range, low-power IoT applications.

## Objective

The main objective of this project is to establish a robust and efficient wireless communication system using STM32 and LoRa modules. The system aims to:
- Transmit text and pressure sensor data wirelessly over long distances.
- Demonstrate the use of LoRa in IoT applications for low-power and long-range data transmission.

## Components Used

The following hardware components are used in the project:

- **STM32F103C8T6 Bluepill Board** (2 units)
- **LoRa RA-02 SX1278** (2 units)
- **BMP280 Barometric Pressure Sensor** (1 unit)
- **USB to TTL Serial Adapter** (2 units)
- **Breadboard** and **Connecting Wires**
- **Wireless Antenna** (2 units)

## Circuit Design and Working

The circuit consists of two main parts: 
1. **Text Data Transmission**: A simple text message such as "Hello World" is transmitted from one STM32 device to another using LoRa.
2. **Sensor Data Transmission**: The BMP280 pressure sensor records atmospheric pressure, which is transmitted wirelessly through the LoRa module to a receiver STM32 device.

### Working:
- The STM32 microcontroller communicates with the **LoRa module** over **SPI**.
- For **sensor data transmission**, the pressure data is collected from the BMP280, converted to Hecto-Pascals (hPa), and transmitted via LoRa.
- The system operates in the frequency range of **420 MHz to 450 MHz**.
