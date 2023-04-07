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
#include "Matrix_Numbers.h"

int main() {
    gpio_init(0);
    gpio_init(1);
    gpio_init(2);

    gpio_set_dir(0 , GPIO_OUT);
    gpio_set_dir(1 , GPIO_OUT);
    gpio_set_dir(2 , GPIO_OUT);

    max7219 Matrix(0, 2, 1);
    Matrix_Numbers Matrix_Numbers;

    Matrix.init_8x8_Matrix();
    Matrix_Numbers.set_time(1, 2, 3, 4);
    Matrix.send_Data_decimal(Matrix_Numbers.Matrix_dots);


    while(1){

    }
}