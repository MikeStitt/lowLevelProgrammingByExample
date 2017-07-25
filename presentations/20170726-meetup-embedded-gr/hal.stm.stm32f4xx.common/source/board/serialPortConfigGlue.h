#ifndef __BOARD_SERIAL_PORT_CONFIG_GLUE_H
#define __BOARD_SERIAL_PORT_CONFIG_GLUE_H

#include "app/commonHeaders.h"

typedef struct {
    gpio_t pinGpio;
    uint8_t pinSource;

} serialPortPinConfig_t;

typedef struct {
    serialPortPinConfig_t tx;
    serialPortPinConfig_t rx;
    uint8_t gpioAF;
    IRQn_Type irq;
    __IO uint32_t *clkEnaP;
    uint32_t clk;
    USART_TypeDef* serialPortPtr;
    USART_InitTypeDef usartCfg;
} serialPortConfigGlue_t;

#endif // __BOARD_SERIAL_PORT_CONFIG_GLUE_H
