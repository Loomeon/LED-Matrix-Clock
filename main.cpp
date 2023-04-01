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

int main() {
    gpio_init(0);
    gpio_init(1);
    gpio_init(2);

    gpio_set_dir(0 , GPIO_OUT);
    gpio_set_dir(1 , GPIO_OUT);
    gpio_set_dir(2 , GPIO_OUT);

    max7219 Matrix(0, 2, 1);

    //Init the Matrix Display
    Matrix.power_state(true);
    Matrix.decode_mode(0x00);
    Matrix.clear();
    Matrix.digits(0x7);
    Matrix.intensity(0x00);


    while(1){
        Matrix.test_pattern();
        Matrix.clear();
    }
}