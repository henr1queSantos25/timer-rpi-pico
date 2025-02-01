#include <stdio.h>
#include "pico/stdlib.h"
#include "hardware/timer.h"

// DEFINIÇÃO DOS PINOS
#define LED_GREEN 11
#define LED_YELLOW 12
#define LED_RED 13

// VARIÁVEL RESPONSÁVEL PELA TROCA DE LEDS
uint volatile counter = 1;

// PROTÓTIPOS
void initLEDs();
void setLEDs(bool g, bool y, bool r);

// FUNÇÃO DE CALLBACK CHAMADA A CADA 3 SEGUNDOS
bool repeating_timer_callback(struct repeating_timer *t){
    if(counter == 1){
        setLEDs(0, 0, 1);
    }
    else if(counter == 2){
        setLEDs(0, 1, 0);
    }
    else{
        setLEDs(1, 0, 0);
    }
    counter++;

    if(counter > 3){
        counter = 1;
    }

    return true;
}

int main()
{
    stdio_init_all();
    initLEDs(); //INICIALIZA OS LEDS E OS CONFIGURA COMO SAÍDA

    struct repeating_timer timer;//ESTA ESTRUTURA ARMAZENARÁ INFORMAÇÕES SOBRE O TEMPORIZADOR CONFIGURADO.

    add_repeating_timer_ms(3000, repeating_timer_callback, NULL, &timer); //CONFIGURA O TEMPORIZADOR PARA CHAMAR A FUNÇÃO DE CALLBACK A CADA 3 SEGUNDOS.

    while (true) {
        //LOOP PRINCIPAL
        printf("Ola, Embarcatech!\n");
        sleep_ms(1000);
    }
    return 0;
}

//FUNÇÃO QUE INICIALIZA E CONFIGURA OS LEDS
void initLEDs(){
    gpio_init(LED_GREEN);
    gpio_set_dir(LED_GREEN, GPIO_OUT);
    gpio_init(LED_YELLOW);
    gpio_set_dir(LED_YELLOW, GPIO_OUT);
    gpio_init(LED_RED);
    gpio_set_dir(LED_RED, GPIO_OUT);
}

//FUNÇÃO QUE SETA QUAIS LEDS ESTARÃO LIGADOS OU APAGADOS
void setLEDs(bool g, bool y, bool r){
    gpio_put(LED_GREEN, g);
    gpio_put(LED_YELLOW, y);
    gpio_put(LED_RED, r);
}
