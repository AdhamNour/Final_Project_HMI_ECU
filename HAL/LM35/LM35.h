/*
 * LM35.h
 *
 *  Created on: Oct 20, 2023
 *      Author: adham
 */

#ifndef HAL_LM35_LM35_H_
#define HAL_LM35_LM35_H_

#include "../../MCAL/ADC/ADC.h"


#define LM35_CHANNEL ADC_CHANNEL_3
#define MAX_TEMPERATURE 150
#define MAX_VOLTAGE 1.5

void LM35_init();

uint16 LM35_readTemp();

#endif /* HAL_LM35_LM35_H_ */
