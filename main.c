#include <msp430.h> 
#include <stdint.h>
#include "mcu.h"
#include "spi.h"
#include "trf7970.h"

/**
 * main.c
 */

 _Bool IRQ_SHOULD_READ = 0;
uint8_t IRQ_STAT = 0;

int main(void)
{
    uint8_t temp = 0;
    uint8_t iso_ctrl = 0;

	mcu_init();
	/*trf7970_init();

	__delay_cycles(20000);

    SPI_writeSingle(0x20, 0x00);
    SPI_readSingle(&temp, 0x00);     //try to read from 0x00

    SPI_writeSingle(0xB8, 0x01);
    SPI_readSingle(&iso_ctrl, 0x01);
    //SPI_readSingle(&IRQ_STAT, 0x0C);
    //SPI_readSingle(&temp, 0x0D);


    SPI_readSingle(&temp, 0x00);
    SPI_readSingle(&iso_ctrl, 0x01);

    if(IRQ_SHOULD_READ) {
        SPI_readSingle(&IRQ_STAT, 0x0C);
        SPI_readSingle(&temp, 0x0D);
    }

    SPI_writeSingle(0x00, 0x1D);
    SPI_writeSingle(0x10, 0x1E);
    SPI_writeSingle(0xAB, 0x1F);
    SPI_directCommand(0x10);
    */

    //__delay_cycles(4000);                       //variables seem to be off during delay; why?

    while(1) {
        EN_HIGH;
        delay_us(20000);
        EN_LOW;
        delay_us(8000);
        EN_HIGH;
        delay_us(1000);
        EN_LOW;
        delay_us(100);
    }


	return 0;
}
