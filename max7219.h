//
// Created by Paul Weber on 31.03.23.
//
#include "hardware/rtc.h"
#include "pico/util/datetime.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"


#ifndef MATRIX_CLOCK_MAX7219_H
#define MATRIX_CLOCK_MAX7219_H


class max7219 {
public:
    max7219(int Data, int Clock, int Load); //Class constructor
    void power_state(bool state);
    void Display_test(bool state);
    void clear();
    void Matrix_set(int x, int y, bool state);
    void refresh();
    void decode_mode(int mode);
    void test_pattern();
    void intensity(int brightnes);
    void digits(int number_of_digits);

private:
    int Data_Pin;
    int Clock_Pin;
    int Load_Pin;
    bool Matrix_dot[8][8];

    unsigned short int Address_dec;
    unsigned short int Data_dec;
    bool Address_bin[8];
    bool Data_bin[8];

    void send_Data();
    void convert_Address_to_binary();
    void convert_Data_to_binary();
};


#endif //MATRIX_CLOCK_MAX7219_H
