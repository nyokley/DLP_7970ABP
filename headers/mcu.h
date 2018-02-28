/*
 * mspfr5994.c
 *
 *  Created on: Feb 21, 2018
 *      Author: Nathaniel
 */

#ifndef MCU_H
#define MCU_H

extern _Bool READ_VALUE;

//Tx Button - P5.5
#define txBtn_SETDIR          P5DIR &= ~BIT5
#define txBtn_REN             P5REN |= BIT5      //disable pullup resistor
#define txBtn_IE              P5IE |= BIT5      //interrupt enable
#define txBtn_IES_RISING      P5IES &= ~BIT5      //Interrupt edge select - rising
#define txBtn_IES_FALLING     P5IES |= BIT5       //interrupt edge select - falling
#define txBtn_IFG_CLR         P5IFG &= ~BIT5      //IFG cleared
#define txBtn_HIGH            P5OUT |= BIT5
#define txBtn_LOW             P5OUT &= ~BIT5

//IRQ - P6.3
#define IRQ_SETDIR          P6DIR &= ~BIT3
#define IRQ_RDIS            P6REN &= ~BIT3      //disable pullup resistor
#define IRQ_IE              P6IE |= BIT3        //interrupt enable
#define IRQ_IES_RISING      P6IES &= ~BIT3      //Interrupt edge select - rising
#define IRQ_IES_FALLING     P6IES |= BIT3       //interrupt edge select - falling
#define IRQ_IFG_CLR         P6IFG &= ~BIT3      //IFG cleared
#define IRQ_HIGH            P6OUT |= BIT3
#define IRQ_LOW             P6OUT &= ~BIT3

//Slave Select - P7.1
#define SS_SETDIR       P7DIR |= BIT1
#define SS_HIGH         P7OUT |= BIT1
#define SS_LOW          P7OUT &= ~BIT1

//EN - P7.0
#define EN_SETDIR       P7DIR |= BIT0
#define EN_HIGH         P7OUT |= BIT0
#define EN_LOW          P7OUT &= ~BIT0

void mcu_init();
void xt1_init();


#endif /* MCU_H */
