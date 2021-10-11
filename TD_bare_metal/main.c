#include <stdlib.h>
#include "led.h"


int main() {
    led_init();
    led(LED_BLUE);
    led(LED_YELLOW);
    led(LED_GREEN);
    led(LED_OFF);
    led(LED_BLUE);
    led(LED_YELLOW);
    led(LED_GREEN);
    led(LED_OFF);
    led(LED_BLUE);
    led(LED_YELLOW);
    led(LED_GREEN);
    led(LED_OFF);
}
