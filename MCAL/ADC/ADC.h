/*
 * ADC.h
 *
 *  Created on: Oct 14, 2023
 *      Author: adham
 */

#ifndef MCAL_ADC_ADC_H_
#define MCAL_ADC_ADC_H_
#include "../../std_types.h"


#define ADC_MAX_READING 1023

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/*
 * Description: ADC_ReferenceVoltage => is used to define the voltage reference for the AVR ADC
 * */
typedef enum {
	ADC_AREF, /*External ARef is used and the internal 2.56v is turrned off*/
	ADC_AVCC,/*using ADC's VCC as reference*/
	ADC_RESERVED, /*Reserved and nothing is happened*/
	ADC_2_56V /*using the interenal 2.56 volts as reference*/
} ADC_ReferenceVoltage;

/*
 * Description: ADC_PreScaler=> is used to define the prescaler for the AVR ADC
 * */

typedef enum {
	ADC_DIVISION_FACTOR_2,
	ADC_DIVISION_FACTOR_2_I,
	ADC_DIVISION_FACTOR_4,
	ADC_DIVISION_FACTOR_8,
	ADC_DIVISION_FACTOR_16,
	ADC_DIVISION_FACTOR_32,
	ADC_DIVISION_FACTOR_128
} ADC_PreScaler;


typedef enum {
	ADC_CHANNEL_0	,
	ADC_CHANNEL_1	,
	ADC_CHANNEL_2	,
	ADC_CHANNEL_3	,
	ADC_CHANNEL_4	,
	ADC_CHANNEL_5	,
	ADC_CHANNEL_6	,
	ADC_CHANNEL_7

} ADC_Channel;

typedef struct {
	ADC_ReferenceVoltage ref_volts;
	ADC_PreScaler prescaler;
} ADC_ConfigType;


/********************************************************************************
 *                               Function Declaration							*
 ********************************************************************************/
/*
 * Description: Initing the ADC Module
 * */
void ADC_init (const ADC_ConfigType const* config_ptr);

/*
 * Description: reading the required channel from the ADC
 * */
uint16 ADC_readChannel(ADC_Channel channel);

#endif /* MCAL_ADC_ADC_H_ */
