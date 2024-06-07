#ifndef MSTK_PRIVATE_H
#define MSTK_PRIVATE_H

#define STK_BASE_ADDRESS 0xE000E010

#define STK_CTRL (*(volatile u32*)(STK_BASE_ADDRESS + 0x00))
#define STK_LOAD (*(volatile u32*)(STK_BASE_ADDRESS + 0x04))
#define STK_VAL (*(volatile u32*)(STK_BASE_ADDRESS + 0x08))
#define STK_CALIB (*(volatile u32*)(STK_BASE_ADDRESS + 0x0C))

#define COUNTFLAG 16
#define CLKSOURCE 2
#define TICKINT 1
#define ENABLE 0

#define AHB 0
#define AHB_DIV_8 1

#endif
