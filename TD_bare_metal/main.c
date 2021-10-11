#include <stdlib.h>
#include "led.h"


int main() {
    led_init();
    int i = 0;
    while (i++ < 15) {
        led_g_on();
        for (int i=0; i<15; i++) asm volatile("nop");
        led_g_off();
    }      
}
