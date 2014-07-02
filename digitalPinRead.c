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
// 	Filename: digitalPinRead.c
//    Author: SveinnWorker
//	    Date: 27/06/2014
//
// >> This file is used to create and analyse a digital read function
//		to make it easy and better to look at, where pins and ports
//		are given, and the function returns a 1 or 0.
//
// >> The test is made where the PF1 pin is hooked up to PA6 pin,
// 		when the RED_LED turns on and off, the digital signal can
//		be detected and read.
//
//=============================================================
//  Include libraries
//=============================================================
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tm4c123ge6pm.h"
#include "smallFunctions.h"
//=============================================================

unsigned long readPin(unsigned long port, unsigned long pin);
unsigned int variableTest;

int main(void)
{
//=============================================================
//  Enable A-Pins & Port
//=============================================================
	volatile uint32_t ui32Loop;
    // Enable the GPIO port that is used for the on-board LED.
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOA;	//SYSCTL_RCGC2_GPIOF; // This is the same as: SYSCTL_RCGC2_R |= 0x00000021;

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    ui32Loop = SYSCTL_RCGC2_R;

    //--- Pin setup
    // Enable the GPIO pin for the LED (PF).  Set the direction as output, and
    // enable the GPIO pin for digital function.

    GPIO_PORTA_DIR_R = Pin2+Pin3;// This is the same as: 0x02+0x04+0x08;

    GPIO_PORTA_PDR_R = Pin2+Pin3+Pin6;
    GPIO_PORTA_AFSEL_R &= ~Pin2+Pin3+Pin6;      // 6) disable alt funct on PA7
    GPIO_PORTA_DEN_R = Pin2+Pin3+Pin6;

	enablePortF_Out(BLUE_LED+RED_LED+GREEN_LED); // Experimental EnableOut function

//=============================================================

	GPIO_PORTF_DATA_R |= RED_LED;

    // Loop forever.
    while(1)
    {

    	toggle(PortF,RED_LED);
    	variableTest = readPin(PortA,Pin6);
    	delay(delayTime);
    	toggle(PortF,RED_LED);
    	variableTest = readPin(PortA,Pin6);
    	delay(delayTime);

     }
}

//=====================END=OF=FILE===========================

unsigned long readPin(unsigned long port, unsigned long pin){
	toggle(PortF,BLUE_LED);
	// Digital pin read function, using ? operator:
	//		The condition must evaluate to true or false. If condition
	//		is true, first_expression is evaluated and becomes the result.
	//		If condition is false, second_expression is evaluated and
	//		becomes the result. Only one of the two expressions is evaluated.
	unsigned int pinLogic = (*((volatile uint32_t *) (port + dataBit)))&pin;
	pinLogic = (pinLogic > 32) ? 1 : 0; // instead of geting a number between 64 and 0,
	return pinLogic;
}
