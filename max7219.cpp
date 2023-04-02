//
// Created by Paul Weber on 31.03.23.
//

#include "max7219.h"
max7219::max7219(int Data, int Clock, int Load){

    //Copy the GPIO PINS
    Data_Pin = Data;
    Clock_Pin = Clock;
    Load_Pin = Load;
}

/* Signal
 * The MAX7219 is controlled with a Data, Clock and Load signal
 *
 * Transfer Address fist, then Data (MSB first)
 *
 * Load has to be low
 * Everytime clk is high, the state from Data is moved to the shift register
 * When Load is high, everything from the shift register is loaded
 */

/* Register Overview
 * 0x0 - No-Op
 * 0x1 - Digit 0
 * 0x2 - Digit 1
 * 0x3 - Digit 2
 * 0x4 - Digit 3
 * 0x5 - Digit 4
 * 0x6 - Digit 5
 * 0x7 - Digit 6
 * 0x8 - Digit 7
 * 0x9 - Decode Mode
 * 0xA - Intensity
 * 0xB - Scan Limit
 * 0xC - Shutdown
 * 0xD - Nothing
 * 0xE - Nothing
 * 0xF - Display Test
 */

//Setting Register------------------------------------------------------------------------------------------------------

void max7219::decode_mode(int mode) {
    /* Decode-Mode Register (0x9) - Values
     * 0x0 - No Decode for Digits 0-7
     * 0x1 - Code B Decode for Digits 1-7
     * 0x2 - Code B Decode for Digits 4-7
     * 0x3 - Code B Decode for Digits 0-7
     */

    Address_dec = 0x09; //Set Address to "Decode Mode"
    Data_dec = mode;

    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::intensity(int brightness){
    /* Intensity Register (0xA) - Values
     * 0x0 - Minimum Intensity
     * ... (All Values in between)
     * 0xF - Maximum Intensity
     */

    Address_dec = 0x0A; //Set Address to "Intensity"
    Data_dec = brightness;

    //Convert and send Address and Data
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::digits(int Mode) {
    /* Scan-Limit Register (0xB) - Values
     * 0x0 - Only Display Digit 0
     * 0x1 - Display Digit 0 1
     * 0x2 - Display Digit 0 1 2
     * 0x3 - Display Digit 0 1 2 3
     * 0x4 - Display Digit 0 1 2 3 4
     * 0x5 - Display Digit 0 1 2 3 4 5
     * 0x6 - Display Digit 0 1 2 3 4 5 6
     * 0x7 - Display Digit 0 1 2 3 4 5 6 7
     */

    Address_dec = 0x0B; //Set Address to "Scan Limit"
    Data_dec = Mode;

    //Convert and send Address and Data
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::power_state(bool state){
    /* Shutdown Register (0xC) - Values
     * 0x0 - Shutdown Mode
     * 0x1 - Normal Operation
     */

    Address_dec = 0x0C; //Set Address to "Shutdown"
    Data_dec = state; //Set Data to "Shutdown Mode"

    //convert and transfer Data and Address
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

void max7219::Display_test(bool state) {
    /* Display-Test Register (0xF) - Values
     * 0x0 - 0x0 - Normal Operation
     * 0x1 - Display Test Mode
     */

    Address_dec = 0x0F; //Set Address to "Shutdown"
    Data_dec = state; //Set Data to "Shutdown Mode"

    //convert and transfer Data and Address
    convert_Address_to_binary();
    convert_Data_to_binary();
    send_Data();
}

//Converting and Transferring functions --------------------------------------------------------------------------------

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

//Matrix Functions -----------------------------------------------------------------------------------------------------

void max7219::init_8x8_Matrix() {
    //Init the Matrix Display
    power_state(true); //turn on the Display
    decode_mode(0x00); //use no decode mode
    digits(0x7); //Use all 8 Lines of the Matrix
    intensity(0x00); //Use the lowest brightness

    Matrix_clear(); //clear the Matrix
    refresh(); //Send the empty Matrix Array to the Display
}

void max7219::Matrix_clear() {
    for (int x = 0; x < 8; ++x) {
        Address_dec = x+1;
        convert_Address_to_binary();

        for (int y = 0; y < 8; ++y) {
            Matrix_set(x,y,false);

            convert_Data_to_binary();
            send_Data();
        }
    }
}

void max7219::Matrix_set(int x, int y, bool state) {
    Matrix_dot[x][y] = state; //set the x y coordinate LED to state
}

void max7219::refresh() {
    for (int y = 0; y < 8; ++y) {
        Address_dec = y+1;
        convert_Address_to_binary();

        for (int x = 0; x < 8; ++x) {
            if(Matrix_dot[x][y]){
                Data_bin[x] = true;
            }
            else{
                Data_bin[x] = false;
            }
        }
        send_Data();
    }
}

//Other ----------------------------------------------------------------------------------------------------------------

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