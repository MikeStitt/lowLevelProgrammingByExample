#include "app/commonHeaders.h"

#include "board/serialPortDriver.h"
#include "board/serialPortPrivateDriver.h"
#include "board/serialPortConfig.h"
#include "board/gpioDriver.h"

void serialPortPrivateInitSingleSpid(const serialPortConfig_t *serialPortSetupPtr)
{

    *(serialPortSetupPtr->halConfigGlue.clkEnaP) |= serialPortSetupPtr->halConfigGlue.clk;
    gpioInitGpio(serialPortSetupPtr->halConfigGlue.tx.pinGpio);
    gpioInitGpio(serialPortSetupPtr->halConfigGlue.rx.pinGpio);

    GPIO_PinAFConfig(gpioConfig[serialPortSetupPtr->halConfigGlue.tx.pinGpio].halConfigGlue.gpioPort_p, serialPortSetupPtr->halConfigGlue.tx.pinSource, serialPortSetupPtr->halConfigGlue.gpioAF);

    GPIO_PinAFConfig(gpioConfig[serialPortSetupPtr->halConfigGlue.rx.pinGpio].halConfigGlue.gpioPort_p, serialPortSetupPtr->halConfigGlue.rx.pinSource, serialPortSetupPtr->halConfigGlue.gpioAF);

    USART_Init(serialPortSetupPtr->halConfigGlue.serialPortPtr, (USART_InitTypeDef*)&serialPortSetupPtr->halConfigGlue.usartCfg);

    USART_Cmd(serialPortSetupPtr->halConfigGlue.serialPortPtr, ENABLE);
}


void serialPortPrivateInitSpid(serialPortId_t spid)
{
    isSpidWithinRangeMayNotReturn(spid); 
    const serialPortConfig_t *serialPortConfigPtr = &serialPortConfig[spid];

    serialPortPrivateInitSingleSpid(serialPortConfigPtr);
    gSerialPortInitializedList[spid] = SERIAL_PORT_IS_INITIALIZED_MAGIC_VALUE;
}


void serialPortPrivateEnableInterrupt(serialPortId_t spid, uint8_t PreemptionPriority, uint8_t SubPriority)
{
    isSpidWithinRangeAndInitializedMayNotReturn(spid);
    const serialPortConfig_t *serialPortConfigPtr = &serialPortConfig[spid];

    NVIC_InitTypeDef nvicInitS;
    nvicInitS.NVIC_IRQChannel = serialPortConfigPtr->halConfigGlue.irq;
    nvicInitS.NVIC_IRQChannelPreemptionPriority = PreemptionPriority;
    nvicInitS.NVIC_IRQChannelSubPriority = SubPriority;
    nvicInitS.NVIC_IRQChannelCmd = ENABLE;
    NVIC_Init(&nvicInitS);
}


void serialPortPrivateWaitWhileFull(serialPortId_t spid)
{
    isSpidWithinRangeMayNotReturn(spid); 
    if (!isSerialPortInitialized(spid)) return;

    while (USART_GetFlagStatus(serialPortConfig[spid].halConfigGlue.serialPortPtr, USART_FLAG_TXE) != SET) {
       // Wait
    }
}


void serialPortPrivateWaitWhileTxing(serialPortId_t spid)
{
    isSpidWithinRangeMayNotReturn(spid); 
    if (!isSerialPortInitialized(spid)) return;

    while (USART_GetFlagStatus(serialPortConfig[spid].halConfigGlue.serialPortPtr, USART_FLAG_TC) == RESET) {
        // Wait
    }
}


void serialPortPrivateTxByte(serialPortId_t spid, uint8_t c)
{
    isSpidWithinRangeMayNotReturn(spid); 
    if (!isSerialPortInitialized(spid)) return;

    USART_SendData(serialPortConfig[spid].halConfigGlue.serialPortPtr, c);
}


void serialPortPrivateEnableRxDataInterrupt(serialPortId_t spid)
{
    isSpidWithinRangeMayNotReturn(spid); 
    if (!isSerialPortInitialized(spid)) return;
    USART_ITConfig(serialPortConfig[spid].halConfigGlue.serialPortPtr, USART_IT_RXNE, ENABLE);
}


void serialPortPrivateClearPendingRxDataInterrupt(serialPortId_t spid)
{
    isSpidWithinRangeMayNotReturn(spid); 
    if (!isSerialPortInitialized(spid)) return;
    USART_ClearITPendingBit(serialPortConfig[spid].halConfigGlue.serialPortPtr, USART_IT_RXNE);
}


bool serialPortPrivateRxDataAvailToLookAt(serialPortId_t spid)
{
    isSpidWithinRangeMayNotReturn(spid); 
    if (!isSerialPortInitialized(spid)) return false;

    uint16_t statusRegister = serialPortConfig[spid].halConfigGlue.serialPortPtr->SR;

    return (statusRegister&USART_FLAG_RXNE);
}


bool serialPortPrivateRxByte(serialPortId_t spid, uint8_t *rxBytePtr)
{
    isSpidWithinRangeMayNotReturn(spid); 
    if (!isSerialPortInitialized(spid)) return false;

    uint16_t statusRegister = serialPortConfig[spid].halConfigGlue.serialPortPtr->SR;

    if (statusRegister & USART_FLAG_RXNE) {
        uint16_t rxData = USART_ReceiveData(serialPortConfig[spid].halConfigGlue.serialPortPtr);
        if (statusRegister & USART_FLAG_ORE) {
            // ignore overrun errors
        }
        if (statusRegister & (USART_FLAG_NE|USART_FLAG_FE|USART_FLAG_PE)) {
            return false;
        }
        if (rxBytePtr) {
            *rxBytePtr = rxData;
        }
        return true;
    }
    return false;
}
