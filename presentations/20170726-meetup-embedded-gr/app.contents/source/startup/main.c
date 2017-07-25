#include "app/commonHeaders.h"
#include "startup/main.h"

void sendRepeatedSerialMessage(void)
{
    static int index = 0;
    char const* message = "Hello World!\n\rWhattttt's happening?\n\r";

    if (0==message[index]) {
       index = 0;
    }

    serialPortWaitWhileFull(SERIAL0);
    serialPortTxByte(SERIAL0, (uint8_t)message[index]);
    index++;
}

int nextGpioState(int current)
{
    int next=0;
    if (0==current) {
      next = 1;
    }
    return next;
}  

void toggleDiscretes(void)
{
    static uint32_t toggleCount = 0;
    const uint32_t symbolsPerSecond=115200;
    const uint32_t symbolsPerChar = 10;
    const uint32_t oneHz = symbolsPerSecond / symbolsPerChar;
    const uint32_t fiveHz = (symbolsPerSecond / symbolsPerChar) / 5;
    
    if (0==toggleCount) {
        int current = gpioGetOutCmd(GPIOLED1);
        int next = nextGpioState(current);
        gpioSetOutCmd(GPIOLED1, next);
    }

    if (0==toggleCount%fiveHz) {
        int current = gpioGetOutCmd(GPIOLED2);
        int next = nextGpioState(current);
        gpioSetOutCmd(GPIOLED2, next);
    }

    toggleCount = (toggleCount+1) % oneHz;
}

volatile uint32_t gCounter;

// This main does not have a WEAK prefix so it overrides the default main.
int main(void) {

    gpioInit();
    serialPortInit();

    while (1) {
        gCounter++;

	toggleDiscretes();
        sendRepeatedSerialMessage();
    }
    
    // An infinite loop for safety
    while (1) {
    }

    // We can't get passed the infinite loop to here
}

