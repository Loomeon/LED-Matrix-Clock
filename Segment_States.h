//
// Created by Paul Weber on 02.04.23.
//

#ifndef MATRIX_CLOCK_SEGMENT_STATES_H
#define MATRIX_CLOCK_SEGMENT_STATES_H

class Segment_States {

public:
    Segment_States(); //Class Constructor

    int Matrix_dots[4][8]{}; //Stores all 8 Lines of the 4 Segments

    //Set the segment states to a time
    void set_time(int Hours, //Hour (0-23)
                  int Minute //Minute (0-59)
                  );

    //Set the segment states to a temperature
    void set_temperature(int temperature //Temperature (0 °C - 50 °C will be Displayed, everything else as -- °C)
    );

    //Set the segment states to a humidity
    void set_humidity (int humidity //humidity (20 % - 90% will be Displayed, everything else as -- %)
    );

private:
    //Set a state for a segment
    void set_segment_state(int segment, //The segment to set (0-3)
                           int number //State to set (0-9 Numbers, 10 °C, 11 -, 12 %)
    );

    //Clear all segment states
    void clear_segments();

    //Add the separator dots between hour and minutes
    void add_separator(int segment, //Segment where the dots will be added (0-3)
                       int offset //Dots default position is column 7, offset moves it to the left (0-7)
                       );

    //Moves all dots in a segment to the left or right
    void segment_offset(int segment, //Segment which dots will be moved (0-3)
                        int offset); //Amount that the dots will be moved (Left: negative number / Right: positive number)
};

#endif //MATRIX_CLOCK_SEGMENT_STATES_H