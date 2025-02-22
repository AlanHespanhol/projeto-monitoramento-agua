#ifndef INIT_GPIO_H  
#define INIT_GPIO_H

#include "pico/stdlib.h"
#include "pio_matrix.pio.h"

#define BTN_A 5
#define BTN_B 6
#define LED_RED 13
#define tempo 200
#define BUZZER 10


void init_gpio(){
    gpio_init(BTN_A);
    gpio_set_dir(BTN_A, GPIO_IN);
    gpio_pull_up(BTN_A);

    gpio_init(BTN_B);
    gpio_set_dir(BTN_B, GPIO_IN);
    gpio_pull_up(BTN_B);

    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
}


#endif