#include <msp430.h>
#include "timer.h"



//TEST ME
void delay_us(int us) {
    //SMCLK <- DCOCLK = 4Mhz
    int i = 0;
    int ticks = us*4;
    int n = ticks / 10000;
    int t = ticks % 10000;

    TA0R = TACLR;                           //Clear register / restart timer
    TA0CCTL0 &= ~CCIE;                        // TACCR0 interrupt enabled
    TA0CCR0 = 10000;

    TA0CTL = TASSEL__SMCLK | MC__UP;        // SMCLK, UP mode

    for(i = 0; i < n; ++i) {
        while((TA0R < 10000 && i <n) || i < t);
        TA0R = TACLR;
    }

    TA0CTL = MC__STOP;

    return;
}



