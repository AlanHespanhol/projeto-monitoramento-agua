#include <stdlib.h>
#include "pico/stdlib.h"
#include "hardware/pio.h"
#include "hardware/clocks.h"
#include "hardware/timer.h"
#include "hardware/pwm.h"
#include "hardware/gpio.h"
#include "config_matriz.h"
#include "pio_matrix.pio.h"
#include "init_GPIO.h"
#include "pico/bootrom.h"

uint32_t last_time = 0;
int num_atual = 0; 

// Configura o PWM nos buzzers
void setup_buzzer(uint pin) {
    gpio_set_function(pin, GPIO_FUNC_PWM);
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_wrap(slice_num, 255);
    pwm_set_enabled(slice_num, true);
}

// Gera um tom no buzzer
void play_tone(uint pin, uint16_t frequency, uint8_t intensity) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_clkdiv(slice_num, 125000000 / (frequency * 256));
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(pin), intensity);
}

// Para o som do buzzer
void stop_tone(uint pin) {
    uint slice_num = pwm_gpio_to_slice_num(pin);
    pwm_set_chan_level(slice_num, pwm_gpio_to_channel(pin), 0);
}

// Função de interrupção com debouncing
void gpio_irq_handler(uint gpio, uint32_t events)
{
    // Obtém o tempo atual em microssegundos
    uint32_t current_time = to_us_since_boot(get_absolute_time());
    // Verifica se passou tempo suficiente desde o último evento
    if (current_time - last_time > 200000) // 200 ms de debouncing
    {
        if(gpio == BTN_A)
        {
            num_atual++;
        }
        else if (gpio == BTN_B)
        {
            num_atual--;
        }
        last_time = current_time;
    }
}
    
//função principal
int main()
{
    init_gpio();
    stdio_init_all();
    
    setup_buzzer(BUZZER);

    PIO pio = pio0; 
    //configurações da PIO
    uint offset = pio_add_program(pio, &pio_matrix_program);
    uint sm = pio_claim_unused_sm(pio, true);
    pio_matrix_program_init(pio, sm, offset, OUT_PIN);

    gpio_set_irq_enabled_with_callback(BTN_A, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    gpio_set_irq_enabled_with_callback(BTN_B, GPIO_IRQ_EDGE_FALL, true, &gpio_irq_handler);
    
    while (true) {

        switch (num_atual)
        {
        //extra para apagar os leds
        case -1:
            desenho_pio(apagar_leds, valor_led, pio, sm, r, g, b);
            break;
        case 0:
            desenho_pio(num_0, valor_led, pio, sm, r, g, b);
            gpio_put(LED_RED, 1);
            sleep_ms(500);
            gpio_put(LED_RED, 0);
            sleep_ms(500);
            break;
        case 1:
            desenho_pio(num_1, valor_led, pio, sm, r, g, b);
            break;
        case 2:
            desenho_pio(num_2, valor_led, pio, sm, r, g, b);
            break;
        case 3:
            desenho_pio(num_3, valor_led, pio, sm, r, g, b);
            break;    
        case 4:
            desenho_pio(num_4, valor_led, pio, sm, r, g, b);
            break;
        case 5:
            desenho_pio(num_5, valor_led, pio, sm, r, g, b);
            gpio_put(BUZZER, 1);  // Liga o buzzer
            play_tone(BUZZER, 1000, 128);
            sleep_ms(500);        // Mantém o buzzer ligado por 500 ms
            stop_tone(BUZZER);
            gpio_put(BUZZER, 0);  // Desliga o buzzer
            break;
        }
        sleep_ms(tempo);
    }
}


    

