#ifndef __BOARD_SERIAL_PORT_DRIVER_H
#define __BOARD_SERIAL_PORT_DRIVER_H

#include "app/commonHeaders.h"
#include "board/serialPortList.h"
#include "board/serialPortConfig.h"


void serialPortInit(void);


static inline bool isSpidWithinRange(serialPortId_t spid) {
  return (spid>=0) && (spid<serialPortConfigSize) && (serialPortConfig[spid].index==spid);
}

static inline void isSpidWithinRangeMayNotReturn(serialPortId_t spid) {
    if (!isSpidWithinRange(spid)) {
        // @todo add failure handlers
        while (1) {
        }
    }
}

#define SERIAL_PORT_IS_INITIALIZED_MAGIC_VALUE 0xF1D01152

static inline bool isSerialPortInitialized(serialPortId_t spid) {
    return (gSerialPortInitializedList[spid]==SERIAL_PORT_IS_INITIALIZED_MAGIC_VALUE);
}

static inline void isSpidWithinRangeAndInitializedMayNotReturn(serialPortId_t spid) {

    if (!(isSpidWithinRange(spid) && isSerialPortInitialized(spid))) {
        // @todo add failure handlers
        while (1) {
        }
    }
}


static inline void serialPortInitSpid(serialPortId_t spid) {
    isSpidWithinRangeMayNotReturn(spid);
    serialPortConfig[spid].spJumpTableFunctions.serialPortInitSpidFp(spid);
}

static inline void serialPortEnableInterrupt(serialPortId_t spid, uint8_t PreemptionPriority, uint8_t SubPriority) {
   isSpidWithinRangeAndInitializedMayNotReturn(spid);
   serialPortConfig[spid].spJumpTableFunctions.serialPortEnableInterruptFp(spid, PreemptionPriority, SubPriority);
}

static inline void serialPortWaitWhileFull(serialPortId_t spid) {
    isSpidWithinRangeAndInitializedMayNotReturn(spid);
    serialPortConfig[spid].spJumpTableFunctions.serialPortWaitWhileFullFp(spid);
}

static inline void serialPortWaitWhileTxing(serialPortId_t spid) {
    isSpidWithinRangeAndInitializedMayNotReturn(spid);
    serialPortConfig[spid].spJumpTableFunctions.serialPortWaitWhileTxingFp(spid);
}

static inline void serialPortTxByte(serialPortId_t spid, uint8_t c) {
    isSpidWithinRangeAndInitializedMayNotReturn(spid);
    serialPortConfig[spid].spJumpTableFunctions.serialPortTxByteFp(spid, c);
}

static inline void serialPortEnableRxDataInterrupt(serialPortId_t spid) {
    isSpidWithinRangeAndInitializedMayNotReturn(spid);
    serialPortConfig[spid].spJumpTableFunctions.serialPortEnableRxDataInterruptFp(spid);
}

static inline void serialPortClearPendingRxDataInterrupt(serialPortId_t spid) {
    isSpidWithinRangeAndInitializedMayNotReturn(spid);
    serialPortConfig[spid].spJumpTableFunctions.serialPortClearPendingRxDataInterruptFp(spid);
}

static inline bool serialPortRxDataAvailToLookAt(serialPortId_t spid) {
    isSpidWithinRangeAndInitializedMayNotReturn(spid);
    return serialPortConfig[spid].spJumpTableFunctions.serialPortRxDataAvailToLookAtFp(spid);
}

static inline bool serialPortRxByte(serialPortId_t spid, uint8_t *rxBytePtr) {
    isSpidWithinRangeAndInitializedMayNotReturn(spid);
    return serialPortConfig[spid].spJumpTableFunctions.serialPortRxByteFp(spid, rxBytePtr);
}

#endif
