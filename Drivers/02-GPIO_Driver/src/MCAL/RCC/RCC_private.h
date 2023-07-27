/*
 * RCC_private.h
 *
 *  Created on: Jul 21, 2023
 *      Author: Mario Ezzat
 */

#ifndef MCAL_RCC_RCC_PRIVATE_H_
#define MCAL_RCC_RCC_PRIVATE_H_

/* ------------------------------- BIT VALUES ------------------------------- */
#define ENABLE      1
#define DISABLE     0
#define SET         1
#define RESET       0
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                             Registers Addresses                            */
/* -------------------------------------------------------------------------- */

/* ----------- base address: the first address in registers range ----------- */
#define RCC_BASE_ADDRESS    0x40023800  // from memory map table 

/* --------------------- arrange the registers addresses -------------------- */
typedef struct 
{
    u32 CR;
    u32 PLLCFGR;
    u32 CFGR;
    u32 CIR;
    
    u32 AHB1RSTR;
    u32 AHB2RSTR;
    u32 reserved1;  // reserved
    u32 reserved2;  // reserved
    
    u32 APB1RSTR;
    u32 APB2RSTR;
    u32 reserved3;  // reserved
    u32 reserved4;  // reserved

    u32 AHB1ENR;
    u32 AHB2ENR;
    u32 reserved5;  // reserved
    u32 reserved6;  // reserved

    u32 APB1ENR;
    u32 APB2ENR;
    u32 reserved7;  // reserved
    u32 reserved8;  // reserved
    
    u32 AHB1LPENR;
    u32 AHB2LPENR;
    u32 reserved9;  // reserved
    u32 reserved10;  // reserved

    u32 APB1LPENR;
    u32 APB2LPENR;
    u32 reserved11;  // reserved
    u32 reserved12; // reserved

    u32 BDCR;
    u32 CSR;
    u32 reserved13; // reserved
    u32 reserved14; // reserved

    u32 SSCGR;
    u32 PLLI2SCFGR;
    u32 DCKCFGR;

}RCC_Memmap_t;

/* ------------ pointer to the base address of the registers range ----------- */
#define RCC ((volatile RCC_Memmap_t*) (RCC_BASE_ADDRESS))

#endif /* MCAL_RCC_RCC_PRIVATE_H_ */
