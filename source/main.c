#include <msp430.h> 
#include <stdint.h>
#include "headers/mcu.h"
#include "headers/spi.h"
#include "headers/trf7970.h"
#include "headers/NFC-A.h"
#include "headers/timer.h"

/**
 * main.c
 */

_Bool READ_VALUE = 0;
_Bool IRQ_SHOULD_READ = 0;
uint8_t IRQ_STAT = 0;
uint8_t fifo_val_something = 0;

uint8_t fifo_something = 0;
uint8_t irq_something = 0;
int main(void)
{
    _Bool collision_check;
    uint8_t fifo_val = 0;

    uint8_t fifo = 0;
    uint8_t irq = 0;
    uint8_t iso_ctrl = 0;
    uint8_t rssi_level = 0;


    uint8_t bytes[1];
    bytes[0] = 0xAA;


	mcu_init();
	trf7970_init();

	//turn on rf detection
	//SPI_writeSingle(0x07, 0x18);



    /*while(1) {
    //write 0x02 to 0x00 to enable receiver and set in 3v mode
    SPI_writeSingle(0x02, 0x00);

    //write direct command 0x19 to test external rf
    SPI_directCommand(0x19);

    //delay 50us to measure field strength and set RSSI register
    delay_us(150);

    //read 0x0F RSSI levels register
    SPI_readSingle(&rssi_level, 0x0F);
    }

	//while(1) {
	//    SPI_readSingle(&temp, 0x19);
	//    SPI_readSingle(&irq, 0x0C);
	//}

	//while(1) {
	//   if(collision_initial() == false) collision_check = 1;
	//}

	//while(!collision_initial()){
	//    delay_us(10000);
	    //check for packet
	//}
    */

    //collision_initial();
	SPI_writeSingle(0x02, 0x00);

    reset_after_command();
    
    
	while(1) {
        
	    if(READ_VALUE) {
	        initiator_sendPacket(bytes, 1);
	        READ_VALUE = 0;

	    }
	        SPI_readSingle(&fifo, 0x1C);
	        SPI_readSingle(&irq, 0x0C);
	        if(fifo != 0x00) {
	            fifo_something = fifo;
	            SPI_readContinuous(&fifo_val, 0x1F, 1);
	            if(fifo_val != 0){
	                fifo_val_something = fifo_val;
	            }
	        }
	        if(irq != 0x00) {
	            irq_something = irq;
	        }

	        delay_us(1000);


	        //READ_VALUE = 0;
	       //initiator_sendPacket(bytes, 1);
            //reset_after_command();
           // START_TRANSFER = 0;


	}




	return 0;
}
