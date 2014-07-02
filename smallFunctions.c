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
// 	Filename: smallFunctions.c
//    Author: SveinnWorker
//	    Date: 21/06/2014
//
// >> This file is made to be a home for small helper functions
//		in order to keep the main file clean, and to have as few
//		extra files, code and header files.
//
//=============================================================

#include "smallFunctions.h"
#include "tm4c123ge6pm.h"

//=============================================================
//		Delay Function
//=============================================================
void delay(int mtime){
	// Delay function is passed time in milliseconds.
	// This induces a delay over corresponding time.
	long unsigned int timeC = 0;					// Counter var initialized
	long unsigned int timePR = ((mtime * 8000)/5);  // Period calculated
	while(timeC <= timePR){timeC++;}				// Count until Period is reached
}

//=============================================================
//		GPIO Functions
//=============================================================
unsigned long digitalRead(unsigned long port, unsigned long pin){
		 /* Digital pin read function, using ? operator:
			The condition must evaluate to true or false. If condition
			is true, first_expression is evaluated and becomes the result.
			If condition is false, second_expression is evaluated and
			becomes the result. Only one of the two expressions is evaluated. */

	//toggle(PortF,BLUE_LED); << For test.
	unsigned int pinLogic = (*((volatile uint32_t *) (port + dataBit)))&pin;
	pinLogic = (pinLogic > 32) ? 1 : 0; // instead of geting a number between 64 and 0,
	return pinLogic;
}

void pinON(unsigned long Port, unsigned long Pin){
	#define pinOn (*((volatile unsigned long *) Port + Pin))
	pinOn = Pin;
}
void pinOFF(unsigned long Port, unsigned long Pin){
	#define pinOff (*((volatile unsigned long *) Port + Pin))
	pinOff = 0x00;
}

void toggle(unsigned long Port, unsigned long Pin){
	// Pin toggle function. The function is passed port and pin;
	// 	See the pin & port definitions in the 'smallFunctions'
	//	header file.

	#define TogglePin (*((volatile unsigned long *) Port + Pin))
	TogglePin ^= Pin;

	// Litterature:
	// >> http://users.ece.utexas.edu/~valvano/Volume1/E-Book/C6_MicrocontrollerPorts.htm
}

//=====================END=OF=FILE===========================
