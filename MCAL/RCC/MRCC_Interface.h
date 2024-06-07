#ifndef MRCC_INTERFACE_H
#define MRCC_INTERFACE_H

#define MRCC_AHB 0
#define MRCC_APB1 1
#define MRCC_APB2 2

#define MRCC_GPIOA 0
#define MRCC_GPIOB 1
#define MRCC_GPIOC 2
#define MRCC_GPIOD 3
#define MRCC_GPIOE 4    
#define MRCC_GPIOH 7
#define MRCC_CRCEN 12
#define MRCC_DMA1 21
#define MRCC_DMA2 22

#define MRCC_TIM2 0
#define MRCC_TIM3 1
#define MRCC_TIM4 2
#define MRCC_TIM5 3
#define MRCC_WWDG 11
#define MRCC_SPI2 14   
#define MRCC_SPI3 15
#define MRCC_USART2 17
#define MRCC_I2C1 21
#define MRCC_I2C2 22
#define MRCC_I2C3 23
#define MRCC_PWR 28

#define MRCC_TIM1 0
#define MRCC_USART1 4
#define MRCC_USART6 5
#define MRCC_ADC1 8
#define MRCC_SDIO 11
#define MRCC_SPI1 12
#define MRCC_SPI4 13
#define MRCC_SYSCFG 14
#define MRCC_TIM9 16
#define MRCC_TIM10 17
#define MRCC_TIM11 18

/**
 * @brief initialize clock
 * 
 * @return void
 */
void MRCC_voidInit(void);
/**
 * @brief enable clock for a specific peripheral
 * 
 * @param A_u8PeripheralBus macro for peripheral bus <MRCC_AHB, MRCC_APB1, MRCC_APB2>
 * @param A_u8Peripherals macro for peripheral name
 * 
 * @return void
 */
void MRCC_voidEnablePeripheralClock(u8 A_u8PeripheralBus, u8 A_u8Peripherals);
/**
 * @brief disable clock for a specific peripheral
 * 
 * @param A_u8PeripheralBus macro for peripheral bus <MRCC_AHB, MRCC_APB1, MRCC_APB2>
 * @param A_u8Peripherals macro for peripheral name
 * 
 * @return void
 */
void MRCC_voidDisablePeripheralClock(u8 A_u8PeripheralBus, u8 A_u8Peripherals);


#endif