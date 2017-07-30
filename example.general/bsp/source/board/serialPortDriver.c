#include "app/commonHeaders.h"

void serialPortInit(void)
{
    for (int i=0; i<serialPortConfigSize; i++) {
	isSpidWithinRangeMayNotReturn(i);
        if (serialPortConfig[i].autoInitializeOnPowerUp) {
	    serialPortInitSpid(i);
        }
    }
}


extern inline bool isSpidWithinRange(serialPortId_t spid);

extern inline void isSpidWithinRangeMayNotReturn(serialPortId_t spid);

extern inline bool isSerialPortInitialized(serialPortId_t spid);

extern inline void isSpidWithinRangeAndInitializedMayNotReturn(serialPortId_t spid);

extern inline void serialPortInitSpid(serialPortId_t spid);

extern inline void serialPortEnableInterrupt(serialPortId_t spid, uint8_t PreemptionPriority, uint8_t SubPriority);

extern inline void serialPortWaitWhileFull(serialPortId_t spid);

extern inline void serialPortWaitWhileTxing(serialPortId_t spid);

extern inline void serialPortTxByte(serialPortId_t spid, uint8_t c);

extern inline void serialPortEnableRxDataInterrupt(serialPortId_t spid);

extern inline void serialPortClearPendingRxDataInterrupt(serialPortId_t spid);

extern inline bool serialPortRxDataAvailToLookAt(serialPortId_t spid);

extern inline bool serialPortRxByte(serialPortId_t spid, uint8_t *rxBytePtr);


