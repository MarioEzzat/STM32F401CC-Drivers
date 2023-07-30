/*
 * NVIC_interface.h
 *
 *  Created on: Jul 25, 2023
 *      Author: Mario Ezzat
 */

#ifndef MCAL_NVIC_NVIC_INTERFACE_H_
#define MCAL_NVIC_NVIC_INTERFACE_H_

/* Global static variable contains the AIRCR register */
static u32 GlobalStatic_u32GroupConfig;
/* -------------------------------------------------------------------------- */
/* ----------------------------- Core Peripheral ---------------------------- */
/* Core Peripheral SHPR1 */
#define MEMORY_MANGEMENT_FAULT -6
#define BUS_FAULT -5
#define USAGE_FAULT -4
/* Core Peripheral SHPR2 */
#define SV_CALL -3
/* Core Peripheral SHPR3 */
#define PEND_SV -2
#define SYSTICK -1
/* -------------------------------------------------------------------------- */
/* --------------------------- External Peripheral -------------------------- */
#define WWDG 0
#define EXTI16 1
#define EXTI21 2
#define EXTI22 3
#define FLASH 4
#define RCC 5
#define EXTI0 6
#define EXTI1 7
#define EXTI2 8
#define EXTI3 9
#define EXTI4 10
#define DMA1_STREAM0 11
#define DMA1_STREAM1 12
#define DMA1_STREAM2 13
#define DMA1_STREAM3 14
#define DMA1_STREAM4 15
#define DMA1_STREAM5 16
#define DMA1_STREAM6 17
#define ADC 18
#define EXTI9 23
#define TIM1_BRK_TIM9 24
#define TIM1_UP_TIM10 25
#define TIM1_TRG_COM_TIM11 26
#define TIM1_CC 27
#define TIM2 28
#define TIM3 29
#define TIM4 30
#define I2C1_EV 31
#define I2C1_ER 32
#define I2C2_EV 33
#define I2C2_ER 34
#define SPI1 35
#define SPI2 36
#define USART1 37
#define USART2 38
#define EXTI15_10 30
#define EXTI17 41
#define EXTI18 42
#define DMA1_STREAM7 47
#define SDIO 49
#define TIM5 50
#define SPI3 51
#define DMA2_STREAM0 56
#define DMA2_STREAM1 57
#define DMA2_STREAM2 58
#define DMA2_STREAM3 59
#define DMA2_STREAM4 60
#define OTG_FS 67
#define DMA2_STREAM5 68
#define DMA2_STREAM6 69
#define DMA2_STREAM7 70
#define USART6 71
#define I2C3_EV 72
#define I2C3_ER 73
#define FPU 81
#define SPI4 84
/* -------------------------------------------------------------------------- */
/* --------------------------- NVIC Configuration --------------------------- */
#define GROUP_4BITS 0b011
#define GROUP_3BITS 0b100
#define GROUP_2BITS 0b101
#define GROUP_1BITS 0b110
#define GROUP_0BITS 0b111
#define GROUP_16_PRIORITY_0 GROUP_4BITS
#define GROUP_8_PRIORITY_2 GROUP_3BITS
#define GROUP_4_PRIORITY_4 GROUP_2BITS
#define GROUP_2_PRIORITY_8 GROUP_1BITS
#define GROUP_0_PRIORITY_16 GROUP_0BITS
/* -------------------------------------------------------------------------- */
/* ------------------------------ Group Options ----------------------------- */
#define NO_GROUP_PRIORITY 0
#define GROUP_PRIORITY_0 0
#define GROUP_PRIORITY_1 1
#define GROUP_PRIORITY_2 2
#define GROUP_PRIORITY_3 3
#define GROUP_PRIORITY_4 4
#define GROUP_PRIORITY_5 5
#define GROUP_PRIORITY_6 6
#define GROUP_PRIORITY_7 7
#define GROUP_PRIORITY_8 8
#define GROUP_PRIORITY_9 9
#define GROUP_PRIORITY_10 10
#define GROUP_PRIORITY_11 11
#define GROUP_PRIORITY_12 12
#define GROUP_PRIORITY_13 13
#define GROUP_PRIORITY_14 14
#define GROUP_PRIORITY_15 15
/* -------------------------------------------------------------------------- */
/* -------------------------- Sub Priority Options -------------------------- */
#define NO_SUB_PRIORITY 0
#define SUB_PRIORITY_0 0
#define SUB_PRIORITY_1 1
#define SUB_PRIORITY_2 2
#define SUB_PRIORITY_3 3
#define SUB_PRIORITY_4 4
#define SUB_PRIORITY_5 5
#define SUB_PRIORITY_6 6
#define SUB_PRIORITY_7 7
#define SUB_PRIORITY_8 8
#define SUB_PRIORITY_9 9
#define SUB_PRIORITY_10 10
#define SUB_PRIORITY_11 11
#define SUB_PRIORITY_12 12
#define SUB_PRIORITY_13 13
#define SUB_PRIORITY_14 14
#define SUB_PRIORITY_15 15
/* -------------------------------------------------------------------------- */
/* ************************************************************************** */
/* Function : MNVIC_voidEnablePeripheral                                      */
/* Argument : Interrupt ID                                                    */
/* Returns  : Void                                                            */
/* Role     : Enable the interrupt of the peripheral in NVIC                  */
/* ************************************************************************** */
void MNVIC_voidEnablePeripheral(u8 A_u8InterruptID);

/* ************************************************************************** */
/* Function : MNVIC_voidDisablePeripheral                                     */
/* Argument : Interrupt ID                                                    */
/* Returns  : Void                                                            */
/* Role     : Disable the interrupt of the peripheral in NVIC                 */
/* ************************************************************************** */
void MNVIC_voidDisablePeripheral(u8 A_u8InterruptID);

/* ************************************************************************** */
/* Function : MNVIC_voidSetPending                                            */
/* Argument : Interrupt ID                                                    */
/* Returns  : Void                                                            */
/* Role     : Set the pending flag of the peripheral                          */
/* ************************************************************************** */
void MNVIC_voidSetPending(u8 A_u8InterruptID);

/* ************************************************************************** */
/* Function : MNVIC_voidClearPending                                          */
/* Argument : Interrupt ID                                                    */
/* Returns  : Void                                                            */
/* Role     : Clear the pending flag of the peripheral                        */
/* ************************************************************************** */
void MNVIC_voidClearPending(u8 A_u8InterruptID);

/* ************************************************************************** */
/* Function : MNVIC_voidGetActive                                             */
/* Argument : Interrupt ID                                                    */
/* Returns  : Active flag state                                               */
/* Role     : Check the executing interrupt (active interrupt)                */
/* ************************************************************************** */
u8 MNVIC_u8GetActive(u8 A_u8InterruptID);

/* ************************************************************************** */
/* Function : MNVIC_voidSetPriorityConfig                                     */
/* Argument : Group Priority Options                                          */
/* Returns  : Void                                                            */
/* Role     : Set the number of groups and sub  priorities                    */
/* ************************************************************************** */
void MNVIC_voidSetPriorityConfig(u8 A_u8PriorityOptions);

/* ************************************************************************** */
/* Function : MNVIC_voidSetPriority                                           */
/* Argument : Interrupt ID, Group Priority, & Sub-Priority                    */
/* Returns  : Void                                                            */
/* Role     : Set the peripheral priority                                     */
/* ************************************************************************** */
void MNVIC_voidSetPriority(u8 A_u8InterruptID, u8 A_u8GroupPriority, u8 A_u8SubPriority);

#endif /* MCAL_NVIC_NVIC_INTERFACE_H_ */
