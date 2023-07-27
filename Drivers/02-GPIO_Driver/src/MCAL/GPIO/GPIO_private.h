/*
 * GPIO_private.h
 *
 *  Created on: Jul 22, 2023
 *      Author: Mario Ezzat
 */

#ifndef MCAL_GPIO_GPIO_PRIVATE_H_
#define MCAL_GPIO_GPIO_PRIVATE_H_

#define GPIO_INPUT_conc  00
#define GPIO_OUTPUT_conc 01
#define GPIO_ALTFUN_conc 10
#define GPIO_ANALOG_conc 11

#define LOW_SPEED_conc   00
#define MED_SPEED_conc   01
#define HIGH_SPEED_conc  10
#define VHIGH_SPEED_conc 11

#define NO_PULL_conc    00
#define PULL_UP_conc    01
#define PULL_DOWN_conc  10

#define GPIOA_BASE_ADDRESS  0x40020000
#define GPIOB_BASE_ADDRESS  0x40020400
#define GPIOC_BASE_ADDRESS  0x40020800

typedef struct
{
    u32 MODER;
    u32 OTYPER;
    u32 OSPEEDR;
    u32 PUPDR;
    u32 IDR;
    u32 ODR;
    u32 BSRR;
    u32 LCKR;
    u32 AFRL;
    u32 AFRH;
} GPIO_MemMap_t;

#define GPIOA ((volatile GPIO_MemMap_t*)(GPIOA_BASE_ADDRESS))
#define GPIOB ((volatile GPIO_MemMap_t*)(GPIOB_BASE_ADDRESS))
#define GPIOC ((volatile GPIO_MemMap_t*)(GPIOC_BASE_ADDRESS))

#define AF00 0b0000
#define AF01 0b0001
#define AF02 0b0010
#define AF03 0b0011
#define AF04 0b0100
#define AF05 0b0101
#define AF06 0b0110
#define AF07 0b0111
#define AF08 0b1000
#define AF09 0b1001
#define AF10 0b1010
#define AF11 0b1011
#define AF12 0b1100
#define AF13 0b1101
#define AF14 0b1110
#define AF15 0b1111

#endif /* MCAL_GPIO_GPIO_PRIVATE_H_ */
