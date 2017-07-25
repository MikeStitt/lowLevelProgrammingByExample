#include "app/commonHeaders.h"
#include "board/gpioConfig.h"

const gpioConfig_t WEAK gpioConfig[] = {
    {
        .index = GPIOLED1,
        .name = "GPIOLED1",
        .autoInitializeOnPowerUp = true,
        .initialOutputValue = 0,
        .halConfigGlue = {
            .gpioPort_p = GPIOG,
            .gpioInit = {
	        .GPIO_Pin   = GPIO_Pin_6,
                .GPIO_Mode  = GPIO_Mode_OUT,
                .GPIO_Speed = GPIO_Speed_50MHz,
                .GPIO_OType = GPIO_OType_PP,
                .GPIO_PuPd  = GPIO_PuPd_UP
	    },
            .clkEna_p = &(RCC->AHB1ENR),
           .clk       = RCC_AHB1Periph_GPIOG
        }
    },
    {
        .index = GPIOLED2,
        .name = "GPIOLED2",
        .autoInitializeOnPowerUp = true,
        .initialOutputValue = 0,
        .halConfigGlue = {
            .gpioPort_p = GPIOG,
            .gpioInit = {
	        .GPIO_Pin   = GPIO_Pin_8,
                .GPIO_Mode  = GPIO_Mode_OUT,
                .GPIO_Speed = GPIO_Speed_50MHz,
                .GPIO_OType = GPIO_OType_PP,
                .GPIO_PuPd  = GPIO_PuPd_UP
	    },
            .clkEna_p = &(RCC->AHB1ENR),
            .clk      = RCC_AHB1Periph_GPIOG
        }
    },
    {
        .index = SERIAL0TX,
        .name = "SERIAL0TX",
        .autoInitializeOnPowerUp = false,
        .initialOutputValue = 1,
        .halConfigGlue = {
            .gpioPort_p = GPIOC,
            .gpioInit = {
	        .GPIO_Pin   = GPIO_Pin_10,
                .GPIO_Mode  = GPIO_Mode_AF,
                .GPIO_Speed = GPIO_Speed_50MHz,
                .GPIO_OType = GPIO_OType_PP,
                .GPIO_PuPd  = GPIO_PuPd_UP},
        .clkEna_p = &(RCC->AHB1ENR),
        .clk      = RCC_AHB1Periph_GPIOC
      }
    },
    {
        .index = SERIAL0RX,
        .name = "SERIAL0RX",
        .autoInitializeOnPowerUp = false,
        .initialOutputValue = 0,
        .halConfigGlue = {
            .gpioPort_p = GPIOC,
            .gpioInit = {
	        .GPIO_Pin   = GPIO_Pin_11,
                .GPIO_Mode  = GPIO_Mode_AF,
                .GPIO_Speed = GPIO_Speed_50MHz,
                .GPIO_OType = GPIO_OType_PP,
                .GPIO_PuPd  = GPIO_PuPd_UP
	},
        .clkEna_p = &(RCC->AHB1ENR),
        .clk      = RCC_AHB1Periph_GPIOC
      }
    },
};


const size_t WEAK gpioConfigSize = COUNT_OF( gpioConfig );
