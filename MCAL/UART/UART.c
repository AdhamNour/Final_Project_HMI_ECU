/*
 * UART.c
 *
 *  Created on: Oct 27, 2023
 *      Author: adham
 */

#include "UART.h"

#include <avr/io.h>
#include "../../common_macros.h"

#define PARITY_SETTING_BITS_SELECTION 0xCF
#define PARITY_SETTING_BITS_SELECTION_START_BIT UPM0

#define STOP_BITS_SETTING_BITS_SELECTION 0xF7
#define STOP_BITS_SETTING_BITS_SELECTION_START_BIT USBS

#define BIT_DATA_SETTING_BITS_SELECTION 0xFC
#define BIT_DATA_SETTING_BITS_SELECTION_START_BIT UCSZ0

void UART_init(const UART_ConfigType const *config) {
	uint16 ubrr_value = 0;

	/* U2X = 1 for double transmission speed */
	UCSRA = (1 << U2X);

	/************************** UCSRB Description **************************
	 * RXCIE = 0 Disable USART RX Complete Interrupt Enable
	 * TXCIE = 0 Disable USART Tx Complete Interrupt Enable
	 * UDRIE = 0 Disable USART Data Register Empty Interrupt Enable
	 * RXEN  = 1 Receiver Enable
	 * RXEN  = 1 Transmitter Enable
	 * UCSZ2 = 0 For 8-bit data mode
	 * RXB8 & TXB8 not used for 8-bit data mode
	 ***********************************************************************/
	UCSRB = (1 << RXEN) | (1 << TXEN);

	/************************** UCSRC Description **************************
	 * URSEL   = 1 The URSEL must be one when writing the UCSRC
	 * UMSEL   = 0 Asynchronous Operation
	 * UPM1:0  = 00 Disable parity bit
	 * USBS    = 0 One stop bit
	 * UCSZ1:0 = 11 For 8-bit data mode
	 * UCPOL   = 0 Used with the Synchronous operation only
	 ***********************************************************************/
	DDRA = 0xFF;
	PORTA = (1 << URSEL) | ((config->bit_data) << UCSZ0)
			| ((config->parity) << UPM0) | ((config->stop_bit) << USBS);
	UCSRC = (1 << URSEL) | ((config->bit_data) << UCSZ0)
			| ((config->parity) << UPM0) | ((config->stop_bit) << USBS);

	/* Calculate the UBRR register value */
	ubrr_value = (uint16) (((F_CPU / ((config->baud_rate) * 8UL))) - 1);

	/* First 8 bits from the BAUD_PRESCALE inside UBRRL and last 4 bits in UBRRH*/
	UBRRH = ubrr_value >> 8;
	UBRRL = ubrr_value;

}

void UART_sendByte(uint8 data) {
	/*
	 * UDRE flag is set when the Tx buffer (UDR) is empty and ready for
	 * transmitting a new byte so wait until this flag is set to one
	 */
	while (BIT_IS_CLEAR(UCSRA, UDRE))
		;

	/*
	 * Put the required data in the UDR register and it also clear the UDRE flag as
	 * the UDR register is not empty now
	 */
	UDR = data;
}
