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
    max7219(int Data, int Clock, int Load);
    void power_on();
    void power_off();
    void Display_test();
    void Matrix_clear();
    void Matrix_set(int x, int y);
    void Matrix_unset(int x, int y);
    void Matrix_refresh();
    void Matrix_decode_mode();

private:
    int Data_Pin;
    int Clock_Pin;
    int Load_Pin;
    bool Matrix_State[8][8];

    unsigned short int Address_dec;
    unsigned short int Data_dec;
    bool Address_bin[8];
    bool Data_bin[8];

    void send_Data();
    void convert_Address_to_binary();
    void convert_Data_to_binary();
};


#endif //MATRIX_CLOCK_MAX7219_H
