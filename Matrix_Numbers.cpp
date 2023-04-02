//
// Created by Paul Weber on 02.04.23.
//

#include "Matrix_Numbers.h"

Matrix_Numbers::Matrix_Numbers() {

}

/*

0
- X - -
X - X -
X - X -
- X - -

1
- X X -
X - X -
- - X -
- - X -

2
X X X -
- - X -
X X - -
X X X- -

3
X X X -
- - X -
X X X -
X X X -

4
X - X -
X - X -
- X X -
- - X -

5
X X X -
X - - -
- X X -
X X X -

6
X X X -
X - - -
X X X -
X X X -

7
X X X -
- - X -
- - X -
- - X -

8
X X X -
X - X -
X X X -
X X X -

9
X X X -
X X X -
- - X -
- X X -

 */

void Matrix_Numbers::update_qudrant(int number, int qudrant) {
    int x_offset = 0;
    int y_offset = 0;

    switch (qudrant) {
        case 0:

            x_offset = 0;
            y_offset = 0;
            break;

        case 1:
            x_offset = 4;
            y_offset = 0;
            break;

        case 2:
            x_offset = 0;
            y_offset = 4;
            break;

        case 3:
            x_offset = 4;
            y_offset = 4;
            break;

        default:
            break;
    }

    switch (number) {

        //-------------------------------------------------------------------------
        case 0:
            /*
            - X - -
            X - X -
            X - X -
            - X - -
            */

            Matrix_dot[0+x_offset][0+y_offset] = false;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = false;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = true;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = true;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = true;
            Matrix_dot[1+x_offset][2+y_offset] = false;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = false;
            Matrix_dot[1+x_offset][3+y_offset] = true;
            Matrix_dot[2+x_offset][3+y_offset] = false;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;

            //-------------------------------------------------------------------------
        case 1:
            /*
- X X -
X - X -
- - X -
- - X -
            */

            Matrix_dot[0+x_offset][0+y_offset] = false;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = true;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = true;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = false;
            Matrix_dot[1+x_offset][2+y_offset] = false;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = false;
            Matrix_dot[1+x_offset][3+y_offset] = false;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;

            //-------------------------------------------------------------------------
        case 2:
            /*
X X X -
- - X -
X X - -
X X X- -
            */

            Matrix_dot[0+x_offset][0+y_offset] = true;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = false;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = true;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = true;
            Matrix_dot[1+x_offset][2+y_offset] = true;
            Matrix_dot[2+x_offset][2+y_offset] = false;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = true;
            Matrix_dot[1+x_offset][3+y_offset] = true;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;


            //-------------------------------------------------------------------------
        case 3:
            /*
    X X X -
    - - X -
    X X X -
    X X X -
            */

            Matrix_dot[0+x_offset][0+y_offset] = true;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = false;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = true;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = true;
            Matrix_dot[1+x_offset][2+y_offset] = true;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = true;
            Matrix_dot[1+x_offset][3+y_offset] = true;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;


            //-------------------------------------------------------------------------
        case 4:
            /*
X - X -
X - X -
- X X -
- - X -
            */

            Matrix_dot[0+x_offset][0+y_offset] = true;
            Matrix_dot[1+x_offset][0+y_offset] = false;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = true;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = true;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = false;
            Matrix_dot[1+x_offset][2+y_offset] = true;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = false;
            Matrix_dot[1+x_offset][3+y_offset] = false;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;

            //-------------------------------------------------------------------------
        case 5:
            /*
X X X -
X - - -
- X X -
X X X -
            */

            Matrix_dot[0+x_offset][0+y_offset] = true;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = true;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = false;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = false;
            Matrix_dot[1+x_offset][2+y_offset] = true;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = true;
            Matrix_dot[1+x_offset][3+y_offset] = true;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;

            //-------------------------------------------------------------------------
        case 6:
            /*
X X X -
X - - -
X X X -
X X X -
            */

            Matrix_dot[0+x_offset][0+y_offset] = true;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = true;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = false;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = true;
            Matrix_dot[1+x_offset][2+y_offset] = true;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = true;
            Matrix_dot[1+x_offset][3+y_offset] = true;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;

            //-------------------------------------------------------------------------
        case 7:
            /*
X X X -
- - X -
- - X -
- - X -
            */

            Matrix_dot[0+x_offset][0+y_offset] = true;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = false;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = true;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = false;
            Matrix_dot[1+x_offset][2+y_offset] = false;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = false;
            Matrix_dot[1+x_offset][3+y_offset] = false;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;

            //-------------------------------------------------------------------------
        case 8:
            /*
X X X -
X - X -
X X X -
X X X -

            */

            Matrix_dot[0+x_offset][0+y_offset] = true;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = true;
            Matrix_dot[1+x_offset][1+y_offset] = false;
            Matrix_dot[2+x_offset][1+y_offset] = true;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = true;
            Matrix_dot[1+x_offset][2+y_offset] = true;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = true;
            Matrix_dot[1+x_offset][3+y_offset] = true;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;

            //-------------------------------------------------------------------------
        case 9:
            /*
X X X -
X X X -
- - X -
- X X -
            */

            Matrix_dot[0+x_offset][0+y_offset] = true;
            Matrix_dot[1+x_offset][0+y_offset] = true;
            Matrix_dot[2+x_offset][0+y_offset] = true;
            Matrix_dot[3+x_offset][0+y_offset] = false;

            Matrix_dot[0+x_offset][1+y_offset] = true;
            Matrix_dot[1+x_offset][1+y_offset] = true;
            Matrix_dot[2+x_offset][1+y_offset] = true;
            Matrix_dot[3+x_offset][1+y_offset] = false;

            Matrix_dot[0+x_offset][2+y_offset] = false;
            Matrix_dot[1+x_offset][2+y_offset] = false;
            Matrix_dot[2+x_offset][2+y_offset] = true;
            Matrix_dot[3+x_offset][2+y_offset] = false;

            Matrix_dot[0+x_offset][3+y_offset] = false;
            Matrix_dot[1+x_offset][3+y_offset] = true;
            Matrix_dot[2+x_offset][3+y_offset] = true;
            Matrix_dot[3+x_offset][3+y_offset] = false;

            break;

    default:
        break;
}



}

void Matrix_Numbers::export_array(bool *export_Matrix_Dot) {
    for (int x = 0; x < 8; ++x) {
        for (int y = 0; y < 8; ++y) {
            *(export_Matrix_Dot+x+y*8) = Matrix_dot[x][y];
        }
    }

}