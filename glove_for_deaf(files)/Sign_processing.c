/*
 * Demultiplexer.c
 *
 * Created: 10/02/2022 23:54:12
 *  Author: 123
 */ 
#include "ADC.h"
#include "LCD.h"
#include "StringHandler.h"
#include "STD_Types.h"
#include "Dio.h"
#include  "Sign_Processing.h"

enum Fingers{Thumb,Index,Middle,Ring,Little};
uint8 i=0;
uint16 Thumb_Value=0;
uint16 Index_Value=0;
uint16 Middle_Value=0;
uint16 Ring_Value=0;
uint16 Little_Value=0;
uint8 Thumb_String[5];
uint8 Index_String[5];
uint8 Middle_String[5];
uint8 Ring_String[5];
uint8 Little_String[5];

uint8 String0[]={"Hello"};
uint8 String1[]={"I Love You"};	 
uint8 String2[]={"See You Later"};
uint8 String3[]={"No"};
uint8 String4[]={"Goodbye"};
uint8 String5[]={"This is Terrible"};
uint8 String6[]={"You"};
uint8 String7[]={"OK"};
uint8 String8[]={"I really like u"};		
uint8 String9[]={"Good Job"};
uint8 String10[]={"I am Watching u"};
uint8 String11[]={"Peace"};
uint8 String12[]={"Question"};
uint8 String13[]={"Perfect"};
uint8 String14[]={"I am not sure"};	


void Sign_Read()
{
	for(i=0;i<5;i++)
	{
	 switch(i)
	 {	 
	   case 0:
	 Selector_Set(Thumb) ;
	 U16HEX2String(Thumb_Value,Thumb_String);
	   break;
	 
	   case 1:
     Selector_Set(Index);
     U16HEX2String(Index_Value,Index_String);
       break;
	 
	   case 2: 
     Selector_Set(Middle);
     U16HEX2String(Middle_Value,Middle_String);
       break;
	  
	   case 3:
     Selector_Set(Ring);
     U16HEX2String(Ring_Value,Ring_String);
	   break;
	
	   case 4:
	 Selector_Set(Little);
	 U16HEX2String(Little_Value,Little_String);
	   break;
	 }
	}
}

void Selector_Set(uint8 Selector_Value)
{
	switch(Selector_Value)
	{
		
		case 0:
	Dio_PinWrite(B,0,PinLow);
	Dio_PinWrite(D,6,PinLow);
	Dio_PinWrite(D,2,PinLow);
    ADC_ReadChannel(0,&Thumb_Value);   
		break;
	
	
	    case 1:
	Dio_PinWrite(B,0,PinHigh);
	Dio_PinWrite(D,6,PinLow);
	Dio_PinWrite(D,2,PinLow);
	ADC_ReadChannel(0,&Index_Value);
		break;
	
	
	    case 2:
	Dio_PinWrite(B,0,PinLow);
	Dio_PinWrite(D,6,PinHigh);
	Dio_PinWrite(D,2,PinLow);
    ADC_ReadChannel(0,&Middle_Value);
		break;
	
	   
	    case 3:
	Dio_PinWrite(B,0,PinHigh);
	Dio_PinWrite(D,6,PinHigh);
	Dio_PinWrite(D,2,PinLow);
	ADC_ReadChannel(0,&Ring_Value);
	    break;
	
	
	    case 4:
	Dio_PinWrite(B,0,PinLow);
	Dio_PinWrite(D,6,PinLow);
    Dio_PinWrite(D,2,PinHigh);
    ADC_ReadChannel(0,&Little_Value);
	    break;	
	
	   default:
       break;
		
	}
}

void Sign_Values(void)
{
	LCD_Command(ClearDispaly);
	LCD_Postion(1,1);
	LCD_DataString(Thumb_String);
	LCD_Postion(1,6);
	LCD_DataString(Index_String);
	LCD_Postion(1,11);
	LCD_DataString(Middle_String);
	LCD_Postion(2,1);
	LCD_DataString(Ring_String);
	LCD_Postion(2,6);
	LCD_DataString(Little_String);
}

void Sign_ClearAll()
{
	Thumb_String[0]=0;
	Thumb_String[1]=0;
	Thumb_String[2]=0;
	Thumb_String[3]=0;
	Thumb_String[4]=0;
	
	Middle_String[0]=0;
	Middle_String[1]=0;
	Middle_String[2]=0;
	Middle_String[3]=0;
	Middle_String[4]=0;
	
	Index_String[0]=0;
	Index_String[1]=0;
	Index_String[2]=0;
	Index_String[3]=0;
	Index_String[4]=0;

	Ring_String[0]=0;
	Ring_String[1]=0;
	Ring_String[2]=0;
	Ring_String[3]=0;
	Ring_String[4]=0;
	
	Little_String[0]=0;
	Little_String[1]=0;
	Little_String[2]=0;
	Little_String[3]=0;
	Little_String[4]=0;

	
}

void Sign_Represent()
{
	//Hello
	if((Thumb_Value>=0x0305)&&(Thumb_Value<=0x0321)&&(Index_Value>=0x0310)&&(Index_Value<=0x0330)&&(Middle_Value>=0x0310)&&(Middle_Value<=0x0337)&&(Ring_Value>=0x030A)&&(Ring_Value<=0x032F)&&(Little_Value>=0x033D)&&(Little_Value<=0x035F))
	{
		LCD_Command(ClearDispaly);
		LCD_DataString(String0);
	}
	
	//I Love You
	else if((Thumb_Value>=0x0310)&&(Thumb_Value<=0x0325)&&(Index_Value>=0x030A)&&(Index_Value<=0x0328)&&(Middle_Value>=0x0380)&&(Middle_Value<=0x0395)&&(Ring_Value>=0x0355)&&(Ring_Value<=0x0375)&&(Little_Value>=0x0340)&&(Little_Value<=0x0360))
	{
		LCD_Command(ClearDispaly);
		LCD_DataString(String1);
	}
	
	//See You Later
   else if((Thumb_Value>=0x0316)&&(Thumb_Value<=0x032B)&&(Index_Value>=0x0310)&&(Index_Value<=0x032C)&&(Middle_Value>=0x037A)&&(Middle_Value<=0x039A)&&(Ring_Value>=0x035F)&&(Ring_Value<=0x037F)&&(Little_Value>=0x0385)&&(Little_Value<=0x03AF))
   {
	   LCD_Command(ClearDispaly);
	   LCD_DataString(String2);
   }
  
  //No
    else if((Thumb_Value>=0x0300)&&(Thumb_Value<=0x0315)&&(Index_Value>=0x0385)&&(Index_Value<=0x039F)&&(Middle_Value>=0x0380)&&(Middle_Value<=0x0395)&&(Ring_Value>=0x0368)&&(Ring_Value<=0x0385)&&(Little_Value>=0x0390)&&(Little_Value<=0x03A6))
    {
	    LCD_Command(ClearDispaly);
	    LCD_DataString(String3);
    }
	
	//Goodbye
	  else if((Thumb_Value>=0x036C)&&(Thumb_Value<=0x0380)&&(Index_Value>=0x0307)&&(Index_Value<=0x0320)&&(Middle_Value>=0x0315)&&(Middle_Value<=0x032F)&&(Ring_Value>=0x0300)&&(Ring_Value<=0x0315)&&(Little_Value>=0x032E)&&(Little_Value<=0x0340))
	  {
		  LCD_Command(ClearDispaly);
		  LCD_DataString(String4);
	  }
	  
	   //This is Terrible
	   else if((Thumb_Value>=0x0379)&&(Thumb_Value<=0x038F)&&(Index_Value>=0x0319)&&(Index_Value<=0x032F)&&(Middle_Value>=0x037C)&&(Middle_Value<=0x0399)&&(Ring_Value>=0x0359)&&(Ring_Value<=0x0379)&&(Little_Value>=0x0340)&&(Little_Value<=0x0367))
	   {
		   LCD_Command(ClearDispaly);
		   LCD_DataString(String5);
	   }
	   
	   //You
	   else if((Thumb_Value>=0x037F)&&(Thumb_Value<=0x039C)&&(Index_Value>=0x0319)&&(Index_Value<=0x032C)&&(Middle_Value>=0x0380)&&(Middle_Value<=0x0399)&&(Ring_Value>=0x035C)&&(Ring_Value<=0x0379)&&(Little_Value>=0x0385)&&(Little_Value<=0x03A0))
	   {
		   LCD_Command(ClearDispaly);
		   LCD_DataString(String6);
	   }
	   
	   //OK
	   else if((Thumb_Value>=0x036A)&&(Thumb_Value<=0x0395)&&(Index_Value>=0x038D)&&(Index_Value<=0x03A9)&&(Middle_Value>=0x037A)&&(Middle_Value<=0x0395)&&(Ring_Value>=0x0370)&&(Ring_Value<=0x0385)&&(Little_Value>=0x038F)&&(Little_Value<=0x03AF))
	   {
		   LCD_Command(ClearDispaly);
		   LCD_DataString(String7);
	   }
	   
	   //really like u
	   else if((Thumb_Value>=0x030A)&&(Thumb_Value<=0x0325)&&(Index_Value>=0x0300)&&(Index_Value<=0x031F)&&(Middle_Value>=0x032D)&&(Middle_Value<=0x0345)&&(Ring_Value>=0x0350)&&(Ring_Value<=0x036A)&&(Little_Value>=0x0340)&&(Little_Value<=0x0360))
	   {
		   LCD_Command(ClearDispaly);
		   LCD_DataString(String8);
	   }
	   
	  //Good Job
	  else if((Thumb_Value>=0x0315)&&(Thumb_Value<=0x0330)&&(Index_Value>=0x0390)&&(Index_Value<=0x03A7)&&(Middle_Value>=0x037C)&&(Middle_Value<=0x039B)&&(Ring_Value>=0x0368)&&(Ring_Value<=0x037F)&&(Little_Value>=0x0395)&&(Little_Value<=0x03AF))
	  {
		  LCD_Command(ClearDispaly);
		  LCD_DataString(String9);
	  }
	  
	  //I am watching u
	  else if((Thumb_Value>=0x0395)&&(Thumb_Value<=0x03AF)&&(Index_Value>=0x0385)&&(Index_Value<=0x039E)&&(Middle_Value>=0x037F)&&(Middle_Value<=0x0390)&&(Ring_Value>=0x0367)&&(Ring_Value<=0x037C)&&(Little_Value>=0x0387)&&(Little_Value<=0x03A1))
	  {
		  LCD_Command(ClearDispaly);
		  LCD_DataString(String10);
	  }
	  
	  //Peace
	  else if((Thumb_Value>=0x0370)&&(Thumb_Value<=0x038C)&&(Index_Value>=0x0310)&&(Index_Value<=0x032B)&&(Middle_Value>=0x0310)&&(Middle_Value<=0x032C)&&(Ring_Value>=0x0350)&&(Ring_Value<=0x0370)&&(Little_Value>=0x037D)&&(Little_Value<=0x0390))
	  {
		  LCD_Command(ClearDispaly);
		  LCD_DataString(String11);
	  }
	  
	  //Question
	  else if((Thumb_Value>=0x0388)&&(Thumb_Value<=0x03A0)&&(Index_Value>=0x0365)&&(Index_Value<=0x0380)&&(Middle_Value>=0x0380)&&(Middle_Value<=0x039E)&&(Ring_Value>=0x0360)&&(Ring_Value<=0x0381)&&(Little_Value>=0x0395)&&(Little_Value<=0x03A8))
	  {
		  LCD_Command(ClearDispaly);
		  LCD_DataString(String12);
	  }
	  
	  //Perfect
	  else if((Thumb_Value>=0x035C)&&(Thumb_Value<=0x0370)&&(Index_Value>=0x0380)&&(Index_Value<=0x03A9)&&(Middle_Value>=0x0305)&&(Middle_Value<=0x0329)&&(Ring_Value>=0x0316)&&(Ring_Value<=0x0325)&&(Little_Value>=0x0340)&&(Little_Value<=0x0360))
	  {
		  LCD_Command(ClearDispaly);
		  LCD_DataString(String13);
	  }
	  
	  //I am not sure
	  else if((Thumb_Value>=0x0305)&&(Thumb_Value<=0x032C)&&(Index_Value>=0x037E)&&(Index_Value<=0x0390)&&(Middle_Value>=0x0375)&&(Middle_Value<=0x038F)&&(Ring_Value>=0x0355)&&(Ring_Value<=0x0370)&&(Little_Value>=0x0340)&&(Little_Value<=0x035C))
	  {
		  LCD_Command(ClearDispaly);
		  LCD_DataString(String14);
	  }
	  
	  else
	  {
		 LCD_Command(ClearDispaly);
		 
		  
	  }
	  
}