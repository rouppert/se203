#include <stdint.h>
#include "led.h"


#define RCC (*(volatile uint32_t * ) 0x4002104C) //enables clock if set to 1

#define GPIOB (*(volatile uint32_t * ) 0x48000400) //defines I/O for GPIO B
#define LEDB (*(volatile uint32_t * ) 0x48000418) //enables led if set to one


#define GPIOC (*(volatile uint32_t * ) 0x48000800) //defines I/O for GPIO C
#define LEDC (*(volatile uint32_t * ) 0x48000818) //enables led if set to one

const int pinb_on = 14;
const int pinb_off = 30;
const int pinc_on = 9;
const int pinc_off = 25;

void led_init(void) {
    RCC |= 1 << 1; // enables clock of GPIOB;
    RCC |= 1 << 2; // enables clock of GPIOC;
    GPIOB &= ~(1<<29); // set bit 29 to 0;
    GPIOB |= 1 << 28; // set bit 28 to 1;
    GPIOC &= ~(1<<19); // set bit 19 to 0;
    GPIOC |= 1 << 18; // set bit 18 to 1;

}

void led_g_on() {
    LEDB |= 1 <<pinb_on;
}

void led_g_off() {
    LEDB |= 1 << pinb_off;
    
}

void led(state_t state) {
    switch (state) {
        case LED_YELLOW:
        {
            LEDC |= 1 <<pinc_on;
            GPIOC &= ~(1<<19); // set bit 19 to 0;
            GPIOC |= 1 << 18; // set bit 18 to 1;
        };

        case LED_BLUE:
        {
            LEDC |= 1 <<pinc_off;
            GPIOC &= ~(1<<19); // set bit 19 to 0;
            GPIOC |= 1 << 18; // set bit 18 to 1;
        };

        case LED_GREEN:
        {
            led_g_on();
            led_g_off();
        }

        case LED_OFF:
        {
            GPIOC &= ~(1<<18); // set bit 18 to 0;
            GPIOC &= ~(1<<19); // set bit 19 to 0;
        };
    }
}