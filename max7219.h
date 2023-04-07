//
// Created by Paul Weber on 31.03.23.
//


#include "hardware/gpio.h"
#include "pico/stdlib.h"

//This is a Raspberry Pi Pico driver for the MAX7219 chip
//My focus was to control a LED Matrix, but it is possible to extend the code to work as a driver for 7 Segment Displays

#ifndef MATRIX_CLOCK_MAX7219_H
#define MATRIX_CLOCK_MAX7219_H

class MAX7219 {
public:
    MAX7219(int Data, int Clock, int Load); //Class constructor
    void power_state(bool state_seg0, bool state_seg1, bool state_seg2, bool state_seg3); //Set the Display power state to true = on and false = off
    void Display_test(bool state_seg0, bool state_seg1, bool state_seg2, bool state_seg3); //Turn on all dots true = test mode on and false = test mode off
    void Matrix_clear(int segment); //Set all Dots to off
    void Matrix_set(int x, int y, bool state); //turn a specific dot with x y coordinates true = on or false = off
    void refresh(); //send the current array of dots to the LED Matrix
    void decode_mode(int mode_seg0, int mode_seg1, int mode_seg2, int mode_seg3); //set the Decode Mode
    void test_pattern(); //go through all possible states of every digit
    void intensity(int brightness_seg0, int brightness_seg1, int brightness_seg2, int brightness_seg3); //set brightness 0-15
    void digits(int Mode_seg0, int Mode_seg1, int Mode_seg2, int Mode_seg3); //Number of active digits 0-6
    void init_8x8_Matrix(); //Configures everything for a 8x8 LED Matrix
    void send_Data_decimal(int import[4][8]);

private:
    int Data_Pin; //Pin for the Data transfer
    int Clock_Pin; //Pin for Clock signal
    int Load_Pin; //Pin for Load signal
    bool Matrix_dot[8][8]{}; //Matrix with states for all dots

    bool Address_bin[4][8]{}; //Address as a bool string (acts as a byte 0 = MSB, 7 = LSB)
    bool Data_bin[4][8]{}; //Data as a bool string (acts as a byte 0 = MSB, 7 = LSB)

    void send_Data(); //Sends Address and Data
    void convert_Address_to_binary(int Address, int segment); //Converts the hex or dec Address intro binary
    void convert_Data_to_binary(int Data, int segment); //Converts the hex or dec Data into binary
};

#endif //MATRIX_CLOCK_MAX7219_H
