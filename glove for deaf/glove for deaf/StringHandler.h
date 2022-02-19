/*
 * StringHandler.h
 *
 * Created: 10/21/2021 11:29:30 AM
 *  Author: Mohamed Magdi
 */ 


#ifndef STRINGHANDLER_H_
#define STRINGHANDLER_H_
#include "STD_Types.h"

ReturnValueType U8HEX2String (uint8 HEX,uint8 string[3]);
ReturnValueType U8Decimal2String (uint8 Decimal,uint8 string[4]);

ReturnValueType U16HEX2String (uint16 HEX,uint8 string[5]); //string kan 8 w 5aleto 16
ReturnValueType U16Decimal2String (uint16 Decimal,uint8 string[4]);

uint16 PowFunction(uint16 x , uint16 y);
#endif /* STRINGHANDLER_H_ */