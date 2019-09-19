/********************************************/
/* Author   : MOHAMED ALTAHAN               */
/* Date     : 29 AUG 2019                   */
/* Version  : V1                            */
/********************************************/


#ifndef DIO_INTERFACE_H_
#define  DIO_INTERFACE_H_



#define DIO_U8_HIGH     1
#define DIO_U8_LOW      0
#define DIO_U8_ERROR    0xff


//---------pin number---------------
#define DIO_U8_PIN0				0
#define DIO_U8_PIN1				1
#define DIO_U8_PIN2				2
#define DIO_U8_PIN3				3
#define DIO_U8_PIN4				4
#define DIO_U8_PIN5				5
#define DIO_U8_PIN6				6
#define DIO_U8_PIN7				7

//---------port number--------------

#define DIO_U8_PORTA    		0
#define DIO_U8_PORTB			1
#define DIO_U8_PORTC			2
#define DIO_U8_PORTD			3

//--------Direction------------------
#define DIO_U8_DIR_IN			0
#define DIO_U8_DIR_OUT			1



//--------- prototypes for pins-------------------------
void DIO_vidSetPinDirection(u8 Cpy_u8PortId , u8 Cpy_u8PinNo , u8 Cpy_u8PinDir);

void DIO_vidSetPinValue(u8 Cpy_u8PortId , u8 Cpy_u8PinNo , u8 Cpy_u8PinValue);

u8 DIO_u8GetPinValue(u8 Cpy_u8PortId , u8 Cpy_u8PinNo);


//-------prototypes for port--------------------------
void DIO_vidSetPortDirection(u8 Cpy_u8PortId , u8 Cpy_u8ProtDir);

void DIO_vidSetPortValue(u8 Cpy_u8PortId , u8 Cpy_u8PortValue);

u8 DIO_u8GetPortValue(u8 Cpy_u8PortId);



#endif
