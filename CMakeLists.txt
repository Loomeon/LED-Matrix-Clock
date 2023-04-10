cmake_minimum_required(VERSION 3.13)

# initialize the SDK based on PICO_SDK_PATH
# note: this must happen before project()
include(pico_sdk_import.cmake)

project(Matrix_Clock)
set(CMAKE_C_STANDARD 11)
set(CMAKE_CXX_STANDARD 14)

# initialize the Raspberry Pi Pico SDK
pico_sdk_init()

# rest of your project

add_executable(Matrix_Clock main.cpp max7219.cpp max7219.h Segment_States.cpp Segment_States.h pico_rtc.cpp pico_rtc.h)

# Add all the needed libraries
target_link_libraries(Matrix_Clock pico_stdlib hardware_rtc pico_multicore)

# create map/bin/hex/uf2 file in addition to ELF.
pico_add_extra_outputs(Matrix_Clock)
