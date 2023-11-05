/*
 * Timer1.c
 *
 *  Created on: Oct 31, 2023
 *      Author: adham
 */

#include "Timer1.h"

#include <avr/io.h>
#include <avr/interrupt.h>
#define LED_PIN PD0 // define the pin for the LED

static void (*callBackPointer)(void);
static volatile uint8_t led_state = 0; // variable to store the LED state

void Timer1_init(const Timer1_ConfigType const *Config_Ptr) {
	TCNT1 = Config_Ptr->initial_value;
	switch (Config_Ptr->mode) {
	case TIMER1_NORMAL:
	case TIMER1_CTC:
	case TIMER1_CTC_ICR1:
		TCCR1A = (1 << FOC1A) | (1 << FOC1B);
		break;
	default:
		TCCR1A = ~((1 << FOC1A) | (1 << FOC1B));

		break;
	}
	TCCR1A = (TCCR1A & 0xFC) | (Config_Ptr->mode & (~0xFC)); // set Timer1 mode

	OCR1A = Config_Ptr->compare_value; // set Timer1 compare value A to 15624 for 1 second delay
	switch (Config_Ptr->mode) {
	case TIMER1_NORMAL:
		TIMSK |= (1 << TOIE1); // enable Timer1 compare match A interrupt
		break;
	case TIMER1_CTC:
		TIMSK |= (1 << OCIE1A); // enable Timer1 compare match A interrupt
		break;
	case TIMER1_CTC_ICR1:
		TIMSK |= (1 << TICIE1);
		break;
	default:
		TIMSK = 0xC3;

	}
	TCCR1B = ((((Config_Ptr->mode) & (~0xf3)) >> 2) << WGM12)
			| Config_Ptr->prescaler; // set Timer1 mode to CTC and prescaler to 1024
}
void Timer1_setCallBack(void (*a_ptr)(void)) {
	callBackPointer = a_ptr;
}
void Timer1_deInit(void) {
	TCCR1A = 0; // set Timer1 mode to normal
	TCCR1B = 0; // set Timer1 mode to CTC and prescaler to 1024
	OCR1A = 0; // set Timer1 compare value A to 15624 for 1 second delay
	TIMSK |= 0xC3; // enable Timer1 compare match A interrupt
}

ISR(TIMER1_COMPA_vect) // interrupt service routine for Timer1 compare match A
{
	callBackPointer();
}

ISR(TIMER1_OVF_vect) // interrupt service routine for Timer1 Over Flow
{
	callBackPointer();
}
ISR(TIMER1_CAPT_vect) // interrupt service routine for Timer1 Over Flow
{
	callBackPointer();
}
