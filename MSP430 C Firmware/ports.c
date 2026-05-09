/*******************************************************************************
 * @file        ports.c
 * @brief       GPIO and Peripheral Pin Multiplexing.
 * @project     MSP430 Sensor Suite
 * @author      Luca
 * @date        May 3, 2026
 * * @description
 * Sets up the physical interface for the MSP430, including:
 * - Analog inputs for sensor data (V_THUMB, V_PHOTORES).
 * - Digital inputs with pull-up resistors for user switches.
 * - Digital outputs for the Blue, Yellow, Green, and Red status LEDs.
 ******************************************************************************/

#include "ProjectMaster.h"

void Init_Ports(void){
    Init_Port1();
    Init_Port2();
    Init_Port3();
}

//-----------------------
// Port 1 Configurations
void Init_Port1(void){
    P1SEL0 |= V_THUMB;  //Set to ADC Function
    P1SEL1 |= V_THUMB;  //Set to ADC function
    P1DIR &= ~V_THUMB;  //Set direction to input

    P1SEL0 |= V_PHOTORES;  //Set to ADC Function
    P1SEL1 |= V_PHOTORES;  //Set to ADC function
    P1DIR &= ~V_PHOTORES;  //Set direction to input
}

//-----------------------
// Port 2 Configurations
void Init_Port2(void){

    P2SEL0 &= ~SW1; //Set to GPIO operation
    P2SEL1 &= ~SW1; //Set to GPIO operation
    P2DIR &= ~SW1; // Set direction to input
    P2REN |= SW1;   //Enable Pull-up or Pull-down resistors
    P2PUPD |= SW1;  //Set to Pull-up resistor
    P2IES |= SW1;   //Set interrupt edge trigger to High to Low
    P2IFG &= ~SW1;  //Clear any existing interrupt flags
    P2IE |= SW1;    //Enable interrupt

    P2SEL0 &= ~SW2; //Set to GPIO operation
    P2SEL1 &= ~SW2; //Set to GPIO operation
    P2DIR &= ~SW2;  // Set direction to input
    P2REN |= SW2;   //Enable Pull-up or Pull-down resistors
    P2PUPD |= SW2;  //Set to Pull-up resistor
    P2IES |= SW2;   //Set interrupt edge trigger to High to Low
    P2IFG &= ~SW2;  //Clear any existing flags
    P2IE |= SW2;    //Enable interrupt

    P2SEL0 &= ~SW3; //Set to GPIO operation
    P2SEL1 &= ~SW3; //Set to GPIO operation
    P2DIR &= ~SW3;  // Set direction to input
    P2REN |= SW3;   //Enable Pull-up or Pull-down resistors
    P2PUPD |= SW3;  //Set to Pull-up resistor
    P2IES |= SW3;   //Set interrupt edge trigger to High to Low
    P2IFG &= ~SW3;  //Clear any existing flags
    P2IE |= SW3;    //Enable interrupt
}

//-----------------------
// Port 3 Configurations
void Init_Port3(void){

    P3SEL0 &= ~BLUE_LED;        //Set to GPIO operation
    P3SEL1 &= ~BLUE_LED;        //Set to GPIO operation
    P3DIR |= BLUE_LED;          //Direction set to output
    P3OUT &= ~BLUE_LED;         //Output set to Low

    P3SEL0 &= ~YELLOW_LED;        //Set to GPIO operation
    P3SEL1 &= ~YELLOW_LED;        //Set to GPIO operation
    P3DIR |= YELLOW_LED;          //Direction set to output
    P3OUT &= ~YELLOW_LED;         //Output set to Low

    P3SEL0 &= ~GREEN_LED;        //Set to GPIO operation
    P3SEL1 &= ~GREEN_LED;        //Set to GPIO operation
    P3DIR |= GREEN_LED;          //Direction set to output
    P3OUT &= ~GREEN_LED;         //Output set to Low

    P3SEL0 &= ~RED_LED;        //Set to GPIO operation
    P3SEL1 &= ~RED_LED;        //Set to GPIO operation
    P3DIR |= RED_LED;          //Direction set to output
    P3OUT &= ~RED_LED;         //Output set to Low
}


