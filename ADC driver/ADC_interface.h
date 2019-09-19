/*
 * ADC_interface.h
 *
 *  Created on: Sep 8, 2019
 *      Author: Maged
 */

#ifndef ADC_INTERFACE_H_
#define ADC_INTERFACE_H_

#include"STD_TYPES.h"

#define ADC_ENABLE    1
#define ADC_DISABLE   0

/* Single ended Channels*/
#define Channel0 0
#define Channel1 1
#define Channel2 2
#define Channel3 3
#define Channel4 4
#define Channel5 5
#define Channel6 6
#define Channel7 7

/*Differential Channels*/


/* Voltage Reference Selection */
#define REF_INTERNAL_MAIN 100   /* the provided power to MCU(normally 5V)*/
#define REF_INTERNAL_2_5V 200   /* 2.5 fixed internal*/
#define REF_EXTERNAL      300   /* external power through AREF PIN*/


 /* Left/right Adjust Result */
#define RIGHT  0
#define LEFT   1

/*ADC modes*/
#define SINGLE_SHOT    0
#define FREE_RUNNING   1

/*ADC start*/
#define START_CONV_BIT    0
#define TRIGGER_SIGNAL    1

/* trigger source */   /*only if TRIGGER_SIGNAL is selected*/




void ADC_vidStart(void);
void ADC_vidInitialize(void);
u16 ADC_u16Read_blocked(void);  /* == START conv. + WAIT + READ  */



#endif /* ADC_INTERFACE_H_ */
