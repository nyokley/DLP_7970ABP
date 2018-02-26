/*
 * spi.c
 *
 *  Created on: Feb 21, 2018
 *      Author: Nathaniel
 */

#include <msp430.h>
#include <stdint.h>
#include "headers/mcu.h"
#include "headers/spi.h"
#include "headers/trf7970.h"

void uscib1_init() {
    // Configure USCI_B1 for SPI operation
    UCB1CTLW0 = UCSWRST;                    // **Put state machine in reset**
    UCB1CTLW0 |= UCMST| UCSYNC | UCMSB ; // 3-pin, 8-bit SPI master
    UCB1CTLW0 &= ~UCCKPL & ~UCCKPH;
                                            // Clock polarity active high, phase change first, MSB
    UCB1CTLW0 |= UCSSEL__SMCLK;              // SMCLK
    UCB1BRW = 0x04;                         // /4
    //UCB1MCTLW = 0;                          // No modulation
    UCB1CTLW0 &= ~UCSWRST;                  // **Initialize USCI state machine**
   //UCB1IE |= UCRXIE;                       // Enable USCI_B1 RX interrupt
    //TXData = 0x1;                           // Holds TX data

}

void SPI_SendByte(uint8_t data){

    UCB1TXBUF = data;

    while (UCB1STAT & UCBUSY);
}

void SPI_directCommand(uint8_t command)
{
    volatile uint8_t x;

    SS_LOW;                       // Start SPI Mode

    // set Address/Command Word Bit Distribution to command
    command = command & 0b00011111;
    command = command | 0b10000000;
    
    SPI_SendByte( command );

    SS_HIGH;                      //Stop SPI Mode
}

void SPI_writeSingle(uint8_t data, uint8_t reg)
{
    volatile int8_t x;

    SS_LOW;                       // Start SPI Mode

    // Address/Command Word Bit Distribution
    // address, write, single (fist 3 bits = 0)
    reg = (0x1f &reg);              // register address

    SPI_SendByte(reg);
    SPI_SendByte(data);

    SS_HIGH;                      // Stop SPI Mode

}

void SPI_readSingle(uint8_t *pbuf, uint8_t reg)
{
    volatile uint8_t x;

    SS_LOW;                       // Start SPI Mode

    // Address/Command Word Bit Distribution
    // address, write, single (fist 3 bits = 0)
    reg = (0x1f & reg);             // register address
    reg = (0x40 | reg);             // address, read, single


    SPI_SendByte(reg);              // Previous data to TX, RX

    *pbuf = SPI_ReceiveByte();

    SS_HIGH;                      // Stop SPI Mode

}

uint8_t SPI_ReceiveByte(){

    UCB1TXBUF = 0x00;

    while (UCB1STAT & UCBUSY);

    return UCB1RXBUF;

}

void SPI_readCont(uint8_t *pbuf, uint8_t reg, uint8_t length)
{
    volatile int8_t x;

    SS_LOW;                       // Start SPI Mode

    // Address/Command Word Bit Distribution
    // address, write, single (fist 3 bits = 0)
    reg = (0x1f & reg);                 // register address
    reg = (0x60 | reg);                     // address, read, continuous
    SPI_SendByte( reg);

    while(length > 0)
    {
        *pbuf = SPI_ReceiveByte();
        pbuf++;
        length--;
    }

    SS_HIGH;                      // Stop SPI Mode

}

void SPI_writeCont(uint8_t *pbuf, uint8_t reg, uint8_t length)
{
    volatile int8_t x;

    SS_LOW;                       // Start SPI Mode

    // Address/Command Word Bit Distribution
    // address, write, single (fist 3 bits = 0)
    reg = (0x20 | reg);                 // address, write, continuous
    reg = (0x3f & reg);                 // register address

    SPI_SendByte(reg);


    while(length > 0)
    {
        SPI_SendByte(*pbuf);

        pbuf++;
        length--;

    }

    SS_HIGH;                      // Stop SPI Mode
}



