/*
 * trf7970.c
 *
 *  Created on: Feb 21, 2018
 *      Author: Nathaniel
 */

#include <msp430fr5994.h>
#include "headers/mcu.h"
#include "headers/trf7970.h"
#include "headers/spi.h"
#include "headers/timer.h"


void trf7970_init() {
        IRQ_SHOULD_READ = 0;
        IRQ_STAT = 0;

        // De-assert the Slave Select
        SS_HIGH;
        // The TRF79x0 requires a low to high transition on the Enable Line.
        EN_LOW;
        delay_us(10000);        //10ms
        // Set EN = 1 on the TRF 79xx
        EN_HIGH;

        SPI_directCommand(0x03);        //Soft reset
        SPI_directCommand(0x00);        //idle mode
        delay_us(1000);   //1ms

        SPI_directCommand(0x0F);        //clear fifo
        SPI_writeSingle(0x30, 0x09);    //mod/sys_clk settings
        SPI_writeSingle(0x00, 0x18);
        SPI_writeSingle(0x02, 0x00);    //set to 3v mode

        //SPI_writeSingle(0xB8, 0x01);    //write to IRQ control register

}



