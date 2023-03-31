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
    max7219(int Data, int Clock, int Load);
public:
    void power_on();
    void power_off();
    void Display_test();

private:
    int Data_Pin;
    int Clock_Pin;
    int Load_Pin;

    unsigned short int Address_dec;
    unsigned short int Data_dec;
    bool Address_bin[8];
    bool Data_bin[8];

    void send_Data();
    void convert_to_binaray();
};


#endif //MATRIX_CLOCK_MAX7219_H
