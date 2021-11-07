#include "buttons.h"

void button_init() {
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOCEN; // enables clock of GPIOC;
    GPIOC -> MODER = GPIOC -> MODER & ~GPIO_MODER_MODE13_Msk; // sets PC13 as input;
    SYSCFG -> EXTICR[3] |= SYSCFG_EXTICR4_EXTI13_PC; // sets PC13 as interrupt line for EXTI13;
    EXTI -> IMR1 = (EXTI -> IMR1 & ~EXTI_IMR1_IM13_Msk) | EXTI_IMR1_IM13; // interrupt request from line 13 is not masked;
    EXTI -> FTSR1 = (EXTI -> FTSR1 & ~EXTI_FTSR1_FT13_Msk) | EXTI_FTSR1_FT13; // enables falling trigger;
    //__disable_irq();
    NVIC_EnableIRQ(40); // Exception 40 (EXTI15_10) enabled;
}

void EXTI15_10_IRQHandler() {
    __disable_irq();
    EXTI -> PR1 = (EXTI -> PR1 & ~EXTI_PR1_PIF13_Msk) | EXTI_PR1_PIF13;
    led_g_on();
    for(int i=0; i<20000000; i++) {
        asm volatile ("nop");
    };
    led_g_off();
    __enable_irq();
}