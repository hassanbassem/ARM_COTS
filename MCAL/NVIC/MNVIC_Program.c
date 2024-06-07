//library directives
#include "../../LIB/bit_math.h"
#include "../../LIB/std_types.h"

//nvic directives
#include "MNVIC_Interface.h"
#include "MNVIC_Private.h"
#include "MNVIC_Cfg.h"

void MNVIC_voidInit(void)
{
    #define SCB_AIRCR (*(volatile u32*)(0xE000ED00 + 0x0C))
    #define PRIGROUP 8
    #define VECTKEY_BIT 16
    #define VECTKEY 0x5FA
    #define ENDIANESS 15

	SCB_AIRCR = ((VECTKEY<<VECTKEY_BIT) | (PRIORITY_GROUPING<<PRIGROUP));
}

void MNVIC_voidSetInterruptEnable(u8 A_u8PeripheralName)
{
    u8 local_u8RegisterNumber = A_u8PeripheralName/32;
    u32 local_u32BitNumber = A_u8PeripheralName%32;

    NVIC->ISER[local_u8RegisterNumber] = (1<<local_u32BitNumber);
}

void MNVIC_voidClearInterruptEnable(u8 A_u8PeripheralName)
{
    u8 local_u8RegisterNumber = A_u8PeripheralName/32;
    u32 local_u32BitNumber = A_u8PeripheralName%32;

    NVIC->ICER[local_u8RegisterNumber] = (1<<local_u32BitNumber);
}

void MNVIC_voidSetInterruptPendingFlag(u8 A_u8PeripheralName)
{
    u8 local_u8RegisterNumber = A_u8PeripheralName/32;
    u32 local_u32BitNumber = A_u8PeripheralName%32;

    NVIC->ISPR[local_u8RegisterNumber] = (1<<local_u32BitNumber);   
}

void MNVIC_voidClearInterruptPendingFlag(u8 A_u8PeripheralName)
{
    u8 local_u8RegisterNumber = A_u8PeripheralName/32;
    u32 local_u32BitNumber = A_u8PeripheralName%32;

    NVIC->ICPR[local_u8RegisterNumber] = (1<<local_u32BitNumber);  
}

void MNVIC_voidSetInterruptPriority(u8 A_u8PeripheralName, u8 A_u8Priority)
{
    NVIC->IPR[A_u8PeripheralName] = (A_u8Priority<<4);
}

u8 MNVIC_u8ReadActiveFlag(u8 A_u8PeripheralName)
{
    u8 local_u8RegisterNumber = A_u8PeripheralName/32;
    u32 local_u32BitNumber = A_u8PeripheralName%32;

    return GET_BIT(NVIC->IABR[local_u8RegisterNumber], local_u32BitNumber);   
}