#include "uart.h"
#include "clocks.h"

int main(void) {
    clocks_init();
    uart_init(115200);
    while (1) {
        uart_putchar(uart_getchar());
    }
}