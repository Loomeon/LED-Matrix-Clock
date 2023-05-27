
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"
#include "max7219.h"
#include "Segment_States.h"
#include "pico_rtc.h"
#include <stdio.h>
#include "DHT11.h"


int8_t min;
int8_t hour;
Segment_States Segments;
pico_rtc rtc_time;
MAX7219 Matrix(0, 2, 1);
int state=0;
DHT11 Sensor(4);

void callback_switch(uint gpio, uint32_t events);
void callback_set_hour(uint gpio, uint32_t events);
void callback_set_min(uint gpio, uint32_t events);

void callback_set_min(uint gpio, uint32_t events) {

    //Store the current time
    uint64_t start_time = to_ms_since_boot(get_absolute_time());

    //Stay in this while, while the Button is pressed
    while (gpio_get(3)) {

        //If the button is held down for 3 seconds, enter this if statement
        uint32_t current_time = to_ms_since_boot(get_absolute_time());
        if (current_time - start_time >= 3000) {
            min--; //Decrement the Min by one, because that would be the currently displayed value
            Matrix.power_state( true, true, false, false); //Only show the Hour Segments
            gpio_set_irq_enabled_with_callback(3, GPIO_IRQ_EDGE_RISE, true, &callback_set_hour); //Switch the IRQ to set hour
            break;
        }
    }

    //Increase the Minute and check for an overflow
    min++;
    if(min > 59){
        min = 0;
    }

}

void callback_set_hour(uint gpio, uint32_t events) {

    //Store the current time
    uint64_t start_time = to_ms_since_boot(get_absolute_time());

    //Stay in this while, while the Button is pressed
    while (gpio_get(3)) {

        //If the button is held down for 3 seconds, enter this if statement
        uint32_t current_time = to_ms_since_boot(get_absolute_time());
        if (current_time - start_time >= 3000) {
            hour--; //Decrement the Hour by one, because that would be the currently displayed value
            rtc_time.set_time(hour, min);
            Matrix.power_state( true, true, true, true);
            gpio_set_irq_enabled_with_callback(3, GPIO_IRQ_EDGE_RISE, true, &callback_switch);  //Switch the IRQ back to the switch menu
            break;
        }
    }

    //Increase the Hour and check for an overflow
    hour++;
    if(hour > 24){
        hour = 0;
    }
}


void callback_switch(uint gpio, uint32_t events){

    //Cycle through the States
    state++;
    if(state > 2){
        state = 0;
    }

    //Store the current time
    uint64_t start_time = to_ms_since_boot(get_absolute_time());

    //Stay in this while, while the Button is pressed
    while (gpio_get(3)) {

        //If the button is held down for 3 seconds, enter this if statement
        uint32_t current_time = to_ms_since_boot(get_absolute_time());
        if (current_time-start_time >= 3000) {
            state=3;
            Matrix.power_state(false, false, true, true); //Only show the Minute Segments
            gpio_set_irq_enabled_with_callback(3, GPIO_IRQ_EDGE_RISE, true, &callback_set_min); //Switch the IRQ to set minute
            break;
        }
    }

    switch (state) {

        //Display Time
        case 0:
            Segments.set_time(hour, min);
            break;

            //Display Temperature
        case 1:
            Segments.set_temperature(Sensor.temperature);
            break;

            //Display Humidity
        case 2:
            Segments.set_humidity(Sensor.humidity);
            break;

            //Change time mode
        case 3:
            //Segments.set_time(hour, min);
            break;

            //Set rtc to new time
        case 4:
            rtc_time.set_time(hour, min);
            state = 0;
            break;

            //in case there is an invalid mode, display time
        default:
            rtc_time.get_time(hour, min);
            Segments.set_time(hour, min);
    }

    Matrix.send_Data_decimal(Segments.Matrix_dots);


}

bool Update_Sensor(struct repeating_timer *t){
    Sensor.get_data();
    Sensor.convert_data();

    if(state == 1){
        Segments.set_temperature(Sensor.temperature);
    }
    else if(state == 2){
        Segments.set_humidity(Sensor.humidity);
    }

    return true;
}

bool Update_Clock(struct repeating_timer *t){
    rtc_time.get_time(hour, min);
    Segments.set_time(hour, min);
    return true;
}

int main() {
    stdio_init_all();

    gpio_init(0);
    gpio_init(1);
    gpio_init(2);

    gpio_set_dir(0 , GPIO_OUT);
    gpio_set_dir(1 , GPIO_OUT);
    gpio_set_dir(2 , GPIO_OUT);

    rtc_time.set_time(12,0);

    Matrix.init_8x8_Matrix();

    gpio_set_irq_enabled_with_callback(3, GPIO_IRQ_EDGE_RISE, true, &callback_switch);

    struct repeating_timer Sensor_timer;
    add_repeating_timer_ms(5000, Update_Sensor, NULL, &Sensor_timer);

    struct repeating_timer Clock_timer;
    add_repeating_timer_ms(60000, Update_Clock, NULL, &Clock_timer);

    //First read
    rtc_time.get_time(hour, min);
    Sensor.get_data();
    Sensor.convert_data();
    Segments.set_time(hour, min);

    while(1) {

    }
}
