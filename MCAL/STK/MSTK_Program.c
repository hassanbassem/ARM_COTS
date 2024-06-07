#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

#include "MSTK_Interface.h"
#include "MSTK_Private.h"
#include "MSTK_Cfg.h"

void (*global_PvoidSysTickCallBack) (void) = 0;
u8 global_u8PeriodicFlag;

void MSTK_voidInit(void)
{
    //choose SysTick clock source
#if STK_CLK_SOURCE == AHB
    SET_BIT(STK_CTRL, CLKSOURCE);
#elif STK_CLK_SOURCE == AHB_DIV_8
    CLR_BIT(STK_CTRL, CLKSOURCE);
#else
    #error ("Wrong configuration in choosing clock source")
#endif

#if STK_INTERRUPT_ENABLE < 0 || STK_INTERRUPT_ENABLE > 1
    #error ("Wrong configuration of interrupt enable")
#endif

    //set interrupt enable configuration
    STK_CTRL &= ~(ONE_BIT_MASK<<TICKINT);
    STK_CTRL |= (STK_INTERRUPT_ENABLE<<TICKINT);
}

void MSTK_voidSetBusyWait(u32 A_u32TimeInUs)
{
    //set reload value
    STK_LOAD = A_u32TimeInUs - 1;
    //clear current value register
    STK_VAL = 0;
    //enable SysTick Timer
    SET_BIT(STK_CTRL, ENABLE);
    //Polling on flag
    while (!GET_BIT(STK_CTRL, COUNTFLAG));
    //Disable SysTick Timer
    CLR_BIT(STK_CTRL, ENABLE);
}

void MSTK_voidSetIntervalSingle(u32 A_u32TimeInUs, void (*P_u8CallBack)(void))
{
    //set Reload Value
    STK_LOAD = A_u32TimeInUs - 1;
    //clear current value register
    STK_VAL = 0;
    //reset Periodic flag
    global_u8PeriodicFlag = 0;
    //set callback
    global_PvoidSysTickCallBack = P_u8CallBack;
    //Enable SysTick Timer
    SET_BIT(STK_CTRL, ENABLE);
}

void MSTK_voidSetIntervalPeriodic(u32 A_u32TimeInUs, void (*P_u8CallBack)(void))
{
    //set Reload Value
    STK_LOAD = A_u32TimeInUs - 1;
    //clear current value register
    STK_VAL = 0;
    //set Periodic flag
    global_u8PeriodicFlag = 1;
    //set callback
    global_PvoidSysTickCallBack = P_u8CallBack;
    //Enable SysTick Timer
    SET_BIT(STK_CTRL, ENABLE);
}

u32 MSTK_voidGetTimeElapsed(void)
{
    return STK_LOAD - STK_VAL;
}

u32 MSTK_voidGetTimeRemaining(void)
{
    return STK_VAL + 1;
}

void SysTick_Handler(void)
{
    //Call callback function
    if (global_PvoidSysTickCallBack)
        (*global_PvoidSysTickCallBack)();

    //disable SysTick Timer if flag is reset
    if (!global_u8PeriodicFlag)
        CLR_BIT(STK_CTRL, ENABLE);

    //clear flag
    STK_VAL = 0;
}

