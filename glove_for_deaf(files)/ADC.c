
#include "ADC.h"
void ADC_Init(void) 
{
	ADCSRA |= (1<<ADEN) ; //enable  ADC
 	SetBit(ADMUX,REFS0) ; //set Vref to Vcc
 	ClearBit(ADMUX,REFS1); //set Vref to Vcc

	ClearBit(ADCSRA,ADPS1);
    SetBit(ADCSRA,ADPS0);
	SetBit(ADCSRA,ADPS2);

	//ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);  //conversion set to 128
}

void ADC_ChannelInit(uint8 ADC_Channel)
{
	
			Dio_PinSetDirection(A,ADC_Channel,PinInput);   //set input channel 
			ADMUX= (ADMUX & ~0x1F) | (ADC_Channel & 0x1F) ;    //bits for setting the required channel  (clear ADMUX then setting required channel)
	
}
void ADC_ReadChannel(uint8 ADC_Channel , uint16* Adc_Data)
{
	ADCSRA |= (1<<ADSC) ;  //activate conversion bit
	while (GetBit(ADCSRA,ADIF) == 0);  //wait for conversion
	*Adc_Data = ADCL ;
	*Adc_Data |= (uint16) (ADCH<<8) ;   //read value from register;
}









// 	DDRA &=~ (1<<PA1) ; // 1
// 	ADCSRA |= (1<<ADEN) ; // 2
// 	ADCSRA |= (1<<ADPS0) | (1<<ADPS1) | (1<<ADPS2);
// 	SetBit(ADMUX,REFS0) ;
// 	ClearBit(ADMUX,REFS1);
// 	SetBit(ADMUX,MUX0);
// 	ADMUX &= ~ (1<<MUX1) & ~ (1<<MUX2) & ~ (1<<MUX3) & ~ (1<<MUX4);