#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"

#include "MCAL/RCC/RCC_interface.h"

int main()
{
	MRCC_voidInit();
	MRCC_voidEnableClock(AHB1, AHB1_GPIOAEN);
	while (1)
	{

	}
}
