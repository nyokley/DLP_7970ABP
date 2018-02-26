/*
 * mspfr5994.c
 *
 *  Created on: Feb 21, 2018
 *      Author: Nathaniel
 */

#include <msp430fr5994.h>
#include <stdbool.h>
#include "mcu.h"
#include "spi.h"
#include "trf7970.h"

void mcu_init() {
    WDTCTL = WDTPW | WDTHOLD;
    P5SEL1 &= ~(BIT0 | BIT1 | BIT2);        // USCI_B1 SCLK, MOSI, and MISO pin
    P5SEL0 |= (BIT0 | BIT1 | BIT2);
    PJSEL0 |= BIT4 | BIT5;                  // For XT1

    IRQ_LOW;
    IRQ_SETDIR;
    IRQ_RDIS;
    IRQ_IE;
    IRQ_IES_RISING;
    IRQ_IFG_CLR;

    SS_LOW;
    SS_SETDIR;

    EN_LOW;
    EN_SETDIR;

    PM5CTL0 &= ~LOCKLPM5;

    xt1_init();

    uscib1_init();

    __enable_interrupt();

}

void xt1_init() {
    CSCTL0_H = CSKEY_H;                     // Unlock CS registers
    CSCTL1 = DCOFSEL_3;                     // Set DCO to 4MHz
    CSCTL2 = SELA__LFXTCLK | SELS__DCOCLK | SELM__DCOCLK;
    CSCTL3 = DIVA__1 | DIVS__1 | DIVM__1;   // set all dividers
    CSCTL4 &= ~LFXTOFF;
    do
    {
        CSCTL5 &= ~LFXTOFFG;                // Clear XT1 fault flag
        SFRIFG1 &= ~OFIFG;
    } while (SFRIFG1 & OFIFG);              // Test oscillator fault flag
    CSCTL0_H = 0;                           // Lock CS registers
}

#pragma vector = PORT6_VECTOR
__interrupt void Port_6(void) {
    P6IFG &= ~BIT3;
    IRQ_SHOULD_READ = 1;

}




