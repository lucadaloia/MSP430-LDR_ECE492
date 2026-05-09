/*******************************************************************************
 * @file        timers.c
 * @brief       Timer_B0 configuration for periodic system ticks.
 * @project     MSP430 Sensor Suite
 * @author      Luca
 * @date        May 5, 2026
 * * @description
 * Configures Timer B0 using the ACLK (~32.768 kHz) in Up Mode.
 * Sets a compare value of 3277 to generate an interrupt at approximately
 * 10Hz, which acts as the heartbeat for ADC sampling.
 ******************************************************************************/

#include "ProjectMaster.h"

void Init_Timer(void) {
    // TB0CTL - Timer B0 Control
    // TBSSEL__ACLK: Use Auxiliary Clock (~32.768 kHz)
    // MC__UP: Up mode (counts from 0 to TB0CCR0)
    // TBCLR: Clear the timer to start fresh
    TB0CTL = TBSSEL__ACLK | MC__UP | TBCLR;

    // Set the compare value (32768 / 10 = ~3277 for 10Hz)
    TB0CCR0 = 3277;

    // Enable the interrupt for CCR0
    TB0CCTL0 |= CCIE;
}

