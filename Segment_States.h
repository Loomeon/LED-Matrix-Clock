//
// Created by Paul Weber on 02.04.23.
//

#ifndef MATRIX_CLOCK_SEGMENT_STATES_H
#define MATRIX_CLOCK_SEGMENT_STATES_H

class Segment_States {

public:
    Segment_States(); //Class Constructor
    int Matrix_dots[4][8]{}; //Stores all 8 Lines of the 4 Segments
    void set_time(int Hours, int Minute); //Set the 4 Segments to formatted Time with Hours and Minutes
    void set_temperature(int temperature); //Set the 4 Segments to formatted Temperature
    void set_humidity (int humidity); //Set the 4 Segments to formatted Temperature

private:
    void clear_segments(); //Go through all segments and clear all lines
    void set_segment_state(int segment, int number); //Set the state (number or symbol) for a specific segment
    void add_separator(int segment, int offset); //Add the dots of the clock to the segments, only half, because they are on two segments
    void segment_offset(int segment, int offset); //Move the number inside a segment to the left or right
};

#endif //MATRIX_CLOCK_SEGMENT_STATES_H