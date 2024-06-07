#ifndef MEXTI_INTERFACE_H
#define MEXTI_INTERFACE_H

#define PORTA 0
#define PORTB 1
#define PORTC 2
#define NONE 3

#define RISING_EDGE 1
#define FALLING_EDGE 2
#define RISING_EDGE_AND_FALLING_EDGE (RISING_EDGE | FALLING_EDGE)

#define ENABLE_INTERRUPT 1
#define DISABLE_INTERRUPT 0

typedef struct
{
    u8 NUMBER;
    u8 PORT;
    u8 SENSE_MODE;
    u8 ENABLE;
}Channel_t;

void MEXTI_voidInitializeChannel(Channel_t A_channel);
void MEXTI_voidEnableInterrupt(u8 A_u8ChannelNumber);
void MEXTI_voidDisableInterrupt(u8 A_u8ChannelNumber);
void MEXTI_voidChangeSenseMode(u8 A_u8ChannelNumber, u8 A_u8SenseMode);
void MEXTI_voidChangePORT(u8 A_u8ChannelNumber, u8 A_u8PORT);
void MEXTI_voidTriggerPendingFlag(u8 A_u8ChannelNumber);
void MEXTI_voidClearPendingFlag(u8 A_u8ChannelNumber);
u8 MEXTI_u8ReadTriggerFlag(u8 A_u8ChannelNumber);
void MEXTI_voidSetCallBackEXTI(u8 A_u8ChannelNumber, void (*pVoidCallBack) (void));

#endif