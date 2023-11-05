/*
 * TWI.c
 *
 *  Created on: Oct 28, 2023
 *      Author: adham
 */


#include "twi.h"
#include "../../common_macros.h"
#include <avr/io.h>


uint8 TWI_init(const TWI_ConfigType * const config)
{
	sint8 TWPS_value=0,p1,p2,x;
	float64 CPU_Ration;
	for(TWPS_value=0;TWPS_value<5;TWPS_value++){
		p1=(2<<TWPS_value)+1;
		p2=4-p1;
		CPU_Ration = (float64)F_CPU/((float64)(config->bit_rate)/1000.0);
		CPU_Ration = CPU_Ration/(2<<p1);
		x=CPU_Ration-(2<<p2) ;
		if(x>1){
			TWBR=x;
			TWSR=TWPS_value;
		    /* Two Wire Bus address my address if any master device want to call me: 0x1 (used in case this MC is a slave device)*/
		    TWAR = config->address;
		    TWCR = (1<<TWEN); /* enable TWI */

			return SUCCESS;
		}
	}

	return ERROR;

}

void TWI_start(void)
{
    /*
	 * Clear the TWINT flag before sending the start bit TWINT=1
	 * send the start bit by TWSTA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWSTA) | (1 << TWEN);

    /* Wait for TWINT flag set in TWCR Register (start bit is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

void TWI_stop(void)
{
    /*
	 * Clear the TWINT flag before sending the stop bit TWINT=1
	 * send the stop bit by TWSTO=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWSTO) | (1 << TWEN);
}

void TWI_writeByte(uint8 data)
{
    /* Put data On TWI data Register */
    TWDR = data;
    /*
	 * Clear the TWINT flag before sending the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register(data is send successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
}

uint8 TWI_readByteWithACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable sending ACK after reading or receiving data TWEA=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN) | (1 << TWEA);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

uint8 TWI_readByteWithNACK(void)
{
	/*
	 * Clear the TWINT flag before reading the data TWINT=1
	 * Enable TWI Module TWEN=1
	 */
    TWCR = (1 << TWINT) | (1 << TWEN);
    /* Wait for TWINT flag set in TWCR Register (data received successfully) */
    while(BIT_IS_CLEAR(TWCR,TWINT));
    /* Read Data */
    return TWDR;
}

uint8 TWI_getStatus(void)
{
    uint8 status;
    /* masking to eliminate first 3 bits and get the last 5 bits (status bits) */
    status = TWSR & 0xF8;
    return status;
}
