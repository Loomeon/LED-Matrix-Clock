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
    void get_time(int8_t &hours, int8_t &minutes); //Store the minutes and hours in the variables
    void set_time(int8_t hours, int8_t minutes); //Set hours and minutes to the given values, resets seconds to 0
    void increase_minute();
    void increase_hour();
};


#endif //MATRIX_CLOCK_PICO_RTC_H
