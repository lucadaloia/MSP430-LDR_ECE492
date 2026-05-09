/*******************************************************************************
 * @file        main.c
 * @brief       Main application entry point and system control logic.
 * @project     MSP430 Sensor Suite
 * @author      Luca
 * @date        May 5, 2026
 * * @description
 * This file serves as the central hub of the application. It initializes
 * hardware peripherals, manages the global state machine (modes 1-3), and
 * controls the LED output logic based on photoresistor thresholds.
 ******************************************************************************/

#include "ProjectMaster.h"

int main(void) {
    // Stop the watchdog timer to prevent constant resets
    WDTCTL = WDTPW | WDTHOLD;

    Init_Ports();
    Init_Timer();
    Init_ADC();



    P3OUT |= RED_LED;   //Turn LED on to display power



    // Disable the GPIO power-on default high-impedance mode
    // This is required for FR series (FRAM) MSP430s to activate the settings
    PM5CTL0 &= ~LOCKLPM5;
    __enable_interrupt();
    // Infinite loop to keep the LEDs illuminated
    while(1) {
        switch (mode){
        case 1:
            if (photo_val > (initial_photo_val + 60)){
                P3OUT |= BLUE_LED;
                P3OUT |= YELLOW_LED;
                P3OUT |= GREEN_LED;
            }
            else {
                P3OUT &= ~BLUE_LED;
                P3OUT &= ~YELLOW_LED;
                P3OUT &= ~GREEN_LED;
            }
            break;
        case 2:
            if (photo_val > (initial_photo_val + 60)){
                P3OUT |= GREEN_LED;
            }
            else P3OUT &= ~GREEN_LED;
            if (photo_val > (initial_photo_val + 80)){
                P3OUT |= YELLOW_LED;
            }
            else P3OUT &= ~YELLOW_LED;
            if (photo_val > (initial_photo_val + 100)){
                P3OUT |= BLUE_LED;
            }
            else P3OUT &= ~BLUE_LED;
            break;
        case 3:
            P3OUT &= ~BLUE_LED;
            P3OUT &= ~YELLOW_LED;
            P3OUT &= ~GREEN_LED;
            break;
        default: break;
        }

        __no_operation();
    }

    return 0;
}
