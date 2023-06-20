//
// Created by Paul Weber on 24.05.23.
//



#ifndef MATRIX_CLOCK_DHT11_H
#define MATRIX_CLOCK_DHT11_H


class DHT11 {

public:
    DHT11(int Data_GPIO);

    //Int and decimal part of temperature (temperature . temperature_decimal)
    int temperature;
    float temperature_decimal;

    //Int and decimal part of temperature (humidity . humidity_decimal)
    int humidity;
    float humidity_decimal;

    //Function to read Temperature, Humidity and Checksum from the DHT11
    //Stores 40 Bits of Data in bool data[40]
    void get_data();

    //Converts the 40 Bits of Sensor Data into usable int and float values
    bool convert_data();

private:
    int Data_PIN; //Pin for the Data transfer
    bool data[40]{}; //Bitvector for the DHT11 Sensor Data

    //Waits until the GPIO State changes from the check state or when 255 µs passed
    //Returns the time in µs it took to change the State
    int read_state_change(bool state //Check state
    );

    //Converts the two int parts of the decimal number intro a float value
    //Returns the combined float value
    float convertToFloat(int beforeDecimal, //Normal int value
                         int afterDecimal); //Value behind the decimal, is going to be divided by 10 and added to Normal
};


#endif //MATRIX_CLOCK_DHT11_H
