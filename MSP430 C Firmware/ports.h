/*
 * ports.h
 *
 *  Created on: May 3, 2026
 *      Author: Luca
 */

#ifndef PORTS_H_
#define PORTS_H_

//-----------------------------------------------------
// Port 1 Pin Definitions
#define V_PHOTORES   (0x02)  //P1.1 - Photoresistor
#define V_THUMB     (0x04)  //P1.2 - Thumbwheel

//-----------------------------------------------------
// Port 2 Pin Definitions
#define SW1         (0x10)  //P2.4 - SW1
#define SW2         (0x20)  //P2.5 - SW2
#define SW3         (0x40)  //P2.6 - SW3

//-----------------------------------------------------
// Port 3 Pin Definitions
#define P2PUPD        P2OUT
#define BLUE_LED    (0x01)  //P3.0 - Blue LED
#define YELLOW_LED  (0x02)  //P3.1 - Yellow LED
#define GREEN_LED   (0x04)  //P3.2 - Green LED
#define RED_LED     (0x08)  //P3.4 - Red LED


void Init_Port1(void);
void Init_Port2(void);
void Init_Port3(void);
void Init_Ports(void);



#endif /* PORTS_H_ */
