/*
 * Register.h
 *
 *  Created on: Aug 21, 2019
 *      Author: ahmed
 */

#ifndef REGISTER_H_
#define REGISTER_H_

/**********************************************************************************************************
 *										Include Header Files   											  *
 **********************************************************************************************************/
#include "STD_TYPES.h"

/*********************************************************************************************************
 *									PORTA Registers					    								 *
 **********************************************************************************************************/
#define PORTA  (*((volatile u8 *)(0x3B)))
#define DDRA   (*((volatile u8 *)(0x3A)))
#define PINA   (*((volatile u8 *)(0x39)))

/*********************************************************************************************************
 *									PORTB Registers					    								 *
 **********************************************************************************************************/
#define PORTB  (*((volatile u8 *)(0x38)))
#define DDRB   (*((volatile u8 *)(0x37)))
#define PINB   (*((volatile u8 *)(0x36)))

/*********************************************************************************************************
 *									PORTC Registers					    								 *
 **********************************************************************************************************/
#define PORTC  (*((volatile u8 *)(0x35)))
#define DDRC   (*((volatile u8 *)(0x34)))
#define PINC   (*((volatile u8 *)(0x33)))
/*********************************************************************************************************
 *									PORTD Registers					    								 *
 **********************************************************************************************************/
#define PORTD  (*((volatile u8 *)(0x32)))
#define DDRD   (*((volatile u8 *)(0x31)))
#define PIND   (*((volatile u8 *)(0x30)))
/*********************************************************************************************************
 *									EXTI Registers					    								 *
 **********************************************************************************************************/
#define SREG  		        (*((volatile u8 *)(0x5F)))
#define MCUCR               (*((volatile u8 *)(0x55)))
#define MCUCSR              (*((volatile u8 *)(0x54)))
#define GICR                (*((volatile u8 *)(0x5B)))
#define GIFR                (*((volatile u8 *)(0x5A)))

#define INT0_ENABLE_BIT  		6
#define INT1_ENABLE_BIT  		7
#define INT2_ENABLE_BIT  		5

#define INT0_FLAG_BIT  		6
#define INT1_FLAG_BIT  		7
#define INT2_FLAG_BIT  		5

#define GLOBAL_INT_I_BIT        7

#define EXTI0_U8_BIT_ISC00      0
#define EXTI0_U8_BIT_ISC01      1
#define EXTI1_U8_BIT_ISC10      2
#define EXTI1_U8_BIT_ISC11      3
#define EXTI2_U8_BIT_ISC2       6


/*********************************************************************************************************
 *									ADC Registers					    								 *
 **********************************************************************************************************/
#define ADMUX   (*((volatile u8 *)(0x27)))
#define ADCSRA  (*((volatile u8 *)(0x26)))
#define ADCH    (*((volatile u8 *)(0x25)))
#define ADCL    (*((volatile u8 *)(0x24)))
#define SFIOR   (*((volatile u8 *)(0x50)))

/*ADMUX register bits*/
#define REFS1   7
#define REFS0   6
#define ADLAR   5

/*ADCSRA register bits*/
#define ADEN    7	/* ADC Enable */
#define ADSC    6	/*ADC Start Conversion*/
#define ADATE   5   /*ADC Auto Trigger Enable*/
#define ADIF    4   /*ADC Interrupt Flag*/
#define ADIE    3   /*ADC Interrupt Enable */
#define ADPS2    2   /*ADC Interrupt Enable */
#define ADPS1    1   /*ADC Interrupt Enable */
#define ADPS0    0   /*ADC Interrupt Enable */



#endif /* REGISTER_H_ */
