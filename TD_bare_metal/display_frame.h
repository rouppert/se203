#ifndef _DISPLAY_FRAME_H_
#define _DISPLAY_FRAME_H_

#include "uart.h"
#include "matrix.h"
#include "irq.h"

void USART1_IRQHandler(void);
void update_frame(void);
void update_matrix(void);
void display_file(void);
void display_file_60(void);
void TIM2_IRQHandler(void);

#endif