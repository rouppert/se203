#ifndef UART_H
#define UART_H

#include "stm32l475xx.h"
#include <stddef.h>

void uart_init();
void uart_putchar(char c);
char uart_getchar();
void uart_puts(const char* s);
void uart_gets(char *s, size_t size);

#endif