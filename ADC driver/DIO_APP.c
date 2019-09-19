
/********************************************/
/* this driver has 6 functions              */
/* 1- set the pins as input or output       */
/* 2- set the pins as HIGH OR LOW           */
/* 3- get the pin value and return its value*/
/* 4- SetPortDirection                      */
/* 5- SET port value                        */ 
/* 6- Get port value and return its value   */
/********************************************/

#include "STD_TYPES.h"
#include "BIT_MATHS.h"
#include "Register.h"

#include "DIO_INTERFACE.h"
/*************************************************************/
/***************set the pins as input or output***************/
/*************************************************************/

void DIO_vidSetPinDirection(u8 Cpy_u8PortId , u8 Cpy_u8PinNo , u8 Cpy_u8PinDir)
{
  //to ensure that the user's input is valid
  if( (Cpy_u8PortId <= DIO_U8_PORTD && Cpy_u8PortId >= DIO_U8_PORTA) &&
	  (Cpy_u8PinNo  <= DIO_U8_PIN7  && Cpy_u8PortId >= DIO_U8_PIN0))
	  {
		  
//check if the pin is input

	 if(Cpy_u8PinDir == DIO_U8_DIR_IN)
		  {
        switch(Cpy_u8PortId)
		{
			
		    case DIO_U8_PORTA:
			  CLR_BIT(DDRA , Cpy_u8PinNo);
			  SET_BIT(PORTA , Cpy_u8PinNo);
			break;
			
		    case DIO_U8_PORTB:
				CLR_BIT(DDRB , Cpy_u8PinNo);
				SET_BIT(PORTB , Cpy_u8PinNo);
			break;
			
		    case DIO_U8_PORTC:
				CLR_BIT(DDRC , Cpy_u8PinNo);
				SET_BIT(PORTC , Cpy_u8PinNo);
			break;
			
		    case DIO_U8_PORTD:
				CLR_BIT(DDRD , Cpy_u8PinNo);
				SET_BIT(PORTD , Cpy_u8PinNo);
            break;
	    }//end switch 	
	}//end input if 
//check if the port is output
	 else if(Cpy_u8PinDir == DIO_U8_DIR_OUT)
	    { 
          switch(Cpy_u8PortId)
		     {
			
		    case DIO_U8_PORTA:
			  SET_BIT(DDRA , Cpy_u8PinNo);
			break;
			
		    case DIO_U8_PORTB:
				SET_BIT(DDRB , Cpy_u8PinNo);
			break;
			
		    case DIO_U8_PORTC:
				SET_BIT(DDRC , Cpy_u8PinNo);
			break;
			
		    case DIO_U8_PORTD:
				SET_BIT(DDRD , Cpy_u8PinNo);
            break;
	  
        }//end switch
	}//end else if
	else
	   {
		   //
	   }

}//end security if

}//end function

/*************************************************************/
/*******************set the pins as HIGH OR LOW***************/
/*************************************************************/




void DIO_vidSetPinValue(u8 Cpy_u8PortId , u8 Cpy_u8PinNo , u8 Cpy_u8PinValue){
//ensure that the user's input is valid
if( (Cpy_u8PortId <= DIO_U8_PORTD && Cpy_u8PortId >= DIO_U8_PORTA) &&
		 (Cpy_u8PinNo <= DIO_U8_PIN7 && Cpy_u8PortId >= DIO_U8_PIN0))
		 {

        if (Cpy_u8PinValue == DIO_U8_HIGH)
		{
			/* Check on the Required PORT Number */
			switch (Cpy_u8PortId)
			{
				case DIO_U8_PORTA: SET_BIT(PORTA,Cpy_u8PinNo); break;
				case DIO_U8_PORTB: SET_BIT(PORTB,Cpy_u8PinNo); break;
				case DIO_U8_PORTC: SET_BIT(PORTC,Cpy_u8PinNo); break;
				case DIO_U8_PORTD: SET_BIT(PORTD,Cpy_u8PinNo); break;
			}
		
		}
		
		else if (Cpy_u8PinValue == DIO_U8_LOW)
		{
			/* Check on the Required PORT Number */
			switch (Cpy_u8PortId)
			{
				case DIO_U8_PORTA: CLR_BIT(PORTA,Cpy_u8PinNo); break;
				case DIO_U8_PORTB: CLR_BIT(PORTB,Cpy_u8PinNo); break;
				case DIO_U8_PORTC: CLR_BIT(PORTC,Cpy_u8PinNo); break;
				case DIO_U8_PORTD: CLR_BIT(PORTD,Cpy_u8PinNo); break;
			}
		}
	
		else
		{
			/* Do nothing, Wrong value to set */
		}
	}
}
	
/*************************************************************/
/************get the pin value and return its value***********/
/*************************************************************/


u8 DIO_u8GetPinValue ( u8 Cpy_u8PortId , u8 Cpy_u8PinNo )
{
	/* Define Local Variable to get the BIT Value */
	u8 u8ResultLocal;
	/* Make sure that the Port ID and Pin ID are in the valid range */
	if ((Cpy_u8PortId <= DIO_U8_PORTD) && (Cpy_u8PinNo <= DIO_U8_PIN7))
	{
		/* Check on the Required PORT Number */
		switch (Cpy_u8PortId)
		{
			case DIO_U8_PORTA: u8ResultLocal= GET_BIT(PINA,Cpy_u8PinNo); break;
			case DIO_U8_PORTB: u8ResultLocal= GET_BIT(PINB,Cpy_u8PinNo); break;
			case DIO_U8_PORTC: u8ResultLocal= GET_BIT(PINC,Cpy_u8PinNo); break;
			case DIO_U8_PORTD: u8ResultLocal= GET_BIT(PIND,Cpy_u8PinNo); break;
		}
	}
	
	else
	{
		/* return 0xff in case of error in the Pin ID or PORT ID */
		u8ResultLocal = 0xFF;
	}
	
	return u8ResultLocal;

}//end of function get value

/*************************************************************/
/*************************SetPortValue************************/
/*************************************************************/

void DIO_vidSetPortValue(u8 Cpy_u8PortId , u8 Cpy_u8ProtValue)
{    //check if the range is valid
	if ( Cpy_u8PortId <= DIO_U8_PORTD )
	{   
          switch (Cpy_u8PortId)
	{
		case     DIO_U8_PORTA: PORTA = Cpy_u8ProtValue; break;
		case     DIO_U8_PORTB: PORTB = Cpy_u8ProtValue; break;
		case     DIO_U8_PORTC: PORTC = Cpy_u8ProtValue; break;
		case     DIO_U8_PORTD: PORTD = Cpy_u8ProtValue; break;
		default: /* Wrong Port ID */        break;
	}
	   
	}//end if check range 
	
}//end of set port value

/*************************************************************/
/*************************set port direction******************/
/*************************************************************/

void DIO_vidSetPortDirection(u8 Cpy_u8PortId , u8 Cpy_u8PortValue)
{ 
  //check if the port is valid
  if(Cpy_u8PortId <= DIO_U8_PORTD)
  {  
//check if the port is input
     if(Cpy_u8PortValue == DIO_U8_DIR_IN)
		 //clear chosen port to be input
    	 //and active pull up resistor
	  switch (Cpy_u8PortId )
	  {
		  case DIO_U8_PORTA :
			  CLEAR_BYTE(DDRA);
		      SET_BYTE(PORTA);
		  break;

		  case DIO_U8_PORTB :
			  CLEAR_BYTE(DDRB);
			  SET_BYTE(PORTB);
		  break;
		  case DIO_U8_PORTC :
			  CLEAR_BYTE(DDRC);
			  SET_BYTE(PORTC);
		  break;
		  case DIO_U8_PORTD :
			  CLEAR_BYTE(DDRD);
			  SET_BYTE(PORTD);
			  break;

	  }//end switch
	  
	  //check if the port is output
     if(Cpy_u8PortValue == DIO_U8_DIR_OUT)
		 //set chosen port
	  switch (Cpy_u8PortId )
	  {
		  case DIO_U8_PORTA : SET_BYTE(DDRA); break;
		  case DIO_U8_PORTB : SET_BYTE(DDRB); break;
		  case DIO_U8_PORTC : SET_BYTE(DDRC); break;
		  case DIO_U8_PORTD : SET_BYTE(DDRD); break;

	  }//end switch
	  
  }//end if check 
	
}//end SetPortDirection function

/*************************************************************/
/************Get port value and return its value**************/
/*************************************************************/

u8 DIO_u8GetPortValue(u8 Cpy_u8PortId)
{
	u8 Loc_u8Value = 0xff;
	
	// check if the range is valid
	if(Cpy_u8PortId <= DIO_U8_PORTD)
	{
		switch (Cpy_u8PortId)
		{
			case DIO_U8_PORTA: Loc_u8Value = (PORTA); break;
			case DIO_U8_PORTB: Loc_u8Value = (PORTB); break;
			case DIO_U8_PORTC: Loc_u8Value = (PORTC); break;
			case DIO_U8_PORTD: Loc_u8Value = (PORTD); break;
		}//end swich
	}//end if of the range is valid
	else
	{
		//
	}//end else
	return Loc_u8Value;
}//end function


 
