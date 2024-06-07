#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#include "MGPIO_Interface.h"
#include "MGPIO_Private.h"
#include "MGPIO_Cfg.h"

void MGPIO_voidSetPinMode(u8 A_u8Port, u8 A_u8Pin, u8 A_u8Mode)
{
    if (A_u8Pin < 16 && A_u8Mode < 4)
    {   
        switch (A_u8Port)
        {
        case MGPIO_PORTA:
            GPIOA_MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOA_MODER |= (A_u8Mode<<(A_u8Pin*2));
            break;
        case MGPIO_PORTB:
            GPIOB_MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOB_MODER |= (A_u8Mode<<(A_u8Pin*2));
            break;
        case MGPIO_PORTC:
            GPIOC_MODER &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOC_MODER |= (A_u8Mode<<(A_u8Pin*2));
            break;
        default:
            break;
        }
    }
}

void MGPIO_voidSetPinOutputType(u8 A_u8Port, u8 A_u8Pin, u8 A_u8OutputType)
{
    if (A_u8Pin < 16 && A_u8OutputType < 2)
    {
        switch (A_u8Port)
        {
        case MGPIO_PORTA:
            GPIOA_OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
            GPIOA_OTYPER |= (A_u8OutputType<<A_u8Pin);
            break;
        case MGPIO_PORTB:
            GPIOB_OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
            GPIOB_OTYPER |= (A_u8OutputType<<A_u8Pin);
            break;
        case MGPIO_PORTC:
            GPIOC_OTYPER &= ~(ONE_BIT_MASK<<A_u8Pin);
            GPIOC_OTYPER |= (A_u8OutputType<<A_u8Pin);
            break;
        default:
            break;
        }
    }
}

void MGPIO_voidSetPinOutputSpeed(u8 A_u8Port, u8 A_u8Pin, u8 A_u8OutputSpeed)
{
    if (A_u8Pin < 16 && A_u8OutputSpeed < 4)
    {   
        switch (A_u8Port)
        {
        case MGPIO_PORTA:
            GPIOA_OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOA_OSPEEDR |= (A_u8OutputSpeed<<(A_u8Pin*2));
            break;
        case MGPIO_PORTB:
            GPIOB_OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOB_OSPEEDR |= (A_u8OutputSpeed<<(A_u8Pin*2));
            break;
        case MGPIO_PORTC:
            GPIOC_OSPEEDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOC_OSPEEDR |= (A_u8OutputSpeed<<(A_u8Pin*2));
            break;
        default:
            break;
        }
    }
}

void MGPIO_voidSetPinPullupPullDown(u8 A_u8Port, u8 A_u8Pin, u8 A_u8PullupPullDown)
{
    if (A_u8Pin < 16 && A_u8PullupPullDown < 3)
    {   
        switch (A_u8Port)
        {
        case MGPIO_PORTA:
            GPIOA_PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOA_PUPDR |= (A_u8PullupPullDown<<(A_u8Pin*2));
            break;
        case MGPIO_PORTB:
            GPIOB_PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOB_PUPDR |= (A_u8PullupPullDown<<(A_u8Pin*2));
            break;
        case MGPIO_PORTC:
            GPIOC_PUPDR &= ~(TWO_BIT_MASK<<(A_u8Pin*2));
            GPIOC_PUPDR |= (A_u8PullupPullDown<<(A_u8Pin*2));
            break;
        default:
            break;
        }
    }
}

u8 MGPIO_u8GetPinValue(u8 A_u8Port, u8 A_u8Pin)
{
    if (A_u8Pin < 16)
    {    
        switch (A_u8Port)
        {
        case MGPIO_PORTA:
            return GET_BIT(GPIOA_IDR, A_u8Pin);
            break;
        case MGPIO_PORTB:
            return GET_BIT(GPIOB_IDR, A_u8Pin);
            break;
        case MGPIO_PORTC:
            return GET_BIT(GPIOC_IDR, A_u8Pin);
            break;
        default:
            return 255;
            break;
        }
    }
}

u16 MGPIO_u8GetPortValue(u8 A_u8Port)
{
    switch (A_u8Port)
    {
    case MGPIO_PORTA:
        return (u16)GPIOA_IDR;
        break;
    case MGPIO_PORTB:
        return (u16)GPIOB_IDR;
        break;
    case MGPIO_PORTC:
        return (u16)GPIOC_IDR;
        break;
    default:
        return 0;
        break;
    }
}

void MGPIO_voidSetPinValue(u8 A_u8Port, u8 A_u8Pin, u8 A_PinValue)
{
    if (A_u8Pin < 16 && A_PinValue < 2)
    {    
        switch (A_u8Port)
        {
        case MGPIO_PORTA:
            if (A_PinValue)
                GPIOA_BSRR = (1<<A_u8Pin);
            else
                GPIOA_BSRR = (1<<(A_u8Pin + RESET_PIN0));
            break;
        case MGPIO_PORTB:
            if (A_PinValue)
                GPIOB_BSRR = (1<<A_u8Pin);
            else
                GPIOB_BSRR = (1<<(A_u8Pin + RESET_PIN0));
            break;
        case MGPIO_PORTC:
            if (A_PinValue)
                GPIOC_BSRR = (1<<A_u8Pin);
            else
                GPIOC_BSRR = (1<<(A_u8Pin + RESET_PIN0));
            break;
        default:
            break;
        }
    }
}

void MGPIO_voidSetPortValue(u8 A_u8Port, u16 A_PortValue)
{
    switch (A_u8Port)
    {
    case MGPIO_PORTA:
        GPIOA_ODR = A_PortValue;
        break;
    case MGPIO_PORTB:
        GPIOB_ODR = A_PortValue;
        break;
    case MGPIO_PORTC:
        GPIOC_ODR = A_PortValue;
        break;
    default:
        break;
    }
}

void MGPIO_voidLockPin(u8 A_u8Port, u8 A_u8Pin)
{
    if (A_u8Pin < 16)
    {
        switch (A_u8Port)
        {
        case MGPIO_PORTA:
            SET_BIT(GPIOA_LCKR, A_u8Pin);
            //Lock sequence
            SET_BIT(GPIOA_LCKR, LCKK);
            CLR_BIT(GPIOA_LCKR, LCKK);
            SET_BIT(GPIOA_LCKR, LCKK);
            break;
        case MGPIO_PORTB:
            SET_BIT(GPIOB_LCKR, A_u8Pin);
            //Lock sequence
            SET_BIT(GPIOB_LCKR, LCKK);
            CLR_BIT(GPIOB_LCKR, LCKK);
            SET_BIT(GPIOB_LCKR, LCKK);
            break;
        case MGPIO_PORTC:
            SET_BIT(GPIOC_LCKR, A_u8Pin);
            //Lock sequence
            SET_BIT(GPIOC_LCKR, LCKK);
            CLR_BIT(GPIOC_LCKR, LCKK);
            SET_BIT(GPIOC_LCKR, LCKK);
            break;
        default:
            break;
        }
    }    
}
