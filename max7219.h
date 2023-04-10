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
    //Class constructor
    MAX7219(int Data, int Clock, int Load);

    //Set the decode mode for each segment
    void decode_mode(int mode_seg0, //Segment 0
                     int mode_seg1, //Segment 1
                     int mode_seg2, //Segment 2
                     int mode_seg3 //Segment 3
                     );

    //Set the intensity for each segment
    void intensity(int brightness_seg0, //Segment 0
                   int brightness_seg1, //Segment 1
                   int brightness_seg2, //Segment 2
                   int brightness_seg3 //Segment 3
                   );

    //Set the amount of displayed rows for each segment
    void digits(int Mode_seg0, //Segment 0
                int Mode_seg1, //Segment 1
                int Mode_seg2, //Segment 2
                int Mode_seg3 //Segment 3
                );

    //Set the power state for each segment
    void power_state(bool state_seg0, //Segment 0
                     bool state_seg1, //Segment 1
                     bool state_seg2, //Segment 2
                     bool state_seg3 //Segment 3
                     );

    //Enable display test for each segment
    void Display_test(bool state_seg0, //Segment 0
                      bool state_seg1, //Segment 1
                      bool state_seg2, //Segment 2
                      bool state_seg3 //Segment 3
                      );

    //Clear one LED Matrix segment
    void Matrix_clear(int segment //Segment to be cleared
    );

    //Set a specific dot to on or off ---- update to work with 4 segments
    void Matrix_set(int x, //column (left 0 to right 7)
                    int y, //line (top 0 to bottom 7)
                    bool state //on or off
                    );

    //Send all the dot information that has been set with Matrix_set to the Matrix ---- update to work with 4 segments
    void refresh();

    //A simple test pattern to send all binary states to each segment
    void test_pattern();

    //Set all registers to the right values for a 8x8 LED matrix
    void init_8x8_Matrix();

    //Directly send data from a decimal or hexadecimal array to the LED matrix
    void send_Data_decimal(int import[4][8] //Array with 8 rows for all 4 segments
    );

private:
    int Data_Pin; //Pin for the Data transfer
    int Clock_Pin; //Pin for Clock signal
    int Load_Pin; //Pin for Load signal
    bool Matrix_dot[8][8]{}; //Matrix with states for all dots

    bool Address_bin[4][8]{}; //Address as a bool string (acts as a byte 0 = MSB, 7 = LSB)
    bool Data_bin[4][8]{}; //Data as a bool string (acts as a byte 0 = MSB, 7 = LSB)


    //Converting a number into it's binary number and stores it in Address_bin
    void convert_Address_to_binary(int Address, //Address as a decimal or hexadecimal number (0-8)
                                   int segment //The segment which address should be set (0-3)
                                   );

    //Converting a number into it's binary number and stores it in Data_bin
    void convert_Data_to_binary(int Data, //Data as a decimal or hexadecimal number (0-8)
                                int segment //The segment which address should be set (0-3)
                                );

    //Sending Data to the Address for all 4 segments
    void send_Data();
};

#endif //MATRIX_CLOCK_MAX7219_H
