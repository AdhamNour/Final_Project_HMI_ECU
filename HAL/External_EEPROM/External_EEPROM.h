/*
 * External_EEPROM.h
 *
 *  Created on: Oct 29, 2023
 *      Author: adham
 */

#ifndef HAL_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_
#define HAL_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_


#include "../../std_types.h"

/*******************************************************************************
 *                      Preprocessor Macros                                    *
 *******************************************************************************/
#define ERROR 0
#define SUCCESS 1

/*******************************************************************************
 *                      Functions Prototypes                                   *
 *******************************************************************************/

uint8 EEPROM_writeByte(uint16 u16addr,uint8 u8data);
uint8 EEPROM_readByte(uint16 u16addr,uint8 *u8data);

#endif /* HAL_EXTERNAL_EEPROM_EXTERNAL_EEPROM_H_ */
