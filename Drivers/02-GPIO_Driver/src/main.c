#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/RCC/RCC_interface.h"

#include "MCAL/GPIO/GPIO_interface.h"
int main()
{
	/* Enable Clock */
	MRCC_voidInit();
	MRCC_voidEnableClock(AHB1, AHB1_GPIOAEN);
	MRCC_voidEnableClock(AHB1, AHB1_GPIOBEN);

	//	MGPIO_vSetPinMode(GPIO_PORTA, PIN_0, GPIO_OUTPUT);
	//	MGPIO_vSetPinOutType(GPIO_PORTA, PIN_0, GPIO_PUSHPULL_PIN);
	//	MGPIO_vSetPinValueFast(GPIO_PORTA, PIN_0, GPIO_PIN_HIGH);

	MGPIO_vInit();

	MGPIO_vSetPinMode(GPIO_PORTB, PIN_0, GPIO_OUTPUT);
	MGPIO_vSetPinOutType(GPIO_PORTB, PIN_0, GPIO_PUSHPULL_PIN);
	MGPIO_vSetPinValueFast(GPIO_PORTB, PIN_0, GPIO_PIN_HIGH);
	while (1)
	{
	}
}
