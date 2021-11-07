#include <stdlib.h>
#include <stdio.h>

#include "matrix.h"
#include "clocks.h"

extern uint8_t _binary_image_raw_start;
extern uint8_t _binary_image_raw_end;
extern uint8_t _binary_image_raw_size;

uint8_t image[48];


int main(void) {
    clocks_init();
    matrix_init();
    while(1) {
        display_image(&_binary_image_raw_start, &_binary_image_raw_size);
    }
};

// Pour afficher le résultat de la somme, faire p/x sum à la fin de l'exécution.
/*
uint32_t uart_sum(size_t size) {
    int i = 0;
    uint32_t sum = 0;
    while (i<1000) {
        sum += (uint32_t) uart_getchar();
        i++;
    }
    return sum;
};
*/
