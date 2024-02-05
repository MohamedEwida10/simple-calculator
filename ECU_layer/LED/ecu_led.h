/* 
 * File:   ecu_led.h
 * Author: mohamed.ewida
 * LinkedIn : https://www.linkedin.com/in/mohamed-ewida-181151264/
 * Created on September 21, 2023, 9:43 PM
 */

#ifndef ECU_LED_H
#define	ECU_LED_H


/******************* Section : Includes *******************/
#include "../../MCAL_layer/GPIO/hal_gpio.h"
#include "ecu_led_cfg.h"
/******************* Section : Macro Declarations *******************/


/******************* Section : Macro Functions Declarations *******************/


/******************* Section : MacroData Type Declarations *******************/
typedef enum{
    LED_OFF = 0,
    LED_ON
}led_status_t;

typedef struct{
    uint8 port_name :4 ;
    uint8 pin : 3;
    uint8 led_status :1;
}led_t;

/******************* Section : Functions Declarations *******************/
STD_ReturnType ecu_led_initialize(const led_t *led);
STD_ReturnType ecu_led_turn_on(const led_t *led);
STD_ReturnType ecu_led_turn_off(const led_t *led);
STD_ReturnType ecu_led_turn_toggle(const led_t *led);

#endif	/* ECU_LED_H */

