#ifndef _DISPLAY_FRAME_H_
#define _DISPLAY_FRAME_H_

#include "uart.h"
#include "matrix.h"
#include "irq.h"

void USART1_IRQHandler(void);
void update_frame(uint8_t* end_frame_pointer);
void update_matrix();
void display_file(uint8_t* file);

#endif