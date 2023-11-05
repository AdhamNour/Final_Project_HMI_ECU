/*
 * LM35.c
 *
 *  Created on: Oct 20, 2023
 *      Author: adham
 */

#include "LM35.h"

#define ADC_MAX_VOLTAGE 2.56
static ADC_ConfigType ADC_configType;
static 	float64 factor = ((float64)MAX_TEMPERATURE*ADC_MAX_VOLTAGE)/((float64)MAX_VOLTAGE*ADC_MAX_READING);


void LM35_init() {

	ADC_configType.prescaler = ADC_DIVISION_FACTOR_8;
	ADC_configType.ref_volts = ADC_2_56V;

	ADC_init(&ADC_configType);
}

uint16 LM35_readTemp() {
	uint16 channelReading= ADC_readChannel(LM35_CHANNEL);
	return (uint16)((uint32)(factor * channelReading));
}
