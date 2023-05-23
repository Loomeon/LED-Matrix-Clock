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
void pico_rtc::set_time(int8_t hours, //Set hours (0-23)
                        int8_t minutes //Set minutes (0-59)
                        ) {

    //Copy the values to the internal structure
    pico_rtc_time.hour = hours;
    pico_rtc_time.min = minutes;
    pico_rtc_time.sec = 0;

    rtc_set_datetime(&pico_rtc_time); //Modify the rtc
    sleep_us(64); //Wait for the rtc to update
}

//Set hours and minutes to the given values, resets seconds to 0
void pico_rtc::get_time(int8_t &hours, //Returns hours from rtc
                        int8_t &minutes //Returns minutes from rtc
                        ) {
    rtc_get_datetime(&pico_rtc_time); //copy current time to time structure

    //Copy values
    hours = pico_rtc_time.hour;
    minutes = pico_rtc_time.min;
}

void pico_rtc::increase_minute(){

    if(pico_rtc_time.min == 59){
        pico_rtc_time.min = 0;
    }
    else{
        pico_rtc_time.min++;
    }


}

void pico_rtc::increase_hour(){
    if(pico_rtc_time.hour == 23){
        pico_rtc_time.hour = 0;
    }
    else{
        pico_rtc_time.hour++;
    }
}