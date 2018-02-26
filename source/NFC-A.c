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

//performs initial rf collision
//returns true if no collision, false if collision
bool collision_initial() {
    uint8_t rssi_level;

    //write 0x02 to 0x00 to enable receiver and set in 3v mode
    SPI_writeSingle(0x02, 0x00);

    //write direct command 0x19 to test external rf
    SPI_directCommand(0x19);

    //delay 50us to measure field strength and set RSSI register
    delay_us(50);

    //read 0x0F RSSI levels register
    SPI_readSingle(&rssi_level, 0x0F)

    //check bits 2-0 active channel RSSI value. If greater than 0, stay
    //in target mode (return false). Else, go into initiator/target mode
    //(return true)
    rssi_level &= 0x07;     //get bits 2-0
    if(rssi_level > 0) return false;
    else if(rssi_level == 0) return true;


}


