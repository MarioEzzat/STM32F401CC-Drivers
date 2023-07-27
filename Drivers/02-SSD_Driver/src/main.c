#include "LIB/STD_TYPES.h"
#include "LIB/BIT_MATH.h"
#include "MCAL/RCC/RCC_interface.h"
#include "MCAL/GPIO/GPIO_interface.h"
#include "HAL/SSD/SSD_interface.h"


int main()
{
	MRCC_voidInit();
	HSSD_voidInit();
//	HSSD_voidDisplay(TWO);
//	sleep(1);

	u32 Counter = 0;
	while (1)
	{
		HSSD_voidDisplay(ONE);
		for (Counter = 0; Counter < 10000000; Counter++)
			;
		HSSD_voidDisplay(TWO);
		for (Counter = 0; Counter < 10000000; Counter++)
			;
		HSSD_voidDisplay(THREE);
		for (Counter = 0; Counter < 10000000; Counter++)
			;
		HSSD_voidDisplay(FOUR);
		for (Counter = 0; Counter < 10000000; Counter++)
			;

	}
}
