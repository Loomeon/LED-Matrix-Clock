//
// Created by Paul Weber on 02.04.23.
//

#ifndef MATRIX_CLOCK_MATRIX_NUMBERS_H
#define MATRIX_CLOCK_MATRIX_NUMBERS_H


class Matrix_Numbers {

public:
    Matrix_Numbers();
    int Matrix_dots[4][8];
    void set_time(int hour_left, int hour_right, int minute_left, int minute_right);

private:

    void clear_segments();
    void set_segment_state(int segment, int number);

    void add_seperator(int segment, int offset);
    void segment_offset(int segment, int offset);
};


#endif //MATRIX_CLOCK_MATRIX_NUMBERS_H
