/* 
 * File:   ecu_layer_init.c
 * Author: mohamed.ewida
 * LinkedIn : https://www.linkedin.com/in/mohamed-ewida-181151264/
 * Created on October 21, 2023, 9:11 PM
 */

#include "ecu_layer_init.h"

chr_lcd_4bit_t lcd1 ={
.rs.port = PORTC_INDEX,
.rs.direction = DICRECTION_OUTOUT,
.rs.pin = PIN0,
.rs.logic = LOW,

.en.port = PORTC_INDEX,
.en.direction = DICRECTION_OUTOUT,
.en.pin = PIN1,
.en.logic = LOW,

.data[0].port = PORTC_INDEX,
.data[0].direction = DICRECTION_OUTOUT,
.data[0].pin = PIN2,
.data[0].logic = LOW,

.data[1].port = PORTC_INDEX,
.data[1].direction = DICRECTION_OUTOUT,
.data[1].pin = PIN3,
.data[1].logic = LOW,

.data[2].port = PORTC_INDEX,
.data[2].direction = DICRECTION_OUTOUT,
.data[2].pin = PIN4,
.data[2].logic = LOW,

.data[3].port = PORTC_INDEX,
.data[3].direction = DICRECTION_OUTOUT,
.data[3].pin = PIN5,
.data[3].logic = LOW,

};

keypad_t keypad = {
.keypad_rows_pins[0].port = PORTD_INDEX,
.keypad_rows_pins[0].pin = PIN0,
.keypad_rows_pins[0].direction = DICRECTION_OUTOUT,
.keypad_rows_pins[0].logic = LOW,
.keypad_rows_pins[1].port = PORTD_INDEX,
.keypad_rows_pins[1].pin = PIN1,
.keypad_rows_pins[1].direction = DICRECTION_OUTOUT,
.keypad_rows_pins[1].logic = LOW,
.keypad_rows_pins[2].port = PORTD_INDEX,
.keypad_rows_pins[2].pin = PIN2,
.keypad_rows_pins[2].direction = DICRECTION_OUTOUT,
.keypad_rows_pins[2].logic = LOW,
.keypad_rows_pins[3].port = PORTD_INDEX,
.keypad_rows_pins[3].pin = PIN3,
.keypad_rows_pins[3].direction = DICRECTION_OUTOUT,
.keypad_rows_pins[3].logic = LOW,

.keypad_columns_pins[0].port = PORTD_INDEX,
.keypad_columns_pins[0].pin = PIN4,
.keypad_columns_pins[0].direction = DICRECTION_INPUT,
.keypad_columns_pins[0].logic = LOW,
.keypad_columns_pins[1].port = PORTD_INDEX,
.keypad_columns_pins[1].pin = PIN5,
.keypad_columns_pins[1].direction = DICRECTION_INPUT,
.keypad_columns_pins[1].logic = LOW,
.keypad_columns_pins[2].port = PORTD_INDEX,
.keypad_columns_pins[2].pin = PIN6,
.keypad_columns_pins[2].direction = DICRECTION_INPUT,
.keypad_columns_pins[2].logic = LOW,
.keypad_columns_pins[3].port = PORTD_INDEX,
.keypad_columns_pins[3].pin = PIN7,
.keypad_columns_pins[3].direction = DICRECTION_INPUT,
.keypad_columns_pins[3].logic = LOW,
};

void ecu_layer_Initialization(void)
{
    lcd_4bit_initialize(&lcd1);
    ecu_keypad_initialize(&keypad);
}