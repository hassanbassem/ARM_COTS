#ifndef MNVIC_INTERFACE_H
#define MNVIC_INTERFACE_H

#define MNVIC_EXTI0 6
#define MNVIC_EXTI1 7
#define MNVIC_EXTI2 8
#define MNVIC_EXTI3 9
#define MNVIC_EXTI4 10

void MNVIC_voidInit(void);
void MNVIC_voidSetInterruptEnable(u8 A_u8PeripheralName);
void MNVIC_voidClearInterruptEnable(u8 A_u8PeripheralName);
void MNVIC_voidSetInterruptPendingFlag(u8 A_u8PeripheralName);
void MNVIC_voidClearInterruptPendingFlag(u8 A_u8PeripheralName);
void MNVIC_voidSetInterruptPriority(u8 A_u8PeripheralName, u8 A_u8Priority);
u8 MNVIC_u8ReadActiveFlag(u8 A_u8PeripheralName);

#endif