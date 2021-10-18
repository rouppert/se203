#include <stdint.h>
#include "led.h"
#include "stm32l475xx.h"

//RCC devient RCC_AHB2ENR
//Pour GPIOB : RCC_AHB2ENR_GPIOB
//Pour GPIOB : RCC_AHB2ENR_GPIOC

//GPIOB devient GPIOB_MODER
//Pour définir GPIOB en sortie GPIOB |= GPIO_MODER_MODE14
//Pour définir GPIOC en sortie GPIOC |= CPIO_MODER_MODE9

//Pour allumer la LED sur GPIOB GPIOB_BSRR |= GPIO_BSRR_BS14


//#define RCC (*(volatile uint32_t * ) 0x4002104C) //enables clock if set to 1

//#define GPIOB (*(volatile uint32_t * ) 0x48000400) //defines I/O for GPIO B
//#define LEDB (*(volatile uint32_t * ) 0x48000418) //enables led if set to one


//#define GPIOC (*(volatile uint32_t * ) 0x48000800) //defines I/O for GPIO C
//#define LEDC (*(volatile uint32_t * ) 0x48000818) //enables led if set to one

const int pinb_on = 14;
const int pinb_off = 30;
const int pinc_on = 9;
const int pinc_off = 25;

void led_init(void) {
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOBEN_Msk; // enables clock of GPIOB;
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOCEN_Msk; // enables clock of GPIOC;
    GPIOB -> MODER |= GPIO_MODER_MODE14_Msk; // The 14th port is defined as output.
    GPIOC -> MODER |= GPIO_MODER_MODE9_Msk; // The nineth port is defined as output.

}

void led_g_on() {
    GPIOB -> BSRR |= 1 <<pinb_on;
}

void led_g_off() {
    GPIOB -> BSRR |= 1 << pinb_off;
    
}

void led(state_t state) {
    switch (state) {
        case LED_YELLOW:
        {
            GPIOC -> BSRR |= 1 <<pinc_on;
            GPIOC -> MODER |= GPIO_MODER_MODE9_Msk; // The nineth port is defined as output.
        };

        case LED_BLUE:
        {
            GPIOC -> BSRR |= 1 <<pinc_off;
            GPIOC -> MODER |= GPIO_MODER_MODE9_Msk; // The nineth port is defined as output.
        };

        case LED_GREEN:
        {
            led_g_on();
            led_g_off();
        }

        case LED_OFF:
        {
            GPIOC -> MODER &= ~(1<<18); // set bit 18 to 0;
            GPIOC -> MODER &= ~(1<<19); // set bit 19 to 0;
        };
    }
}