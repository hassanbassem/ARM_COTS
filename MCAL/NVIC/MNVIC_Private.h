#ifndef MNVIC_PRIVATE_H
#define MNVIC_PRIVATE_H

typedef struct
{
    volatile u32 ISER[8];
    volatile u32 offset1[24];
    volatile u32 ICER[8];
    volatile u32 offset2[24];
    volatile u32 ISPR[8];
    volatile u32 offset3[24];
    volatile u32 ICPR[8];
    volatile u32 offset4[24];
    volatile u32 IABR[8];
    volatile u32 offset5[56];
    volatile u8 IPR[240];
}NVIC_STRUCT;

#define NVIC ((volatile NVIC_STRUCT*)(0xE000E100))

#endif