#include "buttons.h"
#include "clocks.h"
#include "led.h"
#include "irq.h"

int main(void) {
    clocks_init();
    led_init();
    irq_init();
    button_init();
    while(1) {};
}
