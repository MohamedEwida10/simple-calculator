/* 
 * File:   calculator_functions.h
 * Author: Blu-Ray
 * LinkedIn : https://www.linkedin.com/in/mohamed-ewida-181151264/
 * Created on February 4, 2024, 8:14 PM
 */

#ifndef CALCULATOR_FUNCTIONS_H
#define	CALCULATOR_FUNCTIONS_H

/******************* Section : Includes *******************/
#include "../simple calculator/ECU_layer/Keypad/ecu_keypad.h"
#include "../simple calculator/ECU_layer/chr_LCD/ecu_chr_LCD.h"

/******************* Section : Macro Declarations *******************/
    uint8 keypad_value  = 0;

    uint8 lcd_counter = 1;
    uint8 counter_num1 = 0;
    uint8 counter_num2 = 0;
    uint8 counter_num3 = 0;
    uint8 operation = 0;
    uint8 operation2 = 0;
    uint8 operation3 = 0;


    uint8 num1[4] = {0,0,0,0};
    float32 num1_val = 0;
    uint8 num2[4] = {0,0,0,0};
    float32 num2_val = 0;
    uint8 num3[4] = {0,0,0,0};
    float32 num3_val = 0;

    float32 result = 0;
    float32 total_result = 0;
    
    extern chr_lcd_4bit_t lcd1;
    extern keypad_t keypad;

/******************* Section : Macro Functions Declarations *******************/


/******************* Section : MacroData Type Declarations *******************/


/******************* Section : Functions Declarations *******************/
void get_number_and_operartion(uint8 *num,uint8 *counter_num,uint8 *lcd_counter,
                               uint8 *operation);
void get_third_number_and_third_operartion(uint8 *num,uint8 *counter_num,uint8 *lcd_counter,
                                           uint8 *operation);

void convert_arr_to_float( const uint8 *arr,const uint8 counter_num,float32 *num_value);
void convert_float_to_string(float32 value,uint8 *str);


void sum_operation           (float32 num1_val, float32 num2_val,float32 *result);
void subtraction_operation   (float32 num1_val, float32 num2_val,float32 *result);
void multiplication_operation(float32 num1_val, float32 num2_val,float32 *result);
void Division_operation      (float32 num1_val, float32 num2_val,float32 *result);

void send_the_result_to_LCD(float32 result);

void initialize_var(void);


#endif	/* CALCULATOR_FUNCTIONS_H */

