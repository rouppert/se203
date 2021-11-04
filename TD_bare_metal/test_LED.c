#include "led.h"
#include "clocks.h"

int main(void) {
    clocks_init();
    led_init();
    led_g_on();
    for(int i=0; i<10; i++) {
        asm volatile ("nop");
    }
    led_g_off();
    for(int i=0; i<10; i++) {
        asm volatile ("nop");
    }
    led(LED_YELLOW);
    for(int i=0; i<10; i++) {
        asm volatile ("nop");
    }
    led(LED_BLUE);
    for(int i=0; i<10; i++) {
        asm volatile ("nop");
    }
    led(LED_OFF);
}