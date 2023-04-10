//
// Created by Paul Weber on 31.03.23.
//

#include "max7219.h"
MAX7219::MAX7219(int Data, int Clock, int Load){

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

void MAX7219::decode_mode(int mode_seg0, int mode_seg1, int mode_seg2, int mode_seg3) {
    /* Decode-Mode Register (0x9) - Values
     * 0x0 - No Decode for Digits 0-7
     * 0x1 - Code B Decode for Digits 1-7
     * 0x2 - Code B Decode for Digits 4-7
     * 0x3 - Code B Decode for Digits 0-7
     */

    //Set Address to "Decode Mode"
    convert_Address_to_binary(0x09, 0);
    convert_Address_to_binary(0x09, 1);
    convert_Address_to_binary(0x09, 2);
    convert_Address_to_binary(0x09, 3);

    convert_Data_to_binary(mode_seg0, 0);
    convert_Data_to_binary(mode_seg1, 1);
    convert_Data_to_binary(mode_seg2, 2);
    convert_Data_to_binary(mode_seg3, 3);

    send_Data();
}

void MAX7219::intensity(int brightness_seg0, int brightness_seg1, int brightness_seg2, int brightness_seg3){
    /* Intensity Register (0xA) - Values
     * 0x0 - Minimum Intensity
     * ... (All Values in between)
     * 0xF - Maximum Intensity
     */

    //Set Address to "Intensity"
    convert_Address_to_binary(0x0A, 0);
    convert_Address_to_binary(0x0A, 1);
    convert_Address_to_binary(0x0A, 2);
    convert_Address_to_binary(0x0A, 3);

    //Convert and send Address and Data
    convert_Data_to_binary(brightness_seg0, 0);
    convert_Data_to_binary(brightness_seg1, 1);
    convert_Data_to_binary(brightness_seg2, 2);
    convert_Data_to_binary(brightness_seg3, 3);

    send_Data();
}

void MAX7219::digits(int Mode_seg0, int Mode_seg1, int Mode_seg2, int Mode_seg3) {
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




    //Set Address to "Scan Limit"
    convert_Address_to_binary(0x0B, 0);
    convert_Address_to_binary(0x0B, 1);
    convert_Address_to_binary(0x0B, 2);
    convert_Address_to_binary(0x0B, 3);

    convert_Data_to_binary(Mode_seg0, 0);
    convert_Data_to_binary(Mode_seg1, 1);
    convert_Data_to_binary(Mode_seg2, 2);
    convert_Data_to_binary(Mode_seg3, 3);

    send_Data();
}

void MAX7219::power_state(bool state_seg0, bool state_seg1, bool state_seg2, bool state_seg3){
    /* Shutdown Register (0xC) - Values
     * 0x0 - Shutdown Mode
     * 0x1 - Normal Operation
     */

    //Set Address to "Shutdown"
    convert_Address_to_binary(0x0C, 0);
    convert_Address_to_binary(0x0C, 1);
    convert_Address_to_binary(0x0C, 2);
    convert_Address_to_binary(0x0C, 3);

    convert_Data_to_binary(state_seg0, 0);
    convert_Data_to_binary(state_seg0, 1);
    convert_Data_to_binary(state_seg0, 2);
    convert_Data_to_binary(state_seg0, 3);

    send_Data();
}

void MAX7219::Display_test(bool state_seg0, bool state_seg1, bool state_seg2, bool state_seg3) {
    /* Display-Test Register (0xF) - Values
     * 0x0 - 0x0 - Normal Operation
     * 0x1 - Display Test Mode
     */

    //convert and transfer Data and Address
    convert_Address_to_binary(0x0F, 0);
    convert_Address_to_binary(0x0F, 1);
    convert_Address_to_binary(0x0F, 2);
    convert_Address_to_binary(0x0F, 3);

    convert_Data_to_binary(state_seg0, 0);
    convert_Data_to_binary(state_seg1, 1);
    convert_Data_to_binary(state_seg2, 2);
    convert_Data_to_binary(state_seg3, 3);

    send_Data();
}

//Converting and Transferring functions --------------------------------------------------------------------------------

void MAX7219::convert_Address_to_binary(int Address, int segment){
    int bit_selector = 1; // 0b00000001

    //Go through all 8 Bits
    for (int i = 7; i >= 0; --i) {
        //Compare with bit_selector, to check if bit exists at that postion
        if(bit_selector & Address){
            Address_bin[segment][i] = true; //set to true if the bit exists
        }
        else{
            Address_bin[segment][i] = false; //set to false if the bit does not exist
        }
        bit_selector = bit_selector << 1; //Move bit_selector one bit to the left
    }
}

void MAX7219::convert_Data_to_binary(int Data, int segment){
    int bit_selector = 1; // 0b00000001

    //Go through all 8 Bits
    for (int i = 7; i >= 0; --i) {
        //Compare with bit_selector, to check if bit exists at that postion
        if(bit_selector & Data){
            Data_bin[segment][i] = true; //set to true if the bit exists
        }
        else{
            Data_bin[segment][i] = false; //set to false if the bit does not exist
        }

        bit_selector = bit_selector << 1; //Move bit_selector one bit to the left
    }
}

void MAX7219::send_Data() {
    gpio_put(Load_Pin, false); //set Load Pin to low

    for (int j = 3; j >= 0; --j) {
        for (int i = 0; i < 8; ++i) {
            gpio_put(Clock_Pin, false); //Disable Read on the max7219
            gpio_put(Data_Pin, Address_bin[j][i]); //set the Data Pin to value
            gpio_put(Clock_Pin, true); //Enable Read on the max7219

            sleep_us(1);
        }

        for (int i = 0; i < 8; ++i) {
            gpio_put(Clock_Pin, false); //Disable Read on the max7219
            gpio_put(Data_Pin, Data_bin[j][i]); //set the Data Pin to value
            gpio_put(Clock_Pin, true); //Enable Read on the max7219

            sleep_us(1);
        }
    }

    gpio_put(Load_Pin, true); //Load the Bits into the max7219
}

//Matrix Functions -----------------------------------------------------------------------------------------------------

void MAX7219::init_8x8_Matrix() {

    //Init the Matrix Display
    power_state(true, true, true, true); //turn on the Display
    decode_mode(0x00, 0x00,0x00,0x00); //use no decode mode
    intensity(0x0F, 0x0F, 0x0F, 0x0F); //Use the lowest brightness
    digits(0x7, 0x7, 0x7, 0x7); //Use all 8 Lines of the Matrix

    for (int i = 0; i < 4; ++i) {
        Matrix_clear(i); //clear the Matrix
    }

    refresh(); //Send the empty Matrix Array to the Display
}

void MAX7219::Matrix_clear(int segment) {
    for (int x = 0; x < 8; ++x) {
        convert_Address_to_binary(x+1, segment);

        for (int y = 0; y < 8; ++y) {
            convert_Data_to_binary(0, segment);
            send_Data();
        }
    }
}

void MAX7219::Matrix_set(int x, int y, bool state) {
    Matrix_dot[x][y] = state; //set the x y coordinate LED to state
}

void MAX7219::refresh() {

    for (int i = 0; i < 4; ++i) {
        for (int y = 0; y < 8; ++y) {
            convert_Address_to_binary(y+1, i);

            for (int x = 0; x < 8; ++x) {
                if(Matrix_dot[x][y]){
                    Data_bin[i][x] = true;
                }
                else{
                    Data_bin[i][x] = false;
                }
            }
            send_Data();
        }
    }
}

//Other ----------------------------------------------------------------------------------------------------------------

void MAX7219::test_pattern() {

    convert_Data_to_binary(0, 0);
    convert_Data_to_binary(0, 1);
    convert_Data_to_binary(0, 2);
    convert_Data_to_binary(0, 3);

    for (int z = 0; z < 4; ++z) {
        //Go through all Digits / Rows
        for (int i = 1; i <= 8; ++i) {
            //Convert the Address into binary
            convert_Address_to_binary(i, z);

            //Go through all columns
            for (int j = 0; j < 256; ++j) {
                //Convert the Data into binary and send Address and Data
                convert_Data_to_binary(j, z);
                send_Data();

                sleep_ms(5);
            }
        }
    }
}

void MAX7219::send_Data_decimal(int import[4][8]) {

    for (int j = 0; j < 8; ++j) {
        for (int i = 0; i < 4; ++i) {
            convert_Address_to_binary(j+1, i);
            convert_Data_to_binary(import[i][7-j], i);
        }
        send_Data();
    }
}