#include "display_frame.h"
#include "clocks.h"
#include "irq.h"
#include "timer.h"
#include "led.h"

uint8_t frame[192];
int end_frame;
int row_number;
rgb_color row[8];
uint32_t reg;

//Est déclenché dès qu'un octet est reçu par l'UART.
void USART1_IRQHandler(void) {
    __disable_irq();
    update_matrix();
    reg = USART1->ISR;
    __enable_irq();
}

//Est appelée par USART1_IRQHandler. Met à jour l'image à afficher en fonction du dernier octet reçu.
void update_matrix() {
    char current_byte = uart_getchar();    
    if ((current_byte == 0xff) | (end_frame == 192)) {
        end_frame = 0;
    }

    else {
        frame[end_frame] = current_byte;
        end_frame ++;
    }
}

//Est utilisé pour le test de la partie UART + IRQ + LED : affiche le fichier envoyé à l'UART.
void display_file() {
    clocks_init();
    irq_init();
    uart_init(38400);
    NVIC_EnableIRQ(37);
    matrix_init();
    deactivate_rows();
    USART1 -> CR1 = (USART1 -> CR1 &~ USART_CR1_RXNEIE_Msk) | USART_CR1_RXNEIE;
    end_frame = 0;
    while (1) {
        display_image(frame, end_frame);
    }
}

//Est utilisé pour le test de la partie timer : affiche le fichier envoyé à l'UART à la fréquence de 60Hz.
void display_file_60() {
    end_frame = 0;
    row_number = 0;
    for (int i = 0; i<192; i++) {
        frame[i] = 0;
    }
    for (int j = 0; j<8; j++) {
        row[j].r = 0;
        row[j].g = 0;
        row[j].b = 0;
    }
    clocks_init();
    irq_init();
    uart_init(38400);
    NVIC_EnableIRQ(37);
    matrix_init();
    deactivate_rows();
    timer_init(1000);
    USART1 -> CR1 = (USART1 -> CR1 &~ USART_CR1_RXNEIE_Msk) | USART_CR1_RXNEIE;
    while (1) {
        int i = 24*row_number;
        int pixel_number = 0;
        while ((i < (8+1) * 3 * row_number) | (i < end_frame)) {
            row[pixel_number].r = 3;
            i++;
            row[pixel_number].g = 0;
            i++;
            row[pixel_number].b = 0;
            i++;
            pixel_number++;
        }
        if (row_number == 7) {
            row_number = 0;
        }
    }
}

// Est declenche tous les 1/480e de seconde, et affiche une des colonnes de l'image reçue.
void TIM2_IRQHandler() {
    //__disable_irq();
    deactivate_rows();
    mat_set_row(row_number, row);
    row_number++;
    TIM2 -> SR = (TIM2 -> SR & ~TIM_SR_UIF_Msk);
    //__enable_irq();
}
