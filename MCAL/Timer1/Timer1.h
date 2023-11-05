/*
 * Timer1.h
 *
 *  Created on: Oct 31, 2023
 *      Author: adham
 */

#ifndef MCAL_TIMER1_TIMER1_H_
#define MCAL_TIMER1_TIMER1_H_
#include "../../std_types.h"

/*******************************************************************************
 *                               Types Declaration                             *
 *******************************************************************************/

typedef enum {
	TIMER1_NO_CLOCK	,
	TIMER1_CLK_1	,
	TIMER1_CLK_8	,
	TIMER1_CLK_64	,
	TIMER1_CLK_256	,
	TIMER1_CLK_1024	,
	TIMER1_T1_FALLING_EDGE	,
	TIMER1_T1_RISING_EDGE
} Timer1_Prescaler;
typedef enum {
	TIMER1_NORMAL,
	TIMER1_PWM_PHASE_CORRECT_8_BIT,
	TIMER1_PWM_PHASE_CORRECT_9_BIT,
	TIMER1_PWM_PHASE_CORRECT_10_BIT,
	TIMER1_CTC,
	TIMER1_FASTPWM_8_BIT,
	TIMER1_FASTPWM_9_BIT,
	TIMER1_FASTPWM_10_BIT,
	TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_ICR1,
	TIMER1_PWM_PHASE_AND_FREQUENCY_CORRECT_OCR1A,
	TIMER1_PWM_PHASE_CORRECT_ICR1,
	TIMER1_PWM_PHASE_CORRECT_OCR1A,
	TIMER1_CTC_ICR1,
	TIMER1_FASTPWM_ICR1,
	TIMER1_FASTPWM_OCR1A,

} Timer1_Mode;

typedef struct {
uint16 initial_value;
uint16 compare_value; // it will be used in compare mode only.
Timer1_Prescaler prescaler;
Timer1_Mode mode;
} Timer1_ConfigType;

/*******************************************************************************
 *                               Function Prototypes                           *
 *******************************************************************************/
void Timer1_init(const Timer1_ConfigType const* Config_Ptr);
void Timer1_setCallBack(void(*a_ptr)(void));
void Timer1_deInit(void);
#endif /* MCAL_TIMER1_TIMER1_H_ */
