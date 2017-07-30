#ifndef __BOARD_SERIAL_PORT_CONFIG_H
#define __BOARD_SERIAL_PORT_CONFIG_H

#include "app/commonHeaders.h"
#include "board/gpioConfig.h"
#include "board/serialPortList.h"
#include "board/serialPortConfigGlue.h"
#include "board/serialPortFunctionJumpTableGlue.h"


typedef struct {
    serialPortId_t index;
    const char* name;
    bool autoInitializeOnPowerUp;
    serialPortConfigGlue_t halConfigGlue;
    spJumpTableFunctions_t spJumpTableFunctions;
} serialPortConfig_t;

extern const serialPortConfig_t serialPortConfig[];
extern const size_t serialPortConfigSize;
extern uint32_t gSerialPortInitializedList[];

#endif // __BOARD_SERIAL_PORT_CONFIG_H
