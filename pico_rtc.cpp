//
// Created by Paul Weber on 10.04.23.
//

#include "pico_rtc.h"

//Structure to store the Time and Date
datetime_t pico_rtc_time = {
        .year  = 2022,
        .month = 9,
        .day   = 17,
        .dotw  = 6,
        .hour  = 12,
        .min   = 00,
        .sec   = 00
};

//Class constructor
pico_rtc::pico_rtc() {
    rtc_init(); //Initialise the RTC Module
}

//Store the minutes and hours in the variables
void pico_rtc::get_time(int8_t &hours, //Returns hours from rtc
              int8_t &minutes) { //Returns minutes from rtc

    //copy current time to time structure
    rtc_get_datetime(&pico_rtc_time);

    //Copy values
    hours = pico_rtc_time.hour;
    minutes = pico_rtc_time.min;
}

//Set hours and minutes to the given values, resets seconds to 0
void pico_rtc::set_time(int8_t hours, //New hour value
              int8_t minutes) { //New minute value

    //Copy the values to the internal structure
    pico_rtc_time.hour = hours;
    pico_rtc_time.min = minutes;
    pico_rtc_time.sec = 0;

    rtc_set_datetime(&pico_rtc_time); //Modify the rtc
    busy_wait_us(64); //Wait for the RTC to update
}

