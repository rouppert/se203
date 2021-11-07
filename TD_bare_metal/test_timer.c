#include "timer.h"
#include "clocks.h"
#include "led.h"
#include "irq.h"

int main() {
    clocks_init();
    irq_init();
    led_init();
    timer_init(1000);
    while (1) {};
}