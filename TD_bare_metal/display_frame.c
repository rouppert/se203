#include "display_frame.h"

uint8_t* frame;
uint8_t* current_byte;
int end_frame = 0;

// Handler for exception raised if a byte is written in current frame;
void USART1_IRQHandler(void) {
    update_matrix();
}

void update_matrix() {
    if (*current_byte == 0xff) {
        end_frame = 0;
    }

    else {
        frame[end_frame] = *current_byte;
        end_frame ++;
        display_image(frame, end_frame++);
    }
}

void update_frame(uint8_t* end_frame_pointer) {
    uart_gets(current_byte, 1);
}

void display_file(uint8_t* file) {
    clocks_init();
    uart_init(38400);
    USART1 -> CR1 = (USART1 -> CR1 &~ USART_CR1_RXNEIE_Msk) | USART_CR1_RXNEIE;
    while (1) {
        update_frame(end_frame);
    }
}

