/*
 * DC_Motor.c
 *
 *  Created on: Oct 20, 2023
 *      Author: adham
 */

#include "DC_Motor.h"
#include "../../MCAL/PWM_Timer0/PWM_Timer0.h"

/********************************************************************************
 *                               Function Definition							*
 ********************************************************************************/
/*
 * Description:
 * 			=> 	The Function responsible for
 * 				setup the direction for the two
 * 				motor pins through the GPIO driver.
 * 			=> 	Stop at the DC-Motor at the beginning
 * 				through the GPIO driver.
 * */
void DcMotor_Init(void) {
	GPIO_setupPinDirection(MOTOR_RIGHT_PORT_ID, MOTOR_RIGHT_PIN_ID, PIN_OUTPUT);
	GPIO_setupPinDirection(MOTOR_LEFT_PORT_ID, MOTOR_LEFT_PIN_ID, PIN_OUTPUT);
}
/*
 * Description:
 * 			=> 	The function responsible for rotate the
 * 				DC Motor CW/ or A-CW or stop the motor based
 * 				on the state input state value.
 * 			=> 	Send the required duty cycle to the PWM driver
 * 				based on the required speed value.
 * */
void DcMotor_Rotate(DCMotor_State state, uint8 speed) {
	if (OFF == state)
		PWM_Timer0_Start(0);
	else {
		switch (state) {
		case CW:
			GPIO_writePin(MOTOR_RIGHT_PORT_ID, MOTOR_RIGHT_PIN_ID, LOGIC_HIGH);
			GPIO_writePin(MOTOR_LEFT_PORT_ID, MOTOR_LEFT_PIN_ID, LOGIC_LOW);
			break;
		case ACW:
			GPIO_writePin(MOTOR_RIGHT_PORT_ID, MOTOR_RIGHT_PIN_ID, LOGIC_LOW);
			GPIO_writePin(MOTOR_LEFT_PORT_ID, MOTOR_LEFT_PIN_ID, LOGIC_HIGH);
			break;
		default:
			break;
		}
		PWM_Timer0_Start(speed);
	}
}
