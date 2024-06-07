#ifndef MSTK_INTERFACE_H
#define MSTK_INTERFACE_H

/**
 * @brief initialize SysTick Timer
 * 
 * @return void
 */
void MSTK_voidInit(void);
/**
 * @brief 
 * 
 * @param A_u32TimeInUs 
 * 
 * @return void
 */
void MSTK_voidSetBusyWait(u32 A_u32TimeInUs);

void MSTK_voidSetIntervalSingle(u32 A_u32TimeInUs, void (*P_u8CallBack)(void));

void MSTK_voidSetIntervalPeriodic(u32 A_u32TimeInUs, void (*P_u8CallBack)(void));

u32 MSTK_voidGetTimeElapsed(void);

u32 MSTK_voidGetTimeRemaining(void);

#endif