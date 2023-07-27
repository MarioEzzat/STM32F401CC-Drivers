/*
 * GPIO_interface.h
 *
 *  Created on: Jul 22, 2023
 *      Author: Mario Ezzat
 */

#ifndef MCAL_GPIO_GPIO_INTERFACE_H_
#define MCAL_GPIO_GPIO_INTERFACE_H_

/* -------------------------------------------------------------------------- */
/*                                 GPIO VALUES                                */
/* -------------------------------------------------------------------------- */
/* PORT NUMBER */
#define GPIO_PORTA 0
#define GPIO_PORTB 1
#define GPIO_PORTC 2
/* -------------------------------------------------------------------------- */
/* PIN NUMBER */
#define PIN_0 0
#define PIN_1 1
#define PIN_2 2
#define PIN_3 3
#define PIN_4 4
#define PIN_5 5
#define PIN_6 6
#define PIN_7 7
#define PIN_8 8
#define PIN_9 9
#define PIN_10 10
#define PIN_11 11
#define PIN_12 12
#define PIN_13 13
#define PIN_14 14
#define PIN_15 15
/* -------------------------------------------------------------------------- */
/* PIN MODE */
#define GPIO_INPUT 0b00
#define GPIO_OUTPUT 0b01
#define GPIO_ALTFUN 0b10
#define GPIO_ANALOG 0b11
/* -------------------------------------------------------------------------- */
/* OUTPUT PIN SPEED */
#define GPIO_LOW_SPEED 0b00
#define GPIO_MED_SPEED 0b01
#define GPIO_HIGH_SPEED 0b10
#define GPIO_VHIGH_SPEED 0b11
/* -------------------------------------------------------------------------- */
/* OUTPUT PIN TYPE */
#define GPIO_OPENDRAIN_PIN 1
#define GPIO_PUSHPULL_PIN 0
/* -------------------------------------------------------------------------- */
/* OUTPUT PIN VALUE */
#define GPIO_PIN_HIGH 1
#define GPIO_PIN_LOW 0
/* -------------------------------------------------------------------------- */
/* INPUT PIN TYPE */
#define GPIO_NO_PULL 0b00
#define GPIO_PULL_UP 0b01
#define GPIO_PULL_DOWN 0b10
/* -------------------------------------------------------------------------- */

#define PA0_TIM2_CH1_ETR AF01
#define PA0_ TIM5_CH1 AF02
#define PA0_USART2_CTS AF07

#define PA1_TIM2_CH2 AF01
#define PA1_TIM5_CH2 AF02
#define PA1_USART2_RTS AF07

#define PA2_TIM2_CH3 AF01
#define PA2_TIM5_CH3 AF02
#define PA2_TIM9_CH1 AF03
#define PA2_USART2_TX AF07

#define PA3_TIM2_CH4 AF01
#define PA3_TIM5_CH4 AF02
#define PA3_TIM9_CH2 AF03
#define PA3_USART2_RX AF07

#define PA4_SPI1_NSS AF05
#define PA4_SPI3_NSS AF06
#define PA4_I2S3_WS AF06
#define PA4_USART2_CK AF07

#define PA5_TIM2_CH1_ETR AF01
#define PA5_SPI1_SCK AF05

#define PA6_TIM1_BKIN AF01
#define PA6_TIM3_CH1 AF02
#define PA6_SPI1_MISO AF05

#define PA7_TIM1_CH1N AF01
#define PA7_TIM3_CH3 AF02
#define PA7_SPI1_MOSI AF05

#define PA8_MCO1_MOSI AF00
#define PA8_TIM1_CH1 AF01
#define PA8_I2S3_SCL AF04
#define PA8_USART1_CK AF07
#define PA8_OTG_FS_SOF AF10

#define PA9_TIM1_CH2 AF01
#define PA9_I2S3_SMBA AF04
#define PA9_USART1_TX AF07
#define PA9_OTG_FS_VBUS AF10

#define PA10_TIM1_CH3 AF01
#define PA10_USART1_RX AF07
#define PA10_OTG_FS_ID AF10

#define PA11_TIM1_CH4 AF01
#define PA11_USART1_CTS AF07
#define PA11_USART6_TX AF08
#define PA11_OTG_FS_DM AF10

#define PA12_TIM1_ETR AF01
#define PA12_USART1_RTS AF07
#define PA12_USART6_RX AF08
#define PA12_OTG_FS_DP AF10
/* -------------------------------------------------------------------------- */
#define PB0_TIM1_CH2NF AF01
#define PB0_TIM3_CH3 AF02

#define PB1_TIM1_CH3N AF01
#define PB1_TIM3_CH4 AF02

#define PB5_TIM3_CH1 AF02
#define PB5_I2C1_SMBA AF04
#define PB5_SPI1_MISO AF05
#define PB5_SPI3_MOSI AF06
#define PB5_I2S3_SD AF06

#define PB6_TIM4_CH1 AF02
#define PB6_I2C1_SCL AF04
#define PB6_USART1_TX AF06

#define PB7_TIM4_CH2 AF02
#define PB7_I2C1_SDA AF04
#define PB7_USART1_RX AF06

#define PB8_TIM4_CH3 AF02
#define PB8_TIM10_CH1 AF03
#define PB8_I2C1_SCL AF04
#define PB8_SDIO_D4 AF12

#define PB9_TIM4_CH4 AF02
#define PB9_TIM11_CH1 AF03
#define PB9_I2C1_SDA AF04
#define PB9_SPI2_NSS AF05
#define PB9_SDIO_D5 AF12

#define PB10_TIM2_CH3 AF01
#define PB10_I2C2_SCL AF04
#define PB10_SPI2_SCK AF05
#define PB10_I2S2_CK AF05

#define PB11_TIM2_CH4 AF01
#define PB10_I2C2_SDA AF04

#define PB12_TIM1_BKIN AF01
#define PB12_I2C2_SMBA AF04
#define PB12_SPI2_NSS AF05
#define PB12_I2S2_WS AF05

#define PB13_TIM1_CH1N AF01
#define PB13_SPI2_SCK AF05
#define PB13_I2S2_CK AF05

#define PB14_TIM1_CH2N AF01
#define PB14_SPI2_MISO AF05
#define PB14_I2S2ext_SD AF06

#define PB15_RTC_REFN AF00
#define PB15_TIM1_CH3N AF01
#define PB15_SPI2_MOSI AF05
#define PB15_I2S2_SD AF05
/* -------------------------------------------------------------------------- */
/*                                 FUNCTIONS                                  */
/* -------------------------------------------------------------------------- */

/* ************************************************************************** */
/* Function : MGPIO_vInit                                                     */
/* Argument : Void                                                            */
/* Returns  : Void                                                            */
/* Role     : Set the GPIO pin settings that defined in configuration.h       */
/* ************************************************************************** */
void MGPIO_vInit(void);
/* ************************************************************************** */
/* Function : MGPIO_vSetPinMode                                               */
/* Argument : Port ID, Pin number, and Pin mode                               */
/* Returns  : Void                                                            */
/* Role     : Set pin mode (Input - Output - Alternative function - Analog)   */
/* ************************************************************************** */
void MGPIO_vSetPinMode(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8Mode);
/* ************************************************************************** */
/* Function : MGPIO_vSetPinOutType                                            */
/* Argument : Port ID, Pin number, and Output pin type                        */
/* Returns  : Void                                                            */
/* Role     : Set output pin type (PushPull - OpenDrain)                      */
/* ************************************************************************** */
void MGPIO_vSetPinOutType(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8OutType);
/* ************************************************************************** */
/* Function : MGPIO_vSetPinOutSpeed                                           */
/* Argument : Port ID, Pin number, and Required pin speed                     */
/* Returns  : Void                                                            */
/* Role     : Set output pin speed (Low - Medium = High = VeryHigh)           */
/* ************************************************************************** */
void MGPIO_vSetPinOutSpeed(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8OutSpeed);
/* ************************************************************************** */
/* Function : MGPIO_vSetPinInType                                             */
/* Argument : Port ID, Pin number, and Input pin type                         */
/* Returns  : Void                                                            */
/* Role     : Set output pin type (PushPull - OpenDrain)                      */
/* ************************************************************************** */
void MGPIO_vSetPinInType(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8OutType);
/* ************************************************************************** */
/* Function : MGPIO_u8GetPinInValue                                           */
/* Argument : Port ID and Pin number                                          */
/* Returns  : Input pin status                                                */
/* Role     : Get the status of input pins                                    */
/* ************************************************************************** */
u8 MGPIO_u8GetPinInValue(u8 A_u8PorID, u8 A_u8PinID);
/* ************************************************************************** */
/* Function : MGPIO_u8GetPinOutValue                                          */
/* Argument : Port ID and Pin number                                          */
/* Returns  : Output pin status                                               */
/* Role     : Get the status of Output pins                                   */
/* ************************************************************************** */
u8 MGPIO_u8GetPinOutValue(u8 A_u8PorID, u8 A_u8PinID);
/* ************************************************************************** */
/* Function : MGPIO_vSetPinValue                                              */
/* Argument : Port ID, Pin number, and Pin value                              */
/* Returns  : Void                                                            */
/* Role     : Set output pins (High - Low)                                    */
/* ************************************************************************** */
void MGPIO_vSetPinValue(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8PinValue);
/* ************************************************************************** */
/* Function : MGPIO_vSetPinValueFast                                          */
/* Argument : Port ID, Pin number, and Pin value                              */
/* Returns  : Void                                                            */
/* Role     : Set output pins (High - Low) use BSRR Register                  */
/* ************************************************************************** */
void MGPIO_vSetPinValueFast(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8PinValue);
/* ************************************************************************** */
/* Function : MGPIO_vSetPinAltFunction                                        */
/* Argument : Port ID, Pin number, and Alternative Function ID                */
/* Returns  : Void                                                            */
/* Role     : Set Alternative Function pins to specific peripheral            */
/* ************************************************************************** */
void MGPIO_vSetPinAltFunction(u8 A_u8PorID, u8 A_u8PinID, u8 A_u8AltID);
/* -------------------------------------------------------------------------- */
#endif /* MCAL_GPIO_GPIO_INTERFACE_H_ */
