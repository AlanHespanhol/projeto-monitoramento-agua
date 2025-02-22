#ifndef CONFIG_MATRIZ_H  
#define CONFIG_MATRIZ_H

#include "pico/stdlib.h"
#include "pio_matrix.pio.h"

#define NUM_PIXELS 25

//variaveis para a matriz
uint32_t valor_led;
double r = 0.0, b = 0.0 , g = 0.0;


//pino de saída da matriz(ws2812) da placa 
#define OUT_PIN 7

double apagar_leds[NUM_PIXELS] =   
                        {0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0, 
                         0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0,
                         0.0, 0.0, 0.0, 0.0, 0.0};
                         
double num_0[NUM_PIXELS] =   
                        {0.35, 0.35, 0.35, 0.35, 0.35,
                         0.35, 0.35, 0.35, 0.35, 0.35, 
                         0.35, 0.35, 0.35, 0.35, 0.35,
                         0.35, 0.35, 0.35, 0.35, 0.35,
                         0.35, 0.35, 0.35, 0.35, 0.35};
                                                  
double num_1[NUM_PIXELS] =   
                        {0.0, 0.0, 0.00, 0.0, 0.0,
                         0.35, 0.35, 0.35, 0.35, 0.35, 
                         0.35, 0.35, 0.35, 0.35, 0.35,
                         0.35, 0.35, 0.35, 0.35, 0.35,
                         0.35, 0.35, 0.35, 0.35, 0.35};

double num_2[NUM_PIXELS] =   
                        {0.0, 0.0, 0.00, 0.0, 0.0,
                         0.00, 0.00, 0.00, 0.00, 0.00, 
                         0.35, 0.35, 0.35, 0.35, 0.35,
                         0.35, 0.35, 0.35, 0.35, 0.35,
                         0.35, 0.35, 0.35, 0.35, 0.35};

double num_3[NUM_PIXELS] =   
                        {0.0, 0.0, 0.00, 0.0, 0.0,
                         0.00, 0.00, 0.00, 0.00, 0.00, 
                         0.00, 0.00, 0.00, 0.00, 0.00,
                         0.35, 0.35, 0.35, 0.35, 0.35,
                         0.35, 0.35, 0.35, 0.35, 0.35};

double num_4[NUM_PIXELS] =   
                        {0.0, 0.0, 0.00, 0.0, 0.0,
                         0.00, 0.00, 0.00, 0.00, 0.00, 
                         0.00, 0.00, 0.00, 0.00, 0.00,
                         0.00, 0.00, 0.00, 0.00, 0.00,
                         0.35, 0.35, 0.35, 0.35, 0.35};

double num_5[NUM_PIXELS] =   
                        {0.0, 0.0, 0.00, 0.0, 0.0,
                         0.00, 0.00, 0.00, 0.00, 0.00, 
                         0.00, 0.00, 0.00, 0.00, 0.00,
                         0.00, 0.00, 0.00, 0.00, 0.00,
                         0.00, 0.00, 0.00, 0.00, 0.00};



//rotina para definição da intensidade de cores do led
uint32_t matrix_rgb(double b, double r, double g)
{
  unsigned char R, G, B;
  R = r * 255;
  G = g * 255;
  B = b * 255;
  return (G << 24) | (R << 16) | (B << 8);
}

//rotina para acionar a matrix de leds - ws2812b
void desenho_pio(double *desenho, uint32_t valor_led, PIO pio, uint sm, double r, double g, double b){

    for (int16_t i = 0; i < NUM_PIXELS; i++) {
        
            valor_led = matrix_rgb(desenho[24-i], r=0.0, g=0.0);
            pio_sm_put_blocking(pio, sm, valor_led);
    }
}


#endif