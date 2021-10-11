#include <stdint.h>
#include "led.h"

#define GPIOB (*(volatile uint32_t * ) 0x48000400) //defines I/O
#define RCC (*(volatile uint32_t * ) 0x4002104C) //enables clock if set to 1
#define LED (*(volatile uint32_t * ) 0x48000418) //enables led if set to one

const int pin_on = 14;
const int pin_off = 30;

void led_init(void) {
    RCC |= 1 << 1; // enables clock
    GPIOB &= ~(1<<29); // set bit 29 to 0;
    GPIOB |= 1 << 28; // set bit 28 to 1;
}

void led_g_on() {
    LED |= 1 <<pin_on;
}

void led_g_off() {
    LED |= 1 << pin_off;
}