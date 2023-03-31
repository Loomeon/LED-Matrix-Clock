//
// Created by Paul Weber on 31.03.23.
//

#include "max7219.h"
max7219::max7219(int Data, int Clock, int Load){

    //Copy the GPIO PINS
    Data_Pin = Data;
    Clock_Pin = Clock;
    Load_Pin = Load;

    //Init the Matrix Display
    power_on();
    Matrix_decode_mode();
}


void max7219::convert_Address_to_binary(){
    int bit_selector = 1; // 0b00000001

    //Go through all 8 Bits
    for (int i = 7; i >= 0; --i) {
        //Compare with bit_selector, to check if bit exists at that postion
        if(bit_selector & Address_dec){
            Address_bin[i] = true; //set to true if the bit exists
        }
        else{
            Address_bin[i] = false; //set to false if the bit does not exist
        }
        bit_selector = bit_selector << 1; //Move bit_selector one bit to the left
    }
}

void max7219::convert_Data_to_binary(){
    int bit_selector = 1; // 0b00000001

    //Go through all 8 Bits
    for (int i = 7; i >= 0; --i) {
        //Compare with bit_selector, to check if bit exists at that postion
        if(bit_selector & Data_dec){
            Data_bin[i] = true; //set to true if the bit exists
        }
        else{
            Data_bin[i] = false; //set to false if the bit does not exist
        }

        bit_selector = bit_selector << 1; //Move bit_selector one bit to the left
    }
}

void max7219::send_Data() {

    gpio_put(Load_Pin, false); //set Load Pin to low

    for (int i = 0; i < 8; ++i) {
        gpio_put(Clock_Pin, false); //Disable Read on the max7219
        sleep_ms(1);
        gpio_put(Data_Pin, Address_bin[i]); //set the Data Pin to value
        gpio_put(Clock_Pin, true); //Enable Read on the max7219

        sleep_ms(1);
    }

    for (int i = 0; i < 8; ++i) {
        gpio_put(Clock_Pin, false); //Disable Read on the max7219
        sleep_ms(1);
        gpio_put(Data_Pin, Data_bin[i]); //set the Data Pin to value
        gpio_put(Clock_Pin, true); //Enable Read on the max7219

        sleep_ms(1);
    }


    gpio_put(Load_Pin, true); //Load the Bits into the max7219
}

void max7219::power_on() {

    Address_dec = 0xC; //Set Address to "Shutdown"
    Data_dec = 1; //Set Data to "Normal Operation"

    //convert and transfer Data and Address
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::power_off() {

    Address_dec = 0xC; //Set Address to "Shutdown"
    Data_dec = 0; //Set Data to "Shutdown Mode"

    //convert and transfer Data and Address
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::Display_test() {
    Address_dec = 0xF; //Set Address to "Shutdown"
    Data_dec = 1; //Set Data to "Shutdown Mode"

    //convert and transfer Data and Address
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::Matrix_clear() {
    //wow such empty
}

void max7219::Matrix_set(int x, int y) {
    Matrix_State[x][y] = true; //set the x y coordinate LED to on
}

void max7219::Matrix_unset(int x, int y) {
    Matrix_State[x][y] = false; //set the x y coordinate LED to off
}

void max7219::Matrix_refresh() {

    //Go through all rows
    for (int x = 0; x < 7; ++x) {
        //Go through all columns
        for (int y = 0; y < 7; ++y) {
            Data_bin[y] = Matrix_State[x][y]; //copy Binary Data from the State Array to the Send Data Array
        }


        Address_dec = x+1; //Row Start Adress is 0x1 that is why there is an +1 offset
        //Convert Address and send
        convert_Address_to_binary();
        send_Data();
    }
}

void max7219::Matrix_decode_mode() {
    Address_dec = 0x9; //Set Address to "Decode Mode"
    Data_dec = 0; //Set Decode Mode to "No decode"

    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}