
#include "pico/stdlib.h"
#include "pico/util/datetime.h"
#include "hardware/gpio.h"
#include "pico/multicore.h"
#include "max7219.h"
#include "Segment_States.h"
#include "pico_rtc.h"
#include "DHT11.h"

//Declarations for Functions
void callback_switch(uint gpio, uint32_t events);
void callback_set_hour(uint gpio, uint32_t events);
void callback_set_min(uint gpio, uint32_t events);
bool Update_Clock(struct repeating_timer *t);
bool Update_Sensor(struct repeating_timer *t);

//Global Declarations for the Classes
DHT11 Sensor(4);
Segment_States Segments;
pico_rtc rtc_time;
MAX7219 Matrix(0, 2, 1);

//Global Timer Structures
struct repeating_timer Sensor_timer;
struct repeating_timer Clock_timer;

//Global Variables
int8_t min=0;
int8_t hour=12;
int state=0;
int GPIO_Button = 3;
int Debounce_wait = 50;
int long_press = 1000;


void callback_set_min(uint gpio, uint32_t events) {
    //Temporary Disable IRQ to prevent Button Bounce
    gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, false, &callback_set_min);

    //Variable to keep track if the IRQ Functions is going to change
    bool set_hour = false;

    //Store the current time
    uint64_t start_time = to_ms_since_boot(get_absolute_time());

    //Stay in this while, while the Button is pressed
    while (gpio_get(GPIO_Button)) {

        //If the button is held down for 3 seconds, enter this if statement
        uint32_t current_time = to_ms_since_boot(get_absolute_time());
        if (current_time - start_time >= long_press) {
            Matrix.power_state( true, true, false, false); //Only show the Hour Segments
            gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, true, &callback_set_hour); //Switch the IRQ to set hour
            set_hour = true;
            break;
        }
    }

    busy_wait_ms(Debounce_wait);

    if(!set_hour){
        //Increase the Minute and check for an overflow
        min++;
        if(min > 59){
            min = 0;
        }

        gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, true, &callback_set_min);
    }

    Segments.set_time(hour, min);
    Matrix.send_Data_decimal(Segments.Matrix_dots);
}

void callback_set_hour(uint gpio, uint32_t events) {
    //Temporary Disable IRQ to prevent Button Bounce
    gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, false, &callback_set_hour);

    //Variable to keep track if the IRQ Functions is going to change
    bool menu = false;

    //Store the current time
    uint64_t start_time = to_ms_since_boot(get_absolute_time());

    //Stay in this while, while the Button is pressed
    while (gpio_get(GPIO_Button)) {

        //If the button is held down for 3 seconds, enter this if statement
        uint32_t current_time = to_ms_since_boot(get_absolute_time());
        if (current_time - start_time >= long_press) {
            rtc_time.set_time(hour, min);
            Matrix.power_state( true, true, true, true);
            gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, true, &callback_switch);  //Switch the IRQ back to the switch menu
            add_repeating_timer_ms(60000, Update_Clock, NULL, &Clock_timer);
            menu = true;
            break;
        }
    }

    //Increase the Hour and check for an overflow

    busy_wait_ms(Debounce_wait);

    if(!menu) {
        gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, true, &callback_set_hour);
        hour++;
        if(hour > 24){
            hour = 0;
        }
    }

    Segments.set_time(hour, min);
    Matrix.send_Data_decimal(Segments.Matrix_dots);
}


void callback_switch(uint gpio, uint32_t events){
    //Temporary Disable IRQ to prevent Button Bounce
    gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, false, &callback_switch);

    //Variable to keep track if the IRQ Functions is going to change
    bool set_time = false;

    //Store the current time
    uint64_t start_time = to_ms_since_boot(get_absolute_time());

    //Stay in this while, while the Button is pressed
    while (gpio_get(GPIO_Button)) {

        //If the button is held down for 3 seconds, enter this if statement
        uint32_t current_time = to_ms_since_boot(get_absolute_time());
        if (current_time-start_time >= long_press) {
            state = 3; //Set the state to 3, because the State will later be set from 3 to 0, state 0 is needed to display Time
            cancel_repeating_timer(&Clock_timer);
            Matrix.power_state(false, false, true, true); //Only show the Minute Segments
            gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, true, &callback_set_min); //Switch the IRQ to set minute
            set_time = true;
            break;
        }
    }

    //Cycle through the States
    state++;
    if(state > 2){
        state = 0;
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
    }

    Matrix.send_Data_decimal(Segments.Matrix_dots);

    busy_wait_ms(Debounce_wait);
    if(!set_time){
        gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, true, &callback_switch);
    }
}


bool Update_Sensor(struct repeating_timer *t){

    //Read new Data from the Sensor
    Sensor.get_data();
    Sensor.convert_data();

    //Depending on the State Display new Value
    if(state == 1){
        Segments.set_temperature(Sensor.temperature);
        Matrix.send_Data_decimal(Segments.Matrix_dots);
    }
    else if(state == 2){
        Segments.set_humidity(Sensor.humidity);
        Matrix.send_Data_decimal(Segments.Matrix_dots);
    }

    return true;
}

bool Update_Clock(struct repeating_timer *t){
    rtc_time.get_time(hour, min);

    if(state == 0){
        Segments.set_time(hour, min);
        Matrix.send_Data_decimal(Segments.Matrix_dots);
    }

    return true;
}

int main() {
    stdio_init_all();
    Matrix.init_8x8_Matrix();

    //First Read of Sensor and Time
    Sensor.get_data();
    Sensor.convert_data();
    rtc_time.set_time(hour, min);

    //Display the Read values
    Segments.set_time(hour, min);
    Matrix.send_Data_decimal(Segments.Matrix_dots);

    //Enable the GPIO Interrupt and the 2 Timer
    gpio_set_irq_enabled_with_callback(GPIO_Button, GPIO_IRQ_EDGE_RISE, true, &callback_switch);
    add_repeating_timer_ms(5000, Update_Sensor, NULL, &Sensor_timer); //Updates the Sensor once every 5 seconds
    add_repeating_timer_ms(60000, Update_Clock, NULL, &Clock_timer); //Updates the Clock Display once every 60 seconds

    //Until powerdown the Raspberry Pi Pico always goes to sleep when it has nothing to do
    while(1) {
        sleep_us(0);
    }
}
