#include "app/commonHeaders.h"
#include "startup/halStartupBeforeMain.h"

void halStartupBeforeMain(void) {

    // In the ARM Nested Vectored Interrupt Controller, configure the priority grouping for all 4 bits at pre-emption priority.   
    NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
}

