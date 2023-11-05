/*
 * ADC.c
 *
 *  Created on: Oct 14, 2023
 *      Author: adham
 */


#include "ADC.h"
#include "avr/io.h"
#include "../../common_macros.h"
/*
 * Description: Initing the ADC Module
 * */
void ADC_init (const ADC_ConfigType const* config_ptr){


	ADMUX = (config_ptr->ref_volts)<<6;
	CLEAR_BIT(ADMUX,ADLAR);
	ADMUX &= 0xE0; /*selecting the channel zero as default*/

	SET_BIT(ADCSRA,ADEN);
	CLEAR_BIT(ADCSRA,ADIE);

	ADCSRA=(ADCSRA&0xF8)|((config_ptr->prescaler)|(0x07));

}
/*
 * Description: reading the required channel from the ADC
 * */
uint16 ADC_readChannel(ADC_Channel channel){
	ADMUX=(ADMUX&0xF8)|((channel)&(0x07));

	SET_BIT(ADCSRA,ADSC);

	while(!(GET_BIT(ADCSRA,ADIF)));

	SET_BIT(ADCSRA,ADIF);

	return ADC;

}
