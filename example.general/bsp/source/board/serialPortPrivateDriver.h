#ifndef __BOARD_SERIAL_PORT_PRIVATE_DRIVER_H
#define __BOARD_SERIAL_PORT_PRIVATE_DRIVER_H

#include "app/commonHeaders.h"
#include "board/serialPortList.h"

void serialPortPrivateInitSpid(serialPortId_t spid);
void serialPortPrivateEnableInterrupt(serialPortId_t spid, uint8_t PreemptionPriority, uint8_t SubPriority);
void serialPortPrivateWaitWhileFull(serialPortId_t spid);
void serialPortPrivateWaitWhileTxing(serialPortId_t spid);
void serialPortPrivateTxByte(serialPortId_t spid, uint8_t c);
void serialPortPrivateEnableRxDataInterrupt(serialPortId_t spid);
void serialPortPrivateClearPendingRxDataInterrupt(serialPortId_t spid);

bool serialPortPrivateRxDataAvailToLookAt(serialPortId_t spid);
bool serialPortPrivateRxByte(serialPortId_t spid, uint8_t *rxBytePtr);

#define SERIAL_PORT_FUNCTION_POINTERS \
    { \
        .serialPortInitSpidFp = serialPortPrivateInitSpid, \
        .serialPortEnableInterruptFp = serialPortPrivateEnableInterrupt, \
        .serialPortWaitWhileFullFp = serialPortPrivateWaitWhileFull, \
        .serialPortWaitWhileTxingFp = serialPortPrivateWaitWhileTxing, \
        .serialPortTxByteFp = serialPortPrivateTxByte, \
        .serialPortEnableRxDataInterruptFp = serialPortPrivateEnableRxDataInterrupt, \
        .serialPortClearPendingRxDataInterruptFp = serialPortPrivateClearPendingRxDataInterrupt, \
        .serialPortRxDataAvailToLookAtFp = serialPortPrivateRxDataAvailToLookAt, \
        .serialPortRxByteFp = serialPortPrivateRxByte, \
    }

#endif 
