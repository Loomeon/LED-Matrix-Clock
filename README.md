# LED Matrix Clock with Raspberry Pi Pico

## How to use the SDK

A Guide and all necessary links can be found [here](https://www.raspberrypi.com/documentation/microcontrollers/c_sdk.html).

To be able to compile this project you have to:

1. Install the [Packages for your System](https://github.com/raspberrypi/picotool).
2. Add the [PI Pico SDK](https://github.com/raspberrypi/pico-sdk) to your cmake environment.
3. Copy `external/pico_sdk_import.cmake` from the sdk to this project folder.

# Project Overview

This is a Project to use a Raspberry Pi Pico with a LED Matrix to display the time, temperature and humidity.

Currently, the Pi Pico can control the LED Matrix and keep track of the Time, but nothing else.