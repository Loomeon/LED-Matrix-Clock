/**
 * Copyright (c) 2020 Raspberry Pi (Trading) Ltd.
 *
 * SPDX-License-Identifier: BSD-3-Clause
 */

#include "pico/stdlib.h"

#include "pico/util/datetime.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"
#include "max7219.h"
#include "Segment_States.h"
#include "pico_rtc.h"



int main() {
    gpio_init(0);
    gpio_init(1);
    gpio_init(2);

    gpio_set_dir(0 , GPIO_OUT);
    gpio_set_dir(1 , GPIO_OUT);
    gpio_set_dir(2 , GPIO_OUT);

    int8_t min;
    int8_t hour;

    MAX7219 Matrix(0, 2, 1);
    Segment_States Segments;
    pico_rtc rtc_time;

    rtc_time.set_time(12,0);

    Matrix.init_8x8_Matrix();

    while(1) {
        rtc_time.get_time(hour, min);
        Segments.set_time(hour, min);
        Matrix.send_Data_decimal(Segments.Matrix_dots);
    }
}