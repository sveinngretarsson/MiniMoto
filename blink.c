//=============================================================
//							_         __
//		   ___  _______    (_)__ ____/ /_
//		  / _ \/ __/ _ \  / / -_) __/ __/
//		 / .__/_/  \___/_/ /\__/\__/\__/
//		/_/           |___/
//					__  ____       _ __  ___      __
//				   /  |/  (_)___  (_)  |/  /___  / /_____
//				  / /|_/ / / __ \/ / /|_/ / __ \/ __/ __ \
//				 / /  / / / / / / / /  / / /_/ / /_/ /_/ /
//				/_/  /_/_/_/ /_/_/_/  /_/\____/\__/\____/
//=============================================================
// 	Filename: blink.c
//    Author: SveinnWorker
//	    Date: 21/06/2014
//
// >> This file is a test file, to learn how the board works.
//		By using the on-board LEDs, alot can be learned about
//		basic pin operations.
//
// >> Functions like "toggle" and "delay" can be found in the "smallFunctions.c"
//		file.
//=============================================================
//  Include libraries
//=============================================================
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tm4c123ge6pm.h"
#include "smallFunctions.h"
//=============================================================

// >> Pin HEX names, for convinience.
/*
 * PIN		HEX
 * 0		0x01
 * 1		0x02
 * 2		0x04
 * 3		0x08
 * 4		0x10
 * 5		0x20
 * 6		0x40
 * 7		0x80
 */

//#define portF (*((volatile unsigned long *) 0x40025000))

//void enablePin()

unsigned int counter;


int main(void)
{
//=============================================================
//  Enable Pin & Port
//=============================================================
	enablePortF_Out(BLUE_LED+RED_LED+GREEN_LED); // Experimental EnableOut function
//=============================================================


    // Loop forever.
    while(1)
    {
    	// Turn on the LED.
    	toggle(PortF,(RED_LED+GREEN_LED));
    	if(counter<=10){pinON(PortF,BLUE_LED);}

    	//GPIO_PORTF_DATA_R |= RED_LED+BLUE_LED+GREEN_LED;

    	// Delay for a bit, function call to delay, this is a counting while loop.
    	delay(delayTime);
    	toggle(PortF,GREEN_LED);
    	//toggle(PortF,RED_LED+GREEN_LED);
    	counter++;
    	if(counter > 10){pinOFF(PortF,BLUE_LED);}
    	// Turn off the LED.
        //GPIO_PORTF_DATA_R &= ~(RED_LED+BLUE_LED);
    	//delay(delayTime);
     }
}



//=====================END=OF=FILE===========================
