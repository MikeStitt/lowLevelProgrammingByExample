#ifndef __MEMORY_MAP_H
#define __MEMORY_MAP_H

#define APP_ADR      0x00000000
#define APP_LEN      0x00070000
#define APP_RN       4

#define VECTORS_OFF        0x00000000
#define VECTORS_LEN        0x00000200

#define RAM_KEEP_THROUGH_RESET_ADR 0x20000000
#define RAM_KEEP_THROUGH_RESET_LEN 0x000011C0

#define RAM_APP_RESET_STACK        (RAM_KEEP_THROUGH_RESET_ADR + RAM_KEEP_THROUGH_RESET_LEN)
#define RAM_APP_RESET_STACK_LEN    0x00000800

#define RAM_ADR                    (RAM_APP_RESET_STACK + RAM_APP_RESET_STACK_LEN)
#define RAM_LEN                    (0x20030000 - RAM_ADR)

#define RAM_RN                     6

#define SW_FLASH_ADR APP_ADR
#define SW_FLASH_LEN APP_LEN

#define SW_RAM_ADR RAM_ADR
#define SW_RAM_LEN RAM_LEN

#define BUILD_AN_APP 1

#endif // __MEMORY_MAP_H

