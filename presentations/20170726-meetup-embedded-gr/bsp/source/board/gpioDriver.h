#ifndef GPIODRIVER_H_
#define GPIODRIVER_H_

#include "board/gpioList.h"

void gpioInitGpio(gpio_t gpio);
void gpioInit(void);
void gpioSetOutCmdHigh(gpio_t gpio);
void gpioSetOutCmdLow(gpio_t gpio);
void gpioSetOutCmd(gpio_t gpio, int val);
int gpioGetOutCmd(gpio_t gpio);
int gpioReadIn(gpio_t gpio);

#endif
