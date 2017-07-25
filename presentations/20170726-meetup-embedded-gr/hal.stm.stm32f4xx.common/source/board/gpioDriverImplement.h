#ifndef __BOARD_GPIO_DRIVER_IMPLEMENT_H
#define __BOARD_GPIO_DRIVER_IMPLEMENT_H

#include "board/gpioConfig.h"

#include "stm32f4xx_gpio.h"
#include "stm32f4xx_rcc.h"


static inline void gpioImplementInitGpioDoIt(const gpioConfig_t *gpioSetup_p)
{
    *(gpioSetup_p->halConfigGlue.clkEna_p) |= gpioSetup_p->halConfigGlue.clk;

    gpioSetOutCmd(gpioSetup_p->index, gpioSetup_p->initialOutputValue);

    GPIO_Init(gpioSetup_p->halConfigGlue.gpioPort_p, (GPIO_InitTypeDef *)&gpioSetup_p->halConfigGlue.gpioInit);

    if (gpioSetup_p->halConfigGlue.gpioInit.GPIO_Mode == GPIO_Mode_AF) {
        GPIO_PinAFConfig(gpioSetup_p->halConfigGlue.gpioPort_p, gpioSetup_p->halConfigGlue.gpioPortSource, gpioSetup_p->halConfigGlue.afSelection);
    }
}


static inline void gpioImplementSetOutCmdHighDoIt(gpio_t gpio)
{
    gpioConfig[gpio].halConfigGlue.gpioPort_p->BSRRL = gpioConfig[gpio].halConfigGlue.gpioInit.GPIO_Pin;
}


static inline void gpioImplementSetOutCmdLowDoIt(gpio_t gpio)
{
    gpioConfig[gpio].halConfigGlue.gpioPort_p->BSRRH = gpioConfig[gpio].halConfigGlue.gpioInit.GPIO_Pin;
}


static inline int gpioImplementGetOutCmdDoIt(gpio_t gpio)
{
    return gpioConfig[gpio].halConfigGlue.gpioPort_p->ODR & gpioConfig[gpio].halConfigGlue.gpioInit.GPIO_Pin ? 1 : 0;
}


static inline int gpioImplementReadInDoIt(gpio_t gpio)
{
    return gpioConfig[gpio].halConfigGlue.gpioPort_p->IDR & gpioConfig[gpio].halConfigGlue.gpioInit.GPIO_Pin ? 1 : 0;
}

#endif
