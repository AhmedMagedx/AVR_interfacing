/*
 * main.c
 *
 *  Created on: Sep 8, 2019
 *      Author: Maged
 */

#include"STD_TYPES.h"
#include"BIT_MATHS.h"
#include"delay.h"
#include"DIO_INTERFACE.h"
#include"ADC_interface.h"


#define RED_LED     DIO_U8_PIN2
#define YELLOW_LED  DIO_U8_PIN3
#define GREEN_LED   DIO_U8_PIN4


void LED_vidToggle(void);

void main()
{


	DIO_vidSetPinDirection(DIO_U8_PORTA, DIO_U8_PIN0,  DIO_U8_DIR_IN);

	DIO_vidSetPinDirection(DIO_U8_PORTA, RED_LED,      DIO_U8_DIR_OUT);
	DIO_vidSetPinDirection(DIO_U8_PORTA, YELLOW_LED,   DIO_U8_DIR_OUT);
	DIO_vidSetPinDirection(DIO_U8_PORTA, GREEN_LED,    DIO_U8_DIR_OUT);
	DIO_vidSetPinDirection(DIO_U8_PORTA, DIO_U8_PIN6,  DIO_U8_DIR_OUT);

	ADC_vidInitialize();

	u16 value;


	while(1)
	{

		value = ADC_u16Read_blocked();
		//value = value*(5000) / 1024 ;   // BIG ERROR
		value = ((value*(5000UL)) / 1024) ;

		/* make initial statue OFF for LEDs*/
		DIO_vidSetPinValue(DIO_U8_PORTA, RED_LED,    DIO_U8_LOW);
		DIO_vidSetPinValue(DIO_U8_PORTA, YELLOW_LED, DIO_U8_LOW);
		DIO_vidSetPinValue(DIO_U8_PORTA, GREEN_LED,  DIO_U8_LOW);


		if((value < 1500) & (value > 0))
		{
			DIO_vidSetPinValue(DIO_U8_PORTA, RED_LED, DIO_U8_HIGH);
		}
		else if((value < 3000) & (value > 1500))
		{
			DIO_vidSetPinValue(DIO_U8_PORTA, YELLOW_LED, DIO_U8_HIGH);
		}
		else if((value < 5000) & (value > 3000))
		{
			DIO_vidSetPinValue(DIO_U8_PORTA, GREEN_LED, DIO_U8_HIGH);
		}
		else
		{
			DIO_vidSetPinValue(DIO_U8_PORTA, RED_LED,    DIO_U8_HIGH);
			DIO_vidSetPinValue(DIO_U8_PORTA, YELLOW_LED, DIO_U8_HIGH);
			DIO_vidSetPinValue(DIO_U8_PORTA, GREEN_LED,  DIO_U8_HIGH);
		}

		 LED_vidToggle();
		_delay_ms(100);



	}

}

void LED_vidToggle(void)
{
	DIO_vidSetPinValue(DIO_U8_PORTA, DIO_U8_PIN6,  DIO_U8_LOW);
	_delay_ms(200);
	DIO_vidSetPinValue(DIO_U8_PORTA, DIO_U8_PIN6,  DIO_U8_HIGH);
	_delay_ms(200);
}
