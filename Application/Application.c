#include "Application.h"
#include "avr/io.h"

#include <util/delay.h>

#include "Control/Control.h"

#include "../HAL/LCD/LCD.h"
#include "../HAL/Keypad/Keypad.h"

#include "../MCAL/GPIO/gpio.h"

static uint8 x;

static uint8 password[6] = { 0 }, entered_password[6] = { 0xFF };

void Application_Setup() {
	static uint8 i;
	LCD_init();
	KEYPAD_init();
	CONTROL_init();
	LCD_displayString("AN Smart Door");
	_delay_ms(500);



	while (1) {
		LCD_clearScreen();
		LCD_displayString("plz enter the password");
		for (i = 0; i < 5; ++i) {
			do {
				x = KEYPAD_getPressedKey();
			} while (x == 255);
			LCD_displayStringRowColumn(1, i, "*");
			_delay_ms(150);
			password[i] = x;
		}
		LCD_clearScreen();
		LCD_displayString("plz re-enter the password");
		for (i = 0; i < 5; ++i) {
			do {
				x = KEYPAD_getPressedKey();
			} while (x == 255);
			LCD_displayStringRowColumn(1, i, "*");
			_delay_ms(150);
			entered_password[i] = x;
		}
		uint8 eqlFlg = 1;
		for (i = 0; i < 5; ++i) {
			if (password[i] != entered_password[i]) {
				eqlFlg = 0;
				break;
			}
		}
		if (eqlFlg) {
			break;
		}
		LCD_clearScreen();
		LCD_displayString("Password verifiction error");
	}
	LCD_clearScreen();
	CONTROL_sendPassword(entered_password);

}

void Application_Loop() {
	x = KEYPAD_getPressedKey();
	if (x != 255)
		LCD_displayCharacter(x);
	_delay_ms(150);
}
