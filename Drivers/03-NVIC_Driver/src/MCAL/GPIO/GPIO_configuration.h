/*
 * GPIO_configuration.h
 *
 *  Created on: Jul 22, 2023
 *      Author: Mario Ezzat
 */

#ifndef MCAL_GPIO_GPIO_CONFIGURATION_H_
#define MCAL_GPIO_GPIO_CONFIGURATION_H_

/* -------------------------------------------------------------------------- */
/*                                    PORTA                                   */
/* -------------------------------------------------------------------------- */
/* -------------------------------- PIN_MODE -------------------------------- */
/* GPIO_INPUT_conc - GPIO_OUTPUT_conc - GPIO_ALTFUN_conc - GPIO_ANALOG_conc */
#define PORTA_PIN0_MODE     GPIO_INPUT_conc
#define PORTA_PIN1_MODE     GPIO_INPUT_conc
#define PORTA_PIN2_MODE     GPIO_INPUT_conc
#define PORTA_PIN3_MODE     GPIO_INPUT_conc
#define PORTA_PIN4_MODE     GPIO_INPUT_conc
#define PORTA_PIN5_MODE     GPIO_INPUT_conc
#define PORTA_PIN6_MODE     GPIO_INPUT_conc
#define PORTA_PIN7_MODE     GPIO_INPUT_conc
#define PORTA_PIN8_MODE     GPIO_INPUT_conc
#define PORTA_PIN9_MODE     GPIO_INPUT_conc
#define PORTA_PIN10_MODE    GPIO_INPUT_conc
#define PORTA_PIN11_MODE    GPIO_INPUT_conc
#define PORTA_PIN12_MODE    GPIO_INPUT_conc
#define PORTA_PIN13_MODE    GPIO_ANALOG_conc    // JTCK (NO CHANGE)
#define PORTA_PIN14_MODE    GPIO_INPUT_conc     // JTMS (NO CHANGE)
#define PORTA_PIN15_MODE    GPIO_INPUT_conc     // JTDI (NO CHANGE)
/* -------------------------------------------------------------------------- */
/* ------------------------------- OUTPUT TYPE ------------------------------ */
/* OPENDRAIN_PIN - PUSHPULL_PIN */ 
#define PORTA_PIN0_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN1_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN2_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN3_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN4_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN5_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN6_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN7_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN8_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN9_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTA_PIN10_OUT_TYPE   GPIO_PUSHPULL_PIN
#define PORTA_PIN11_OUT_TYPE   GPIO_PUSHPULL_PIN
#define PORTA_PIN12_OUT_TYPE   GPIO_PUSHPULL_PIN
#define PORTA_PIN13_OUT_TYPE   GPIO_PUSHPULL_PIN    // JTCK (NO CHANGE)
#define PORTA_PIN14_OUT_TYPE   GPIO_PUSHPULL_PIN    // JTMS (NO CHANGE)
#define PORTA_PIN15_OUT_TYPE   GPIO_PUSHPULL_PIN    // JTDI (NO CHANGE)
/* -------------------------------------------------------------------------- */
/* ------------------------------ OUTPUT SPEED ------------------------------ */
/* LOW_SPEED_conc - MED_SPEED_conc - HIGH_SPEED_conc - VHIGH_SPEED_conc */ 
#define PORTA_PIN0_SPEED    LOW_SPEED_conc
#define PORTA_PIN1_SPEED    LOW_SPEED_conc
#define PORTA_PIN2_SPEED    LOW_SPEED_conc
#define PORTA_PIN3_SPEED    LOW_SPEED_conc
#define PORTA_PIN4_SPEED    LOW_SPEED_conc
#define PORTA_PIN5_SPEED    LOW_SPEED_conc
#define PORTA_PIN6_SPEED    LOW_SPEED_conc
#define PORTA_PIN7_SPEED    LOW_SPEED_conc
#define PORTA_PIN8_SPEED    LOW_SPEED_conc
#define PORTA_PIN9_SPEED    LOW_SPEED_conc
#define PORTA_PIN10_SPEED   LOW_SPEED_conc
#define PORTA_PIN11_SPEED   LOW_SPEED_conc
#define PORTA_PIN12_SPEED   LOW_SPEED_conc
#define PORTA_PIN13_SPEED   VHIGH_SPEED_conc    // JTCK (NO CHANGE)
#define PORTA_PIN14_SPEED   LOW_SPEED_conc      // JTMS (NO CHANGE)
#define PORTA_PIN15_SPEED   LOW_SPEED_conc      // JTDI (NO CHANGE)
/* -------------------------------------------------------------------------- */
/* ------------------------------- OUTPUT DATA ------------------------------ */
/* GPIO_PIN_HIGH - GPIO_PIN_LOW */
#define PORTA_PIN0_OUT      GPIO_PIN_HIGH
#define PORTA_PIN1_OUT      GPIO_PIN_LOW
#define PORTA_PIN2_OUT      GPIO_PIN_LOW
#define PORTA_PIN3_OUT      GPIO_PIN_LOW
#define PORTA_PIN4_OUT      GPIO_PIN_LOW
#define PORTA_PIN5_OUT      GPIO_PIN_LOW
#define PORTA_PIN6_OUT      GPIO_PIN_LOW
#define PORTA_PIN7_OUT      GPIO_PIN_LOW
#define PORTA_PIN8_OUT      GPIO_PIN_LOW
#define PORTA_PIN9_OUT      GPIO_PIN_LOW
#define PORTA_PIN10_OUT     GPIO_PIN_LOW
#define PORTA_PIN11_OUT     GPIO_PIN_LOW
#define PORTA_PIN12_OUT     GPIO_PIN_LOW
#define PORTA_PIN13_OUT     GPIO_PIN_LOW    // JTCK (NO CHANGE)
#define PORTA_PIN14_OUT     GPIO_PIN_LOW    // JTMS (NO CHANGE)
#define PORTA_PIN15_OUT     GPIO_PIN_LOW    // JTDI (NO CHANGE)
/* -------------------------------------------------------------------------- */
/* ------------------------------- INPUT TYPE ------------------------------- */
/* NO_PULL_conc - PULL_UP_conc - PULL_DOWN_conc*/
#define PORTA_PIN0_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN1_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN2_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN3_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN4_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN5_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN6_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN7_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN8_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN9_INPUT_TYPE   NO_PULL_conc
#define PORTA_PIN10_INPUT_TYPE  NO_PULL_conc
#define PORTA_PIN11_INPUT_TYPE  NO_PULL_conc
#define PORTA_PIN12_INPUT_TYPE  NO_PULL_conc
#define PORTA_PIN13_INPUT_TYPE  PULL_UP_conc    // JTCK (NO CHANGE)
#define PORTA_PIN14_INPUT_TYPE  PULL_DOWN_conc  // JTMS (NO CHANGE)
#define PORTA_PIN15_INPUT_TYPE  PULL_UP_conc    // JTDI (NO CHANGE)
/* -------------------------------------------------------------------------- */
/* -------------------------------------------------------------------------- */
/*                                    PORTB                                   */
/* -------------------------------------------------------------------------- */
/* -------------------------------- PIN_MODE -------------------------------- */
/* GPIO_INPUT_conc - GPIO_OUTPUT_conc - GPIO_ALTFUN_conc - GPIO_ANALOG_conc */
#define PORTB_PIN0_MODE     GPIO_INPUT_conc
#define PORTB_PIN1_MODE     GPIO_INPUT_conc
#define PORTB_PIN2_MODE     GPIO_INPUT_conc     // BOOT1 (NO CHANGE)
#define PORTB_PIN3_MODE     GPIO_ALTFUN_conc    // JTDO (NO CHANGE)
#define PORTB_PIN4_MODE     GPIO_ALTFUN_conc    // JTRST (NO CHANGE)
#define PORTB_PIN5_MODE     GPIO_INPUT_conc
#define PORTB_PIN6_MODE     GPIO_INPUT_conc
#define PORTB_PIN7_MODE     GPIO_INPUT_conc
#define PORTB_PIN8_MODE     GPIO_INPUT_conc
#define PORTB_PIN9_MODE     GPIO_INPUT_conc
#define PORTB_PIN10_MODE    GPIO_INPUT_conc
#define PORTB_PIN11_MODE    GPIO_INPUT_conc
#define PORTB_PIN12_MODE    GPIO_INPUT_conc
#define PORTB_PIN13_MODE    GPIO_INPUT_conc
#define PORTB_PIN14_MODE    GPIO_INPUT_conc
#define PORTB_PIN15_MODE    GPIO_INPUT_conc
/* -------------------------------------------------------------------------- */
/* ------------------------------- OUTPUT TYPE ------------------------------ */
/* OPENDRAIN_PIN - PUSHPULL_PIN */ 
#define PORTB_PIN0_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTB_PIN1_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTB_PIN2_OUT_TYPE    GPIO_PUSHPULL_PIN    // BOOT1 (NO CHANGE)
#define PORTB_PIN3_OUT_TYPE    GPIO_PUSHPULL_PIN    // JTDO (NO CHANGE)
#define PORTB_PIN4_OUT_TYPE    GPIO_PUSHPULL_PIN    // JTRST (NO CHANGE)
#define PORTB_PIN5_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTB_PIN6_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTB_PIN7_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTB_PIN8_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTB_PIN9_OUT_TYPE    GPIO_PUSHPULL_PIN
#define PORTB_PIN10_OUT_TYPE   GPIO_PUSHPULL_PIN
#define PORTB_PIN11_OUT_TYPE   GPIO_PUSHPULL_PIN
#define PORTB_PIN12_OUT_TYPE   GPIO_PUSHPULL_PIN
#define PORTB_PIN13_OUT_TYPE   GPIO_PUSHPULL_PIN
#define PORTB_PIN14_OUT_TYPE   GPIO_PUSHPULL_PIN
#define PORTB_PIN15_OUT_TYPE   GPIO_PUSHPULL_PIN
/* -------------------------------------------------------------------------- */
/* ------------------------------ OUTPUT SPEED ------------------------------ */
/* LOW_SPEED_conc - MED_SPEED_conc - HIGH_SPEED_conc - VHIGH_SPEED_conc */ 
#define PORTB_PIN0_SPEED    LOW_SPEED_conc
#define PORTB_PIN1_SPEED    LOW_SPEED_conc  
#define PORTB_PIN2_SPEED    LOW_SPEED_conc      // BOOT1 (NO CHANGE)
#define PORTB_PIN3_SPEED    VHIGH_SPEED_conc    // JTDO (NO CHANGE)
#define PORTB_PIN4_SPEED    LOW_SPEED_conc      // JTRST (NO CHANGE)
#define PORTB_PIN5_SPEED    LOW_SPEED_conc
#define PORTB_PIN6_SPEED    LOW_SPEED_conc
#define PORTB_PIN7_SPEED    LOW_SPEED_conc
#define PORTB_PIN8_SPEED    LOW_SPEED_conc
#define PORTB_PIN9_SPEED    LOW_SPEED_conc
#define PORTB_PIN10_SPEED   LOW_SPEED_conc
#define PORTB_PIN11_SPEED   LOW_SPEED_conc
#define PORTB_PIN12_SPEED   LOW_SPEED_conc
#define PORTB_PIN13_SPEED   LOW_SPEED_conc
#define PORTB_PIN14_SPEED   LOW_SPEED_conc
#define PORTB_PIN15_SPEED   LOW_SPEED_conc
/* -------------------------------------------------------------------------- */
/* ------------------------------- OUTPUT DATA ------------------------------ */
/* GPIO_PIN_HIGH - GPIO_PIN_LOW */
#define PORTB_PIN0_OUT      GPIO_PIN_LOW
#define PORTB_PIN1_OUT      GPIO_PIN_LOW
#define PORTB_PIN2_OUT      GPIO_PIN_LOW    // BOOT1 (NO CHANGE)
#define PORTB_PIN3_OUT      GPIO_PIN_LOW    // JTDO (NO CHANGE)
#define PORTB_PIN4_OUT      GPIO_PIN_LOW    // JTRST (NO CHANGE)
#define PORTB_PIN5_OUT      GPIO_PIN_LOW
#define PORTB_PIN6_OUT      GPIO_PIN_LOW
#define PORTB_PIN7_OUT      GPIO_PIN_LOW
#define PORTB_PIN8_OUT      GPIO_PIN_LOW
#define PORTB_PIN9_OUT      GPIO_PIN_LOW
#define PORTB_PIN10_OUT     GPIO_PIN_LOW
#define PORTB_PIN11_OUT     GPIO_PIN_LOW
#define PORTB_PIN12_OUT     GPIO_PIN_LOW
#define PORTB_PIN13_OUT     GPIO_PIN_LOW
#define PORTB_PIN14_OUT     GPIO_PIN_LOW
#define PORTB_PIN15_OUT     GPIO_PIN_LOW
/* -------------------------------------------------------------------------- */
/* ------------------------------- INPUT TYPE ------------------------------- */
/* NO_PULL_conc - PULL_UP_conc - PULL_DOWN_conc*/
#define PORTB_PIN0_INPUT_TYPE   NO_PULL_conc
#define PORTB_PIN1_INPUT_TYPE   NO_PULL_conc
#define PORTB_PIN2_INPUT_TYPE   NO_PULL_conc    // BOOT1 (NO CHANGE)
#define PORTB_PIN3_INPUT_TYPE   NO_PULL_conc    // JTDO (NO CHANGE)
#define PORTB_PIN4_INPUT_TYPE   PULL_UP_conc    // JTRST (NO CHANGE)
#define PORTB_PIN5_INPUT_TYPE   NO_PULL_conc
#define PORTB_PIN6_INPUT_TYPE   NO_PULL_conc
#define PORTB_PIN7_INPUT_TYPE   NO_PULL_conc
#define PORTB_PIN8_INPUT_TYPE   NO_PULL_conc
#define PORTB_PIN9_INPUT_TYPE   NO_PULL_conc
#define PORTB_PIN10_INPUT_TYPE  NO_PULL_conc
#define PORTB_PIN11_INPUT_TYPE  NO_PULL_conc
#define PORTB_PIN12_INPUT_TYPE  NO_PULL_conc
#define PORTB_PIN13_INPUT_TYPE  NO_PULL_conc
#define PORTB_PIN14_INPUT_TYPE  NO_PULL_conc
#define PORTB_PIN15_INPUT_TYPE  NO_PULL_conc
/* -------------------------------------------------------------------------- */
#endif /* MCAL_GPIO_GPIO_CONFIGURATION_H_ */
