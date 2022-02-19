
#include "StringHandler.h"

ReturnValueType U8HEX2String (uint8 HEX,uint8 string[3])
{
	
	string[2] = 0 ;
	if ((HEX & 0x0F) > 9)
	{
		string[1] =(HEX & 0x0F) - 0x0A + 'A' ;
	}
	else
	{
		string[1] =(HEX & 0x0F) + '0' ;
	}
	if ((HEX >> 4) > 9)
	{
		string[0] =(HEX>>4 & 0x0F) - 0x0A + 'A' ;
	}
	else
	{
		string[0] =(HEX>>4 & 0x0F) + 0x30 ;
	}
	
	return OK;
	
	
}

ReturnValueType U8Decimal2String (uint8 Decimal,uint8* string)
{
	string[3]= 0 ; // NULL
	string[0]= Decimal/ 100 + '0' ;  // 0
	string [1] = (Decimal%100)/10  + '0' ; // 3
	string [2] = (Decimal%100)%10 + '0' ; // 2
	
	return OK;
}

ReturnValueType U16HEX2String (uint16 HEX,uint8 string[5])
{
	string[4]= 0;
	uint8 i = 0 ;
	for (i=0 ; i <= 3 ; i++ )
	{
		if ((( HEX >> (i*4) ) & 0x000F) > 9)
		{
			string[3-i] = (( HEX >> (i*4) ) & 0x000F) - 0x0A + 'A' ;
		}
		else
		{
			string[3-i] =(( HEX >> (i*4) ) & 0x000F) + '0' ;
		}
	}
	return OK;
}
ReturnValueType U16Decimal2String (uint16 Decimal,uint8 string[6])
{
	string[5]= 0 ;
	uint8 i = 0 ;
	for (i=0 ; i<=4 ; i++)
	{
		string[i] = 0 ;
		string[i] = Decimal/(PowFunction(10,4-i))+'0';
		Decimal   = Decimal%(PowFunction(10,4-i));
	}
	return OK;
}

uint16 PowFunction(uint16 x , uint16 y)
{
	uint8 i = 0; 
	uint16 result = 1 ;
	for (i=0;i<y;i++)
	{
		result = result * x ;
	}
	return result;
}