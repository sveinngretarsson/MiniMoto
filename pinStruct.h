/*
 * pinStruct.h
 *
 *  Created on: May 10, 2014
 *      Author: Sveinn Gretarsson
 */

#include "tm4c123ge6pm.h"

#ifndef Gpi_pinStruct_H_
#define Gpi_pinStruct_H_

struct PORT{
	volatile uint32_t DataBitsReg;
	volatile uint32_t DataReg;
	volatile uint32_t DirReg;
	volatile uint32_t IntSensReg;
	volatile uint32_t IntBothEdge;
	volatile uint32_t IntEvent;
	volatile uint32_t IntMask;
	volatile uint32_t RawIntStatus;
	volatile uint32_t MaskedIntStat;
	volatile uint32_t IntClear;
	volatile uint32_t AltFuncSel;
	volatile uint32_t DR2R;  // Drive Strength
	volatile uint32_t DR4R;
	volatile uint32_t DR8R;
	volatile uint32_t ODR; // Open Drain
	volatile uint32_t PUR; // Pull Up Resistor
	volatile uint32_t PDR; // Pull Down Resistor
	volatile uint32_t SLR; // Slew-rate
	volatile uint32_t DigitalEnable; // DEN
	volatile uint32_t Lock;
	volatile uint32_t CR;
	volatile uint32_t AMSel; // Analog Select
	volatile uint32_t PortControlReg;
	volatile uint32_t ADCControlReg;
	volatile uint32_t DMAControlReg;
};



/*
struct PORT PORTA = {
GPIO_PORTA_DATA_BITS_R,
GPIO_PORTA_DATA_R,
GPIO_PORTA_DIR_R,
GPIO_PORTA_IS_R,
GPIO_PORTA_IBE_R,
GPIO_PORTA_IEV_R,
GPIO_PORTA_IM_R,
GPIO_PORTA_RIS_R,
GPIO_PORTA_MIS_R,
GPIO_PORTA_ICR_R,
GPIO_PORTA_AFSEL_R,
GPIO_PORTA_DR2R_R,
GPIO_PORTA_DR4R_R,
GPIO_PORTA_DR8R_R,
GPIO_PORTA_ODR_R,
GPIO_PORTA_PUR_R,
GPIO_PORTA_PDR_R,
GPIO_PORTA_SLR_R,
GPIO_PORTA_DEN_R,
GPIO_PORTA_LOCK_R,
GPIO_PORTA_CR_R,
GPIO_PORTA_AMSEL_R,
GPIO_PORTA_PCTL_R,
GPIO_PORTA_ADCCTL_R,
GPIO_PORTA_DMACTL_R,
}*/

#endif
