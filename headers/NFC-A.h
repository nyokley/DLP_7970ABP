/*
 * NFC-A.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Nathaniel
 */

#ifndef NFC_A_H_
#define NFC_A_H_

_Bool collision_initial();
void reset_after_command();
void initiator_sendPacket(uint8_t bytes[], int len);
void target_sendPacket(uint8_t bytes[], int len);



#endif /* NFC_A_H_ */
