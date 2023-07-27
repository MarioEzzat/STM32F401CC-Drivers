/*
 * RCC_interface.h
 *
 *  Created on: Jul 21, 2023
 *      Author: Mario Ezzat
 */

#ifndef MCAL_RCC_RCC_INTERFACE_H_
#define MCAL_RCC_RCC_INTERFACE_H_
/* --------------------------------- RCC BUS -------------------------------- */
#define AHB1    0
#define AHB2    1
#define APB1    2
#define APB2    3
/* -------------------------------------------------------------------------- */

/* ------------------------------- PLL VALUES ------------------------------- */
u8 FPLL;
#define FPLL_MAX    84
/* -------------------------------------------------------------------------- */
/* ------------------------------- Clock Value ------------------------------ */
#define HSI_CLK     0
#define HSE_CLK     1
#define PLL_CLK     2
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                             Register Bit Names                             */
/* -------------------------------------------------------------------------- */

/* --------------------------------- RCC-CR --------------------------------- */
#define HSION       0
#define HSIRDY      1
#define HSEON       16
#define HSERDY      17
#define HSEPYPY     18
#define CSSON       19
#define PLLON       24
#define PLLRDY      25
#define PLL2SON     26
#define PLL2SRDY    27
/* -------------------------------------------------------------------------- */

/* ------------------------------- RCC-PLLCFGR ------------------------------ */
#define PLLM0       0
#define PLLM1       1
#define PLLM2       2
#define PLLM3       3
#define PLLM4       4
#define PLLM5       5
/* -------------------------------------------------------------------------- */

/* -------------------------------- RCC-CFGR -------------------------------- */
#define SW0         0
#define SW1         1
#define SWS0        2
#define SWS1        3

/* -------------------------------------------------------------------------- */

/* ------------------------------- RCC-AHB1ENR ------------------------------ */
#define AHB1_GPIOAEN     0
#define AHB1_GPIOBEN     1
#define AHB1_GPIOCEN     2
#define AHB1_CRCEN       12
#define AHB1_DMA1EN      21
#define AHB1_DMA2EN      22
/* -------------------------------------------------------------------------- */

/* ------------------------------- RCC-AHB2ENR ------------------------------ */
#define AHB2_OTGFSEN     7
/* -------------------------------------------------------------------------- */

/* ------------------------------- RCC-APB1ENR ------------------------------ */
#define APB1_TIM2EN      0
#define APB1_TIM3EN      1
#define APB1_TIM4EN      2
#define APB1_TIM5EN      3
#define APB1_WWDGEN      11
#define APB1_SPI2EN      14
#define APB1_SPI3EN      15
#define APB1_UASRT2EN    17
#define APB1_I2C1EN      21
#define APB1_I2C2EN      22
#define APB1_I2C3EN      23
#define APB1_PWREN       28
/* -------------------------------------------------------------------------- */

/* ------------------------------- RCC-APB2ENR ------------------------------ */
#define APB2_TIM1EN      0
#define APB2_USART1EN    4
#define APB2_USART2EN    5
#define APB2_ADC1EN      8
#define APB2_SDIOEN      11
#define APB2_SPI1EN      12
#define APB2_SOI4EN      13
#define APB2_SYSCFGEN    14
#define APB2_TIM9EN      16
#define APB2_TIM10EN     17
#define APB2_TIM11EN     18
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  Functions                                 */
/* -------------------------------------------------------------------------- */
/* ------------------------------- Initialize ------------------------------- */
void MRCC_voidInit(void);
/* ------------------------- Enable Peripheral clock ------------------------ */
void MRCC_voidEnableClock(u32 A_u32BusID, u32 A_u32PeripheralID);
/* ------------------------ Disable Peripheral clock ------------------------ */
void MRCC_voidDisableClock(u32 A_u32BusID, u32 A_u32PeripheralID);




#endif /* MCAL_RCC_RCC_INTERFACE_H_ */
