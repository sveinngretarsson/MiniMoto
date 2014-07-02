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
// 	Filename: enablePin.c
//    Author: SveinnWorker
//	    Date: 21/06/2014
//
// >> This file is an attempt to get an easy method for initiating
//		pins and ports.
//
// For more information, see:
// >> http://users.ece.utexas.edu/~valvano/Volume1/E-Book/C6_MicrocontrollerPorts.htm
//=============================================================
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include "tm4c123ge6pm.h"
#include "smallFunctions.h"

void enablePortF_In(unsigned long enablePin){
	volatile uint32_t ui32Loop;
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // This is the same as: SYSCTL_RCGC2_R |= 0x00000021;

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    ui32Loop = SYSCTL_RCGC2_R;

    //--- Pin setup
    // Enable the GPIO pin.  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIO_PORTF_DIR_R = enablePin; //Sets Direction bit to OUTPUT for designated pins.
    GPIO_PORTF_DEN_R = enablePin; //Enable Digital I/O
    GPIO_PORTF_PDR_R = enablePin; //Enable Pull-Down

//----- >> Other Smart Stuff that doesn't work.. :@
    // GPIO_PORTF_AMSEL_R=enablePin; 	//Disable Analog on Pin
    //GPIO_PORTF_AFSEL_R=enablePin; 	//Disable PIN alternate function
    //GPIO_PORTF_PUR_R =; 		 		//Enable Pull-Up
    GPIO_PORTF_LOCK_R = 0x4C4F434B;	//Unlock GPIO Port F
    GPIO_PORTF_CR_R = 0x1F;           //Allow changes to PF4-0
}

void enablePortF_Out(unsigned long enablePin){
	volatile uint32_t ui32Loop;
    // Enable the GPIO port that is used for the on-board LED.
    SYSCTL_RCGC2_R |= SYSCTL_RCGC2_GPIOF; // This is the same as: SYSCTL_RCGC2_R |= 0x00000021;

    // Do a dummy read to insert a few cycles after enabling the peripheral.
    ui32Loop = SYSCTL_RCGC2_R;

    //--- Pin setup
    // Enable the GPIO pin.  Set the direction as output, and
    // enable the GPIO pin for digital function.
    GPIO_PORTF_DIR_R = enablePin; //Sets Direction bit to OUTPUT for designated pins.
    GPIO_PORTF_DEN_R = enablePin; //Enable Digital I/O
    GPIO_PORTF_PDR_R = enablePin; //Enable Pull-Down

//----- >> Other Smart Stuff that doesn't work.. :@
    // GPIO_PORTF_AMSEL_R=enablePin; 	//Disable Analog on Pin
    //GPIO_PORTF_AFSEL_R=enablePin; 	//Disable PIN alternate function
    GPIO_PORTF_PUR_R =Pin4+Pin0; 		//Enable Pull-Up
    GPIO_PORTF_LOCK_R = 0x4C4F434B;	//Unlock GPIO Port F
    GPIO_PORTF_CR_R = 0x1F;           //Allow changes to PF4-0
}
