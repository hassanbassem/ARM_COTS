#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#include "MRCC_Interface.h"
#include "MRCC_Private.h"
#include "MRCC_Cfg.h"

void MRCC_voidInit(void)
{
#if CLOCK_SOURCE == HSI
    //turn on HSI
    SET_BIT(RCC_CR, HSION);
    //polling on HSI ready bit until clock is stable
    while (!GET_BIT(RCC_CR, HSIRDY));
    //set clock source as HSI
    RCC_CFGR &= ~(SW_MASK<<SW);
    RCC_CFGR |= (SW_HSI<<SW);
    //polling on SWS bits to ensure that the clock source is HSI
    while (((RCC_CFGR>>SWS) & SWS_MASK) != SW_HSI);
    
#elif CLOCK_SOURCE == HSE
    //turn on HSE
    SET_BIT(RCC_CR, HSEON);
    //polling on HSE ready bit until clock is stable
    while (!GET_BIT(RCC_CR, HSERDY));
    //set clock source as HSE
    RCC_CFGR &= ~(SW_MASK<<SW);
    RCC_CFGR |= (SW_HSE<<SW);
    //polling on SWS bits to ensure that the clock source is HSE
    while (((RCC_CFGR>>SWS) & SWS_MASK) != SW_HSE);

#elif CLOCK_SOURCE == PLL
    //turn on PLL
    SET_BIT(RCC_CR, PLLON);
    //polling on HSI ready bit until clock is stable
    while (!GET_BIT(RCC_CR, PLLRDY));

    #if PLL_SOURCE == PLL_HSI
    //turn on HSI
    SET_BIT(RCC_CR, HSION);
    //polling on HSI ready bit until clock is stable
    while (!GET_BIT(RCC_CR, HSIRDY));
    //set PLL source
    CLR_BIT(RCC_PLLCFGR, PLLSRC);

    #elif PLL_SOURCE == PLL_HSE
    //turn on HSE
    SET_BIT(RCC_CR, HSEON);
    //polling on HSE ready bit until clock is stable
    while (!GET_BIT(RCC_CR, HSERDY));
    //set PLL source
    SET_BIT(RCC_PLLCFGR, PLLSRC);
    #else
    #error ("wrong configuration of PLL source")
    #endif
    //check wether multiplication factor is in the acceptable range
    #if PLL_MULTIPLICATION_FACTOR > 1 && PLL_MULTIPLICATION_FACTOR < 511 && PLL_MULTIPLICATION_FACTOR != 433
    //set multiplication factor
    RCC_CFGR &= ~(PLLN_MASK<<PLLN);
    RCC_CFGR |= (PLL_MULTIPLICATION_FACTOR<<PLLN);
    #else
    #error ("wrong configuration of PLL multiplication factor")
    #endif
    //check wether division factor is in the acceptable range
    #if PLL_DIVISION_FACTOR > 1 && PLL_DIVISION_FACTOR < 64
    //set division factor
    RCC_CFGR &= ~(PLLM_MASK<<PLLM);
    RCC_CFGR |= (PLL_DIVISION_FACTOR<<PLLM);
    #else
    #error ("wrong configuration of PLL division factor")
    #endif
    //set clock source as PLL
    RCC_CFGR &= ~(SW_MASK<<SW);
    RCC_CFGR |= (SW_PLL<<SW);
    //polling on SWS bits to ensure that the clock source is PLL
    while (((RCC_CFGR>>SWS) & SWS_MASK) != SW_PLL);
#endif
    //set AHB Prescaler
    RCC_CFGR &= ~(HPRE_MASK<<HPRE);
    RCC_CFGR |= (AHB_PRESCALER<<HPRE);
    //set APB1 and APB2 Prescaler
    RCC_CFGR &= ~(PPRE_MASK<<PPRE1);
    RCC_CFGR |= (APB2_PRESCALER<<PPRE1);
    RCC_CFGR &= ~(PPRE_MASK<<PPRE2);
    RCC_CFGR |= (APB2_PRESCALER<<PPRE2);
}

void MRCC_voidEnablePeripheralClock(u8 A_u8PeripheralBus, u8 A_u8Peripheral)
{
    switch (A_u8PeripheralBus)
    {
    case MRCC_AHB:
        SET_BIT(RCC_AHB1ENR, A_u8Peripheral);
        break;
    case MRCC_APB1:
        SET_BIT(RCC_APB1ENR, A_u8Peripheral);
        break;
    case MRCC_APB2:
        SET_BIT(RCC_APB2ENR, A_u8Peripheral);
        break;
    default:
        break;
    }    
}

void MRCC_voidDisablePeripheralClock(u8 A_u8PeripheralBus, u8 A_u8Peripheral)
{
    switch (A_u8PeripheralBus)
    {
    case MRCC_AHB:
        CLR_BIT(RCC_AHB1ENR, A_u8Peripheral);
        break;
    case MRCC_APB1:
        CLR_BIT(RCC_APB1ENR, A_u8Peripheral);
        break;
    case MRCC_APB2:
        CLR_BIT(RCC_APB2ENR, A_u8Peripheral);
        break;
    default:
        break;
    }
}