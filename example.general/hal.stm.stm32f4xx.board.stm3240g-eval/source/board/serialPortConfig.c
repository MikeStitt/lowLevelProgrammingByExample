#include "app/commonHeaders.h"
#include "board/serialPortConfig.h"
#include "board/serialPortPrivateDriver.h"

const serialPortConfig_t WEAK serialPortConfig[] = {
    {
        .index = SERIAL0,
        .name = "SERIAL0",
        .autoInitializeOnPowerUp = true,
        .halConfigGlue = {
            .tx = {
                .pinGpio    = SERIAL0TX,
                .pinSource = GPIO_PinSource9
            },
            .rx = {
                .pinGpio    = SERIAL0RX,
                .pinSource = GPIO_PinSource10
            },
            .serialPortPtr = USART3,
            .gpioAF   = GPIO_AF_USART3,
            .irq      = USART3_IRQn,
            .clkEnaP  = &(RCC->APB1ENR),
            .clk      = RCC_APB1Periph_USART3,
            .usartCfg = {
                .USART_BaudRate            = 115200,
                .USART_WordLength          = USART_WordLength_8b,
                .USART_StopBits            = USART_StopBits_1,
                .USART_Parity              = USART_Parity_No,
                .USART_Mode                = USART_Mode_Rx | USART_Mode_Tx,
                .USART_HardwareFlowControl = USART_HardwareFlowControl_None
            }
        },
	.spJumpTableFunctions = SERIAL_PORT_FUNCTION_POINTERS,
    }
};

const size_t WEAK serialPortConfigSize = COUNT_OF(serialPortConfig);
uint32_t WEAK gSerialPortInitializedList[COUNT_OF(serialPortConfig)] = { [0 ... COUNT_OF(serialPortConfig)-1] = 0 };

