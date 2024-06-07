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

#ifndef HIR_INTERFACE_H
#define HIR_INTERFACE_H


#define HIR_CH_MINUS_KEY 0
#define HIR_CH_KEY 1
#define HIR_CH_PLUS_KEY 2
#define HIR_PREV_KEY 3
#define HIR_NEXT_KEY 4
#define HIR_PLAY_PAUSE_KEY 5
#define HIR_VOLUME_MINUS_KEY 6
#define HIR_VOLUME_PLUS_KEY 7
#define HIR_EQ_KEY 8
#define HIR_ZERO_KEY 9
#define HIR_ONE_HUNDRED_PLUS_KEY 10
#define HIR_TWO_HUNDRED_PLUS_KEY 11
#define HIR_ONE_KEY 12
#define HIR_TWO_KEY 13
#define HIR_THREE_KEY 14
#define HIR_FOUR_KEY 15
#define HIR_FIVE_KEY 16
#define HIR_SIX_KEY 17
#define HIR_SEVEN_KEY 18
#define HIR_EIGHT_KEY 19
#define HIR_NINE_KEY 20

void HIR_voidInit(void);
void HIR_voidSetCallBack(u8 Copy_u8Key, void (*P_voidCallBackFunction)(void));

#endif