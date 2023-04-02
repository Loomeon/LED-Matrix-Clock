//
// Created by Paul Weber on 31.03.23.
//


#include "hardware/gpio.h"
#include "pico/stdlib.h"

//This is a Raspberry Pi Pico driver for the MAX7219 chip
//My focus was to control a LED Matrix, but it is possible to extend the code to work as a driver for 7 Segment Displays

#ifndef MATRIX_CLOCK_MAX7219_H
#define MATRIX_CLOCK_MAX7219_H

class max7219 {
public:
    max7219(int Data, int Clock, int Load); //Class constructor
    void power_state(bool state); //Set the Display power state to true = on and false = off
    void Display_test(bool state); //Turn on all dots true = test mode on and false = test mode off
    void Matrix_clear(); //Set all Dots to off
    void Matrix_set(int x, int y, bool state); //turn a specific dot with x y coordinates true = on or false = off
    void refresh(); //send the current array of dots to the LED Matrix
    void decode_mode(int mode); //set the Decode Mode
    void test_pattern(); //go through all possible states of every digit
    void intensity(int brightness); //set brightness 0-15
    void digits(int number_of_digits); //Number of active digits 0-6
    void init_8x8_Matrix(); //Configures everything for a 8x8 LED Matrix
    void import_Matrix(bool *import);

private:
    int Data_Pin; //Pin for the Data transfer
    int Clock_Pin; //Pin for Clock signal
    int Load_Pin; //Pin for Load signal
    bool Matrix_dot[8][8]; //Matrix with states for all dots

    unsigned short int Address_dec;  //Address as decimal or hexadecimal number
    unsigned short int Data_dec; //Data as decimal or hexadecimal number
    bool Address_bin[8]; //Address as a bool string (acts as a byte 0 = MSB, 7 = LSB)
    bool Data_bin[8]; //Data as a bool string (acts as a byte 0 = MSB, 7 = LSB)

    void send_Data(); //Sends Address and Data
    void convert_Address_to_binary(); //Converts the hex or dec Address intro binary
    void convert_Data_to_binary(); //Converts the hex or dec Data into binary
};

#endif //MATRIX_CLOCK_MAX7219_H
