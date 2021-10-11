#ifndef _LED_H_
#define _LED_H_

typedef enum {LED_OFF, LED_YELLOW, LED_BLUE, LED_GREEN} state_t;

void led_init(void);
void led_g_on();
void led_g_off();
void led(state_t);

#endif