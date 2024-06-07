#ifndef MEXTI_PRIVATE_H
#define MEXTI_PRIVATE_H

typedef struct
{
    volatile u32 IMR;
    volatile u32 EMR;
    volatile u32 RTSR;
    volatile u32 FTSR;
    volatile u32 SWIER;
    volatile u32 PR;
}EXTI_t;

#define EXTI ((volatile EXTI_t*)(0x40013C00))

#define SYSCFG_EXTICR ((volatile u32*)(0x40013800 + 0x08))
#define REGISTER_OFFSET 0x04

#define NUMBER_OF_CHANNELS 16

#define SYSCFG_EXTICR_EXTI_MASK 16

#define NIBBLE_SIZE 4

#endif