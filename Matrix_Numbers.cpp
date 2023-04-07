//
// Created by Paul Weber on 02.04.23.
//

#include "Matrix_Numbers.h"

Matrix_Numbers::Matrix_Numbers() {

}


void Matrix_Numbers::clear_segments() {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 8; ++j) {
            Matrix_dots[i][j] = 0;
        }
    }
}

void Matrix_Numbers::set_segment_state(int segment, int number) {
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

            Matrix_dots[segment][0] = 0b00011110;
            Matrix_dots[segment][1] = 0b00111110;
            Matrix_dots[segment][2] = 0b01110110;
            Matrix_dots[segment][3] = 0b01100110;
            Matrix_dots[segment][4] = 0b00000110;
            Matrix_dots[segment][5] = 0b00000110;
            Matrix_dots[segment][6] = 0b00000110;
            Matrix_dots[segment][7] = 0b00000110;

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

            Matrix_dots[segment][0] = 0b01111100;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b00000110;
            Matrix_dots[segment][3] = 0b00111110;
            Matrix_dots[segment][4] = 0b01111100;
            Matrix_dots[segment][5] = 0b01100000;
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

            Matrix_dots[segment][0] = 0b01111100;
            Matrix_dots[segment][1] = 0b01111110;
            Matrix_dots[segment][2] = 0b00000110;
            Matrix_dots[segment][3] = 0b01111100;
            Matrix_dots[segment][4] = 0b01111100;
            Matrix_dots[segment][5] = 0b00000110;
            Matrix_dots[segment][6] = 0b01111110;
            Matrix_dots[segment][7] = 0b01111100;

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

            Matrix_dots[segment][0] = 0b00001100;
            Matrix_dots[segment][1] = 0b00011000;
            Matrix_dots[segment][2] = 0b00110000;
            Matrix_dots[segment][3] = 0b01101100;
            Matrix_dots[segment][4] = 0b01111110;
            Matrix_dots[segment][5] = 0b01111110;
            Matrix_dots[segment][6] = 0b00001100;
            Matrix_dots[segment][7] = 0b00001100;

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
            Matrix_dots[segment][2] = 0b01100000;
            Matrix_dots[segment][3] = 0b01111100;
            Matrix_dots[segment][4] = 0b01111110;
            Matrix_dots[segment][5] = 0b00000110;
            Matrix_dots[segment][6] = 0b01111110;
            Matrix_dots[segment][7] = 0b01111100;

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
            Matrix_dots[segment][1] = 0b01111100;
            Matrix_dots[segment][2] = 0b01100000;
            Matrix_dots[segment][3] = 0b01111100;
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
            Matrix_dots[segment][2] = 0b00000110;
            Matrix_dots[segment][3] = 0b00001100;
            Matrix_dots[segment][4] = 0b00011000;
            Matrix_dots[segment][5] = 0b00110000;
            Matrix_dots[segment][6] = 0b01100000;
            Matrix_dots[segment][7] = 0b01000000;

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
            Matrix_dots[segment][4] = 0b00111110;
            Matrix_dots[segment][5] = 0b00000110;
            Matrix_dots[segment][6] = 0b00111110;
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

            Matrix_dots[segment][0] = 0b11001110;
            Matrix_dots[segment][1] = 0b11011110;
            Matrix_dots[segment][2] = 0b00011000;
            Matrix_dots[segment][3] = 0b00011000;
            Matrix_dots[segment][4] = 0b00011000;
            Matrix_dots[segment][5] = 0b00011000;
            Matrix_dots[segment][6] = 0b1101111;
            Matrix_dots[segment][7] = 0b11001110;

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

        default:

            break;
    }
}

void Matrix_Numbers::set_time(int hour_left, int hour_right, int minute_left, int minute_right) {
    set_segment_state(0, hour_left);
    set_segment_state(1, hour_right);
    set_segment_state(2, minute_left);
    set_segment_state(3, minute_right);

    segment_offset(1, -1);
    segment_offset(2, 1);

    add_seperator(1, 7);
    add_seperator(2, 0);
}

void Matrix_Numbers::add_seperator(int segment, int offset) {
    Matrix_dots[segment][1] |= (0b10000000 >> offset);
    Matrix_dots[segment][2] |= (0b10000000 >> offset);
    Matrix_dots[segment][5] |= (0b10000000 >> offset);
    Matrix_dots[segment][6] |= (0b10000000 >> offset);
}


void Matrix_Numbers::segment_offset(int segment, int offset) {
    if (offset > 0){
        for (int i = 0; i < 8; ++i) {
            Matrix_dots[segment][i] = Matrix_dots[segment][i] >> offset;
        }
    }

    else if(offset < 0){
        for (int i = 0; i < 8; ++i) {
            Matrix_dots[segment][i] = Matrix_dots[segment][i] << offset;
        }
    }

    else{

    }
}
