#ifndef MGPIO_PRIVATE_H
#define MGPIO_PRIVATE_H

#define GPIOA_BASE_ADDRESS 0x40020000
#define GPIOB_BASE_ADDRESS 0x40020400
#define GPIOC_BASE_ADDRESS 0x40020800

#define MODER_OFFSET 0x00
#define OTYPER_OFFSET 0x04
#define OSPEEDR_OFFSET 0x08
#define PUPDR_OFFSET 0x0C
#define IDR_OFFSET 0x10
#define ODR_OFFSET 0x14
#define BSRR_OFFSET 0x18
#define LCKR_OFFSET 0x1C
#define AFRL_OFFSET 0x20
#define AFRH_OFFSET 0x24

#define GPIOA_MODER (*(volatile u32*)(GPIOA_BASE_ADDRESS + MODER_OFFSET))
#define GPIOA_OTYPER (*(volatile u32*)(GPIOA_BASE_ADDRESS + OTYPER_OFFSET))
#define GPIOA_OSPEEDR (*(volatile u32*)(GPIOA_BASE_ADDRESS + OSPEEDR_OFFSET))
#define GPIOA_PUPDR (*(volatile u32*)(GPIOA_BASE_ADDRESS + PUPDR_OFFSET))
#define GPIOA_IDR (*(volatile u32*)(GPIOA_BASE_ADDRESS + IDR_OFFSET))
#define GPIOA_ODR (*(volatile u32*)(GPIOA_BASE_ADDRESS + ODR_OFFSET))
#define GPIOA_BSRR (*(volatile u32*)(GPIOA_BASE_ADDRESS + BSRR_OFFSET))
#define GPIOA_LCKR (*(volatile u32*)(GPIOA_BASE_ADDRESS + LCKR_OFFSET))
#define GPIOA_AFRL (*(volatile u32*)(GPIOA_BASE_ADDRESS + AFRL_OFFSET))
#define GPIOA_AFRH (*(volatile u32*)(GPIOA_BASE_ADDRESS + AFRH_OFFSET))

#define GPIOB_MODER (*(volatile u32*)(GPIOB_BASE_ADDRESS + MODER_OFFSET))
#define GPIOB_OTYPER (*(volatile u32*)(GPIOB_BASE_ADDRESS + OTYPER_OFFSET))
#define GPIOB_OSPEEDR (*(volatile u32*)(GPIOB_BASE_ADDRESS + OSPEEDR_OFFSET))
#define GPIOB_PUPDR (*(volatile u32*)(GPIOB_BASE_ADDRESS + PUPDR_OFFSET))
#define GPIOB_IDR (*(volatile u32*)(GPIOB_BASE_ADDRESS + IDR_OFFSET))
#define GPIOB_ODR (*(volatile u32*)(GPIOB_BASE_ADDRESS + ODR_OFFSET))
#define GPIOB_BSRR (*(volatile u32*)(GPIOB_BASE_ADDRESS + BSRR_OFFSET))
#define GPIOB_LCKR (*(volatile u32*)(GPIOB_BASE_ADDRESS + LCKR_OFFSET))
#define GPIOB_AFRL (*(volatile u32*)(GPIOB_BASE_ADDRESS + AFRL_OFFSET))
#define GPIOB_AFRH (*(volatile u32*)(GPIOB_BASE_ADDRESS + AFRH_OFFSET))

#define GPIOC_MODER (*(volatile u32*)(GPIOC_BASE_ADDRESS + MODER_OFFSET))
#define GPIOC_OTYPER (*(volatile u32*)(GPIOC_BASE_ADDRESS + OTYPER_OFFSET))
#define GPIOC_OSPEEDR (*(volatile u32*)(GPIOC_BASE_ADDRESS + OSPEEDR_OFFSET))
#define GPIOC_PUPDR (*(volatile u32*)(GPIOC_BASE_ADDRESS + PUPDR_OFFSET))
#define GPIOC_IDR (*(volatile u32*)(GPIOC_BASE_ADDRESS + IDR_OFFSET))
#define GPIOC_ODR (*(volatile u32*)(GPIOC_BASE_ADDRESS + ODR_OFFSET))
#define GPIOC_BSRR (*(volatile u32*)(GPIOC_BASE_ADDRESS + BSRR_OFFSET))
#define GPIOC_LCKR (*(volatile u32*)(GPIOC_BASE_ADDRESS + LCKR_OFFSET))
#define GPIOC_AFRL (*(volatile u32*)(GPIOC_BASE_ADDRESS + AFRL_OFFSET))
#define GPIOC_AFRH (*(volatile u32*)(GPIOC_BASE_ADDRESS + AFRH_OFFSET))

#define RESET_PIN0 16

#define LCKK 16

#endif