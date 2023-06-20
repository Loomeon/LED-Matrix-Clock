//
// Created by Paul Weber on 24.05.23.
//

#include "DHT11.h"
#include "pico/stdlib.h"
#include "hardware/gpio.h"

DHT11::DHT11(int Data_GPIO){
    //Copy GPIO Pin
    Data_PIN=Data_GPIO;

    //Initialize GPIO Pin
    gpio_init(Data_GPIO);

    //Set all values to zero
    humidity = 0;
    humidity_decimal = 0;
    temperature = 0;
    temperature_decimal = 0;
}

//Function to read Temperature, Humidity and Checksum from the DHT11
//Stores 40 Bits of Data in bool data[40]
void DHT11::get_data(){
    int count = 0;

    //Set output false and wait 20 ms
    gpio_set_dir(Data_PIN, GPIO_OUT);
    gpio_put(Data_PIN, false);
    busy_wait_ms(20);

    //USE GPIO as an Input
    gpio_set_dir(Data_PIN, GPIO_IN);
    busy_wait_us(150);

    //Wait until the input changes to LOW
    read_state_change(true);

    //Read all 40 Bits of Data
    for (int i = 0; i < 40; ++i) {

        //Wait until the input is HIGH
        read_state_change(false);

        //count the time in ms the input is high
        count = read_state_change(true);

        //If the input is high for more than 35 ms it is a 1, if it is less it is a 0
        if (count > 35){
            data[i] = true;
        }
        else{
            data[i] = false;
        }
    }
}

//Converts the 40 Bits of Sensor Data into usable int and float values
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

    temperature = temp[2];
    temperature_decimal = convertToFloat(temp[2], temp[3]);

    //Check the Sum of Segment 0-4 with the Check Value
    if(temp[0]+temp[1]+temp[2]+temp[3]==temp[4]){
       valid = true;
    }

    return valid;
}

//Waits until the GPIO State changes from the check state or when 255 µs passed
//Returns the time in µs it took to change the State
int DHT11::read_state_change(bool state //Check state
) {
    int count = 0;
    int check = -1;

    //Stay in while loop until the input value changes, wait 1 ms in every loop and increment count, stop if it needs longer than 255 ms
    while (gpio_get(Data_PIN) == state && count < 255) {
        ++count;
        busy_wait_us(1);
    }

    //The value is below 255 return it, otherwise return -1
    if(count < 255){
        check = count;
    }

    return check;
}

//Converts the two int parts of the decimal number intro a float value
//Returns the combined float value
float DHT11::convertToFloat(int beforeDecimal, //Normal int value
                     int afterDecimal) { //Value behind the decimal, is going to be divided by 10 and added to Normal

    //After decimal is just a number between 0 and 9, divide that by 10.0f to convert it to float
    // and get the behind decimal value then add to the before decimal
    float result = beforeDecimal + afterDecimal/10.0f;
    return result;
}