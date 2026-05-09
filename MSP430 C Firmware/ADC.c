/*******************************************************************************
 * @file        ADC.c
 * @brief       ADC initialization and core configuration.
 * @project     MSP430 Sensor Suite
 * @author      Luca
 * @date        May 5, 2026
 * * @description
 * Configures the ADC12 module for 10-bit resolution with a 64-clock cycle
 * sample-and-hold time to ensure signal integrity. It initializes
 * the module to begin sampling on Channel A1 (Photoresistor).
 ******************************************************************************/

#include "ProjectMaster.h"


void Init_ADC(void) {
    // ADCSHT_4: 64 clock cycles (increased from 16)
    // This gives the capacitor time to fully track the new pin voltage.
    ADCCTL0 = ADCSHT_4 | ADCON;

    // ADCSHP: Use sampling timer
    ADCCTL1 = ADCSSEL_0 | ADCSHP;

    // Change ADCRES_2 (12-bit) to ADCRES_1 (10-bit)
    ADCCTL2 = ADCRES_1;

    // Start pointing at A1 (Photoresistor)
    ADCMCTL0 = ADCINCH_1 | ADCSREF_0;

    ADCIE |= ADCIE0; // Enable interrupt
    ADCCTL0 |= ADCENC; // Enable ADC core
}
