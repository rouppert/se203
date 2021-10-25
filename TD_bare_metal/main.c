#include <stdlib.h>

#include "uart.h"
#include "clocks.h"

uint32_t uart_sum(size_t size);
uint32_t sum;

int main() {
    clocks_init();
    uart_init();
    sum = uart_sum(1000);
};

// Pour afficher le résultat de la somme, faire p/x sum à la fin de l'exécution.

uint32_t uart_sum(size_t size) {
    int i = 0;
    uint32_t sum = 0;
    while (i<1000) {
        sum += (uint32_t) uart_getchar();
        i++;
    }
    return sum;
};

