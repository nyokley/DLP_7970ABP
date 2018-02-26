/*
 * NFC-A.c - functions for the 106 kbps protocol
 *
 *  Created on: Feb 26, 2018
 *      Author: Nathaniel
 */
#include <msp430.h>
#include <stdbool.h>
#include <stdint.h>
#include "headers/mcu.h"
#include "headers/spi.h"
#include "headers/NFC-A.h"
#include "headers/timer.h"

//performs initial rf collision
//returns true if no collision, false if collision
_Bool collision_initial() {
    uint8_t rssi_level;
    uint8_t check;          //debugging

    //write 0x02 to 0x00 to enable receiver and set in 3v mode
    SPI_writeSingle(0x02, 0x00);

    SPI_readSingle(&check, 0x00);       //debugging
    //write direct command 0x19 to test external rf
    SPI_directCommand(0x19);

    //delay 50us to measure field strength and set RSSI register
    delay_us(50);

    //read 0x0F RSSI levels register
    SPI_readSingle(&rssi_level, 0x0F);

    //check bits 2-0 active channel RSSI value. If greater than 0, stay
    //in target mode (return false). Else, go into initiator/target mode
    //(return true)
    rssi_level &= 0x07;     //get bits 2-0
    if(rssi_level > 0) return false;
    else return true;



}


//resets iso registers for active initiator / target, and allows it
//to listen for other device
void reset_after_command() {
    //Turn off field by writing 0x21 to 0x01
    SPI_writeSingle(0x21, 0x01);

    //write 0x30 to 0x0A - band pass settings to RX special setting register
    SPI_writeSingle(0x30, 0x0A);

    //write 0x0F to 0x14 - FIFO IRQ Levels settings
    SPI_writeSingle(0x0F, 0x14);
}


void initiator_sendPacket(uint8_t bytes[], int len) {
    //delay time specified in technology spec (56us to 188us)
    uint8_t len_byte1;
    uint8_t len_byte2;
    delay_us(150);

    //write to ISO control register - ISO1443A @ 106kbps, with CRC
    SPI_writeSingle(0x08, 0x01);

    delay_us(1000);

    //send packet:

    //reset fifo
    SPI_directCommand(0x0F);

    //transmission with (0x11) or without (0x10) CRC
    SPI_directCommand(0x11);

    //TX length bytes - assuming all complete
    len_byte2 = ((uint8_t)len) << 4;
    len_byte1 = (uint8_t) (len>>4);
    SPI_writeSingle(len_byte1, 0x1D);       //write tx length byte 1
    SPI_writeSingle(len_byte2, 0x1E);       //write tx length byte 2

    //write command to fifo
    SPI_writeContinuous(bytes, 0x1F, len);

    //reset after transmission
    reset_after_command();
}

void target_sendPacket(uint8_t bytes[], int len) {
    //delay time specified in technology spec (56us to 188us)
    uint8_t len_byte1;
    uint8_t len_byte2;
    delay_us(150);

    //write to ISO control register - ISO1443A @ 106kbps, with CRC
    SPI_writeSingle(0x08, 0x01);

    delay_us(1000);

    //send packet:

    //reset fifo
    SPI_directCommand(0x0F);

    //transmission with (0x11) or without (0x10) CRC
    SPI_directCommand(0x11);

    //TX length bytes - assuming all complete
    len_byte2 = ((uint8_t)len) << 4;
    len_byte1 = (uint8_t) (len>>4);
    SPI_writeSingle(len_byte1, 0x1D);       //write tx length byte 1
    SPI_writeSingle(len_byte2, 0x1E);       //write tx length byte 2

    //write command to fifo
    SPI_writeContinuous(bytes, 0x1F, len);

    //reset after transmission
    reset_after_command();

}


