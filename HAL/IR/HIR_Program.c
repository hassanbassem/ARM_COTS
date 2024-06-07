/*****************************************************************************************
 * Author:				Hassan Bassem Elsayed Ahmed
 * Creation Data:		14 Mar, 2024
 * Version:				v1.0
 * Compiler:			GNU ARM-GCC
 * Controller:			STM32F401CCU6 (32-bit Architecture)
 * Processor:			Cortex M4 (32-bit Architecture)
 * Layer:				HAL Layer
 *****************************************************************************************/
/*****************************************************************************************
 * Version	  Date				  Author				      Description
 * v1.0		  14 Mar, 2024	Hassan Bassem Elsayed Ahmed		  Initial Creation
*****************************************************************************************/

//library inclusions
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

//mcal inclusions
#include "../../MCAL/EXTI/MEXTI_Interface.h"
#include "../../MCAL/STK/MSTK_Interface.h"

//self layer inclusions

//self inclusions
#include "HIR_Interface.h"
#include "HIR_Private.h"
#include "HIR_Cfg.h"

static void (*global_voidIRCallback[NUMBER_OF_KEYS])(void) = {(void*)0};

static u32 global_u32ArrayOfBitTimes[NUMBER_OF_FRAME_BITS];

static u8 global_u8DataFromIR;

static u8 global_u8Counter = 0;

void HIR_voidInit(void)
{
    MEXTI_voidSetCallBackEXTI(EXTI_CHANNEL, &GetTimesOfFrameBits);
}

void HIR_voidSetCallBack(u8 Copy_u8Key, void (*P_voidCallBackFunction)(void))
{
    global_voidIRCallback[Copy_u8Key] = P_voidCallBackFunction;
}

static void GetTimesOfFrameBits(void)
{
	if(global_u8Counter > 0)
		global_u32ArrayOfBitTimes[global_u8Counter - 1] = MSTK_voidGetTimeElapsed();

	MSTK_voidSetIntervalSingle(15000, &GetDataFromArrayOfTimes);

	global_u8Counter++;
}

static void GetDataFromArrayOfTimes(void)
{
	global_u8DataFromIR = 0;
	for(u8 i = 0; i < 8; i++)
		if(global_u32ArrayOfBitTimes[i + 17] > MIN_TIME_OF_HIGH_SIGNAL && global_u32ArrayOfBitTimes[i + 17] < MAX_TIME_OF_HIGH_SIGNAL)
			SET_BIT(global_u8DataFromIR, (8 - i - 1));

	TakeAction();
	global_u8Counter = 0;
}

static void TakeAction(void)
{
    switch (global_u8DataFromIR)
    {
    case CH_MINUS_KEY:
        if (global_voidIRCallback[HIR_CH_MINUS_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_CH_MINUS_KEY])();
        break;
    case CH_KEY:
        if (global_voidIRCallback[HIR_CH_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_CH_KEY])();
        break;
    case CH_PLUS_KEY:
        if (global_voidIRCallback[HIR_CH_PLUS_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_CH_PLUS_KEY])();
        break;
    case PREV_KEY:
        if (global_voidIRCallback[HIR_PREV_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_PREV_KEY])();
        break;
    case NEXT_KEY:
        if (global_voidIRCallback[HIR_NEXT_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_NEXT_KEY])();
        break;
    case PLAY_PAUSE_KEY:
        if (global_voidIRCallback[HIR_PLAY_PAUSE_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_PLAY_PAUSE_KEY])();
        break;
    case VOLUME_MINUS_KEY:
        if (global_voidIRCallback[HIR_VOLUME_MINUS_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_VOLUME_MINUS_KEY])();
        break;
    case VOLUME_PLUS_KEY:
        if (global_voidIRCallback[HIR_VOLUME_PLUS_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_VOLUME_PLUS_KEY])();
        break;
    case EQ_KEY:
        if (global_voidIRCallback[HIR_EQ_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_EQ_KEY])();
        break;
    case ZERO_KEY:
        if (global_voidIRCallback[HIR_ZERO_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_ZERO_KEY])();
        break;
    case ONE_HUNDRED_PLUS_KEY:
        if (global_voidIRCallback[HIR_ONE_HUNDRED_PLUS_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_ONE_HUNDRED_PLUS_KEY])();
        break;
    case TWO_HUNDRED_PLUS_KEY:
        if (global_voidIRCallback[HIR_TWO_HUNDRED_PLUS_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_TWO_HUNDRED_PLUS_KEY])();
        break;
    case ONE_KEY:
        if (global_voidIRCallback[HIR_ONE_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_ONE_KEY])();
        break;
    case TWO_KEY:
        if (global_voidIRCallback[HIR_TWO_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_TWO_KEY])();
        break;
    case THREE_KEY:
        if (global_voidIRCallback[HIR_THREE_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_THREE_KEY])();
        break;
    case FOUR_KEY:
        if (global_voidIRCallback[HIR_FOUR_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_FOUR_KEY])();
        break;
    case FIVE_KEY:
        if (global_voidIRCallback[HIR_FIVE_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_FIVE_KEY])();
        break;
    case SIX_KEY:
        if (global_voidIRCallback[HIR_SIX_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_SIX_KEY])();
        break;
    case SEVEN_KEY:
        if (global_voidIRCallback[HIR_SEVEN_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_SEVEN_KEY])();
        break;
    case EIGHT_KEY:
        if (global_voidIRCallback[HIR_EIGHT_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_EIGHT_KEY])();
        break;
    case NINE_KEY:
        if (global_voidIRCallback[HIR_NINE_KEY] != (void*)0)
            (*global_voidIRCallback[HIR_NINE_KEY])();
        break;
    default:
        break;
    }
}
