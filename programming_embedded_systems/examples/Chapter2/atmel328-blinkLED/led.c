/**********************************************************************
 *
 * Filename:    led.c
 * 
 * Description: LED-related functionality.
 *
 * Notes:       The constants in this file are specific to Arcom's 
 *              Target188EB hardware.
 *
 * 
 * Copyright (c) 1998 by Michael Barr.  This software is placed into
 * the public domain and may be used for any purpose.  However, this
 * notice must not be changed or removed and no warranty is either
 * expressed or implied by its publication or distribution.
 **********************************************************************/

#include "led.h"


/**********************************************************************
 *
 * Function:    toggleLed()
 *
 * Description: Toggle the state of one or both LED's.
 *
 * Notes:       This function is specific to Arcom's Target188EB board.
 *
 * Returns:     None defined.
 *
 **********************************************************************/
void 
toggleLed(unsigned char ledMask)
{
    #define PORTB 0x25	/* The address PORTB	*/
    #define DDRB 0x24	/* The address DDRB		*/		
    

    asm (
      
    	"ldi r24, 0x80 \n\t"	/* Set PINBX as output	*/
    	"out 0x24, r24 \n\t"
    	"ldi r25, 0x25 \n\t"   /* Read contents of port B	*/
    	"com r25 \n\t"			/* Toggle the requested bits.	*/
	 	"out 0x25, r25 \n\t"	/* Write the new register contents.*/
    );

}   /* toggleLed() */
