#include "uart.h"

//Page 70 : utiliser PB6 pour USART1_TX et PB7 pour USART2_RX.
//Page 70 : utiliser AF7 pour USART1.

void uart_init(int baudrate) {
    RCC -> AHB2ENR |= RCC_AHB2ENR_GPIOBEN; // enables clock of GPIOB;
    RCC -> APB2ENR |= RCC_APB2ENR_USART1EN; // enables clock of USART1, which is on APB2 bus;
    RCC -> CCIPR &= ~RCC_CCIPR_USART1SEL; // sets USART1 bits on RCC_CCIPR register to 00, which means "PCLK selected as USART1 clock" (page 272)
    RCC -> APB2RSTR |= RCC_APB2RSTR_USART1RST; // resets USART1 (page 249)
    RCC -> APB2RSTR &= ~RCC_APB2RSTR_USART1RST; // unresets USART1 (page 249)
    GPIOB -> MODER = (GPIOB -> MODER & ~GPIO_MODER_MODE6_Msk) | GPIO_MODER_MODE6_1; //the sixth port is defined as alternate function mode (10).
    GPIOB -> MODER = (GPIOB -> MODER & ~GPIO_MODER_MODE7_Msk) | GPIO_MODER_MODE7_1; //the seventh port is defined as alternate function mode (10).
    GPIOB -> AFR[0] = (GPIOB -> AFR[0] & ~GPIO_AFRL_AFSEL6_Msk) | (7 << GPIO_AFRL_AFSEL6_Pos); //sets GPIOB_AFRL_AFSEL6 to 0111, which means AF7 (page 307)
    GPIOB -> AFR[0] = (GPIOB -> AFR[0] & ~GPIO_AFRL_AFSEL7_Msk) | (7 << GPIO_AFRL_AFSEL7_Pos); //sets GPIOB_AFRL_AFSEL7 to 0111, which means AF7 (page 307)
    USART1 -> CR1 = 0;
    USART1 -> CR2 = 0;
    USART1 -> BRR = 80000000 / baudrate; //sets baudrate to 115200(page 1388) (formula page 1349)
    //USART1 -> CR1 &= ~USART_CR1_OVER8; // Serts USART1 CR1 OVER8 bit to 0 => oversampling by 16 (page 1378)
    USART1 -> CR1 |= USART_CR1_UE; //Sets USART1 CR1 UE bit to 1 => enables USART1 (page 1377)
    USART1 -> CR1 |= USART_CR1_TE; //Sets USART1 CR1 TE bit to 1 => enables transmission (page 1379)
    USART1 -> CR1 |= USART_CR1_RE; //Sets USART1 CR1 TE bit to 1 => enables reception (page 1379)
}

void uart_putchar(char c) {
    while ((USART1 -> ISR & USART_ISR_TXE) == 0); //waits until USART1 ISR TXE is empty, which means we can start to transfer (page 1395)
    USART1 -> TDR = c;
};

char uart_getchar() {
    while ((USART1 -> ISR & USART_ISR_RXNE) == 0);
    char c = USART1 -> RDR;
    return (char) c;
}

void uart_puts(const char* s) {
    int i = 0;
    while(s[i] != '\0') {
        uart_putchar(s[i]);
        i++;
    }
    uart_putchar('\n');
}

void uart_gets(char *s, size_t size) {
    int i = 0;
    char c;
    while (i < size-1) {
        c = uart_getchar();
        if (c == '\n' || c == '\r') {
            break;
        }
        s[i] = c;
        i++;
    }
    s[i] = '\0';
}


