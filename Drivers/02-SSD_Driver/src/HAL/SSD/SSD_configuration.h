/*
 * SSD_configuration.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Mario Ezzat
 */

#ifndef HAL_SSD_SSD_CONFIGURATION_H_
#define HAL_SSD_SSD_CONFIGURATION_H_

// SSD PORT:- GPIO_PORTA - GPIO_PORTB
#define SSD_PORT GPIO_PORTA

// SSD PINS:-
/*
 *	FOR PORTA  PIN_RANGE(0 .. 12)
 *	FOR PORTA  PIN_RANGE(5 .. 15)
 */
#define SSD_PIN0 PIN_0
#define SSD_PIN1 PIN_1
#define SSD_PIN2 PIN_2
#define SSD_PIN3 PIN_3
#define SSD_PIN4 PIN_4
#define SSD_PIN5 PIN_5
#define SSD_PIN6 PIN_6
/* ---------------------------------------*/


// TIME IN (MS)
#define SSD_DISPLAY_TIME 1000


#endif /* HAL_SSD_SSD_CONFIGURATION_H_ */
