//-----------------------------------------------------------------
// Name:	Coulston
// File:	lab7.c
// Date:	Fall 2014
// Purp:	Collect analog samples from P1.3 and P1.4
//-----------------------------------------------------------------
// Name:	JP Terragnoli
// File:	main.c
// Date:	Fall 2014
// Purp:	Sensing objects around the robot.  Lights up left,
//			center, and right LEDs respectively.
//-----------------------------------------------------------------

#include "msp430g2553.h"
#include "header.h"

void initMSP430();

//----------------------------------------------------------------------
//----------------------------------------------------------------------
int main(void) {
	IFG1=0; 													// clear interrupt flag1
	WDTCTL = WDTPW + WDTHOLD;									// disable WDT

	BCSCTL1 = CALBC1_8MHZ;										// 8MHz clock
	DCOCTL = CALDCO_8MHZ;

	P1DIR = BIT0|BIT6;												// Set the red LED as output
	//P1DIR = BIT6;												// Set the green LED as output
	while(1) {


		leftSensor();

		centerSensor();

		rightSensor();

	} // end infinite loop

} // end main

