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
// 	Filename: hBridgeControl_1
//    Author: SveinnWorker
//	    Date: 21/06/2014
//
// >> This file was the first and the perhaps the most simple
//		GPIO toggle script, used to test the H-Brdige (L9110).
//		This script also tested the GPIO digital read function.
//
//	  COMMENT:
//		I need to use a pull down on the h-bridge.
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

int readPin(unsigned long port, unsigned long pin);
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
    	//readPin()
    	//variableTest = (*((volatile uint32_t *)PortA + dataBit))&Pin6;  //GPIO_PORTA_DATA_R &Pin6;
    	// Forward Motor drive
    	//GPIO_PORTA_DATA_R &= ~(Pin3); 	// Turn OFF Pin3
    	delay(delayTime/4);			  	// very short delay, so A&B are not turned on simultaneously
    	GPIO_PORTA_DATA_R |= Pin2;	  	// Turn ON
    	toggle(PortF,GREEN_LED+RED_LED);// Toggle LEDs, Red OFF and Green ON

    	// Delay for a bit, function call to delay, this is a counting while loop.
    	delay(delayTime);
    	//variableTest = GPIO_PORTA_DATA_R&Pin6;
    	// Reverse Motor drive
    	GPIO_PORTA_DATA_R &= ~(Pin2);
    	delay(delayTime/4);
    	GPIO_PORTA_DATA_R |= Pin3;
    	toggle(PortF,GREEN_LED+RED_LED);

    	delay(delayTime);
    	//variableTest = GPIO_PORTA_DATA_R&Pin6;
    	GPIO_PORTA_DATA_R &= ~(Pin2);
    	GPIO_PORTA_DATA_R &= ~(Pin3);
    	toggle(PortF,RED_LED);

    	delay(delayTime);
     }
}
