//
// Created by Paul Weber on 31.03.23.
//

#include "max7219.h"
max7219::max7219(int Data, int Clock, int Load){

    //Copy the GPIO PINS
    Data_Pin = Data;
    Clock_Pin = Clock;
    Load_Pin = Load;

    //Clear the Display
    clear();
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
        sleep_us(1);
        gpio_put(Data_Pin, Address_bin[i]); //set the Data Pin to value
        sleep_us(1);
        gpio_put(Clock_Pin, true); //Enable Read on the max7219
    }

    for (int i = 0; i < 8; ++i) {
        gpio_put(Clock_Pin, false); //Disable Read on the max7219
        sleep_us(1);
        gpio_put(Data_Pin, Data_bin[i]); //set the Data Pin to value
        sleep_us(1);
        gpio_put(Clock_Pin, true); //Enable Read on the max7219
    }

    gpio_put(Load_Pin, true); //Load the Bits into the max7219
}

void max7219::power_state(bool state){
    Address_dec = 0xC; //Set Address to "Shutdown"
    Data_dec = state; //Set Data to "Shutdown Mode"

    //convert and transfer Data and Address
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::Display_test(bool state) {
    Address_dec = 0xF; //Set Address to "Shutdown"
    Data_dec = state; //Set Data to "Shutdown Mode"

    //convert and transfer Data and Address
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::clear() {

    Data_dec=0;
    convert_Data_to_binary();

    for (int i = 1; i <= 8; ++i) {
        Address_dec = i;

        convert_Address_to_binary();
        send_Data();
    }
}

void max7219::Matrix_set(int x, int y, bool state) {
    Matrix_dot[x][y] = state; //set the x y coordinate LED to state
}

void max7219::refresh() {

    for (int x = 0; x < 7; ++x) {
        Address_dec = x+1;
        convert_Address_to_binary();

        for (int y = 0; y < 7; ++y) {
            if(Matrix_dot[x][y]){
                Data_bin[y] = true;
            }
            else{
                Data_bin[y] = false;
            }
        }

        convert_Data_to_binary();
        send_Data();
    }
}

void max7219::decode_mode(int mode) {
    Address_dec = 0x9; //Set Address to "Decode Mode"
    Data_dec = mode; //Set Decode Mode to "No decode"

    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::test_pattern() {

    //Go through all Digits / Rows
    for (int i = 1; i <= 8; ++i) {
        //Convert the Address into binary
        Address_dec = i;
        convert_Address_to_binary();

        //Go through all columns
        for (int j = 0; j < 256; ++j) {
            //Convert the Data into binary and send Address and Data
            Data_dec = j;
            convert_Data_to_binary();
            send_Data();

            sleep_ms(5);
        }
    }
}

void max7219::intensity(int brightness){
    Address_dec = 0x0A; //Set Address to "Intensity"
    Data_dec = brightness;

    //Convert and send Address and Data
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::digits(int Mode) {
    Address_dec = 0x0B; //Set Address to "Scan Limit"
    Data_dec = Mode;

    //Convert and send Address and Data
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}