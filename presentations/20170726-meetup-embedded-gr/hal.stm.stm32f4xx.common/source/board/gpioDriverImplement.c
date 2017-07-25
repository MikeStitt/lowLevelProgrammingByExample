#include "board/gpioDriverImplement.h"

extern inline void gpioImplementInitGpioDoIt(const gpioConfig_t *gpioSetup_p);
extern inline void gpioImplementSetOutCmdHighDoIt(gpio_t gpio);
extern inline void gpioImplementSetOutCmdLowDoIt(gpio_t gpio);
extern inline  int gpioImplementGetOutCmdDoIt(gpio_t gpio);
extern inline  int gpioImplementReadInDoIt(gpio_t gpio);

