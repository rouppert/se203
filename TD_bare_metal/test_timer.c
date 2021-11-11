#include "timer.h"
#include "clocks.h"
#include "led.h"
#include "irq.h"
#include "display_frame.h"

//Fonction main pour la premiere partie du timer : fait clignoter la LED une fois par seconde.
/*
int main() {
    clocks_init();
    irq_init();
    led_init();
    timer_init(1000000);
    while (1) {};
}
*/

//Fonction main pour la deuxième partie du timer : affiche l'image envoyée à la fréquence de 60Hz.
int main() {
    display_file_60();
}