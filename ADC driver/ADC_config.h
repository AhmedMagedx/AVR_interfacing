/*
 * ADC_config.h
 *
 *  Created on: Sep 8, 2019
 *      Author: Maged
 */

#ifndef ADC_CONFIG_H_
#define ADC_CONFIG_H_

	/* enable or disable the ADC */
	#define ADC_STATUE  ADC_ENABLE

	/*Select the channel number*/
	#define ChannelNo   Channel0

	/* Voltage Reference Selection */
	#define VOLT_REF REF_INTERNAL_MAIN

    /* Left/right Adjust Result */
	#define ADJUST RIGHT

	/* ADC modes */
	#define ADC_MODE SINGLE_SHOT

	/* only start convertion in enabled*/
    /* ADC start mode */
    /*  #define ADC_START START_CONV_BIT  */



#endif /* ADC_CONFIG_H_ */
