/*
 * RCC_program.c
 *
 *  Created on: Jul 21, 2023
 *      Author: Mario Ezzat
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
/* --------------------------------- STD KIB -------------------------------- */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/* -------------------------------------------------------------------------- */

/* -------------------------------- RCC MCAL -------------------------------- */
#include "RCC_interface.h"
#include "RCC_configuration.h"
#include "RCC_private.h"
/* -------------------------------------------------------------------------- */


/* -------------------------------------------------------------------------- */
/*                                   Program                                  */
/* -------------------------------------------------------------------------- */
/* ------------------------------- Initialize ------------------------------- */
void MRCC_voidInit()
{
	/* HSI SOURCE */
#if RCC_HSI == ENABLE
#if RCC_SYS_CLK == HSI_CLK
	/* CSS */
#if RCC_CSS == ENABLE
	SET_BIT(RCC->CR,CSSON);
#endif
	CLR_BIT(RCC-> CFGR, SW0);
	CLR_BIT(RCC-> CFGR, SW1);
	/* HSI (ENABLE/DISABLE) */

#endif
	/* SET HSI */
	SET_BIT(RCC ->CR, HSION);
#endif

	/* HSE SOURCE */
#if RCC_HSE == ENABLE
#if RCC_SYS_CLK == HSE_CLK
	/* CSS */
#if RCC_CSS == ENABLE
	SET_BIT(RCC->CR, CSSON);
#endif
	/* Set Configuration HSE */
	SET_BIT(RCC->CFGR, SW0);
	CLR_BIT(RCC-> CFGR, SW1);
#endif
	/* Bypassed (ENABLE/DISABLE) */
#if RCC_HSE_BYPASS == ENABLE
	SET_BIT(RCC ->CR, HSEPYPY);
#elif RCC_HSE_BYPASS == DISABLE
	CLR_BIT(RCC ->CR, HSEPYPY);
#else
#error "Invalid RCC_HSE_BYPASS Value"
#endif
	SET_BIT(RCC ->CR, HSEON);
#endif


	/* PLL ENABLE */
#if RCC_SYS_CLK == PLL_CLK
	/* Set Configuration PLL */
	CLR_BIT(RCC->CFGR, SW0);
	SET_BIT(RCC-> CFGR, SW1);
	/* Prescalers for bus  */
#if RCC_PLL == ENABLE
#if PLLM_VALUE == 2
#if (PLLN_VALUE == 432)
#if (PLLP_VALUE ==0 || PLLP_VALUE == 1 || PLLP_VALUE == 2 || PLLP_VALUE == 3)

	FPLL = (FPLL_IN * (u8)PLLN_VALUE)/((((u8)PLLP_VALUE)*2 +2)*((u16)PLLM_VALUE));

#if FPLL <= FPLL_MAX
	RCC ->PLLCFGR |= (PLLP << 16);
	RCC ->PLLCFGR |= (PLLN << 6);
	RCC ->PLLCFGR |= (PLLM);
#else
#error "Invalid Frequency Change PLLM_VALUE, PLLN_VALUE, and PLLP_VALUE"
#endif
#else
#error "Invalid PLLP_VALUE"
#endif
#else
#error "Invalid PLLN_VALUE"
#endif
#else
#error "Invalid PLLM_VALUE"
#endif
#endif
#endif

}
/* -------------------------------------------------------------------------- */


/* ------------------------- Enable Peripheral clock ------------------------ */
void MRCC_voidEnableClock(u32 A_u32BusID, u32 A_u32PeripheralID)
{
    switch (A_u32BusID)
    {
    case AHB1:
        if (A_u32PeripheralID == AHB1_GPIOAEN || A_u32PeripheralID == AHB1_GPIOBEN ||
            A_u32PeripheralID == AHB1_GPIOCEN || A_u32PeripheralID == AHB1_CRCEN ||
            A_u32PeripheralID == AHB1_DMA1EN || A_u32PeripheralID == AHB1_DMA2EN)
        {
            SET_BIT(RCC->AHB1ENR, A_u32PeripheralID);
        }
        break;
    case AHB2:
        if (A_u32PeripheralID == AHB2_OTGFSEN)
        {
            SET_BIT(RCC->AHB2ENR, A_u32PeripheralID);
        }
        break;
    case APB1:
        if (A_u32PeripheralID == APB1_TIM2EN || A_u32PeripheralID == APB1_TIM3EN ||
            A_u32PeripheralID == APB1_TIM4EN || A_u32PeripheralID == APB1_TIM5EN ||
            A_u32PeripheralID == APB1_WWDGEN || A_u32PeripheralID == APB1_SPI2EN ||
            A_u32PeripheralID == APB1_SPI3EN || A_u32PeripheralID == APB1_UASRT2EN ||
            A_u32PeripheralID == APB1_I2C1EN || A_u32PeripheralID == APB1_I2C2EN ||
            A_u32PeripheralID == APB1_I2C3EN || A_u32PeripheralID == APB1_PWREN)
        {
            SET_BIT(RCC->APB1ENR, A_u32PeripheralID);
        }
        break;
    case APB2:
        if (A_u32PeripheralID == APB2_TIM1EN || A_u32PeripheralID == APB2_USART1EN ||
            A_u32PeripheralID == APB2_USART2EN || A_u32PeripheralID == APB2_ADC1EN ||
            A_u32PeripheralID == APB2_SDIOEN || A_u32PeripheralID == APB2_SPI1EN ||
            A_u32PeripheralID == APB2_SOI4EN || A_u32PeripheralID == APB2_SYSCFGEN ||
            A_u32PeripheralID == APB2_TIM9EN || A_u32PeripheralID == APB2_TIM10EN ||
            A_u32PeripheralID == APB2_TIM11EN)
        {
            SET_BIT(RCC->APB2ENR, A_u32PeripheralID);
        }
        break;
    default:
        break;
    }
}
/* -------------------------------------------------------------------------- */


/* ------------------------ Disable Peripheral clock ------------------------ */
void MRCC_voidDisableClock(u32 A_u32BusID, u32 A_u32PeripheralID)
{
        switch (A_u32BusID)
    {
    case AHB1:
        if (A_u32PeripheralID == AHB1_GPIOAEN || A_u32PeripheralID == AHB1_GPIOBEN ||
            A_u32PeripheralID == AHB1_GPIOCEN || A_u32PeripheralID == AHB1_CRCEN ||
            A_u32PeripheralID == AHB1_DMA1EN || A_u32PeripheralID == AHB1_DMA2EN)
        {
            CLR_BIT(RCC->AHB1ENR, A_u32PeripheralID);
        }
        break;
    case AHB2:
        if (A_u32PeripheralID == AHB2_OTGFSEN)
        {
            CLR_BIT(RCC->AHB2ENR, A_u32PeripheralID);
        }
        break;
    case APB1:
        if (A_u32PeripheralID == APB1_TIM2EN || A_u32PeripheralID == APB1_TIM3EN ||
            A_u32PeripheralID == APB1_TIM4EN || A_u32PeripheralID == APB1_TIM5EN ||
            A_u32PeripheralID == APB1_WWDGEN || A_u32PeripheralID == APB1_SPI2EN ||
            A_u32PeripheralID == APB1_SPI3EN || A_u32PeripheralID == APB1_UASRT2EN ||
            A_u32PeripheralID == APB1_I2C1EN || A_u32PeripheralID == APB1_I2C2EN ||
            A_u32PeripheralID == APB1_I2C3EN || A_u32PeripheralID == APB1_PWREN)
        {
            CLR_BIT(RCC->APB1ENR, A_u32PeripheralID);
        }
        break;
    case APB2:
        if (A_u32PeripheralID == APB2_TIM1EN || A_u32PeripheralID == APB2_USART1EN ||
            A_u32PeripheralID == APB2_USART2EN || A_u32PeripheralID == APB2_ADC1EN ||
            A_u32PeripheralID == APB2_SDIOEN || A_u32PeripheralID == APB2_SPI1EN ||
            A_u32PeripheralID == APB2_SOI4EN || A_u32PeripheralID == APB2_SYSCFGEN ||
            A_u32PeripheralID == APB2_TIM9EN || A_u32PeripheralID == APB2_TIM10EN ||
            A_u32PeripheralID == APB2_TIM11EN)
        {
            CLR_BIT(RCC->APB2ENR, A_u32PeripheralID);
        }
        break;
    default:
        break;
    }
}
/* -------------------------------------------------------------------------- */
