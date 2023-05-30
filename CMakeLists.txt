cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
include(pico_sdk_import.cmake)

project(Matrix_Clock)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

if (TARGET tinyusb_device)
    add_executable(Matrix_Clock main.cpp max7219.cpp max7219.h Segment_States.cpp Segment_States.h pico_rtc.cpp pico_rtc.h DHT11.cpp DHT11.h)

    # Add all the needed libraries
    target_link_libraries(Matrix_Clock pico_stdlib hardware_rtc pico_multicore)

    # Output via USB
    pico_enable_stdio_usb(Matrix_Clock 1)
    pico_enable_stdio_uart(Matrix_Clock 0)

    # create map/bin/hex/uf2 file in addition to ELF.
    pico_add_extra_outputs(Matrix_Clock)

elseif(PICO_ON_DEVICE)
    message(WARNING "not building hello_usb because TinyUSB submodule is not initialized in the SDK")
endif()