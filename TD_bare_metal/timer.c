#include "timer.h"

int led_on = 0;

void timer_init(int max_us) {
    RCC -> APB1ENR1 = (RCC -> APB1ENR1 & ~RCC_APB1ENR1_TIM2EN_Msk) | RCC_APB1ENR1_TIM2EN;
    TIM2 -> SR = 0;
    TIM2 -> CNT = 0;
    TIM2 -> CR1 = (TIM2 -> CR1 & ~TIM_CR1_CMS_Msk);
    TIM2 -> CR1 = (TIM2 -> CR1 & ~TIM_CR1_DIR_Msk) & ~TIM_CR1_DIR;
    TIM2 -> PSC = (80000000/480000) - 1;
    TIM2 -> ARR = max_us;
    TIM2 -> CR1 = (TIM2 -> CR1 & ~TIM_CR1_UDIS_Msk);
    TIM2 -> DIER = (TIM2 -> DIER & ~TIM_DIER_UIE_Msk) | TIM_DIER_UIE;
    NVIC_EnableIRQ(28);
    TIM2 -> CR1 = (TIM2 -> CR1 & ~TIM_CR1_CEN_Msk) | TIM_CR1_CEN;
}

// Handler alternatif pour TIM2, permettant de faire clignoter la led une fois par seconde.
/*
void TIM2_IRQHandler() {
    __disable_irq();
    if (led_on == 0) {
        led_g_on();
        led_on = 1;
    }
    else {
        led_g_off();
        led_on = 0;
    }
    TIM2 -> SR = (TIM2 -> SR & ~TIM_SR_UIF_Msk);
    __enable_irq();
}
*/

