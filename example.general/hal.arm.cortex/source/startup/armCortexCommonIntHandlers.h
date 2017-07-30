//  ------------------------------------------------------------------------------
/// @addtogroup startup
///
/// @{
/// @file startup/armCortexCommonIntHandlers.h
///
//
//  Copyright (c) 2017 Mike Stitt
//  ------------------------------------------------------------------------------

#ifndef __STARTUP_ARM_CORTEX_COMMON_INT_HANDLERS_H
#define __STARTUP_ARM_CORTEX_COMMON_INT_HANDLERS_H

#include "app/commonHeaders.h"


void WEAK INTERRUPT Reset_Handler(void);
void WEAK NMI_Handler(void);
void WEAK NAKED HardFault_Handler(void);
void WEAK NAKED MemManage_Handler(void);
void WEAK NAKED BusFault_Handler(void);
void WEAK NAKED UsageFault_Handler(void);
void WEAK SVC_Handler(void);
void WEAK DebugMon_Handler(void);
void WEAK PendSV_Handler(void);
void WEAK SysTick_Handler(void);

//  ----------------------------------------------------------------------------
/// Default handler if no other handler is present.
//  ----------------------------------------------------------------------------
extern void Default_Handler(void);   


#endif // __STARTUP_ARM_CORTEX_COMMON_INT_HANDLERS_H

/// @}
