//
// Created by Paul Weber on 02.04.23.
//

#ifndef MATRIX_CLOCK_MATRIX_NUMBERS_H
#define MATRIX_CLOCK_MATRIX_NUMBERS_H


class Matrix_Numbers {

public:
    Matrix_Numbers();
    void update_qudrant(int number, int qudrant);
    void export_array(bool *export_Matrix_Dot);

private:
    bool Matrix_dot[8][8]; //Matrix with states for all dots


};


#endif //MATRIX_CLOCK_MATRIX_NUMBERS_H
