/*
 * NVIC_program.c
 *
 *  Created on: Jul 25, 2023
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
#include "../GPIO/GPIO_interface.h"
#include "../GPIO/GPIO_configuration.h"
#include "../GPIO/GPIO_private.h"
/* -------------------------------------------------------------------------- */
/* -------------------------------- NVIC MCAL ------------------------------- */
#include "NVIC_interface.h"
#include "NVIC_configuration.h"
#include "NVIC_private.h"
/* -------------------------------------------------------------------------- */

/* -------------------------------------------------------------------------- */
/*                                   Program                                  */
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MNVIC_voidEnablePeripheral                                      */
/* Argument : Interrupt ID                                                    */
/* Returns  : Void                                                            */
/* Role     : Enable the interrupt of the peripheral in NVIC                  */
/* ************************************************************************** */
void MNVIC_voidEnablePeripheral(u8 A_u8InterruptID)
{

    NVIC->ISER[A_u8InterruptID / REG_SIZE] = (BIT_HIGH << (A_u8InterruptID % REG_SIZE));
}

/* ************************************************************************** */
/* Function : MNVIC_voidDisablePeripheral                                     */
/* Argument : Interrupt ID                                                    */
/* Returns  : Void                                                            */
/* Role     : Disable the interrupt of the peripheral in NVIC                 */
/* ************************************************************************** */
void MNVIC_voidDisablePeripheral(u8 A_u8InterruptID)
{

    NVIC->ICER[A_u8InterruptID / REG_SIZE] = (BIT_HIGH << (A_u8InterruptID % REG_SIZE));
}

/* ************************************************************************** */
/* Function : MNVIC_voidSetPending                                            */
/* Argument : Interrupt ID                                                    */
/* Returns  : Void                                                            */
/* Role     : Set the pending flag of the peripheral                          */
/* ************************************************************************** */
void MNVIC_voidSetPending(u8 A_u8InterruptID)
{
    NVIC->ISPR[A_u8InterruptID / REG_SIZE] = (BIT_HIGH << (A_u8InterruptID % REG_SIZE));
}

/* ************************************************************************** */
/* Function : MNVIC_voidClearPending                                          */
/* Argument : Interrupt ID                                                    */
/* Returns  : Void                                                            */
/* Role     : Clear the pending flag of the peripheral                        */
/* ************************************************************************** */
void MNVIC_voidClearPending(u8 A_u8InterruptID)
{

    NVIC->ICPR[A_u8InterruptID / REG_SIZE] = (BIT_HIGH << (A_u8InterruptID % REG_SIZE));
}

/* ************************************************************************** */
/* Function : MNVIC_voidGetActive                                             */
/* Argument : Interrupt ID                                                    */
/* Returns  : Active flag state                                               */
/* Role     : Check the executing interrupt (active interrupt)                */
/* ************************************************************************** */
u8 MNVIC_u8GetActive(u8 A_u8InterruptID)
{
    u8 L_InterruptState;
    L_InterruptState = GET_BIT((NVIC->IABR[A_u8InterruptID / REG_SIZE]), (BIT_HIGH << (A_u8InterruptID % REG_SIZE)));

    return L_InterruptState;
}

/* ************************************************************************** */
/* Function : MNVIC_voidSetPriorityConfig                                     */
/* Argument : Group Priority Options                                          */
/* Returns  : Void                                                            */
/* Role     : Set the number of groups and sub  priorities                    */
/* ************************************************************************** */
//! GROUP_4BITS - GROUP_3BITS = GROUP_2BITS = GROUP_1BITS = GROUP_0BIT
//! GROUP_16_PRIORITY_0 - GROUP_8_PRIORITY_2 - GROUP_4_PRIORITY_4 - GROUP_2_PRIORITY_8 - GROUP_0_PRIORITY_16
void MNVIC_voidSetPriorityConfig(u8 A_u8PriorityOptions)
{
    GlobalStatic_u32GroupConfig = SCB_AIRCR_PASS_KEY | (A_u8PriorityOptions << SHIFT_8);
    SCB->AIRCR = GlobalStatic_u32GroupConfig;
}

/* ************************************************************************** */
/* Function : MNVIC_voidSetPriority                                           */
/* Argument : Interrupt ID, Group Priority, & Sub-Priority                    */
/* Returns  : Void                                                            */
/* Role     : Set the peripheral priority                                     */
/* ************************************************************************** */
//! A_u8GroupPriority:- (GROUP_PRIORITY_0 ... GROUP_PRIORITY_15)
//! A_u8SubPriority  :- (SUB_PRIORITY_0   ... SUB_PRIORITY_15)
void MNVIC_voidSetPriority(u8 A_u8InterruptID, u8 A_u8GroupPriority, u8 A_u8SubPriority)
{
    u8 L_u8Priority;
    /*
     *  * Get the Group configuration Value *
     *  (GroupConf >> 8) & 0b0111
     *  * To get the number of bits subtract 0b011 from the value *
     *  ((GroupConf >> 8) & 0b0111) - 0b011
     *  * Shift the group priority to left with the number of bits *
     *  A_u8GroupPriority << (((GroupConf >> 8) & 0b0111) - 0b011)
     *  * combine the group value with sub value *
     *  A_u8SubPriority | (A_u8GroupPriority << (((GroupConf >> 8) & 0b0111) - 0b011))
     */
    L_u8Priority = A_u8SubPriority | (A_u8GroupPriority << (((GlobalStatic_u32GroupConfig >> SHIFT_8) & THREE_BIT) - TWO_BIT));

    /* Core peripheral */
    if (A_u8InterruptID < WWDG)
    {
        if (A_u8InterruptID == MEMORY_MANGEMENT_FAULT || A_u8InterruptID == BUS_FAULT || A_u8InterruptID == USAGE_FAULT)
        {
            /* Convert the priority to address on the SHPR register */
            A_u8InterruptID += SHIFT_6;
            /* write on the last 4 bits only (MSB) for each 8 bits */
            SCB->SHPR1 = (L_u8Priority) << ((SHIFT_8 * A_u8InterruptID) + SHIFT_4);
        }
        else if (A_u8InterruptID == SV_CALL)
        {
            /* Convert the priority to address on the SHPR register */
            A_u8InterruptID += SHIFT_6;
            /* write on the last 4 bits only (MSB) for each 8 bits */
            SCB->SHPR2 = (L_u8Priority) << ((SHIFT_8 * A_u8InterruptID) + SHIFT_4);
        }
        else if (A_u8InterruptID == PEND_SV || A_u8InterruptID == SYSTICK)
        {
            /* Convert the priority to address on the SHPR register */
            A_u8InterruptID += SHIFT_4;
            /* write on the last 4 bits only (MSB) for each 8 bits */
            SCB->SHPR3 = (L_u8Priority) << ((SHIFT_8 * A_u8InterruptID) + SHIFT_4);
        }
    }
    /* External peripheral */
    else if (A_u8InterruptID >= WWDG)
    {
        NVIC->IPR[A_u8InterruptID]  = (L_u8Priority <<SHIFT_4);
    }
}