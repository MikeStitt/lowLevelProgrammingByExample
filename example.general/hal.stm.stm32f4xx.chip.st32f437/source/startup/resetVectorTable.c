#include "app/commonHeaders.h"
#include "startup/armCortexCommonIntHandlers.h"

void WEAK Default_Handler_Relay(void)
{
  Default_Handler();
}

void WEAK WWDG_IRQHandler(void);
void WEAK PVD_IRQHandler(void);
void WEAK TAMP_STAMP_IRQHandler(void);
void WEAK RTC_WKUP_IRQHandler(void);
void WEAK FLASH_IRQHandler(void);
void WEAK RCC_IRQHandler(void);
void WEAK EXTI0_IRQHandler(void);
void WEAK EXTI1_IRQHandler(void);
void WEAK EXTI2_IRQHandler(void);
void WEAK EXTI3_IRQHandler(void);
void WEAK EXTI4_IRQHandler(void);
void WEAK DMA1_Stream0_IRQHandler(void);
void WEAK DMA1_Stream1_IRQHandler(void);
void WEAK DMA1_Stream2_IRQHandler(void);
void WEAK DMA1_Stream3_IRQHandler(void);
void WEAK DMA1_Stream4_IRQHandler(void);
void WEAK DMA1_Stream5_IRQHandler(void);
void WEAK DMA1_Stream6_IRQHandler(void);
void WEAK ADC_IRQHandler(void);
void WEAK CAN1_TX_IRQHandler(void);
void WEAK CAN1_RX0_IRQHandler(void);
void WEAK CAN1_RX1_IRQHandler(void);
void WEAK CAN1_SCE_IRQHandler(void);
void WEAK EXTI9_5_IRQHandler(void);
void WEAK TIM1_BRK_TIM9_IRQHandler(void);
void WEAK TIM1_UP_TIM10_IRQHandler(void);
void WEAK TIM1_TRG_COM_TIM11_IRQHandler(void);
void WEAK TIM1_CC_IRQHandler(void);
void WEAK TIM2_IRQHandler(void);
void WEAK TIM3_IRQHandler(void);
void WEAK TIM4_IRQHandler(void);
void WEAK I2C1_EV_IRQHandler(void);
void WEAK I2C1_ER_IRQHandler(void);
void WEAK I2C2_EV_IRQHandler(void);
void WEAK I2C2_ER_IRQHandler(void);
void WEAK SPI1_IRQHandler(void);
void WEAK SPI2_IRQHandler(void);
void WEAK USART1_IRQHandler(void);
void WEAK USART2_IRQHandler(void);
void WEAK USART3_IRQHandler(void);
void WEAK EXTI15_10_IRQHandler(void);
void WEAK RTC_Alarm_IRQHandler(void);
void WEAK OTG_FS_WKUP_IRQHandler(void);
void WEAK TIM8_BRK_TIM12_IRQHandler(void);
void WEAK TIM8_UP_TIM13_IRQHandler(void);
void WEAK TIM8_TRG_COM_TIM14_IRQHandler(void);
void WEAK TIM8_CC_IRQHandler(void);
void WEAK DMA1_Stream7_IRQHandler(void);
void WEAK FSMC_IRQHandler(void);
void WEAK SDIO_IRQHandler(void);
void WEAK TIM5_IRQHandler(void);
void WEAK SPI3_IRQHandler(void);
void WEAK UART4_IRQHandler(void);
void WEAK UART5_IRQHandler(void);
void WEAK TIM6_DAC_IRQHandler(void);
void WEAK TIM7_IRQHandler(void);
void WEAK DMA2_Stream0_IRQHandler(void);
void WEAK DMA2_Stream1_IRQHandler(void);
void WEAK DMA2_Stream2_IRQHandler(void);
void WEAK DMA2_Stream3_IRQHandler(void);
void WEAK DMA2_Stream4_IRQHandler(void);
void WEAK ETH_IRQHandler(void);
void WEAK ETH_WKUP_IRQHandler(void);
void WEAK CAN2_TX_IRQHandler(void);
void WEAK CAN2_RX0_IRQHandler(void);
void WEAK CAN2_RX1_IRQHandler(void);
void WEAK CAN2_SCE_IRQHandler(void);
void WEAK OTG_FS_IRQHandler(void);
void WEAK DMA2_Stream5_IRQHandler(void);
void WEAK DMA2_Stream6_IRQHandler(void);
void WEAK DMA2_Stream7_IRQHandler(void);
void WEAK USART6_IRQHandler(void);
void WEAK I2C3_EV_IRQHandler(void);
void WEAK I2C3_ER_IRQHandler(void);
void WEAK OTG_HS_EP1_OUT_IRQHandler(void);
void WEAK OTG_HS_EP1_IN_IRQHandler(void);
void WEAK OTG_HS_WKUP_IRQHandler(void);
void WEAK OTG_HS_IRQHandler(void);
void WEAK DCMI_IRQHandler(void);
void WEAK CRYP_IRQHandler(void);
void WEAK HASH_RNG_IRQHandler(void);
void WEAK FPU_IRQHandler(void);

#pragma weak WWDG_IRQHandler = Default_Handler_Relay
#pragma weak PVD_IRQHandler = Default_Handler_Relay
#pragma weak TAMP_STAMP_IRQHandler = Default_Handler_Relay
#pragma weak RTC_WKUP_IRQHandler = Default_Handler_Relay
#pragma weak FLASH_IRQHandler = Default_Handler_Relay
#pragma weak RCC_IRQHandler = Default_Handler_Relay
#pragma weak EXTI0_IRQHandler = Default_Handler_Relay
#pragma weak EXTI1_IRQHandler = Default_Handler_Relay
#pragma weak EXTI2_IRQHandler = Default_Handler_Relay
#pragma weak EXTI3_IRQHandler = Default_Handler_Relay
#pragma weak EXTI4_IRQHandler = Default_Handler_Relay
#pragma weak DMA1_Stream0_IRQHandler = Default_Handler_Relay
#pragma weak DMA1_Stream1_IRQHandler = Default_Handler_Relay
#pragma weak DMA1_Stream2_IRQHandler = Default_Handler_Relay
#pragma weak DMA1_Stream3_IRQHandler = Default_Handler_Relay
#pragma weak DMA1_Stream4_IRQHandler = Default_Handler_Relay
#pragma weak DMA1_Stream5_IRQHandler = Default_Handler_Relay
#pragma weak DMA1_Stream6_IRQHandler = Default_Handler_Relay
#pragma weak ADC_IRQHandler = Default_Handler_Relay
#pragma weak CAN1_TX_IRQHandler = Default_Handler_Relay
#pragma weak CAN1_RX0_IRQHandler = Default_Handler_Relay
#pragma weak CAN1_RX1_IRQHandler = Default_Handler_Relay
#pragma weak CAN1_SCE_IRQHandler = Default_Handler_Relay
#pragma weak EXTI9_5_IRQHandler = Default_Handler_Relay
#pragma weak TIM1_BRK_TIM9_IRQHandler = Default_Handler_Relay
#pragma weak TIM1_UP_TIM10_IRQHandler = Default_Handler_Relay
#pragma weak TIM1_TRG_COM_TIM11_IRQHandler = Default_Handler_Relay
#pragma weak TIM1_CC_IRQHandler = Default_Handler_Relay
#pragma weak TIM2_IRQHandler = Default_Handler_Relay
#pragma weak TIM3_IRQHandler = Default_Handler_Relay
#pragma weak TIM4_IRQHandler = Default_Handler_Relay
#pragma weak I2C1_EV_IRQHandler = Default_Handler_Relay
#pragma weak I2C1_ER_IRQHandler = Default_Handler_Relay
#pragma weak I2C2_EV_IRQHandler = Default_Handler_Relay
#pragma weak I2C2_ER_IRQHandler = Default_Handler_Relay
#pragma weak SPI1_IRQHandler = Default_Handler_Relay
#pragma weak SPI2_IRQHandler = Default_Handler_Relay
#pragma weak USART1_IRQHandler = Default_Handler_Relay
#pragma weak USART2_IRQHandler = Default_Handler_Relay
#pragma weak USART3_IRQHandler = Default_Handler_Relay
#pragma weak EXTI15_10_IRQHandler = Default_Handler_Relay
#pragma weak RTC_Alarm_IRQHandler = Default_Handler_Relay
#pragma weak OTG_FS_WKUP_IRQHandler = Default_Handler_Relay
#pragma weak TIM8_BRK_TIM12_IRQHandler = Default_Handler_Relay
#pragma weak TIM8_UP_TIM13_IRQHandler = Default_Handler_Relay
#pragma weak TIM8_TRG_COM_TIM14_IRQHandler = Default_Handler_Relay
#pragma weak TIM8_CC_IRQHandler = Default_Handler_Relay
#pragma weak DMA1_Stream7_IRQHandler = Default_Handler_Relay
#pragma weak FSMC_IRQHandler = Default_Handler_Relay
#pragma weak SDIO_IRQHandler = Default_Handler_Relay
#pragma weak TIM5_IRQHandler = Default_Handler_Relay
#pragma weak SPI3_IRQHandler = Default_Handler_Relay
#pragma weak UART4_IRQHandler = Default_Handler_Relay
#pragma weak UART5_IRQHandler = Default_Handler_Relay
#pragma weak TIM6_DAC_IRQHandler = Default_Handler_Relay
#pragma weak TIM7_IRQHandler = Default_Handler_Relay
#pragma weak DMA2_Stream0_IRQHandler = Default_Handler_Relay
#pragma weak DMA2_Stream1_IRQHandler = Default_Handler_Relay
#pragma weak DMA2_Stream2_IRQHandler = Default_Handler_Relay
#pragma weak DMA2_Stream3_IRQHandler = Default_Handler_Relay
#pragma weak DMA2_Stream4_IRQHandler = Default_Handler_Relay
#pragma weak ETH_IRQHandler = Default_Handler_Relay
#pragma weak ETH_WKUP_IRQHandler = Default_Handler_Relay
#pragma weak CAN2_TX_IRQHandler = Default_Handler_Relay
#pragma weak CAN2_RX0_IRQHandler = Default_Handler_Relay
#pragma weak CAN2_RX1_IRQHandler = Default_Handler_Relay
#pragma weak CAN2_SCE_IRQHandler = Default_Handler_Relay
#pragma weak OTG_FS_IRQHandler = Default_Handler_Relay
#pragma weak DMA2_Stream5_IRQHandler = Default_Handler_Relay
#pragma weak DMA2_Stream6_IRQHandler = Default_Handler_Relay
#pragma weak DMA2_Stream7_IRQHandler = Default_Handler_Relay
#pragma weak USART6_IRQHandler = Default_Handler_Relay
#pragma weak I2C3_EV_IRQHandler = Default_Handler_Relay
#pragma weak I2C3_ER_IRQHandler = Default_Handler_Relay
#pragma weak OTG_HS_EP1_OUT_IRQHandler = Default_Handler_Relay
#pragma weak OTG_HS_EP1_IN_IRQHandler = Default_Handler_Relay
#pragma weak OTG_HS_WKUP_IRQHandler = Default_Handler_Relay
#pragma weak OTG_HS_IRQHandler = Default_Handler_Relay
#pragma weak DCMI_IRQHandler = Default_Handler_Relay
#pragma weak CRYP_IRQHandler = Default_Handler_Relay
#pragma weak HASH_RNG_IRQHandler = Default_Handler_Relay
#pragma weak FPU_IRQHandler = Default_Handler_Relay


RESET_STACK_SECTION int resetStack[RAM_APP_RESET_STACK_LEN / sizeof(int)];


ISR_VECTOR_SECTION void (* WEAK const vectors[])(void) =
{
  (void (*)(void))((unsigned long)resetStack+sizeof(resetStack)),
                                         /* 0000 - The initial stack pointer */
        Reset_Handler,                   /* 0004 - Reset Handler */
        NMI_Handler,                     /* 0008 - NMI Handler */
        HardFault_Handler,               /* 000C - Hard Fault Handler */
        MemManage_Handler,               /* 0010 - Mpu Fault Handler */
        BusFault_Handler,                /* 0014 - Bus Fault Handler */
        UsageFault_Handler,              /* 0018 - Usage Fault Handler */
        Default_Handler,                 /* 001C - Reserved */
        Default_Handler,                 /* 0020 - Reserved */
        Default_Handler,                 /* 0024 - Reserved */
        Default_Handler,                 /* 0028 - Reserved */
        SVC_Handler,                     /* 002C - SVCall Handler */
        DebugMon_Handler,                /* 0030 - Debug Monitor Handler */
        Default_Handler,                 /* 0034 - Reserved */
        PendSV_Handler,                  /* 0038 - PendSV Handler */
        SysTick_Handler,                 /* 003C - SysTick Handler */

        /* External interrupts */
        WWDG_IRQHandler,                 /* 0040 - Window WatchDog */
        PVD_IRQHandler,                  /* 0044 - PVD through EXTI Line detection */
        TAMP_STAMP_IRQHandler,           /* 0048 - Tamper and TimeStamps through the EXTI line */
        RTC_WKUP_IRQHandler,             /* 004C - RTC Wakeup through the EXTI line */
        FLASH_IRQHandler,                /* 0050 - FLASH */
        RCC_IRQHandler,                  /* 0054 - RCC */
        EXTI0_IRQHandler,                /* 0058 - EXTI Line0 */
        EXTI1_IRQHandler,                /* 005C - EXTI Line1 */
        EXTI2_IRQHandler,                /* 0060 - EXTI Line2 */
        EXTI3_IRQHandler,                /* 0064 - EXTI Line3 */
        EXTI4_IRQHandler,                /* 0068 - EXTI Line4 */
        DMA1_Stream0_IRQHandler,         /* 006C - DMA1 Stream 0 */
        DMA1_Stream1_IRQHandler,         /* 0070 - DMA1 Stream 1 */
        DMA1_Stream2_IRQHandler,         /* 0074 - DMA1 Stream 2 */
        DMA1_Stream3_IRQHandler,         /* 0078 - DMA1 Stream 3 */
        DMA1_Stream4_IRQHandler,         /* 007C - DMA1 Stream 4 */
        DMA1_Stream5_IRQHandler,         /* 0080 - DMA1 Stream 5 */
        DMA1_Stream6_IRQHandler,         /* 0084 - DMA1 Stream 6 */
        ADC_IRQHandler,                  /* 0088 - ADC1, ADC2 and ADC3s */
        CAN1_TX_IRQHandler,              /* 008C - CAN1 TX */
        CAN1_RX0_IRQHandler,             /* 0090 - CAN1 RX0 */
        CAN1_RX1_IRQHandler,             /* 0094 - CAN1 RX1 */
        CAN1_SCE_IRQHandler,             /* 0098 - CAN1 SCE */
        EXTI9_5_IRQHandler,              /* 009C - External Line[9:5]s */
        TIM1_BRK_TIM9_IRQHandler,        /* 00A0 - TIM1 Break and TIM9 */
        TIM1_UP_TIM10_IRQHandler,        /* 00A4 - TIM1 Update and TIM10 */
        TIM1_TRG_COM_TIM11_IRQHandler,   /* 00A8 - TIM1 Trigger and Commutation and TIM11 */
        TIM1_CC_IRQHandler,              /* 00AC - TIM1 Capture Compare */
        TIM2_IRQHandler,                 /* 00B0 - TIM2 */
        TIM3_IRQHandler,                 /* 00B4 - TIM3 */
        TIM4_IRQHandler,                 /* 00B8 - TIM4 */
        I2C1_EV_IRQHandler,              /* 00BC - I2C1 Event */
        I2C1_ER_IRQHandler,              /* 00C0 - I2C1 Error */
        I2C2_EV_IRQHandler,              /* 00C4 - I2C2 Event */
        I2C2_ER_IRQHandler,              /* 00C8 - I2C2 Error */
        SPI1_IRQHandler,                 /* 00CC - SPI1 */
        SPI2_IRQHandler,                 /* 00D0 - SPI2 */
        USART1_IRQHandler,               /* 00D4 - USART1 */
        USART2_IRQHandler,               /* 00D8 - USART2 */
        USART3_IRQHandler,               /* 00DC - USART3 */
        EXTI15_10_IRQHandler,            /* 00E0 - External Line[15:10]s */
        RTC_Alarm_IRQHandler,            /* 00E4 - RTC Alarm (A and B) through EXTI Line */
        OTG_FS_WKUP_IRQHandler,          /* 00E8 - USB OTG FS Wakeup through EXTI line */
        TIM8_BRK_TIM12_IRQHandler,       /* 00EC - TIM8 Break and TIM12 */
        TIM8_UP_TIM13_IRQHandler,        /* 00F0 - TIM8 Update and TIM13 */
        TIM8_TRG_COM_TIM14_IRQHandler,   /* 00F4 - TIM8 Trigger and Commutation and TIM14 */
        TIM8_CC_IRQHandler,              /* 00F8 - TIM8 Capture Compare */
        DMA1_Stream7_IRQHandler,         /* 00FC - DMA1 Stream7 */
        FSMC_IRQHandler,                 /* 0100 - FSMC */
        SDIO_IRQHandler,                 /* 0104 - SDIO */
        TIM5_IRQHandler,                 /* 0108 - TIM5 */
        SPI3_IRQHandler,                 /* 010C - SPI3 */
        UART4_IRQHandler,                /* 0110 - UART4 */
        UART5_IRQHandler,                /* 0114 - UART5 */
        TIM6_DAC_IRQHandler,             /* 0118 - TIM6 and DAC1&2 underrun errors */
        TIM7_IRQHandler,                 /* 011C - TIM7 */
        DMA2_Stream0_IRQHandler,         /* 0120 - DMA2 Stream 0 */
        DMA2_Stream1_IRQHandler,         /* 0124 - DMA2 Stream 1 */
        DMA2_Stream2_IRQHandler,         /* 0128 - DMA2 Stream 2 */
        DMA2_Stream3_IRQHandler,         /* 012C - DMA2 Stream 3 */
        DMA2_Stream4_IRQHandler,         /* 0130 - DMA2 Stream 4 */
        ETH_IRQHandler,                  /* 0134 - Ethernet */
        ETH_WKUP_IRQHandler,             /* 0138 - Ethernet Wakeup through EXTI line */
        CAN2_TX_IRQHandler,              /* 013C - CAN2 TX */
        CAN2_RX0_IRQHandler,             /* 0140 - CAN2 RX0 */
        CAN2_RX1_IRQHandler,             /* 0144 - CAN2 RX1 */
        CAN2_SCE_IRQHandler,             /* 0148 - CAN2 SCE */
        OTG_FS_IRQHandler,               /* 014C - USB OTG FS */
        DMA2_Stream5_IRQHandler,         /* 0150 - DMA2 Stream 5 */
        DMA2_Stream6_IRQHandler,         /* 0154 - DMA2 Stream 6 */
        DMA2_Stream7_IRQHandler,         /* 0158 - DMA2 Stream 7 */
        USART6_IRQHandler,               /* 015C - USART6 */
        I2C3_EV_IRQHandler,              /* 0160 - I2C3 event */
        I2C3_ER_IRQHandler,              /* 0164 - I2C3 error */
        OTG_HS_EP1_OUT_IRQHandler,       /* 0168 - USB OTG HS End Point 1 Out */
        OTG_HS_EP1_IN_IRQHandler,        /* 016C - USB OTG HS End Point 1 In */
        OTG_HS_WKUP_IRQHandler,          /* 0170 - USB OTG HS Wakeup through EXTI */
        OTG_HS_IRQHandler,               /* 0174 - USB OTG HS */
        DCMI_IRQHandler,                 /* 0178 - DCMI */
        CRYP_IRQHandler,                 /* 017C - CRYP crypto */
        HASH_RNG_IRQHandler,             /* 0180 - Hash and Rng */
        FPU_IRQHandler,                  /* 0184 - FPU */
        Default_Handler,                 /* 0188 - UART 7 */
        Default_Handler,                 /* 018C - UART 8 */
        Default_Handler,                 /* 0190 - SPI 4 */
        Default_Handler,                 /* 0194 - SPI 5 */
        Default_Handler                  /* 0198 - SPI 6 */
};
