/*
 * NVIC_private.h
 *
 *  Created on: Jul 25, 2023
 *      Author: Mario Ezzat
 */

#ifndef MCAL_NVIC_NVIC_PRIVATE_H_
#define MCAL_NVIC_NVIC_PRIVATE_H_

/* -------------------------------------------------------------------------- */
/*                               Private Values                               */
/* -------------------------------------------------------------------------- */
#define REG_SIZE 32
#define BIT_HIGH 1
#define BIT_LOW 0

#define SCB_AIRCR_PASS_KEY 0x05FA0000
#define SHIFT_8 8
#define SHIFT_6 6
#define SHIFT_4 4
#define SHIFT_2 2

#define TWO_BIT 0b0011
#define THREE_BIT 0b0111

/* -------------------------------------------------------------------------- */
/*                                    NVIC                                    */
/* -------------------------------------------------------------------------- */
#define NVIC_BASEADDRESS 0xE000E100
typedef struct
{
    u32 ISER[8];
    u32 Reserved_1[24];
    u32 ICER[8];
    u32 Reserved_2[24];
    u32 ISPR[8];
    u32 Reserved_3[24];
    u32 ICPR[8];
    u32 Reserved_4[24];
    u32 IABR[8];
    u32 Reserved_5[57];
    u8 IPR[240]; 
} NVIC_MemMap_t;

#define NVIC ((volatile NVIC_MemMap_t *)(NVIC_BASEADDRESS))

/* -------------------------------------------------------------------------- */
/*                                     SCB                                    */
/* -------------------------------------------------------------------------- */
#define SCB_BASEADDRESS 0xE000ED00
typedef struct
{
    u32 CPUID;
    u32 ICSR;
    u32 VTOR;
    u32 AIRCR;
    u32 SCR;
    u32 CCR;
    u32 SHPR1;
    u32 SHPR2;
    u32 SHPR3;
    u32 SHCSR;
    u32 CFSR;
    u32 HFSR;
    u32 MMAR;
    u32 BFAR;
    u32 AFSR;
} SCB_MemMap_t;

#define SCB ((volatile SCB_MemMap_t *)(SCB_BASEADDRESS))

#endif /* MCAL_NVIC_NVIC_PRIVATE_H_ */
