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
    uint8_t iso_ctrl = 0;

    uint8_t bytes[1];
    bytes[0] = 0xA;


	mcu_init();
	trf7970_init();

	//begin NFC-A
	while(1) {
	    collision_check = collision_initial();
	}

	while(!collision_initial()){
	    delay_us(10000);
	    //check for packet
	}

	while(1) {
	    reset_after_command();
	    initiator_sendPacket(bytes, 1);
        delay_us(10000);
	}




	return 0;
}
