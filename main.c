/*
 * main.c
 *
 *  Created on: Oct 27, 2023
 *      Author: adham
 */
#include "Application/Application.h"

int main(void){
	/*Initialization of the application*/
	Application_Setup();
	while(1){
		/*The Main loop of the application*/
		Application_Loop();
	}
}

//#include <avr/io.h>
//#include <avr/interrupt.h>
//
//#define LED_PIN PD0 // define the pin for the LED
//
//volatile uint8_t led_state = 0; // variable to store the LED state
//
//ISR(TIMER1_COMPA_vect) // interrupt service routine for Timer1 compare match A
//{
//  led_state = !led_state; // toggle the LED state
//  PORTD = (PORTD & ~(1 << LED_PIN)) | (led_state << LED_PIN); // set or clear the LED pin according to the state
//}
//
//void timer1_init(void) // function to initialize Timer1
//{
//  TCCR1A = 0; // set Timer1 mode to normal
//  TCCR1B = (1 << WGM12) | (1 << CS12) | (1 << CS10); // set Timer1 mode to CTC and prescaler to 1024
//  OCR1A = 15624; // set Timer1 compare value A to 15624 for 1 second delay
//  TIMSK = (1 << OCIE1A); // enable Timer1 compare match A interrupt
//}
//
//int main(void)
//{
//  DDRD = (1 << LED_PIN); // set the LED pin as output
//  timer1_init(); // initialize Timer1
//  sei(); // enable global interrupts
//  while (1)
//  {
//    // do nothing, let the interrupt handle the blinking
//  }
//}
