//
// Created by Paul Weber on 10.04.23.
//

#include "hardware/rtc.h"
#include "pico/stdlib.h"

#ifndef MATRIX_CLOCK_PICO_RTC_H
#define MATRIX_CLOCK_PICO_RTC_H

class pico_rtc {
public:
    pico_rtc();

    //Store the minutes and hours in the variables
    void get_time(int8_t &hours, //Returns hours from rtc
                  int8_t &minutes); //Returns minutes from rtc

    //Set hours and minutes to the given values, resets seconds to 0
    void set_time(int8_t hours, //New hour value
                  int8_t minutes); //New minute value
};


#endif //MATRIX_CLOCK_PICO_RTC_H
