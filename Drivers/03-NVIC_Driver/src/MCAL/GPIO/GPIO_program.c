/*
 * GPIO_program.c
 *
 *  Created on: Jul 22, 2023
 *      Author: Mario Ezzat
 */

/* -------------------------------------------------------------------------- */
/*                                  Includes                                  */
/* -------------------------------------------------------------------------- */
/* --------------------------------- STD LIB -------------------------------- */
#include "../../LIB/STD_TYPES.h"
#include "../../LIB/BIT_MATH.h"
/* -------------------------------------------------------------------------- */
/* -------------------------------- RCC MCAL -------------------------------- */
#include "../RCC/RCC_interface.h"
#include "../RCC/RCC_configuration.h"
#include "../RCC/RCC_private.h"
/* -------------------------------------------------------------------------- */
/* -------------------------------- GPIO MCAL ------------------------------- */
#include "GPIO_interface.h"
#include "GPIO_configuration.h"
#include "GPIO_private.h"
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                   Program                                  */
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_vInit                                                     */
/* Argument : Void                                                            */
/* Returns  : Void                                                            */
/* Role     : Set the GPIO pin settings that defined in configuration.h       */
/* ************************************************************************** */
void MGPIO_vInit(void)
{
    GPIOA->MODER = CONC_16_2BIT(GPIO_INPUT_conc, GPIO_INPUT_conc, GPIO_ANALOG_conc, PORTA_PIN12_MODE,
                                PORTA_PIN11_MODE, PORTA_PIN10_MODE, PORTA_PIN9_MODE, PORTA_PIN8_MODE,
                                PORTA_PIN7_MODE, PORTA_PIN6_MODE, PORTA_PIN5_MODE, PORTA_PIN4_MODE,
                                PORTA_PIN3_MODE, PORTA_PIN2_MODE, PORTA_PIN1_MODE, PORTA_PIN0_MODE);

    GPIOB->MODER = CONC_16_2BIT(PORTB_PIN15_MODE, PORTB_PIN14_MODE, PORTB_PIN13_MODE, PORTB_PIN12_MODE,
                                PORTB_PIN11_MODE, PORTB_PIN10_MODE, PORTB_PIN9_MODE, PORTB_PIN8_MODE,
                                PORTB_PIN7_MODE, PORTB_PIN6_MODE, PORTB_PIN5_MODE, GPIO_ALTFUN_conc,
                                GPIO_ALTFUN_conc, GPIO_INPUT_conc, PORTB_PIN1_MODE, PORTB_PIN0_MODE);

    GPIOA->OTYPER = CONC_32BIT(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               GPIO_PUSHPULL_PIN, GPIO_PUSHPULL_PIN, GPIO_PUSHPULL_PIN, PORTA_PIN12_OUT_TYPE,
                               PORTA_PIN11_OUT_TYPE, PORTA_PIN10_OUT_TYPE, PORTA_PIN9_OUT_TYPE, PORTA_PIN8_OUT_TYPE,
                               PORTA_PIN7_OUT_TYPE, PORTA_PIN6_OUT_TYPE, PORTA_PIN5_OUT_TYPE, PORTA_PIN4_OUT_TYPE,
                               PORTA_PIN3_OUT_TYPE, PORTA_PIN2_OUT_TYPE, PORTA_PIN1_OUT_TYPE, PORTA_PIN0_OUT_TYPE);

    GPIOB->OTYPER = CONC_32BIT(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                               PORTB_PIN15_OUT_TYPE, PORTB_PIN14_OUT_TYPE, PORTB_PIN13_OUT_TYPE, PORTB_PIN12_OUT_TYPE,
                               PORTB_PIN11_OUT_TYPE, PORTB_PIN10_OUT_TYPE, PORTB_PIN9_OUT_TYPE, PORTB_PIN8_OUT_TYPE,
                               PORTB_PIN7_OUT_TYPE, PORTB_PIN6_OUT_TYPE, PORTB_PIN5_OUT_TYPE, GPIO_PUSHPULL_PIN,
                               GPIO_PUSHPULL_PIN, GPIO_PUSHPULL_PIN, PORTB_PIN1_OUT_TYPE, PORTB_PIN0_OUT_TYPE);

    GPIOA->OSPEEDR = CONC_16_2BIT(LOW_SPEED_conc, LOW_SPEED_conc, VHIGH_SPEED_conc, PORTA_PIN12_SPEED,
                                  PORTA_PIN11_SPEED, PORTA_PIN10_SPEED, PORTA_PIN9_SPEED, PORTA_PIN8_SPEED,
                                  PORTA_PIN7_SPEED, PORTA_PIN6_SPEED, PORTA_PIN5_SPEED, PORTA_PIN4_SPEED,
                                  PORTA_PIN3_SPEED, PORTA_PIN2_SPEED, PORTA_PIN1_SPEED, PORTA_PIN0_SPEED);

    GPIOB->OSPEEDR = CONC_16_2BIT(PORTB_PIN15_SPEED, PORTB_PIN14_SPEED, PORTB_PIN13_SPEED, PORTB_PIN12_SPEED,
                                  PORTB_PIN11_SPEED, PORTB_PIN10_SPEED, PORTB_PIN9_SPEED, PORTB_PIN8_SPEED,
                                  PORTB_PIN7_SPEED, PORTB_PIN6_SPEED, PORTB_PIN5_SPEED, LOW_SPEED_conc,
                                  VHIGH_SPEED_conc, LOW_SPEED_conc, PORTB_PIN1_SPEED, PORTB_PIN0_SPEED);

    GPIOA->ODR = CONC_32BIT(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            GPIO_PIN_LOW, GPIO_PIN_LOW, GPIO_PIN_LOW, PORTA_PIN12_OUT,
                            PORTA_PIN11_OUT, PORTA_PIN10_OUT, PORTA_PIN9_OUT, PORTA_PIN8_OUT,
                            PORTA_PIN7_OUT, PORTA_PIN6_OUT, PORTA_PIN5_OUT, PORTA_PIN4_OUT,
                            PORTA_PIN3_OUT, PORTA_PIN2_OUT, PORTA_PIN1_OUT, PORTA_PIN0_OUT);

    GPIOB->ODR = CONC_32BIT(0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0,
                            PORTB_PIN15_OUT, PORTB_PIN14_OUT, PORTB_PIN13_OUT, PORTB_PIN12_OUT,
                            PORTB_PIN11_OUT, PORTB_PIN10_OUT, PORTB_PIN9_OUT, PORTB_PIN8_OUT,
                            PORTB_PIN7_OUT, PORTB_PIN6_OUT, PORTB_PIN5_OUT, GPIO_PIN_LOW,
                            GPIO_PIN_LOW, GPIO_PIN_LOW, PORTB_PIN1_OUT, PORTB_PIN0_OUT);

    GPIOA->PUPDR = CONC_16_2BIT(PULL_UP_conc, PULL_DOWN_conc, PULL_UP_conc, PORTA_PIN12_INPUT_TYPE,
                                PORTA_PIN11_INPUT_TYPE, PORTA_PIN10_INPUT_TYPE, PORTA_PIN9_INPUT_TYPE, PORTA_PIN8_INPUT_TYPE,
                                PORTA_PIN7_INPUT_TYPE, PORTA_PIN6_INPUT_TYPE, PORTA_PIN5_INPUT_TYPE, PORTA_PIN4_INPUT_TYPE,
                                PORTA_PIN3_INPUT_TYPE, PORTA_PIN2_INPUT_TYPE, PORTA_PIN1_INPUT_TYPE, PORTA_PIN0_INPUT_TYPE);

    GPIOB->PUPDR = CONC_16_2BIT(PORTB_PIN15_INPUT_TYPE, PORTB_PIN14_INPUT_TYPE, PORTB_PIN13_INPUT_TYPE, PORTB_PIN12_INPUT_TYPE,
                                PORTB_PIN11_INPUT_TYPE, PORTB_PIN10_INPUT_TYPE, PORTB_PIN9_INPUT_TYPE, PORTB_PIN8_INPUT_TYPE,
                                PORTB_PIN7_INPUT_TYPE, PORTB_PIN6_INPUT_TYPE, PORTB_PIN5_INPUT_TYPE, PULL_UP_conc,
                                NO_PULL_conc, NO_PULL_conc, PORTB_PIN1_INPUT_TYPE, PORTB_PIN0_INPUT_TYPE);
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_vSetPinMode                                               */
/* Argument : Port ID, Pin number, and Pin mode                               */
/* Returns  : Void                                                            */
/* Role     : Set pin mode (Input - Output - Alternative function - Analog)   */
/* ************************************************************************** */
void MGPIO_vSetPinMode(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8Mode)
{
    switch (A_u8PorID)
    {
    case GPIO_PORTA:
        if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
        {
            /* Mask on the register */
            (GPIOA->MODER) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOA->MODER) |= (A_u8Mode << (A_u8PinID * 2));
        }
        break;
    case GPIO_PORTB:
        if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
        {
            /* Mask on the register */
            (GPIOB->MODER) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOB->MODER) |= (A_u8Mode << (A_u8PinID * 2));
        }
        break;
    case GPIO_PORTC:

        if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
        {
            /* Mask on the register */
            (GPIOC->MODER) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOC->MODER) |= (A_u8Mode << (A_u8PinID * 2));
        }
        break;
    default:
        break;
    }
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_vSetPinOutType                                            */
/* Argument : Port ID, Pin number, and Output pin type                        */
/* Returns  : Void                                                            */
/* Role     : Set output pin type (PushPull - OpenDrain)                      */
/* ************************************************************************** */
void MGPIO_vSetPinOutType(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8OutType)
{
    if (A_u8OutType == GPIO_OPENDRAIN_PIN)
    {
        switch (A_u8PorID)
        {
        case GPIO_PORTA:
            if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
            {
                SET_BIT(GPIOA->OTYPER, A_u8PinID);
            }
            break;
        case GPIO_PORTB:
            if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
            {
                SET_BIT(GPIOB->OTYPER, A_u8PinID);
            }
            break;
        case GPIO_PORTC:

            if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
            {
                SET_BIT(GPIOC->OTYPER, A_u8PinID);
            }
            break;
        default:
            break;
        }
    }
    else if (A_u8OutType == GPIO_PUSHPULL_PIN)
    {
        switch (A_u8PorID)
        {
        case GPIO_PORTA:
            if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
            {
                CLR_BIT(GPIOA->OTYPER, A_u8PinID);
            }
            break;
        case GPIO_PORTB:
            if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
            {
                CLR_BIT(GPIOB->OTYPER, A_u8PinID);
            }
            break;
        case GPIO_PORTC:

            if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
            {
                CLR_BIT(GPIOC->OTYPER, A_u8PinID);
            }
            break;
        default:
            break;
        }
    }
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_vSetPinOutSpeed                                           */
/* Argument : Port ID, Pin number, and Required pin speed                     */
/* Returns  : Void                                                            */
/* Role     : Set output pin speed (Low - Medium = High = VeryHigh)           */
/* ************************************************************************** */
void MGPIO_vSetPinOutSpeed(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8OutSpeed)
{
    switch (A_u8PorID)
    {
    case GPIO_PORTA:
        /* Check pin limitation */
        if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
        {
            /* Mask on the register */
            (GPIOA->OSPEEDR) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOA->OSPEEDR) |= (A_u8OutSpeed << (A_u8PinID * 2));
        }
        break;
    case GPIO_PORTB:
        /* Check pin limitation */
        if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
        {
            /* Mask on the register */
            (GPIOB->OSPEEDR) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOB->OSPEEDR) |= (A_u8OutSpeed << (A_u8PinID * 2));
        }
        break;
    case GPIO_PORTC:
        /* Check pin limitation */
        if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
        {
            /* Mask on the register */
            (GPIOC->OSPEEDR) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOC->OSPEEDR) |= (A_u8OutSpeed << (A_u8PinID * 2));
        }
        break;
    default:
        break;
    }
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_vSetPinInType                                             */
/* Argument : Port ID, Pin number, and Input pin type                         */
/* Returns  : Void                                                            */
/* Role     : Set output pin type (PushPull - OpenDrain)                      */
/* ************************************************************************** */
void MGPIO_vSetPinInType(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8OutType)
{
    switch (A_u8PorID)
    {
    case GPIO_PORTA:
        /* Check pin limitation */
        if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
        {
            /* Mask on the register */
            (GPIOA->PUPDR) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOA->PUPDR) |= (A_u8OutType << (A_u8PinID * 2));
        }
        break;
    case GPIO_PORTB:
        /* Check pin limitation */
        if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
        {
            /* Mask on the register */
            (GPIOB->PUPDR) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOB->PUPDR) |= (A_u8OutType << (A_u8PinID * 2));
        }
        break;
    case GPIO_PORTC:
        /* Check pin limitation */
        if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
        {
            /* Mask on the register */
            (GPIOC->PUPDR) &= ~(0b11 << (A_u8PinID * 2));
            (GPIOC->PUPDR) |= (A_u8OutType << (A_u8PinID * 2));
        }
        break;
    default:
        break;
    }
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_u8GetPinInValue                                           */
/* Argument : Port ID and Pin number                                          */
/* Returns  : Input pin status                                                */
/* Role     : Get the status of input pins                                    */
/* ************************************************************************** */
u8 MGPIO_u8GetPinInValue(u8 A_u8PorID, u8 A_u8PinID)
{
    u8 L_u8PinValue = -1;
    switch (A_u8PorID)
    {
    case GPIO_PORTA:
        /* Check pin limitation */
        if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_15)
        {
            L_u8PinValue = GET_BIT(GPIOA->IDR, A_u8PinID);
        }
        break;
    case GPIO_PORTB:
        /* Check pin limitation */
        if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_15)
        {
            L_u8PinValue = GET_BIT(GPIOB->IDR, A_u8PinID);
        }
        break;
    case GPIO_PORTC:
        /* Check pin limitation */
        if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
        {
            L_u8PinValue = GET_BIT(GPIOC->IDR, A_u8PinID);
        }
        break;
    default:
        /* ERROR: Invalid Value Return -1 */
        break;
    }
    return L_u8PinValue;
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_u8GetPinOutValue                                          */
/* Argument : Port ID and Pin number                                          */
/* Returns  : Output pin status                                               */
/* Role     : Get the status of Output pins                                   */
/* ************************************************************************** */
u8 MGPIO_u8GetPinOutValue(u8 A_u8PorID, u8 A_u8PinID)
{
    u8 L_u8PinValue = -1;
    switch (A_u8PorID)
    {
    case GPIO_PORTA:
        /* Check pin limitation */
        if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_15)
        {
            L_u8PinValue = GET_BIT(GPIOA->ODR, A_u8PinID);
        }
        break;
    case GPIO_PORTB:
        /* Check pin limitation */
        if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_15)
        {
            L_u8PinValue = GET_BIT(GPIOB->ODR, A_u8PinID);
        }
        break;
    case GPIO_PORTC:
        /* Check pin limitation */
        if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
        {
            L_u8PinValue = GET_BIT(GPIOC->ODR, A_u8PinID);
        }
        break;
    default:
        /* ERROR: Invalid Value */
        break;
    }
    return L_u8PinValue;
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_vSetPinValue                                              */
/* Argument : Port ID, Pin number, and Pin value                              */
/* Returns  : Void                                                            */
/* Role     : Set output pins (High - Low)                                    */
/* ************************************************************************** */
void MGPIO_vSetPinValue(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8PinValue)
{
    if (A_u8PinValue == GPIO_PIN_HIGH)
    {
        switch (A_u8PorID)
        {
        case GPIO_PORTA:
            /* Check pin limitation */
            if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
            {
                /* Write Pin High */
                SET_BIT(GPIOA->ODR, A_u8PinID);
            }
            break;
        case GPIO_PORTB:
            /* Check pin limitation */
            if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
            {
                /* Write Pin High */
                SET_BIT(GPIOB->ODR, A_u8PinID);
            }
            break;
        case GPIO_PORTC:
            /* Check pin limitation */
            if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
            {
                /* Write Pin High */
                SET_BIT(GPIOC->ODR, A_u8PinID);
            }
            break;
        default:
            break;
        }
    }
    else if (A_u8PinValue == GPIO_PIN_LOW)
    {
        switch (A_u8PorID)
        {
        case GPIO_PORTA:
            /* Check pin limitation */
            if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
            {
                /* Write Pin Low */
                CLR_BIT(GPIOA->ODR, A_u8PinID);
            }
            break;
        case GPIO_PORTB:
            /* Check pin limitation */
            if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
            {
                /* Write Pin Low */
                CLR_BIT(GPIOB->ODR, A_u8PinID);
            }
            break;
        case GPIO_PORTC:
            /* Check pin limitation */
            if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
            {
                /* Write Pin Low */
                CLR_BIT(GPIOC->ODR, A_u8PinID);
            }
            break;
        default:
            break;
        }
    }
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_vSetPinValueFast                                          */
/* Argument : Port ID, Pin number, and Pin value                              */
/* Returns  : Void                                                            */
/* Role     : Set output pins (High - Low) use BSRR Register                  */
/* ************************************************************************** */
void MGPIO_vSetPinValueFast(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8PinValue)
{
    if (A_u8PinValue == GPIO_PIN_HIGH)
    {
        switch (A_u8PorID)
        {
        case GPIO_PORTA:
            /* Check pin limitation */
            if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
            {
                /* Write Pin High Fast */
                (GPIOA->BSRR) = (0b1 << A_u8PinID);
            }
            break;
        case GPIO_PORTB:
            /* Check pin limitation */
            if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
            {
                /* Write Pin High Fast */
                (GPIOB->BSRR) = (0b1 << A_u8PinID);
            }
            break;
        case GPIO_PORTC:
            /* Check pin limitation */
            if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
            {
                /* Write Pin High Fast */
                (GPIOC->BSRR) = (0b1 << A_u8PinID);
            }
            break;
        default:
            break;
        }
    }
    else if (A_u8PinValue == GPIO_PIN_LOW)
    {
        switch (A_u8PorID)
        {
        case GPIO_PORTA:
            /* Check pin limitation */
            if (A_u8PinID >= PIN_0 && A_u8PinID <= PIN_12)
            {
                /* Write Pin LOW Fast */
                (GPIOA->BSRR) = (0b1 << A_u8PinID + 16);
            }
            break;
        case GPIO_PORTB:
            /* Check pin limitation */
            if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_15) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
            {
                /* Write Pin LOW Fast */
                (GPIOB->BSRR) = (0b1 << A_u8PinID + 16);
            }
            break;
        case GPIO_PORTC:
            /* Check pin limitation */
            if (A_u8PinID == PIN_13 || A_u8PinID == PIN_14 || A_u8PinID == PIN_15)
            {
                /* Write Pin LOW Fast */
                (GPIOC->BSRR) = (0b1 << A_u8PinID + 16);
            }
            break;
        default:
            break;
        }
    }
}
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MGPIO_vSetPinAltFunction                                        */
/* Argument : Port ID, Pin number, and Alternative Function ID                */
/* Returns  : Void                                                            */
/* Role     : Set Alternative Function pins to specific peripheral            */
/* ************************************************************************** */
void MGPIO_vSetPinAltFunction(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8AltID)
{
    switch (A_u8PorID)
    {
    case GPIO_PORTA:
        /* Check pin limitation for low register */
        if (PIN_0 <= A_u8PinID && A_u8PinID <= PIN_7)
        {
            /* AFRL */
            /* Mask on the register */
            (GPIOA->AFRL) &= ~(0b1111 << (A_u8PinID * 4));
            (GPIOA->AFRL) |= (A_u8AltID << (A_u8PinID * 4));
        }
        /* Check pin limitation for high register */
        else if (PIN_7 < A_u8PinID && A_u8PinID <= PIN_12)
        {
            /* AFRH */
            /* Mask on the register */
            (GPIOA->AFRH) &= ~(0b1111 << ((A_u8PinID - PIN_8) * 4));
            (GPIOA->AFRH) |= (A_u8AltID << ((A_u8PinID - PIN_8) * 4));
        }
        break;
    case GPIO_PORTB:
        /* Check pin limitation for low register */
        if ((PIN_5 <= A_u8PinID && A_u8PinID <= PIN_7) || (A_u8PinID == PIN_0) || (A_u8PinID == PIN_1))
        {
            /* AFRL */
            /* Mask on the register */
            (GPIOB->AFRL) &= ~(0b1111 << (A_u8PinID * 4));
            (GPIOB->AFRL) |= (A_u8AltID << (A_u8PinID * 4));
        }
        /* Check pin limitation for high register */
        else if (PIN_7 < A_u8PinID && A_u8PinID <= PIN_15)
        {
            /* AFRH */
            /* Mask on the register */
            (GPIOB->AFRH) &= ~(0b1111 << ((A_u8PinID - PIN_8) * 4));
            (GPIOB->AFRH) |= (A_u8AltID << ((A_u8PinID - PIN_8) * 4));
        }
        break;

    default:
        break;
    }
}
/* -------------------------------------------------------------------------- */