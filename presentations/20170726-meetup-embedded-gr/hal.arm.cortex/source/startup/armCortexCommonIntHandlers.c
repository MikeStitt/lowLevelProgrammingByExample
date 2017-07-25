#include "app/commonHeaders.h"
#include "startup/armCortexCommonIntHandlers.h"
#include "startup/main.h"
#include "startup/halStartupBeforeMain.h"

#include <stdint.h>

//  ----------------------------------------------------------------------------
/// Entry point upon processor reset release.
///
/// When reset is released, the processor loads the stack pointer
/// with the value at vectors[0] and the program counter with
/// the value at vectors[1] to start execution at Reset_Handler.
//  ----------------------------------------------------------------------------
void WEAK INTERRUPT Reset_Handler(void)
{
    extern unsigned long _startInitSourceData;
    extern unsigned long _startInitDestinationData;
    extern unsigned long _endInitDestinationData;
    extern unsigned long _startBss;
    extern unsigned long _endBss;

    extern void SystemInit(void);
    extern void __libc_init_array(void);

    unsigned long *destPtr;
    unsigned long *srcPtr;

    /// Copy the data segment initializers from flash to SRAM in ROM mode.
    /// When (&_startInitSourceData != &_startInitDestinationData) we are linked
    /// to boot from ROM and we need to copy.  Otherwise we are linked to boot
    /// from RAM and we don't need to copy.

    if (&_startInitSourceData != &_startInitDestinationData) {
        srcPtr = (unsigned long *)&_startInitSourceData;
        for (destPtr = &_startInitDestinationData;
             destPtr < &_endInitDestinationData;) {
            *(destPtr++) = *(srcPtr++);
        }
    }

    /// Zero fill the bss segment in RAM.
    for (destPtr = &_startBss; destPtr < &_endBss; destPtr++) {
        *destPtr = 0;
    }

    /// Start the CPU (PLL, FLASH)
    SystemInit();

    /// Initialize newLib.
    __libc_init_array();

    /// The last couple of hardware things we need to be intialzed before main can run.
    halStartupBeforeMain();

    // Call the application's entry point.
    main();

    /// We should not get here.
    while (1) {};
}

volatile uint32_t gUnexpectedInteruptCount;

//  ----------------------------------------------------------------------------
/// Common point for unexpected interrupts to funnel to.
//  ----------------------------------------------------------------------------
void Unexpected_Interrupt_Handler(void)
{
    gUnexpectedInteruptCount++;

    // @TODO fix this up in production code
    __asm volatile ("BKPT #0\n");

    while (1) {};
}


//  ----------------------------------------------------------------------------
/// Default handler if no other handler is present.
//  ----------------------------------------------------------------------------
void WEAK Default_Handler(void)
{
    Unexpected_Interrupt_Handler();
}


//  ----------------------------------------------------------------------------
/// 
//  ----------------------------------------------------------------------------
void WEAK NMI_Handler(void)
{
    Unexpected_Interrupt_Handler();
}

//  ----------------------------------------------------------------------------
/// 
//  ----------------------------------------------------------------------------
void WEAK NAKED logBuildHardFaultParams(void)
{
#if 0
#if defined CONFIG_FACILITY_INCDNTLOG && CONFIG_FACILITY_INCDNTLOG
    /*
     * Get the appropriate stack pointer, depending on our mode,
     * and use it as the parameter to the C handler. This function
     * will never return
     */
     __asm(
	 ".syntax unified\n"
                 "MOVS   R1, #4  \n"   /* R1<=#4 */
                 "MOV    R2, LR  \n"   /* R2<=LR */
                 "TST    R1, R2  \n"   /* Is Bit 2 (#4) of the link register set? */
                 "BEQ    _MSP    \n"
                 "MRS    R1, PSP \n"   /* Pass the Process Stack Pointer (PSP) as the first parameter TODO Second Parameter???*/
                 "B      logHardFault      \n"
         "_MSP:  \n"
                 "MRS    R1, MSP \n"   /* Pass the Main Stack Pointer (MSP) as the first parameter */
                 "B      logHardFault      \n"
         ".syntax divided\n") ;
#endif
#endif
     Unexpected_Interrupt_Handler();
}

//  ----------------------------------------------------------------------------
/// 
///  Use the 'naked' attribute so that C stacking is not used.
//  ----------------------------------------------------------------------------
void WEAK NAKED HardFault_Handler(void)
{
#if 0
        __asm volatile (
            "MOVS   r0,%[value] \n"
            "B      logBuildHardFaultParams  \n" : : [value] "I" (eVectorHardFault) );  // Pass the number of the vector as the first parameter
#endif
}



//  ----------------------------------------------------------------------------
/// 
///  Use the 'naked' attribute so that C stacking is not used.
//  ----------------------------------------------------------------------------
void WEAK NAKED MemManage_Handler(void)
{
#if 0
    __asm(  "MOVS   R0,%[value] \n"
             "B logBuildHardFaultParams  \n": : [value] "I" (eVectorMemManageFault) );  /* Pass the number of the vector as the first parameter */
#endif
}

//  ----------------------------------------------------------------------------
/// 
///  Use the 'naked' attribute so that C stacking is not used.
//  ----------------------------------------------------------------------------
void WEAK NAKED BusFault_Handler(void)
{
#if 0
    __asm(  "MOVS   R0,%[value] \n"
             "B logBuildHardFaultParams  \n": : [value] "I" (eVectorBusFault) );  /* Pass the number of the vector as the first parameter */
#endif
}

//  ----------------------------------------------------------------------------
/// 
///  Use the 'naked' attribute so that C stacking is not used.
//  ----------------------------------------------------------------------------
void WEAK NAKED UsageFault_Handler(void)
{
#if 0
    __asm(  "MOVS   R0,%[value] \n"
             "B logBuildHardFaultParams  \n": : [value] "I" (eVectorUsageFault) );  /* Pass the number of the vector as the first parameter */
#endif
}


//  ----------------------------------------------------------------------------
/// 
//  ----------------------------------------------------------------------------
void WEAK SVC_Handler(void)
{
     Unexpected_Interrupt_Handler();
}


//  ----------------------------------------------------------------------------
/// 
//  ----------------------------------------------------------------------------
void WEAK DebugMon_Handler(void)
{
     Unexpected_Interrupt_Handler();
}


//  ----------------------------------------------------------------------------
/// 
//  ----------------------------------------------------------------------------
void WEAK PendSV_Handler(void)
{
     Unexpected_Interrupt_Handler();
}

//  ----------------------------------------------------------------------------
/// 
//  ----------------------------------------------------------------------------
void WEAK SysTick_Handler(void)
{
     Unexpected_Interrupt_Handler();
}
