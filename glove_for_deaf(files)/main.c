/*
 * glove_for_deaf.c
 *
 * Created: 07/02/2022 01:57:18
 * Author : 123
 */
#define F_CPU 16000000UL
#include <avr/io.h>
#include  "ADC.h"
#include  "STD_Types.h"
#include   "StringHandler.h"
#include  "LCD.h"
#include  "Bitwise.h"
#include  "Dio.h"
#include "Sign_Processing.h"




int main(void)
{	
	//setting selector pins as outputs
	
	Dio_PinSetDirection(B,0,PinOutput);  //Selector0
	Dio_PinSetDirection(D,6,PinOutput); //Selector1
	Dio_PinSetDirection(D,2,PinOutput); //Selector2
	Dio_PinPullupState(B,0,Active);
	Dio_PinPullupState(D,6,Active);
	Dio_PinPullupState(D,2,Active);
	
	ADC_Init();
	LCD_Init();
	ADC_ChannelInit(0);
    Sign_ClearAll();
    while (1)
    {
		Sign_Read();
		//Sign_Values();
		Sign_Represent();
		_delay_ms(2000);
    }
}




