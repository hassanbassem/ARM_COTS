
//library directives
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

//EXTI directives
#include "MEXTI_Interface.h"
#include "MEXTI_Private.h"
#include "MEXTI_Cfg.h"

static void (*pVoidCallBackFunctionEXTI[NUMBER_OF_CHANNELS]) (void) = {(void*)0};

void MEXTI_voidInitializeChannel(Channel_t A_channel)
{
    //set channels and ports
    u8 local_u8RegisterNumber = A_channel.NUMBER / 4;
    u8 local_u8NibbleNumber = A_channel.NUMBER % 4;
    *(SYSCFG_EXTICR + local_u8RegisterNumber) |= (A_channel.PORT << local_u8NibbleNumber * NIBBLE_SIZE);

    //set sense mode
    if ((A_channel.SENSE_MODE & RISING_EDGE) == RISING_EDGE)
        EXTI->RTSR |= (1<<A_channel.NUMBER);

    if ((A_channel.SENSE_MODE & FALLING_EDGE) == FALLING_EDGE)
        EXTI->FTSR |= (1<<A_channel.NUMBER);

    //enable interrupt
    if (A_channel.ENABLE)
        EXTI->IMR |= (1<<A_channel.NUMBER);
}

void MEXTI_voidEnableInterrupt(u8 A_u8ChannelNumber)
{
    EXTI->IMR |= (1<<A_u8ChannelNumber);
}

void MEXTI_voidDisableInterrupt(u8 A_u8ChannelNumber)
{
    EXTI->IMR &= ~(1<<A_u8ChannelNumber);
}

void MEXTI_voidChangeSenseMode(u8 A_u8ChannelNumber, u8 A_u8SenseMode)
{
    if ((A_u8SenseMode & RISING_EDGE) == RISING_EDGE)
        EXTI->RTSR |= (1<<A_u8ChannelNumber);
    else
        EXTI->RTSR &= ~(1<<A_u8ChannelNumber);

    if ((A_u8SenseMode & FALLING_EDGE) == FALLING_EDGE)
        EXTI->FTSR |= (1<<A_u8ChannelNumber);
    else
        EXTI->FTSR &= ~(1<<A_u8ChannelNumber);
}

void MEXTI_voidChangePORT(u8 A_u8ChannelNumber, u8 A_u8PORT)
{
    u8 local_u8RegisterNumber = A_u8ChannelNumber / 4;
    u8 local_u8NibbleNumber = A_u8ChannelNumber % 4;

    *(SYSCFG_EXTICR + local_u8RegisterNumber) &= ~(SYSCFG_EXTICR_EXTI_MASK << (local_u8NibbleNumber * NIBBLE_SIZE));
    *(SYSCFG_EXTICR + local_u8RegisterNumber) |= (A_u8PORT << (local_u8NibbleNumber * NIBBLE_SIZE));
}

void MEXTI_voidTriggerPendingFlag(u8 A_u8ChannelNumber)
{
    EXTI->SWIER |= (1<<A_u8ChannelNumber);
}

void MEXTI_voidClearPendingFlag(u8 A_u8ChannelNumber)
{
    EXTI->PR |= (1<<A_u8ChannelNumber);
}

u8 MEXTI_u8ReadTriggerFlag(u8 A_u8ChannelNumber)
{
    return (((EXTI->PR) >> A_u8ChannelNumber) & 1);
}

void MEXTI_voidSetCallBackEXTI(u8 A_u8ChannelNumber, void (*pVoidCallBack) (void))
{
    pVoidCallBackFunctionEXTI[A_u8ChannelNumber] = pVoidCallBack;
}

void EXTI0_IRQHandler(void)
{
	if(pVoidCallBackFunctionEXTI[0] != (void*)0)
		(*pVoidCallBackFunctionEXTI[0])();

    MEXTI_voidClearPendingFlag(0);
}

void EXTI1_IRQHandler(void)
{
	if(pVoidCallBackFunctionEXTI[1] != (void*)0)
		(*pVoidCallBackFunctionEXTI[1])();

    MEXTI_voidClearPendingFlag(1);
}

void EXTI2_IRQHandler(void)
{
	if(pVoidCallBackFunctionEXTI[2] != (void*)0)
		(*pVoidCallBackFunctionEXTI[2])();

    MEXTI_voidClearPendingFlag(0);
}

void EXTI3_IRQHandler(void)
{
	if(pVoidCallBackFunctionEXTI[3] != (void*)0)
		(*pVoidCallBackFunctionEXTI[3])();

    MEXTI_voidClearPendingFlag(3);
}

void EXTI4_IRQHandler(void)
{
	if(pVoidCallBackFunctionEXTI[4] != (void*)0)
		(*pVoidCallBackFunctionEXTI[4])();

    MEXTI_voidClearPendingFlag(4);
}

void EXTI9_5_IRQHandler(void)
{
	if(MEXTI_u8ReadTriggerFlag(5))
	{
		if(pVoidCallBackFunctionEXTI[5] != (void*)0)
			(*pVoidCallBackFunctionEXTI[5])();

		MEXTI_voidClearPendingFlag(5);
	}

	if(MEXTI_u8ReadTriggerFlag(6))
	{
		if(pVoidCallBackFunctionEXTI[6] != (void*)0)
			(*pVoidCallBackFunctionEXTI[6])();

		MEXTI_voidClearPendingFlag(6);
	}

	if(MEXTI_u8ReadTriggerFlag(7))
	{
		if(pVoidCallBackFunctionEXTI[7] != (void*)0)
			(*pVoidCallBackFunctionEXTI[7])();

		MEXTI_voidClearPendingFlag(7);
	}

	if(MEXTI_u8ReadTriggerFlag(8))
	{
		if(pVoidCallBackFunctionEXTI[8] != (void*)0)
			(*pVoidCallBackFunctionEXTI[8])();

		MEXTI_voidClearPendingFlag(8);
	}

	if(MEXTI_u8ReadTriggerFlag(9))
	{
		if(pVoidCallBackFunctionEXTI[9] != (void*)0)
			(*pVoidCallBackFunctionEXTI[9])();

		MEXTI_voidClearPendingFlag(9);
	}
}

void EXTI15_10_IRQHandler(void)
{
	if(MEXTI_u8ReadTriggerFlag(10))
	{
		if(pVoidCallBackFunctionEXTI[10] != (void*)0)
			(*pVoidCallBackFunctionEXTI[10])();

		MEXTI_voidClearPendingFlag(10);
	}

	if(MEXTI_u8ReadTriggerFlag(11))
	{
		if(pVoidCallBackFunctionEXTI[11] != (void*)0)
			(*pVoidCallBackFunctionEXTI[11])();

		MEXTI_voidClearPendingFlag(11);
	}

	if(MEXTI_u8ReadTriggerFlag(12))
	{
		if(pVoidCallBackFunctionEXTI[12] != (void*)0)
			(*pVoidCallBackFunctionEXTI[12])();

		MEXTI_voidClearPendingFlag(12);
	}

	if(MEXTI_u8ReadTriggerFlag(13))
	{
		if(pVoidCallBackFunctionEXTI[13] != (void*)0)
			(*pVoidCallBackFunctionEXTI[13])();

		MEXTI_voidClearPendingFlag(13);
	}

	if(MEXTI_u8ReadTriggerFlag(14))
	{
		if(pVoidCallBackFunctionEXTI[14] != (void*)0)
			(*pVoidCallBackFunctionEXTI[14])();

		MEXTI_voidClearPendingFlag(14);
	}

	if(MEXTI_u8ReadTriggerFlag(15))
	{
		if(pVoidCallBackFunctionEXTI[15] != (void*)0)
			(*pVoidCallBackFunctionEXTI[15])();

		MEXTI_voidClearPendingFlag(15);
	}
}
