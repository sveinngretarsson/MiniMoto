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
// 	Filename: smallFunctions.h
//    Author: SveinnWorker
//	    Date: 21/06/2014
//
// >> This file is made to be a home for small helper functions
//		in order to keep the main file clean, and to have as few
//		extra files, code and header files.
//
//=============================================================

#ifndef DELAY_H_
#define DELAY_H_

//=============================================================
//		FUNCTION PROTOTYPES
//=============================================================

void delay(int mtime);

// GPIO:
unsigned long digitalRead(unsigned long port, unsigned long pin);// digital read
void toggle(unsigned long Pin, unsigned long Port); // Pin TOGGLE
void pinON(unsigned long Pin, unsigned long Port); // Pin OFF
void pinOFF(unsigned long Pin, unsigned long Port); // Pin ON
void enablePortF_Out(unsigned long enablePin); // PortF Setup

//=============================================================
//		Shared Constants
//=============================================================
#define CPU_FREQUENCY 80e6 // [Hz]
#define CPU_PERIOD 1.25e-8 // [s] or 12.5 ns
#define delayTime 1500

// >> Define pins with numbers
//* PIN	ADDRESS		HEX
#define Pin0		0x01
#define Pin1		0x02
#define Pin2		0x04
#define Pin3		0x08
#define Pin4		0x10
#define Pin5		0x20
#define Pin6		0x40
#define Pin7		0x80
//* PORT ADDRESS	HEX
#define PortA		0x40004000
#define PortB		0x40005000
#define PortC		0x40006000
#define PortD		0x40007000
#define PortE		0x40024000
#define PortF		0x40025000
//* DATA PORT ADDRESS
#define PortA_data 0x400043FC
#define dataBit 0x3FC // data registry

// Special Ports (LEDS) -- For convinience.
#define GREEN_LED 0x08 // GREEN LED (PF-3)
#define RED_LED 0x02 // RED LED (PF-1)
#define BLUE_LED 0x04 // BLUE LED (PF-2)

#endif /* DELAY_H_ */

//=====================END=OF=FILE===========================
