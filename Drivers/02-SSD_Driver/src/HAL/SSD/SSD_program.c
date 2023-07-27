/*
 * SSD_program.c
 *
 *  Created on: Jul 24, 2023
 *      Author: Mario Ezzat
 */
#include "../../LIB/BIT_MATH.h"
#include "../../LIB/STD_TYPES.h"

#include "../../MCAL/RCC/RCC_interface.h"
#include "../../MCAL/GPIO/GPIO_interface.h"

#include "SSD_configuration.h"
#include "SSD_interface.h"
#include "SSD_private.h"


void HSSD_voidInit(void)
{
#if SSD_PORT == GPIO_PORTA
	if (PIN_0 <= SSD_PIN0 && SSD_PIN0 <= PIN_12)
	{
		MRCC_voidEnableClock(AHB1, AHB1_GPIOAEN);
		MGPIO_vSetPinMode(GPIO_PORTA, SSD_PIN0, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTA, SSD_PIN1, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTA, SSD_PIN2, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTA, SSD_PIN3, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTA, SSD_PIN4, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTA, SSD_PIN5, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTA, SSD_PIN6, GPIO_OUTPUT);

		MGPIO_vSetPinOutType(GPIO_PORTA, SSD_PIN0, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTA, SSD_PIN1, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTA, SSD_PIN2, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTA, SSD_PIN3, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTA, SSD_PIN4, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTA, SSD_PIN5, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTA, SSD_PIN6, GPIO_PUSHPULL_PIN);
	}
#elif SSD_PORT == GPIO_PORTB
	if(PIN_3 <= SSD_PIN0 && SSD_PIN0<=PIN_15)
	{
		MRCC_voidEnableClock(AHB1,AHB1_GPIOAEN);
		MGPIO_vSetPinMode(GPIO_PORTA, SSD_PIN0, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTB, SSD_PIN1, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTB, SSD_PIN2, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTB, SSD_PIN3, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTB, SSD_PIN4, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTB, SSD_PIN5, GPIO_OUTPUT);
		MGPIO_vSetPinMode(GPIO_PORTB, SSD_PIN6, GPIO_OUTPUT);

		MGPIO_vSetPinOutType(GPIO_PORTB, SSD_PIN0, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTB, SSD_PIN1, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTB, SSD_PIN2, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTB, SSD_PIN3, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTB, SSD_PIN4, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTB, SSD_PIN5, GPIO_PUSHPULL_PIN);
		MGPIO_vSetPinOutType(GPIO_PORTB, SSD_PIN6, GPIO_PUSHPULL_PIN);
	}
#endif
}
void HSSD_voidDisplay(u8 A_u8Number)
{
	u8 L_u8Counter = 0;
	u8 L_u8bit;
	u8 PINS[] =
	{ SSD_PIN0, SSD_PIN1, SSD_PIN2, SSD_PIN3,
	SSD_PIN4, SSD_PIN5, SSD_PIN6 };
	for (L_u8Counter = 0; L_u8Counter < 7; L_u8Counter++)
	{
		L_u8bit = GET_BIT(A_u8Number, L_u8Counter);
		MGPIO_vSetPinValueFast(SSD_PORT, PINS[L_u8Counter], L_u8bit);
	}

}
void HSSD_voidDisplayAscending(void)
{
	HSSD_voidDisplay(ZERO);

	HSSD_voidDisplay(ONE);
	HSSD_voidDisplay(TWO);
	HSSD_voidDisplay(THREE);
	HSSD_voidDisplay(FOUR);
	HSSD_voidDisplay(FIVE);
	HSSD_voidDisplay(SIX);
	HSSD_voidDisplay(SEVEN);
	HSSD_voidDisplay(EIGHT);
}
void HSSD_voidDisplayDecending(void)
{

}


