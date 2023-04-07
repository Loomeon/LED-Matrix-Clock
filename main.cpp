/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"
#include "hardware/rtc.h"
#include "pico/util/datetime.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"
#include "max7219.h"
#include "Segment_States.h"

//Structure to store the Time and Date
datetime_t time = {
        .year  = 2022,
        .month = 9,
        .day   = 17,
        .dotw  = 6,
        .hour  = 12,
        .min   = 00,
        .sec   = 00
};


int main() {
    gpio_init(0);
    gpio_init(1);
    gpio_init(2);

    gpio_set_dir(0 , GPIO_OUT);
    gpio_set_dir(1 , GPIO_OUT);
    gpio_set_dir(2 , GPIO_OUT);

    MAX7219 Matrix(0, 2, 1);
    Segment_States Segments;

    Matrix.init_8x8_Matrix();
    Segments.set_time(time.hour, time.min);
    Matrix.send_Data_decimal(Segments.Matrix_dots);

    while(1){

    }
}