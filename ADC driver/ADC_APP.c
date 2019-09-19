/*
 * ADC_APP.c
 *
 *  Created on: Sep 8, 2019
 *      Author: Maged
 */

#include"ADC_config.h"
#include"BIT_MATHS.h"
#include"Register.h"
#include"ADC_interface.h"
#include"DIO_INTERFACE.h"

void ADC_vidInitialize(void)
{
	ADCSRA = 0;
	ADMUX  = 0;


	#if ADC_STATUE == ADC_ENABLE
		/*Enable the ADC*/
		SET_BIT(ADCSRA,ADEN);

		/* Voltage Reference Selection */
		#if VOLT_REF == REF_INTERNAL_MAIN
		  SET_BIT(ADMUX, REFS0);
		  CLR_BIT(ADMUX, REFS1);
		#elif VOLT_REF == REF_INTERNAL_2_5V
		  SET_BIT(ADMUX, REFS0);
		  SET_BIT(ADMUX, REFS1);
		#else
		  CLR_BIT(ADMUX, REFS0);
		  CLR_BIT(ADMUX, REFS1);
		#endif

	    /* right Adjust Result, RIGHT by defualt*/
		#if ADJUST == LEFT
		  SET_BIT(ADMUX, ADLAR);
		#else
		  CLR_BIT(ADMUX, ADLAR);
		#endif

		 /* Single ended Channels*/
		  ADMUX |= ChannelNo;

	/*	#if ADC_MODE == SINGLE_SHOT  */
	/*		#if ADC_START == START_CONV_BIT  */

		  /* Disable AUTO trigger*/
		  CLR_BIT(ADCSRA, ADATE);

		 /*Disable interrupt   ADIE*/
		  CLR_BIT(ADCSRA, ADIE);

		/*  ADC Prescaler Selections */
		  /* divid by 128*/
		  SET_BIT(ADCSRA, ADPS2);
		  SET_BIT(ADCSRA, ADPS1);
		  SET_BIT(ADCSRA, ADPS0);

		/*	#endif */
		#endif

}


void ADC_vidStart(void)
{
	SET_BIT(ADCSRA,ADSC);
}


u16 ADC_u16Read_blocked(void)
{
	ADC_vidStart();
	while(ADCSRA & (1<<ADSC));
	u16 temp =  ((u16)(ADCL)) | ((u16)ADCH) << 8;
	return temp;
}



