/*
 * DC_Motor.h
 *
 *  Created on: Oct 20, 2023
 *      Author: adham
 */

#ifndef HAL_DC_MOTOR_DC_MOTOR_H_
#define HAL_DC_MOTOR_DC_MOTOR_H_

#include "../../MCAL/GPIO/gpio.h"

/*Pin and Port Definition*/
#define MOTOR_RIGHT_PORT_ID			PORTB_ID
#define MOTOR_RIGHT_PIN_ID 			PIN0_ID

#define MOTOR_LEFT_PORT_ID			PORTB_ID
#define MOTOR_LEFT_PIN_ID			PIN1_ID

#define MOTOR_SPEED_COTROL_PORT_ID	PORTB_ID
#define MOTOR_SPEED_COTROL_PIN_ID	PIN3_ID

#if (MOTOR_SPEED_COTROL_PORT_ID==PORTB_ID && MOTOR_SPEED_COTROL_PIN_ID==PIN3_ID)
#include "../../MCAL/PWM_Timer0/PWM_Timer0.h"
#elif(MOTOR_SPEED_COTROL_PORT_ID==PORTD_ID &&  MOTOR_SPEED_COTROL_PIN_ID==PIN4_ID)
/*Include the timer 1 OC*/
#error "The timer 1 driver is not implemented yet"
#elif(MOTOR_SPEED_COTROL_PORT_ID==PORTD_ID &&  MOTOR_SPEED_COTROL_PIN_ID==PIN5_ID)
#error "The timer 1 driver is not implemented yet"
#elif(MOTOR_SPEED_COTROL_PORT_ID==PORTD_ID &&  MOTOR_SPEED_COTROL_PIN_ID==PIN7_ID)
#error "The timer 2 driver is not implemented yet"
#else
#error "PWM is not supported in this port and this pin"
#endif


/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/
/*
 * Description: DC_Motor_State => descripes the status of the DC Motor
 * */
typedef enum {
	CW,ACW,OFF
} DCMotor_State;


/********************************************************************************
 *                               Function Declaration							*
 ********************************************************************************/
/*
 * Description:
 * 			=> 	The Function responsible for
 * 				setup the direction for the two
 * 				motor pins through the GPIO driver.
 * 			=> 	Stop at the DC-Motor at the beginning
 * 				through the GPIO driver.
 * */
void DcMotor_Init(void);
/*
 * Description:
 * 			=> 	The function responsible for rotate the
 * 				DC Motor CW/ or A-CW or stop the motor based
 * 				on the state input state value.
 * 			=> 	Send the required duty cycle to the PWM driver
 * 				based on the required speed value.
 * */
void DcMotor_Rotate(DCMotor_State state,uint8 speed);

#endif /* HAL_DC_MOTOR_DC_MOTOR_H_ */
