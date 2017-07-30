
#ifndef __BOARD_GPIOCONFIG_H
#define __BOARD_GPIOCONFIG_H

#include "app/commonHeaders.h"
#include "board/gpioList.h"
#include "board/gpioConfigGlue.h"

typedef struct {
    gpio_t index;
    const char* name;
    bool autoInitializeOnPowerUp;
    uint8_t initialOutputValue;
    gpioConfigGlue_t halConfigGlue;
} gpioConfig_t;

extern const gpioConfig_t gpioConfig[];
extern const size_t gpioConfigSize;


#endif
