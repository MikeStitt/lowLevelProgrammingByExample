#include "board/gpioDriver.h"
#include "board/gpioDriverImplement.h"
#include "board/gpioConfig.h"

static inline bool gpioIsGpioValid(gpio_t gpio)
{
    return (gpio>=0) && (gpio<gpioConfigSize) && (gpioConfig[gpio].index == gpio);
}

void gpioInitGpio(gpio_t gpio)
{
    if (gpioIsGpioValid(gpio)) {
        gpioImplementInitGpioDoIt(&gpioConfig[gpio]);
    } else {
            // todo add failure processing
    }

}


void gpioInit(void)
{
    for (int i=0; i<gpioConfigSize; i++) {
        gpioInitGpio((gpio_t)i);
    }
}


void gpioSetOutCmdHigh(gpio_t gpio)
{
    if (!gpioIsGpioValid(gpio)) {
        // todo add failure processing
    } else {
        gpioImplementSetOutCmdHighDoIt(gpio);
    }
}


void gpioSetOutCmdLow(gpio_t gpio)
{
    if (!gpioIsGpioValid(gpio)) {
        // todo add failure processing
    } else {
        gpioImplementSetOutCmdLowDoIt(gpio);
    }
}


void gpioSetOutCmd(gpio_t gpio, int val)
{
    if (val) {
        gpioImplementSetOutCmdHighDoIt(gpio);
    } else {
        gpioImplementSetOutCmdLowDoIt(gpio);
    }
}


int gpioGetOutCmd(gpio_t gpio)
{
    if (!gpioIsGpioValid(gpio)) {
        // todo add failure processing
    }
    return gpioImplementGetOutCmdDoIt(gpio);
    // todo does this CPU support getting the output command?
}

int gpioReadIn(gpio_t gpio)
{
    if (!gpioIsGpioValid(gpio)) {
        // todo add failure processing
    }
    return gpioImplementReadInDoIt(gpio);
}
