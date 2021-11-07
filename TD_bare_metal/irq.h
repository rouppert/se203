#ifndef _IRQ_H_
#define _IRQ_H_

#include "stm32l475xx.h"
#include <stddef.h>
#include "core_cm4.h"

#define MAKE_DEFAULT_HANDLER(handler_name) void __attribute__((weak)) (handler_name)(void) {__disable_irq(); while(1) {};}

void startHandler(void);
void irq_init(void);

#endif
