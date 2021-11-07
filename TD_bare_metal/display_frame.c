#include "display_frame.h"
#include "clocks.h"
#include "irq.h"

uint8_t frame[192];
int end_frame;

// Handler for exception raised if a byte is written in current frame;
void USART1_IRQHandler(void) {
    __disable_irq();
    update_matrix();
    __enable_irq();
}

void update_matrix() {
    char current_byte = uart_getchar();
    if ((current_byte == 0xff) | (end_frame == 256)) {
        end_frame = 0;
    }

    else {
        frame[end_frame] = current_byte;
        end_frame ++;
    }
}

void display_file() {
    clocks_init();
    irq_init();
    uart_init(2000);
    NVIC_EnableIRQ(37);
    matrix_init();
    deactivate_rows();
    USART1 -> CR1 = (USART1 -> CR1 &~ USART_CR1_RXNEIE_Msk) | USART_CR1_RXNEIE;
    end_frame = 0;
    while (1) {
        display_image(frame, end_frame);
    }
}

