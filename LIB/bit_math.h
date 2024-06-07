/*
 * bit_math.h
 *
 *  Created on: Apr 16, 2023
 *      Author: hassan
 */

#ifndef INCLUDE_LIB_BIT_MATH_H_
#define INCLUDE_LIB_BIT_MATH_H_

#define SET_BIT(Reg, bitNum) (Reg |= 1<<bitNum)
#define CLR_BIT(Reg, bitNum) (Reg &= ~(1<<bitNum))
#define TOGGLE_BIT(Reg, bitNum) (Reg ^= 1<<bitNum)
#define GET_BIT(Reg, bitNum) (Reg>>bitNum & 1)

#define ONE_BIT_MASK 1
#define TWO_BIT_MASK 3
#define THREE_BIT_MASK 7
#define FOUR_BIT_MASK 15

#define GET_LOWER_NIBBLE(Reg) (Reg << 4)
#define GET_UPPER_NIBBLE(Reg) (Reg & 0b11110000)

#define CONC_BIT(b7,b6,b5,b4,b3,b2,b1,b0) Conc_help(b7,b6,b5,b4,b3,b2,b1,b0)
#define Conc_help(b7,b6,b5,b4,b3,b2,b1,b0) 0b##b7##b6##b5##b4##b3##b2##b1##b0



#endif /* INCLUDE_LIB_BIT_MATH_H_ */
