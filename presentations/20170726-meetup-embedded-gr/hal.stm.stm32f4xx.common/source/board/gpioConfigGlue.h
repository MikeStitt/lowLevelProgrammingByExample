#ifndef __BOARD_GPIO_CONFIGGLUE_H
#define __BOARD_GPIO_CONFIGGLUE_H

#include "app/commonHeaders.h"

typedef struct {
    GPIO_TypeDef*    gpioPort_p;
    GPIO_InitTypeDef gpioInit;
    __IO uint32_t    *clkEna_p;
    uint32_t         clk;
    uint16_t         gpioPortSource;
    uint16_t         afSelection;
    uint8_t          extiPortSource;
    uint8_t          extiPinSource;
    uint32_t         extiLine;

} gpioConfigGlue_t;

#endif 
