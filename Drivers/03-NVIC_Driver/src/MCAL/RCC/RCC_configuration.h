/*
 * RCC_configuration.h
 *
 *  Created on: Jul 21, 2023
 *      Author: Mario Ezzat
 */

#ifndef MCAL_RCC_RCC_CONFIGURATION_H_
#define MCAL_RCC_RCC_CONFIGURATION_H_
/* ----------------------------- Clock Selection ---------------------------- */
/*
case of failure of the HSE oscillator used directly or indirectly as the system clock.
    oscillator selected as system clock   HSI_CLK
    oscillator selected as system clock   HSE_CLK
    PLL selected as system clock          PLL_CLK
*/
#define RCC_SYS_CLK     HSE_CLK
/* -------------------------------------------------------------------------- */
/* -------------------------- Clock Security System ------------------------- */
/* RCC_CSS: (ENABLE- DISABLE)*/
#define RCC_CSS         ENABLE
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                            Clock Source Control                            */
/* -------------------------------------------------------------------------- */
/* ----------------------------- Internal Clock ----------------------------- */
/* RCC_HSI -->(ENABLE - DISABLE)  to use internal clock */
#define RCC_HSI         DISABLE
/* -------------------------------------------------------------------------- */
/* ----------------------------- External Clock ----------------------------- */
/* RCC_HSE -->(ENABLE - DISABLE)  to use external clock */
#define RCC_HSE         ENABLE
/* RCC_HSE_BYPASS: ENABLE --> External Clock - DISABLE --> Crystal */
#define RCC_HSE_BYPASS  DISABLE
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                  PLL SETUP                                 */
/* -------------------------------------------------------------------------- */
/* PLL (Enable / Disable) */
#define RCC_PLL         DISABLE
/* FPLL_IN: the value of the Clock in MHz */
#define FPLL_IN         18
/* PLLM_VALUE: Range (2 ... 63) in binary (0b000010...0b111111) */
#define PLLM_VALUE      0b000010
/* PLLP_VALUE: Range (2/4/6/8) (0b00/0b01/0b10/0b11)*/
#define PLLP_VALUE      0b00
/* PLN_VALUE: Range (192 .. 432) 0b110110000*/
#define PLLN_VALUE      0b110110000
/* -------------------------------------------------------------------------- */
#endif /* MCAL_RCC_RCC_CONFIGURATION_H_ */
