//
// Created by Paul Weber on 02.04.23.
//

#include "Segment_States.h"

//Class constructor
Segment_States::Segment_States() = default;

//Basic stuff for setting segments -------------------------------------------------------------------------------------

//Clear all segment states
void Segment_States::clear_segments() {
    //Go Through all Elements in the Array and write 0 to them
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            Matrix_dots[i][j] = 0;
        }
    }
}

//Set a state for a segment
void Segment_States::set_segment_state(int segment, //The segment to set (0-3)
                                       int number //State to set (0-9 Numbers, 10 °C, 11 -, 12 %)
                                       ) {
    //The Array Matrix Dots stores all the states for every segment, 0-7 are the 8 rows, each row begins on the right.
    //Because every row begins on the right, the MSB is the most right LED and the LSB is the most left LED.

    switch (number) {
        case 0:

            /*
            - - X X X X - -
            - X X X X X X -
            - X X - - X X -
            - X X - - X X -
            - X X - - X X -
            - X X - - X X -
            - X X X X X X -
            - - X X X X - -
            */

            Matrix_dots[segment][0] = 0b00111100;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b01100110;
            Matrix_dots[segment][3] = 0b01100110;
            Matrix_dots[segment][4] = 0b01100110;
            Matrix_dots[segment][5] = 0b01100110;
            Matrix_dots[segment][6] = 0b01111110;
            Matrix_dots[segment][7] = 0b00111100;

            break;

        case 1:

            /*
            - - - X X X X -
            - - X X X X X -
            - X X X - X X -
            - X X - - X X -
            - - - - - X X -
            - - - - - X X -
            - - - - - X X -
            - - - - - X X -
            */

            Matrix_dots[segment][0] = 0b01111000;
            Matrix_dots[segment][1] = 0b01111100;
            Matrix_dots[segment][2] = 0b01101110;
            Matrix_dots[segment][3] = 0b01100110;
            Matrix_dots[segment][4] = 0b01100000;
            Matrix_dots[segment][5] = 0b01100000;
            Matrix_dots[segment][6] = 0b01100000;
            Matrix_dots[segment][7] = 0b01100000;

            break;

        case 2:

            /*
            - X X X X X - -
            - X X X X X X -
            - - - - - X X -
            - - X X X X X -
            - X X X X X - -
            - X X - - - - -
            - X X X X X X -
            - X X X X X X -
            */

            Matrix_dots[segment][0] = 0b00111110;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b01100000;
            Matrix_dots[segment][3] = 0b01111100;
            Matrix_dots[segment][4] = 0b00111110;
            Matrix_dots[segment][5] = 0b00000110;
            Matrix_dots[segment][6] = 0b01111110;
            Matrix_dots[segment][7] = 0b01111110;

            break;

        case 3:

            /*
            - X X X X X - -
            - X X X X X X -
            - - - - - X X -
            - X X X X X - -
            - X X X X X - -
            - - - - - X X -
            - X X X X X X -
            - X X X X X - -
            */

            Matrix_dots[segment][0] = 0b00111110;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b01100000;
            Matrix_dots[segment][3] = 0b00111110;
            Matrix_dots[segment][4] = 0b01111110;
            Matrix_dots[segment][5] = 0b01100000;
            Matrix_dots[segment][6] = 0b01111110;
            Matrix_dots[segment][7] = 0b00111110;

            break;

        case 4:

            /*
            - - - - X X - -
            - - - X X - - -
            - - X X - - - -
            - X X - X X - -
            - X X X X X X -
            - X X X X X X -
            - - - - X X - -
            - - - - X X - -
            */

            Matrix_dots[segment][0] = 0b00110000;
            Matrix_dots[segment][1] = 0b00011000;
            Matrix_dots[segment][2] = 0b00001100;
            Matrix_dots[segment][3] = 0b00110110;
            Matrix_dots[segment][4] = 0b01111110;
            Matrix_dots[segment][5] = 0b01111110;
            Matrix_dots[segment][6] = 0b00110000;
            Matrix_dots[segment][7] = 0b00110000;

            break;

        case 5:

            /*
            - X X X X X X -
            - X X X X X X -
            - X X - - - - -
            - X X X X X - -
            - X X X X X X -
            - - - - - X X -
            - X X X X X X -
            - X X X X X - -
            */

            Matrix_dots[segment][0] = 0b01111110;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b00000110;
            Matrix_dots[segment][3] = 0b00111110;
            Matrix_dots[segment][4] = 0b01111110;
            Matrix_dots[segment][5] = 0b01100000;
            Matrix_dots[segment][6] = 0b01111110;
            Matrix_dots[segment][7] = 0b00111110;

            break;

        case 6:

            /*
            - - X X X X - -
            - X X X X X - -
            - X X - - - - -
            - X X X X X - -
            - X X X X X X -
            - X X - - X X -
            - X X X X X X -
            - - X X X X - -
            */

            Matrix_dots[segment][0] = 0b00111100;
            Matrix_dots[segment][1] = 0b00111110;
            Matrix_dots[segment][2] = 0b00000110;
            Matrix_dots[segment][3] = 0b00111110;
            Matrix_dots[segment][4] = 0b01111110;
            Matrix_dots[segment][5] = 0b01100110;
            Matrix_dots[segment][6] = 0b01111110;
            Matrix_dots[segment][7] = 0b00111100;

            break;

        case 7:

            /*
            - X X X X X X -
            - X X X X X X -
            - - - - - X X -
            - - - - X X - -
            - - - X X - - -
            - - X X - - - -
            - X X - - - - -
            - X - - - - - -
            */

            Matrix_dots[segment][0] = 0b01111110;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b01100000;
            Matrix_dots[segment][3] = 0b00110000;
            Matrix_dots[segment][4] = 0b00011000;
            Matrix_dots[segment][5] = 0b00001100;
            Matrix_dots[segment][6] = 0b00000110;
            Matrix_dots[segment][7] = 0b00000010;

            break;

        case 8:

            /*
            - - X X X X - -
            - X X X X X X -
            - X X - - X X -
            - - X X X X - -
            - - X X X X - -
            - X X - - X X -
            - X X X X X X -
            - - X X X X - -
            */

            Matrix_dots[segment][0] = 0b00111100;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b01100110;
            Matrix_dots[segment][3] = 0b00111100;
            Matrix_dots[segment][4] = 0b00111100;
            Matrix_dots[segment][5] = 0b01100110;
            Matrix_dots[segment][6] = 0b01111110;
            Matrix_dots[segment][7] = 0b00111100;

            break;


        case 9:
            /*
            - - X X X X - -
            - X X X X X X -
            - X X - - X X -
            - X X X X X X -
            - - X X X X X -
            - - - - - X X -
            - - X X X X X -
            - - X X X X - -
            */

            Matrix_dots[segment][0] = 0b00111100;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b01100110;
            Matrix_dots[segment][3] = 0b01111110;
            Matrix_dots[segment][4] = 0b01111100;
            Matrix_dots[segment][5] = 0b01100000;
            Matrix_dots[segment][6] = 0b01111100;
            Matrix_dots[segment][7] = 0b00111100;

            break;


        case 10:

            /*
            X X - - X X X -
            X X - X X X X -
            - - - X X - - -
            - - - X X - - -
            - - - X X - - -
            - - - X X - - -
            - - - X X X X -
            - - - - X X X -
            */

            Matrix_dots[segment][0] = 0b01110011;
            Matrix_dots[segment][1] = 0b01111011;
            Matrix_dots[segment][2] = 0b00011000;
            Matrix_dots[segment][3] = 0b00011000;
            Matrix_dots[segment][4] = 0b00011000;
            Matrix_dots[segment][5] = 0b00011000;
            Matrix_dots[segment][6] = 0b01111000;
            Matrix_dots[segment][7] = 0b01110000;

            break;

        case 11:
            /*
            - - - - - - - -
            - - - - - - - -
            - - - - - - - -
            - X X X X X X -
            - X X X X X X -
            - - - - - - - -
            - - - - - - - -
            - - - - - - - -
            */

            Matrix_dots[segment][0] = 0b00000000;
            Matrix_dots[segment][1] = 0b00000000;
            Matrix_dots[segment][2] = 0b00000000;
            Matrix_dots[segment][3] = 0b01111110;
            Matrix_dots[segment][4] = 0b01111110;
            Matrix_dots[segment][5] = 0b00000000;
            Matrix_dots[segment][6] = 0b00000000;
            Matrix_dots[segment][7] = 0b00000000;

            break;

        case 12:
            /*
            - X - - - - X X
            X X X - - X X X
            - X - - X X X -
            - - - X X X - -
            - - X X X - - -
            - X X X - - X -
            X X X - - X X X
            X X - - - - X -
            */

            Matrix_dots[segment][0] = 0b11000010;
            Matrix_dots[segment][1] = 0b11100111;
            Matrix_dots[segment][2] = 0b01110010;
            Matrix_dots[segment][3] = 0b00111000;
            Matrix_dots[segment][4] = 0b00011100;
            Matrix_dots[segment][5] = 0b01001110;
            Matrix_dots[segment][6] = 0b11100111;
            Matrix_dots[segment][7] = 0b01000011;

            break;

        default:

            break;
    }
}

//Set Segments to a Format ---------------------------------------------------------------------------------------------

//Set the segment states to a time
void Segment_States::set_time(int Hours, //Hour (0-23)
                              int Minutes //Minute (0-59)
) {
    clear_segments();

    //If the time is 0:XX, the 0 has to be set manually, otherwise it can be calculated
    if(Hours > 0){
        //Calculate the individual Digits of the Hour (only calculating the Digits that exist, no leading zero)
        int Divisor = 1;
        int Segment = 1; //Start at the right segment

        //Go Through all existing Digits
        while (Hours/Divisor != 0){
            set_segment_state(Segment, Hours/Divisor%10);

            //Increment Divisor and Decrement Segment
            Divisor *= 10;
            Segment--;
        }
    }
    else{
        set_segment_state(1, 0);
    }

    //Calculating the Individual Digits of the Minutes (All of them, if a Number is only 1 Digits long it has leading zeros)
    set_segment_state(2, Minutes/10%10);
    set_segment_state(3, Minutes/1%10);

    //Shift the middle two segment numbers to the sides to make space for the dots
    segment_offset(1, -1); //Move the number in segment 1 1 position to the left
    segment_offset(2, 1); //Move the number in segment 2 1 position to the right

    //Add the Dot (left and right half to the middle segments)
    add_separator(1, 0); //add the separator dots to segment 1
    add_separator(2, 7); //add the separator dots (shifted 7 to the left) to segment 2
}

//Set the segment states to a temperature
void Segment_States::set_temperature(int temperature //Temperature (0 °C - 50 °C will be Displayed, everything else as -- °C)
) {
    clear_segments();

    set_segment_state(3, 10); //Set segment 3 to "°C"

    //The DHT11 can only read temperatures between 0 °C and 50 °C
    if (temperature >= 0 && temperature <= 50){

        //Calculate the individual Digits of the temperature (only calculating the Digits that exist, no leading zero)
        int Divisor = 1;
        int Segment = 2; //Start at the right segment

        //Go Through all existing Digits
        while (temperature/Divisor != 0){
            set_segment_state(Segment, temperature/Divisor%10);

            //Increment Divisor and Decrement Segment
            Divisor *= 10;
            Segment--;
        }
    }
        //If the temperature is outside the readable values, display "--°C"
    else{
        set_segment_state(1, 11);
        set_segment_state(2, 11);
    }
}

//Set the segment states to a humidity
void Segment_States::set_humidity(int humidity //humidity (20 % - 90% will be Displayed, everything else as -- %)
){
    clear_segments();

    set_segment_state(3, 12);  //Set segment 3 to "%"

    //The DHT11 can only read humidity between 20 % and 50 %
    if (humidity  >= 20 && humidity  <= 90){
        //Calculate the individual Digits of the humidity (only calculating the Digits that exist, no leading zero)
        int Divisor = 1;
        int Segment = 2; //Start at the right segment

        //Go Through all existing Digits
        while (humidity /Divisor != 0){
            set_segment_state(Segment, humidity/Divisor%10);

            //Increment Divisor and Decrement Segment
            Divisor *= 10;
            Segment--;
        }
    }
        //If the humidity is outside the readable values, display "--%"
    else{
        set_segment_state(1, 11);
        set_segment_state(2, 11);
    }
}

//set_time formatting --------------------------------------------------------------------------------------------------

//Add the separator dots between hour and minutes
void Segment_States::add_separator(int segment, //Segment where the dots will be added (0-3)
                                   int offset //Dots default position is column 7, offset moves it to the left (0-7)
) {
    //Add separator dots to a specific segment, use |= to turn on the dots in addition to the number,
    //use >> to move the dots in the left, to get them into the right column
    Matrix_dots[segment][1] |= (0b10000000 >> offset);
    Matrix_dots[segment][2] |= (0b10000000 >> offset);
    Matrix_dots[segment][5] |= (0b10000000 >> offset);
    Matrix_dots[segment][6] |= (0b10000000 >> offset);
}

//Moves all dots in a segment to the left or right
void Segment_States::segment_offset(int segment, //Segment which dots will be moved (0-3)
                                    int offset //Amount that the dots will be moved (Left: negative number / Right: positive number)
) {
    //Use Bitshift operations to move a number to the left or right in a segment
    //if the offset is positive move to the right, if the offset is negative, move to the left
    if (offset > 0){
        //Go through all lines of the display
        for (int i = 0; i < 8; ++i) {
            Matrix_dots[segment][i] = Matrix_dots[segment][i] << offset; //Move the dots in a line offset numbers to the right
        }
    }

    if(offset < 0){
        offset = -offset; //Invert the offset, because you can't use a negative number on Bitshift operations

        //Go through all lines of the display
        for (int i = 0; i < 8; ++i) {
            Matrix_dots[segment][i] = Matrix_dots[segment][i] >> offset; //Move the dots in a line offset numbers to the left
        }
    }

        //If the offset is 0, do nothing
    else{
    }
}