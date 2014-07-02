/*
 * GpioPin.h
 *
 *  Created on: May 8, 2014
 *      Author: Sveinn Gretarsson

OR(|) to set(1) -- 1 to the bit to set, rest is zero and left untouched
AND(&) to clear (0) -- 0 to bit to clear, reset is one and left untouched

Port	Base address
---------------------
PortA	0x40004000
PortB	0x40005000
PortC	0x40006000
PortD	0x40007000
PortE	0x40024000
PortF	0x40025000

Bit		Constant
---------------------
7		0x0200
6		0x0100
5		0x0080
4		0x0040
3		0x0020
2		0x0010
1		0x0008
0		0x0004
 */
//#include "pin_map.h"
#include "tm4c123ge6pm.h"


#ifndef GPIOPIN_H_
#define GPIOPIN_H_

// GPIO Init Function prototypes
void PortA_init();
void PortF_init();
void togglePinOn();
void togglePinOff();

// GPIO SETUP
/*void PortA_init(){ // This example only activates pin 7

	volatile uint32_t delayA;
	SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOA; 	// 1. Enable GPIO Port (activate clock)
	delayA = SYSCTL_RCGC2_R;				// 2. Dummy ready to insert a few cycles after enabling peripherals

	GPIO_PORTA_DIR_R = ;
	GPIO_PORTA_DEN_R = ;

/*SYSCTL_RCGC2_R |= 0x00000001;     // 1) activate clock for Port A
delay = SYSCTL_RCGC2_R;           // allow time for clock to start
GPIO_PORTA_AMSEL_R &= ~0x80;      // 3) disable analog on PA7
GPIO_PORTA_PCTL_R &= ~0xF0000000; // 4) PCTL GPIO on PA7
GPIO_PORTA_DIR_R |= 0x80;         // 5) PA7 out
GPIO_PORTA_AFSEL_R &= ~0x80;      // 6) disable alt funct on PA7
GPIO_PORTA_DEN_R |= 0x80;         // 7) enable digital I/O on PA7
} */


void PortF_init(){
	volatile unsigned long delay;
	SYSCTL_RCGC2_R = SYSCTL_RCGC2_GPIOF; // Activate GPIO Port F
	delay = SYSCTL_RCGC2_R; //  Do a dummy read to insert a few cycles after enabling the peripheral.

	// Enable GPIO pin. Set Direction.
    GPIO_PORTF_DIR_R = 0x08;
    GPIO_PORTF_DEN_R = 0x08;
    GPIO_PORTF_AFSEL_R = 0x00; // diable alternate function for port F.


/*
	// From Texas Austin Example
	volatile unsigned long delay;
	  SYSCTL_RCGC2_R |= 0x00000020;     // 1) activate clock for Port F
	  delay = SYSCTL_RCGC2_R;           // allow time for clock to start
	  GPIO_PORTF_LOCK_R = 0x4C4F434B;   // 2) unlock GPIO Port F
	  GPIO_PORTF_CR_R = 0x1F;           // allow changes to PF4-0
	  // only PF0 needs to be unlocked, other bits can't be locked

	  GPIO_PORTF_AMSEL_R = 0x00;        // 3) disable analog on PF
	  GPIO_PORTF_PCTL_R = 0x00000000;   // 4) PCTL GPIO on PF4-0
	  GPIO_PORTF_DIR_R = 0x0E;          // 5) PF4,PF0 in, PF3-1 out
	  GPIO_PORTF_AFSEL_R = 0x00;        // 6) disable alt funct on PF7-0
	  GPIO_PORTF_PUR_R = 0x11;          // enable pull-up on PF0 and PF4
	  GPIO_PORTF_DEN_R = 0x1F;          // 7) enable digital I/O on PF4-0
*/
}


// PIN DEFINITIONS
	// PORT A:
	#define GPIO_PA0 (*((volatile unsigned long *)0x40004004))
	#define GPIO_PA1 (*((volatile unsigned long *)0x40004008))
	#define GPIO_PA2 (*((volatile unsigned long *)0x40004010))
	#define GPIO_PA3 (*((volatile unsigned long *)0x40004020))

	#define GPIO_PA4 (*((volatile unsigned long *)0x40004040))
	#define GPIO_PA5 (*((volatile unsigned long *)0x40004080))
	#define GPIO_PA6 (*((volatile unsigned long *)0x40004100))
	#define GPIO_PA7 (*((volatile unsigned long *)0x40004200))


	// PORT B:
	#define GPIO_PB0 (*((volatile unsigned long *)0x40005004))
	#define GPIO_PB1 (*((volatile unsigned long *)0x40005008))
	#define GPIO_PB2 (*((volatile unsigned long *)0x40005010))
	#define GPIO_PB3 (*((volatile unsigned long *)0x40005020))

	#define GPIO_PB4 (*((volatile unsigned long *)0x40006040))
	#define GPIO_PB5 (*((volatile unsigned long *)0x40006080))
	#define GPIO_PB6 (*((volatile unsigned long *)0x40006100))
	#define GPIO_PB7 (*((volatile unsigned long *)0x40006200))


	// PORT C:
	#define GPIO_PC0 (*((volatile unsigned long *)0x40006004))
	#define GPIO_PC1 (*((volatile unsigned long *)0x40006008))
	#define GPIO_PC2 (*((volatile unsigned long *)0x40006010))
	#define GPIO_PC3 (*((volatile unsigned long *)0x40006020))

	#define GPIO_PC4 (*((volatile unsigned long *)0x40006040))
	#define GPIO_PC5 (*((volatile unsigned long *)0x40006080))
	#define GPIO_PC6 (*((volatile unsigned long *)0x40006100))
	#define GPIO_PC7 (*((volatile unsigned long *)0x40006200))


	// PORT d:
	#define GPIO_PD0 (*((volatile unsigned long *)0x40007004))
	#define GPIO_PD1 (*((volatile unsigned long *)0x40007008))
	#define GPIO_PD2 (*((volatile unsigned long *)0x40007010))
	#define GPIO_PD3 (*((volatile unsigned long *)0x40007020))

	#define GPIO_PD4 (*((volatile unsigned long *)0x40007040))
	#define GPIO_PD5 (*((volatile unsigned long *)0x40007080))
	#define GPIO_PD6 (*((volatile unsigned long *)0x40007100))
	#define GPIO_PD7 (*((volatile unsigned long *)0x40007200))


	// PORT E:
	#define GPIO_PE0 (*((volatile unsigned long *)0x40024004))
	#define GPIO_PE1 (*((volatile unsigned long *)0x40024008))
	#define GPIO_PE2 (*((volatile unsigned long *)0x40024010))
	#define GPIO_PE3 (*((volatile unsigned long *)0x40024020))

	#define GPIO_PE4 (*((volatile unsigned long *)0x40024040))
	#define GPIO_PE5 (*((volatile unsigned long *)0x40024080))
	#define GPIO_PE6 (*((volatile unsigned long *)0x40024100))
	#define GPIO_PE7 (*((volatile unsigned long *)0x40024200))


	// PORT F:
	#define GPIO_PF0 (*((volatile unsigned long *)0x40025004)) // SW2
	#define GPIO_PF1 (*((volatile unsigned long *)0x40025008)) // RED LED
	#define GPIO_PF2 (*((volatile unsigned long *)0x40025010)) // BLUE LED
	#define GPIO_PF3 (*((volatile unsigned long *)0x40025020)) // GREEN LED

	#define GPIO_PF4 (*((volatile unsigned long *)0x40025040)) // SW1
	#define GPIO_PF5 (*((volatile unsigned long *)0x40025080))
	#define GPIO_PF6 (*((volatile unsigned long *)0x40025100))
	#define GPIO_PF7 (*((volatile unsigned long *)0x40025200))



#endif /* GPIOPIN_H_ */
