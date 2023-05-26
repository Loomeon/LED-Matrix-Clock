//
// Created by Paul Weber on 24.05.23.
//



#ifndef MATRIX_CLOCK_DHT11_H
#define MATRIX_CLOCK_DHT11_H


class DHT11 {

public:
    DHT11(int Data_GPIO);

    void get_data();

    int Data_PIN;

    bool data[40]{};

    int read_state_change(bool state);



    bool convert_data();


    int temperature;
    float temperature_decimal;

    int humidity;
    float humidity_decimal;

    float convertToFloat(int beforeDecimal, int afterDecimal);

};


#endif //MATRIX_CLOCK_DHT11_H
