//
// Created by Paul Weber on 31.03.23.
//

#include "max7219.h"
max7219::max7219(int Data, int Clock, int Load){

}


void max7219::convert_to_binaray(){
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
        gpio_put(Data_Pin, Address_bin[i]); //set the Data Pin to value
        gpio_put(Clock_Pin, true); //Enable Read on the max7219

        //Wait here?
    }

    for (int i = 0; i < 8; ++i) {
        gpio_put(Clock_Pin, false); //Disable Read on the max7219
        gpio_put(Data_Pin, Data_bin[i]); //set the Data Pin to value
        gpio_put(Clock_Pin, true); //Enable Read on the max7219

        //Wait here?
    }


    gpio_put(Load_Pin, true); //Load the Bits into the max7219
}

void max7219::power_on() {

    Address_dec = 12; //Set Address to "Shutdown"
    Data_dec = 1; //Set Data to "Normal Operation"

    convert_to_binaray();
    send_Data();
}