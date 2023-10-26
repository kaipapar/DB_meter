# DB_meter
Decibel Meter and Sound Sensing Switch with ESP-12K ESP32 S2
Overview
This project is a collaboration between Karri Korsu and Rasmus Holmalahti, aiming to create a decibel meter and sound sensing switch using the ESP-12K ESP32 S2 microcontroller. 
This README file provides an overview of the project, installation instructions, and usage guidelines.

Table of Contents
Project Description
Prerequisites
Installation
Usage
Contributing
License
Project Description
The primary objective of this project is to build a device that can measure the sound level (in decibels) in the environment and trigger a switch or an action when the sound level crosses a predefined threshold.
This can be useful for various applications such as noise monitoring, automation, and more.

The project will be implemented in the C programming language for the ESP-12K ESP32 S2 microcontroller, utilizing its built-in capabilities for sound sensing and network connectivity.

Prerequisites
Before you begin, ensure that you have the following prerequisites:

An ESP-12K ESP32 S2 development board.
A development environment set up for ESP32 S2 programming (e.g., ESP-IDF).
Basic knowledge of C programming.
Required libraries and dependencies (to be listed in the installation section).
Installation
To get started with the project, follow these installation steps:

1. Clone this repository to your local machine:
git clone https://github.com/kaipapar/DB_meter

2. Set up your ESP-12K ESP32 S2 development environment, including the necessary toolchain.

3. Install any required libraries or dependencies, which will be specified in the project's documentation.

4. Build and flash the project onto your ESP-12K ESP32 S2 development board using the provided build and flash commands:
   make menuconfig     # Configure project settings
   make -j4            # Build the project
   make flash          # Flash the firmware to the ESP32 S2

Usage
Once the project is installed and running on your ESP-12K ESP32 S2 board, you can use it as follows:

1. Power on the ESP-12K ESP32 S2 board.

2. The device will start measuring the sound levels in its environment.

3. When the sound level crosses the predefined threshold, the device will trigger the associated switch or action. The specific action can be customized in the project code.

4. You can monitor the device's activity and adjust settings via the ESP32 S2's network interface, as per your configuration.

Contributing
As we are doing this project for studying purposes, outside collaborations are not needed or expected.
