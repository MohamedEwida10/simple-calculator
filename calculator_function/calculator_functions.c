/* 
 * File:   calculator_functions.c
 * Author: Blu-Ray
 * LinkedIn : https://www.linkedin.com/in/mohamed-ewida-181151264/
 * Created on February 4, 2024, 8:14 PM
 */

#include "calculator_functions.h"

/**
 * @brief getting the number in array and the operation 
 * @param num : array to store the number in the characters form
 * @param counter_num : the counter which indicate the numbers of digits of the number
 * @param lcd_counter : the counter which indicate the position of LCD cursor
 * @param operation : pointer to the operation
 */
void get_number_and_operartion(uint8 *num,uint8 *counter_num,
                               uint8 *lcd_counter,uint8 *operation)
{
uint8 keypad_value  = 0;
    while(1){
        do{
        ecu_keypad_get_value(&keypad,&keypad_value);   // to read the keypad button pressed
        __delay_ms(150);
        }while((keypad_value == 0) );
        
        if(keypad_value == '#'){ // if you pressed '#' ,you want to delete the last number 
           (*counter_num)--; 
           num[*counter_num] = '\0';
           (*lcd_counter)--; 
           lcd_4bit_send_char_data_pos(&lcd1,1,*lcd_counter,' ');
               
        }
        else{    // store the operation and send it to the LCD 
            if((keypad_value == '+'||keypad_value == '-'||keypad_value == '*'||keypad_value == '/'||keypad_value == '=')){
                if(num[0] == 0){ // to avoid get the operation without number
                lcd_4bit_send_string_pos(&lcd1,4,1,"syntax error !");
                __delay_ms(500);
                lcd_4bit_send_string_pos(&lcd1,4,1,"                  "); 
                __delay_ms(500);        
                }
                else{ // get operation
                *operation = keypad_value; 
                lcd_4bit_send_char_data_pos(&lcd1,1,*lcd_counter,keypad_value);
                (*lcd_counter)++;
                break;   
                }
                
            }
            else{
                if((*counter_num) < 4){ // make sure that maxmum digits of the number array is 4  
                        num[*counter_num] = keypad_value; 
                        lcd_4bit_send_char_data_pos(&lcd1,1,*lcd_counter,keypad_value);
                        (*lcd_counter)++;    
                        (*counter_num)++;    
                    }
                else{  // hint message
                    lcd_4bit_send_string_pos(&lcd1,4,1,"hint:max 4 digits");
                    __delay_ms(500);
                    lcd_4bit_send_string_pos(&lcd1,4,1,"                  "); 
                    __delay_ms(500);    
                }
            }
            
        }
           

    }

}

void get_third_number_and_third_operartion(uint8 *num,uint8 *counter_num,uint8 *lcd_counter,
                                           uint8 *operation)
{
uint8 keypad_value  = 0;
    while(1){
        do{
        ecu_keypad_get_value(&keypad,&keypad_value);   // to read the keypad button pressed
        __delay_ms(150);
        }while((keypad_value == 0) );
        
        if(keypad_value == '#'){ // if you pressed '#' ,you want to delete the last char
           (*counter_num)--; 
           num[*counter_num] = '\0';
           (*lcd_counter)--; 
           lcd_4bit_send_char_data_pos(&lcd1,1,*lcd_counter,' ');
               
        }
        else{    // store the operation and send it to the LCD 
            if(keypad_value == '+'||keypad_value == '-'||keypad_value == '*'||keypad_value == '/'){ // hint message
                if(num[0] == 0){ // to avoid get the operation without number
                lcd_4bit_send_string_pos(&lcd1,4,1,"syntax error !");
                __delay_ms(500);
                lcd_4bit_send_string_pos(&lcd1,4,1,"                  "); 
                __delay_ms(500);        
                }
                else{ 
                lcd_4bit_send_string_pos(&lcd1,4,1,"hint:max 2 operation!!");
                 __delay_ms(500);
                 lcd_4bit_send_string_pos(&lcd1,4,1,"                           "); 
                 __delay_ms(500); 
                }

            }     
            else if(keypad_value == '='){ //  getting the '='  
                *operation = keypad_value; 
                lcd_4bit_send_char_data_pos(&lcd1,1,*lcd_counter,keypad_value);
                (*lcd_counter)++;
                break;
            }
            else{
                if((*counter_num) < 4){ // make sure that maxmum digits of the number array is 4  
                    num[*counter_num] = keypad_value; // store the number_array element by element
                    lcd_4bit_send_char_data_pos(&lcd1,1,*lcd_counter,keypad_value);
                    (*lcd_counter)++;    
                    (*counter_num)++;    
                }
                else{ // hint message
                    lcd_4bit_send_string_pos(&lcd1,4,1,"hint:max 4 digits");
                     __delay_ms(500);
                     lcd_4bit_send_string_pos(&lcd1,4,1,"                  "); 
                     __delay_ms(500);    
                }
                
                
            }
            
        }
           

    }

}

/**
 * @brief convert the number_array to float value to do the operations on it
 * @param arr : the number_array 
 * @param counter_num : the counter which indicate the numbers of digits of the number
 * @param num_value :the float value of the number
 */
void convert_arr_to_float( const uint8 *arr,const uint8 counter_num,float32 *num_value){
uint8 count = 0;    
uint8 count_power = counter_num-1;  
for(count;count < counter_num;count++){
*num_value = *num_value + (arr[count] - 48)* (pow(10,count_power));
count_power--;
}    
}
/**
 * @brief convert the float value if the result to send to the LCD 
 * @param value : the float value
 * @param str : the string that will send to the LCD
 */
void convert_float_to_string(float32 value,uint8 *str){
    memset(str,'\0',20);
    sprintf(str,"%.2f",value);
}

/**
 * @brief sum operation
 * @param num1_val : first number
 * @param num2_val : second number
 * @param result : the result of the operation
 */
void sum_operation( float32 num1_val, float32 num2_val,float32 *result){
*result = num1_val+num2_val;    
}

/**
 * @brief subtraction operation
 * @param num1_val : first number
 * @param num2_val : second number
 * @param result : the result of the operation
 */
void subtraction_operation( float32 num1_val, float32 num2_val,float32 *result){
*result = num1_val-num2_val;    
}

/**
 * @brief multiplication operation
 * @param num1_val : first number
 * @param num2_val : second number
 * @param result : the result of the operation
 */
void multiplication_operation( float32 num1_val, float32 num2_val,float32 *result){
*result = num1_val*num2_val;    
}

/**
 * @brief Division operation
 * @param num1_val : first number
 * @param num2_val : second number
 * @param result : the result of the operation
 */
void Division_operation( float32 num1_val, float32 num2_val,float32 *result){
*result = num1_val/num2_val;    
}

/**
 * @brief send the result to the LCD after make sure that it is a float value or not
 * @param result
 * @param lcd_counter : the counter which indicate the position of LCD cursor
 */
void send_the_result_to_LCD(float32 result){
float32 result_str[20];    
if(result > (uint32)result){
convert_float_to_string(result,result_str);
}
else{  
convert_int_to_string((uint32)result,(uint32)result_str);
}  
lcd_4bit_send_command(&lcd1,_LCD_CURSER_OFF_DEPLAY_OFF);
lcd_4bit_send_command(&lcd1,_LCD_CURSER_OFF_DEPLAY_ON);
lcd_4bit_send_string_pos(&lcd1,3,1,result_str);

}

/**
 * to reset the counters and arrays and operations to restart the loop
 */
void initialize_var(void){
     keypad_value  = 0;

     lcd_counter = 1;
     counter_num1 = 0;
     counter_num2 = 0;
     counter_num3 = 0;
     operation = 0;
     operation2 = 0;
     operation3 = 0;

     for(int count = 0;count< 3;count++){
     num1[count] = 0;
     num2[count] = 0;
     num3[count] = 0;
     }
     
     num1_val = 0;
     num2_val = 0;
     num3_val = 0;

     result = 0;
     total_result = 0;     
}
