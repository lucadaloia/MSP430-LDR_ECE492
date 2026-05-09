/*******************************************************************************
 * @file        interrupts.c
 * @brief       Global Interrupt Service Routines (ISRs).
 * @project     MSP430 Sensor Suite
 * @author      Luca
 * @date        May 5, 2026
 * * @description
 * Handles critical asynchronous events including:
 * - Port 2: Button debouncing and mode switching.
 * - Timer B0: 10Hz trigger for ADC conversions.
 * - ADC: Automated channel switching logic between the Photoresistor (A1)
 * and Thumbwheel (A2).
 ******************************************************************************/

#include "ProjectMaster.h"

#pragma vector=PORT2_VECTOR
__interrupt void Port_2_ISR(void){
        // SW1 (P2.4) ISR
        if (P2IFG & SW1) {
            // Perform action
            mode = 1;
            P2IFG &= ~SW1;                                // CLEAR THE FLAG
        }

        // SW2 (P2.5) ISR
        if (P2IFG & SW2) {
            //perform action
            mode = 2;
            P2IFG &= ~SW2;                                 // CLEAR THE FLAG
        }

        // SW3 (P2.6) ISR
        if (P2IFG & SW3) {
            //perform action
            mode = 3;
            initial_photo_val = photo_val;
            P2IFG &= ~SW3;                                 // CLEAR THE FLAG
        }
}



//------------------------------------------------------------------------------
// Timer B0 CCR0 Interrupt Service Routine
// Triggers the ADC conversion every timer cycle (approx 10Hz)
//------------------------------------------------------------------------------
#pragma vector = TIMER0_B0_VECTOR
__interrupt void Timer_B_ISR(void) {
    // Start the first conversion in the chain (Photoresistor)
    ADCCTL0 |= ADCSC;
}

//------------------------------------------------------------------------------
// ADC Interrupt Service Routine
// Fires when a conversion is complete
//------------------------------------------------------------------------------
#pragma vector = ADC_VECTOR
__interrupt void ADC_ISR(void) {
    switch(__even_in_range(ADCIV, ADCIV_ADCIFG)) {
        case ADCIV_ADCIFG:

            ADCCTL0 &= ~ADCENC;

            switch (ADC_Channel) {
                case 0: // Just finished A1 (Photoresistor)
                    photo_val = ADCMEM0 / 4;

                    // 2. DISABLE current channel (A1)
                    ADCMCTL0 &= ~ADCINCH_1;
                    // 3. ENABLE next channel (A2)
                    ADCMCTL0 |= ADCINCH_2;

                    ADC_Channel = 1;

                    // 4. Start the next conversion
                    ADCCTL0 |= ADCENC | ADCSC;
                    break;

                case 1: // Just finished A2 (Thumbwheel)
                    thumb_val = ADCMEM0 / 4;

                    // 5. DISABLE current channel (A2)
                    ADCMCTL0 &= ~ADCINCH_2;
                    // 6. ENABLE next channel (A1)
                    ADCMCTL0 |= ADCINCH_1;

                    ADC_Channel = 0;

                    // 7. Re-enable but WAIT for the Timer
                    ADCCTL0 |= ADCENC;
                    break;
            }
            break;
    }
}

