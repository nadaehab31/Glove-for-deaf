


#ifndef ADC_H_
#define ADC_H_
#include <avr/io.h>
#include "STD_Types.h"
#include "Bitwise.h"
#include "Dio.h"
#define ADC0 0
#define ADC1 1
#define ADC2 2
#define ADC3 3
#define ADC4 4
#define ADC5 5
#define ADC6 6
#define ADC7 7    //ADC channels

void ADC_Init(void) ;
void ADC_ChannelInit(uint8 ADC_Channel);
void ADC_ReadChannel(uint8 ADC_Channel , uint16* Adc_Data) ;

#endif /* ADC_H_ */