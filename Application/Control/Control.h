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

//#define CONTROL_SET_PASSWORD "STPWD"
//#define CONTROL_CHECK_PASSWORD "CHCKPWD"

typedef enum {
	CONTROL_SET_PASSWORD = 'A',
	CONTROL_CHECK_PASSWORD,
	CONTROL_OPEN_DOOR,
	CONTROL_PASSWORD_WRONG_THREE_TIMES
} ControlCommand;

typedef enum {
	CONTROL_CORRECT_PASSWORD = 'a', CONTROL_WRONG_PASSWORD
} PasswordStatus;
typedef enum {
	DOOR_OPENING='A',DOOR_OPENED,DOOR_CLOSED
} DoorStatus;

void CONTROL_init();

void CONTROL_sendCommand(const ControlCommand cmd);

void CONTROL_sendPassword(const uint8 const *password);

DoorStatus CONTROL_receiveDoorStatus();

PasswordStatus CONTROL_receivePasswordStatus();

#endif /* APPLICATION_CONTROL_CONTROL_H_ */
