/* 
 * File:   ecu_layer_init.h
 * Author: mohamed.ewida
 * LinkedIn : https://www.linkedin.com/in/mohamed-ewida-181151264/
 * Created on October 21, 2023, 9:11 PM
 */

#ifndef ECU_LAYER_INIT_H
#define	ECU_LAYER_INIT_H



/******************* Section : Includes *******************/
#include "LED/ecu_led.h"
#include "button/ecu_button.h"
#include "Relay/ecu_relay.h"
#include "DC_motor/ecu_DC_motor.h"
#include "7_segment/ecu_seven_segment.h"
#include "Keypad/ecu_keypad.h"
#include "chr_LCD/ecu_chr_LCD.h"

/******************* Section : Macro Declarations *******************/


/******************* Section : Macro Functions Declarations *******************/


/******************* Section : MacroData Type Declarations *******************/


/******************* Section : Functions Declarations *******************/
void ecu_layer_Initialization(void);

#endif	/* ECU_LAYER_INIT_H */

