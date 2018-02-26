#include <msp430.h>
#include "headers/timer.h"
#include "headers/mcu.h"


void timer_test() {
    while(1) {
            SS_HIGH;
            delay_us(20000);
            SS_LOW;
            delay_us(8000);
            SS_HIGH;
            delay_us(1000);
            SS_LOW;
            delay_us(100);
        }
}

//TEST ME
void delay_us(int us) {
    //SMCLK <- DCOCLK = 4Mhz
    int i = 0;
    int ticks = us*4;
    int n = ticks / 1000;
    int t = ticks % 1000;

    TA0R = TACLR;                           //Clear register / restart timer
    TA0CCTL0 &= ~CCIE;                        // TACCR0 interrupt enabled
    TA0CCR0 = 2000;

    TA0CTL = TASSEL__SMCLK | MC__UP;        // SMCLK, UP mode

    for(i = 0; i < n; ++i) {
        while((TA0R < 1000 && i <n) || TA0R < t);
        TA0R = TACLR;
    }

    TA0CTL = MC__STOP;

    return;
}



