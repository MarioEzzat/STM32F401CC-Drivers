/*
 * SSD_interface.h
 *
 *  Created on: Jul 24, 2023
 *      Author: Mario Ezzat
 */

#ifndef HAL_SSD_SSD_INTERFACE_H_
#define HAL_SSD_SSD_INTERFACE_H_

#define ZERO  0b0111111
#define ONE   0b0000110
#define TWO   0b1011011
#define THREE 0b1001111
#define FOUR  0b1100110
#define FIVE  0b1101101
#define SIX   0b1111101
#define SEVEN 0b0000111
#define EIGHT 0b1111111
#define NINE  0b1101111

void HSSD_voidDisplay(u8 A_u8Number);
void HSSD_voidDisplayAscending(void);
void HSSD_voidDisplayDecending(void);



#endif /* HAL_SSD_SSD_INTERFACE_H_ */
