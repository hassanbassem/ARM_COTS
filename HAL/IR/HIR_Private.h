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

#ifndef HIR_PRIVATE_H
#define HIR_PRIVATE_H

#define NUMBER_OF_KEYS 21
#define NUMBER_OF_FRAME_BITS 33

#define MIN_TIME_OF_HIGH_SIGNAL 2200
#define MAX_TIME_OF_HIGH_SIGNAL 2300

#define CH_MINUS_KEY 162
#define CH_KEY 98
#define CH_PLUS_KEY 226
#define PREV_KEY 34
#define NEXT_KEY 2
#define PLAY_PAUSE_KEY 194
#define VOLUME_MINUS_KEY 224
#define VOLUME_PLUS_KEY 168
#define EQ_KEY 144
#define ZERO_KEY 104
#define ONE_HUNDRED_PLUS_KEY 152
#define TWO_HUNDRED_PLUS_KEY 176
#define ONE_KEY 48
#define TWO_KEY 24
#define THREE_KEY 122
#define FOUR_KEY 16
#define FIVE_KEY 56
#define SIX_KEY 90
#define SEVEN_KEY 66
#define EIGHT_KEY 74
#define NINE_KEY 82

static void GetTimesOfFrameBits(void);
static void GetDataFromArrayOfTimes(void);
static void TakeAction(void);  

#endif