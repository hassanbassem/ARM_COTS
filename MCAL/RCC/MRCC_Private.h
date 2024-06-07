#ifndef MRCC_PRIVATE_H
#define MRCC_PRIVATE_H

#define RCC_BASE_ADDRESS 0x40023800

#define RCC_CR (*(volatile u32*)(RCC_BASE_ADDRESS + 0x00))
#define RCC_PLLCFGR (*(volatile u32*)(RCC_BASE_ADDRESS + 0x04))
#define RCC_CFGR (*(volatile u32*)(RCC_BASE_ADDRESS + 0x08))
#define RCC_AHB1ENR (*(volatile u32*)(RCC_BASE_ADDRESS + 0x30))
#define RCC_APB1ENR (*(volatile u32*)(RCC_BASE_ADDRESS + 0x40))
#define RCC_APB2ENR (*(volatile u32*)(RCC_BASE_ADDRESS + 0x44))

#define HSION 0
#define HSIRDY 1
#define HSITRIM 3
#define HSICAL 8
#define HSEON 16
#define HSERDY 17
#define HSEBYP 18
#define CSSON 19
#define PLLON 24
#define PLLRDY 25

#define PLLM 0
#define PLLN 6
#define PLLSRC 22

#define SW 0
#define SWS 2
#define HPRE 4
#define PPRE1 10
#define PPRE2 13
#define RTCPRE 16
#define MCO1 21
#define MCO1PRE 24
#define MCO2PRE 27
#define MCO2 30

#define GPIOAEN 0
#define GPIOBEN 1
#define GPIOCEN 2
#define GPIODEN 3
#define GPIOEEN 4    
#define GPIOHEN 7
#define CRCEN 12
#define DMA1EN 21
#define DMA2EN 22

#define TIM2EN 0
#define TIM3EN 1
#define TIM4EN 2
#define TIM5EN 3
#define WWDGEN 11
#define SPI2EN 14   
#define SPI3EN 15
#define USART2EN 17
#define I2C1EN 21
#define I2C2EN 22
#define I2C3EN 23
#define PWREN 28

#define TIM1EN 0
#define USART1EN 4
#define USART6EN 5
#define ADC1EN 8
#define SDIOEN 11
#define SPI1EN 12
#define SPI4EN 13
#define SYSCFGEN 14
#define TIM9EN 16
#define TIM10EN 17
#define TIM11EN 18

#define SW_MASK 3
#define SWS_MASK 3
#define PLLN_MASK 511
#define PLLM_MASK 63
#define HPRE_MASK 15
#define PPRE_MASK 7

#define SW_HSI 0
#define SW_HSE 1
#define SW_PLL 2

#define AHB_DIV_1 0
#define AHB_DIV_2 8
#define AHB_DIV_4 9
#define AHB_DIV_8 10
#define AHB_DIV_16 11
#define AHB_DIV_32 12
#define AHB_DIV_64 13
#define AHB_DIV_128 14
#define AHB_DIV_256 15
#define AHB_DIV_512 16

#define APB_DIV_1 0
#define APB_DIV_2 4
#define APB_DIV_4 5
#define APB_DIV_8 6
#define APB_DIV_16 7

#define HSI 0
#define HSE 1
#define PLL 2

#define PLL_HSI 0
#define PLL_HSE 1

#endif
