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

 _Bool IRQ_SHOULD_READ = 0;
uint8_t IRQ_STAT = 0;

int main(void)
{
    _Bool collision_check;
    uint8_t temp = 0;
    uint8_t irq = 0;
    uint8_t iso_ctrl = 0;
    uint8_t rssi_level = 0;

    uint8_t bytes[1];
    bytes[0] = 0xA;


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


	while(1) {
	    initiator_sendPacket(bytes, 1);
	    SPI_readSingle(&temp, 0x00);        //check control register, shouldn't be 0x02
        delay_us(10000);
	}




	return 0;
}
