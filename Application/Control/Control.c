/*
 * Control.c
 *
 *  Created on: Nov 6, 2023
 *      Author: adham
 */

#include "Control.h"

#include <string.h>

void CONTROL_init() {
	UART_ConfigType uart_config;
	uart_config.baud_rate = CONTROL_BAUD_RATE;
	uart_config.bit_data = CONTROL_BIT_DATA;
	uart_config.parity = CONTROL_BIT_PARITY;
	uart_config.stop_bit = CONTROL_BIT_STOP_BIT;
	UART_init(&uart_config);
}
void CONTROL_sendCommand(const ControlCommand cmd){
	UART_sendByte(cmd);
}


void CONTROL_sendPassword(const uint8 const *password) {
	static uint8 sentPassword[7] = { 0 };
	register uint8 i;
	for (i = 0; i < 5; ++i) {
		sentPassword[i] = password[i];
	}
	sentPassword[i] = '#';
	sentPassword[i+1] = '\0';

	UART_sendString(sentPassword);
}

PasswordStatus CONTROL_receivePasswordStatus(){
	return UART_recieveByte();
}

