/*
 * spi.h
 *
 *  Created on: Feb 21, 2018
 *      Author: Nathaniel
 */

#include <msp430.h>
#include <stdint.h>

#ifndef SPI_H_
#define SPI_H_

void uscib1_init();
void SPI_SendByte(uint8_t data);
void SPI_directCommand(uint8_t command);
void SPI_writeSingle(uint8_t data, uint8_t reg);
void SPI_readSingle(uint8_t *pbuf, uint8_t reg);
uint8_t SPI_ReceiveByte();
void SPI_readContinuous(uint8_t *pbuf, uint8_t reg, uint8_t length);
void SPI_writeContinuous(uint8_t *pbuf, uint8_t reg, uint8_t length);






#endif /* SPI_H_ */
