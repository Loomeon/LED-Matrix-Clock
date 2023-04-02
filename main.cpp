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
    Matrix_Numbers Numbers;

    Matrix.init_8x8_Matrix();


    bool *transfer = new bool[64];









    while(1){
        for (int i = 0; i < 10; ++i) {
            Numbers.update_qudrant(i, 0);
            Numbers.update_qudrant(i, 1);
            Numbers.update_qudrant(i, 2);
            Numbers.update_qudrant(i, 3);

            Numbers.export_array(transfer);
            Matrix.import_Matrix(transfer);

            Matrix.refresh();

            sleep_ms(1000);
        }





    }
}