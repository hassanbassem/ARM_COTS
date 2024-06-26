#ifndef MRCC_CFG_H
#define MRCC_CFG_H

/*Options:
    HSI
    HSE
    PLL
*/
#define CLOCK_SOURCE HSI

/*Options:
    PLL_HSI
    PLL_HSE
*/
#define PLL_SOURCE PLL_HSI
/*Options:
    2-510 except 433
*/
#define PLL_MULTIPLICATION_FACTOR NA
/*Options:
    2-63
*/
#define PLL_DIVISION_FACTOR NA

/*Options:
AHB_DIV_1
AHB_DIV_2
AHB_DIV_4
AHB_DIV_8
AHB_DIV_16
AHB_DIV_32
AHB_DIV_64
AHB_DIV_128
AHB_DIV_256
AHB_DIV_512
*/
#define AHB_PRESCALER AHB_DIV_2

/*Options:
APB_DIV_1
APB_DIV_2
APB_DIV_4
APB_DIV_8
APB_DIV_16
*/
#define APB1_PRESCALER APB_DIV_1
#define APB2_PRESCALER APB_DIV_1

#define MCO1_PRESCALER NA
#define MCO2_PRESCALER NA


#endif
