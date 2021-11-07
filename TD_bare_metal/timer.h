#ifndef _TIMER_H_
#define _TIMER_H_

#include "irq.h"
#include "led.h"

void timer_init(int max_us);
void TIM2_IRQHandler();

#endif