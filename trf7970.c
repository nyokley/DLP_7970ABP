/*
 * trf7970.c
 *
 *  Created on: Feb 21, 2018
 *      Author: Nathaniel
 */

#include <msp430fr5994.h>
#include "mcu.h"
#include "trf7970.h"
#include "spi.h"


void trf7970_init() {
        IRQ_SHOULD_READ = 0;
        IRQ_STAT = 0;

        // De-assert the Slave Select
        SS_HIGH;
        // The TRF79x0 requires a low to high transition on the Enable Line.
        EN_LOW;
        __delay_cycles(40000);
        // Set EN = 1 on the TRF 79xx
        EN_HIGH;

        SPI_directCommand(0x03);        //Soft reset
        SPI_directCommand(0x00);        //idle mode
        __delay_cycles(4000);   //1ms

        SPI_directCommand(0x0F);    //clear fifo
        SPI_writeSingle(0x30, 0x09);    //mod/sys_clk settings
        SPI_writeSingle(0x00, 0x18);
        SPI_writeSingle(0x20, 0x00);    //set to 3v mode

        SPI_writeSingle(0xB8, 0x01);    //write to IRQ control register

}



