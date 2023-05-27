//
// Created by Paul Weber on 24.05.23.
//

#include "DHT11.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"
#include <math.h>


DHT11::DHT11(int Data_GPIO){
    Data_PIN=Data_GPIO;
    gpio_init(Data_GPIO);
}

void DHT11::get_data(){
    int count = 0;

    gpio_set_dir(Data_PIN, GPIO_OUT);
    gpio_put(Data_PIN, false);
    busy_wait_ms(20);
    gpio_set_dir(Data_PIN, GPIO_IN);
    busy_wait_us(150);

    read_state_change(true);

    //Reading data
    for (int i = 0; i < 40; ++i) {

        read_state_change(false);

        count = read_state_change(true);

        if (count > 35){
            data[i] = true;
        }
        else{
            data[i] = false;
        }
    }
}

int DHT11::read_state_change(bool state) {
    int count = 0;
    int check = -1;


    while (gpio_get(Data_PIN) == state && count < 255) {
        ++count;
        busy_wait_us(1);
    }

    if(count < 255){
        check = count;
    }

    return check;
}

bool DHT11::convert_data() {

    //Assume that the Data is not Valid
    bool valid = false;

    //Create a temporary Array to store all 5 8bit Data Segments
    int temp[5] = {0,0,0,0,0};

    //Go through all 5 Data Segments
    for (int i = 0; i < 5; ++i) {
        //In each Segment go through all 8 bits
        for (int j = 0; j < 8; ++j) {
            //The first bit of each Segment is the MSB
            //Leftshift all Data currently stored and add the new bit with or operation
            temp[i] = (temp[i] << 1) | data[i*8 + j];
        }
    }

    //Segments
    //0 - Humidity as int
    //1 - Humidity Decimal (8 Bits behind the decimal)
    //2 - Temperature as int
    //3 - Temperature Decimal (8 Bits behind the decimal)
    //4 - Check Value (is equal to sum of Segment 0-4)

    humidity = temp[0];
    humidity_decimal = convertToFloat(temp[0], temp[1]);
    test1 = temp[1];

    temperature = temp[2];
    temperature_decimal = convertToFloat(temp[2], temp[3]);
    test2 = temp[3];

    //Check the Sum of Segment 0-4 with the Check Value
    if(temp[0]+temp[1]+temp[2]+temp[3]==temp[4]){
       valid = true;
    }

    return valid;
}

float DHT11::convertToFloat(int beforeDecimal, int afterDecimal) {

    //Shift before decimal value 8 bits to the left and add the behind decimal bits to the number
    int combinedBits = (beforeDecimal << 8) | afterDecimal;
    //after decimal is just a number between 0 and 9, divide that by 10.0f to convert it to float
    // and get the behind decimal value then add to the before decimal
    float result = beforeDecimal + afterDecimal/10.0f;
    return result;
}



