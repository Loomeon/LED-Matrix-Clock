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



    while(1){
        for (int i = 0; i < 8; ++i) {
            for (int j = 0; j < 8; ++j) {
                Matrix.Matrix_set(j, i, true);
                Matrix.refresh();
                sleep_ms(50);
            }
        }

        Matrix.Matrix_clear();
        Matrix.refresh();



    }
}