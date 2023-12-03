/*
 * main.c
 *
 *  Created on: Oct 7, 2022
 *      Author: MSAEED99
 */


// AVR libraries
#include "../inc/delay.h"

// Libraries
#include "../inc/BIT_MATH.h"

// MCAL
#include "../lib/DIO_interface.h"

// HAL


// Global variables

int main(void)
{ u32 i =0;
DIO_voidSetPortDirection(DIO_u8PORTA, DIO_u8PIN_OUTPUT);
DIO_voidSetPortValue(DIO_u8PORTA,DIO_u8PORT_LOW );
while(i<8)
	{ 
DIO_voidSetPinDirection(DIO_u8PORTA, i,DIO_u8PIN_HIGH );
Delay_ms(500);
i=i+1;
}
return 0;	}




