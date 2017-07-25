#ifndef __SERIAL_PORT_FUNCTION_JUMP_TABLE_GLUE_H
#define __SERIAL_PORT_FUNCTION_JUMP_TABLE_GLUE_H

#include "board/serialPortList.h"
#include <stdint.h>
#include <stdbool.h>

typedef void (*serialPortInitSpidFp_t)(serialPortId_t spid);
typedef void (*serialPortEnableInterruptFp_t)(serialPortId_t spid, uint8_t PreemptionPriority, uint8_t SubPriority);
typedef void (*serialPortWaitWhileFullFp_t)(serialPortId_t spid);
typedef void (*serialPortWaitWhileTxingFp_t)(serialPortId_t spid);
typedef void (*serialPortTxByteFp_t)(serialPortId_t spid, uint8_t c);
typedef void (*serialPortEnableRxDataInterruptFp_t)(serialPortId_t spid);
typedef void (*serialPortClearPendingRxDataInterruptFp_t)(serialPortId_t spid);
typedef bool (*serialPortRxDataAvailToLookAtFp_t)(serialPortId_t spid);
typedef bool (*serialPortRxByteFp_t)(serialPortId_t spid, uint8_t *rxBytePtr);

typedef struct {
    serialPortInitSpidFp_t serialPortInitSpidFp;
    serialPortEnableInterruptFp_t serialPortEnableInterruptFp;
    serialPortWaitWhileFullFp_t serialPortWaitWhileFullFp;
    serialPortWaitWhileTxingFp_t serialPortWaitWhileTxingFp;
    serialPortTxByteFp_t serialPortTxByteFp;
    serialPortEnableRxDataInterruptFp_t serialPortEnableRxDataInterruptFp;
    serialPortClearPendingRxDataInterruptFp_t serialPortClearPendingRxDataInterruptFp;
    serialPortRxDataAvailToLookAtFp_t serialPortRxDataAvailToLookAtFp;
    serialPortRxByteFp_t serialPortRxByteFp;
} spJumpTableFunctions_t;


#endif
