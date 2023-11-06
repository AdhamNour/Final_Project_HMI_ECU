/*
 * Control.h
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#ifndef APPLICATION_CONTROL_CONTROL_H_
#define APPLICATION_CONTROL_CONTROL_H_

#include "../../MCAL/UART/UART.h"

#define CONTROL_BIT_DATA 			UART_8_BIT_DATA
#define CONTROL_BIT_PARITY 			UART_PARITY_DISABLED
#define CONTROL_BIT_STOP_BIT		UART_STOP_BIT_ONE
#define CONTROL_BAUD_RATE 			9600


void CONTROL_init();

void CONTROL_sendPassword(const uint8 const* password);

#endif /* APPLICATION_CONTROL_CONTROL_H_ */
