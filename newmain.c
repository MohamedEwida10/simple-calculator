/* 
 * File:   newmain.c
 * Author: Blu-Ray
 * LinkedIn : https://www.linkedin.com/in/mohamed-ewida-181151264/
 * Created on February 1, 2024, 2:05 PM
 */

#include "newmain.h"
 
uint32 temp1 = 0;
uint32 temp2 = 0;
uint32 temp_result = 0;
int main() { 
    Application_Initialization();
    
 while(1){ 
    
    initialize_var(); // reset the variables
    
    lcd_4bit_send_command(&lcd1,_LCD_CLEAR);               
    lcd_4bit_send_string_pos(&lcd1,2,1,"calc is ready");  // start screen 
	__delay_ms(1000);
	lcd_4bit_send_command(&lcd1,_LCD_CLEAR);
                   
    get_number_and_operartion(num1,&counter_num1,&lcd_counter,&operation); //take first number and first operation 
    convert_arr_to_float( num1,counter_num1,&num1_val);
     temp1 = num1_val;
    get_number_and_operartion(num2,&counter_num2,&lcd_counter,&operation2);//take second number and second operation
    convert_arr_to_float( num2,counter_num2,&num2_val);
    temp2 = num2_val;
    
    if(operation2 == '='){}//nothing // if operation2 = '=' then we don?t need the third number and third operation
    else{
    get_third_number_and_third_operartion(num3,&counter_num3,&lcd_counter,&operation3);
    convert_arr_to_float( num3,counter_num3,&num3_val);   
    }
    
    if((operation2 == '*' || operation2 == '/') && (operation == '+' || operation == '-')) //Arithmetic Operator Precedence
    {
       switch(operation2){
           case '*': multiplication_operation(num2_val,num3_val,&result);break; 
           case '/': Division_operation(num2_val,num3_val,&result);break; 
       }
               
         switch(operation){
           case '+': sum_operation(num1_val,result,&total_result);break; 
           case '-': subtraction_operation(num1_val,result,&total_result);break; 
       }

       switch(operation3){
           case '+': break; 
           case '-': break; 
           case '*': break; 
           case '/': break; 
           case '=': send_the_result_to_LCD(total_result);break; 
       }  
    } 
    else{ //without arithmetic Operator Precedence {by order}
        switch(operation){
           case '+': sum_operation(num1_val,num2_val,&result);break; 
           case '-': subtraction_operation(num1_val,num2_val,&result);break; 
           case '*': multiplication_operation(num1_val,num2_val,&result);break; 
           case '/': Division_operation(num1_val,num2_val,&result);break; 
           case '=': result = num1_val;break; 
       }

       switch(operation2){
           case '+': sum_operation(result,num3_val,&total_result);break; 
           case '-': subtraction_operation(result,num3_val,&total_result);break; 
           case '*': multiplication_operation(result,num3_val,&total_result);break; 
           case '/': Division_operation(result,num3_val,&total_result);break; 
           case '=': send_the_result_to_LCD(result);break; 
       }
       
       switch(operation3){
           case '+': ;break; 
           case '-': ;break; 
           case '*': ;break; 
           case '/': ;break; 
           case '=': send_the_result_to_LCD(total_result);break; 
       }
       
       temp_result = total_result;

       
    }
    
    __delay_ms(5000);
	lcd_4bit_send_command(&lcd1,_LCD_CLEAR);
    }
    return (EXIT_SUCCESS);
}
void Application_Initialization(void){

ecu_layer_Initialization();
}

