/*
 * UART.h
 *
 *  Created on: Oct 27, 2023
 *      Author: adham
 */

#ifndef MCAL_UART_UART_H_
#define MCAL_UART_UART_H_

#include "../../std_types.h"

typedef uint32 UART_BaudRate;

typedef enum {
	UART_PARITY_DISABLED,

	UART_PARITY_EVEN=2,
	UART_PARITY_ODD
}UART_Parity;

typedef enum {
	UART_STOP_BIT_ONE,
	UART_STOP_BIT_TWO
}UART_StopBit;

typedef enum {
	UART_5_BIT_DATA,
	UART_6_BIT_DATA,
	UART_7_BIT_DATA,
	UART_8_BIT_DATA
}UART_BitData;

typedef struct{
UART_BitData bit_data;
UART_Parity parity;
UART_StopBit stop_bit;
UART_BaudRate baud_rate;
}UART_ConfigType;

void UART_init(const UART_ConfigType const * config);

void UART_sendByte(uint8 data);

void UART_sendString(const uint8 *Str);

uint8 UART_recieveByte(void);

void UART_receiveString(uint8 *Str);

#endif /* MCAL_UART_UART_H_ */
