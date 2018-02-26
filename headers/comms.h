/*
 * comms.h
 *
 *  Created on: Feb 26, 2018
 *      Author: Nathaniel
 */

#ifndef HEADERS_COMMS_H_
#define HEADERS_COMMS_H_


#define CSCR 0x00   //Chip Status Control Register
  #define stby 7    //Standby Mode 1
                    //Active Mode 0
  #define direct 6  //Direct Mode 1
                    //Auto Framing 0
  #define rf_on 5   //RF output active 1
                    //RF output not active 0
  #define rf_power 4//Half output power 1
                    //Full output power 0
  #define pm_on 3   //Selects aux RX input 1
                    //Selects main RX input 0
  #define rec_on 1  //Receiver activated for external field measurement 1
                    //Auto enable 0
  #define vrs5_3 0  //5V operation 1
                    //3V operation 0
/*****************************************************************************/
#define ISOCR 0x01  //ISO Control Register
  #define rc_crc_n 7//no RX CRC 1
                    //RX CRC 0
  #define dir_mode 6//Direct Mode 1 1
                    //Direct Mode 0 0
  #define rfid 5    //NFC or card emulation mode 1
                    //RFID mode 0
  #define iso_4 4   //initiator 1
                    //target 0
  #define iso_3 3   //active mode 1
                    //passive mode 0
  #define iso_2 2   //Card Emulation Mode 1
                    //NFC Normal Modes 0
  #define iso_1 1   //bit rate selection or card emulation selection
                    //3V operation 0
  #define iso_0 0   //5V operation 1
                    //3V operation 0
/*****************************************************************************/
#define TXOR 0x02   //ISO/IEC 14443 TX Options Register
  #define egt2 7    //TX EGT time select MSB

  #define egt1 6    //TX EGT time select

  #define egt0 5    //TX EGT time select LSB

  #define eofl_0 4

  #define sof_l1 3

  #define sof_l0 2

  #define l_egt 1   //EGT after each byte 1
                    //EGT after last byte is omitted 0
  #define SSD_SAK 0 //Layer 4 compliant 1
                    //Not layer 4 compliant 0
/*****************************************************************************/
#define HBRPOR 0x03   //ISO/IEC 14443 TX Options Register
  #define dif_tx_br 7 //TX bit rate different from RX bit rate 1

  #define tx_br1 6    //TX bit rate

  #define tx_br0 5    //TX bit rate

  #define parity2tx 4 //parity odd except last byte which is even for TX 0

  #define parity2rx 3 //parity odd except last byte which is even for RX 1
/*****************************************************************************/
#define TXTHBCR 0x04//TX Timer High Byte Control Register
  #define tm_st1 7  //Timer Start Condition

  #define tm_st0 6  //Timer Start Condition

  #define tm_lengthD 5  //Timer Length MSB

  #define tm_lengthC 4  //Timer Length

  #define tm_lengthB 3  //Timer Length

  #define tm_lengthA 2  //Timer Length

  #define tm_length9 1  //Timer Length

  #define tm_length8 0  //Timer Length LSB

/*****************************************************************************/
#define TXTLBCR 0x05//TX Timer Low Byte Control Register
  #define tm_length7 7  //Timer Length MSB

  #define tm_length6 6  //Timer Length

  #define tm_length5 5  //Timer Length

  #define tm_length4 4  //Timer Length

  #define tm_length3 3  //Timer Length

  #define tm_length2 2  //Timer Length

  #define tm_length1 1  //Timer Length

  #define tm_length0 0  //Timer Length LSB
/*****************************************************************************/
#define TXPLCR 0x06//TX Pulse Length Control Register
  #define Pul_p2 7  //Pulse length MSB

  #define Pul_p1 6  //Pulse length

  #define Pul_p0 5  //Pulse length

  #define Pul_c4 4  //Pulse length

  #define Pul_c3 3  //Pulse length

  #define Pul_c2 2  //Pulse length

  #define Pul_c1 1  //Pulse length

  #define Pul_c0 0  //Pulse length LSB
/*****************************************************************************/
#define RXNRWTR 0x07//RX No Response Wait Time Register
  #define NoResp7 7 //No Response MSB

  #define NoResp6 6 //No Response

  #define NoResp5 5 //No Response

  #define NoResp4 4 //No Response

  #define NoResp3 3 //No Response

  #define NoResp2 2 //No Response

  #define NoResp1 1 //No Response

  #define NoResp0 0 //No Response LSB
/*****************************************************************************/
#define RXWTR 0x08//RX No Response Wait Time Register
  #define Rxw7 7  //RX wait time MSB

  #define Rxw6 6  //RX wait time

  #define Rxw5 5  //RX wait time

  #define Rxw4 4  //RX wait time

  #define Rxw3 3  //RX wait time

  #define Rxw2 2  //RX wait time

  #define Rxw1 1  //RX wait time

  #define Rxw0 0  //RX wait time LSB
/*****************************************************************************/
#define MSCR 0x09//RX No Response Wait Time Register
  #define MHz27 7//Enable 27.12MHz crystal (default) 1

  #define en_ook_p 6  //Enable ASK/OOK pin 12 for "on the fly" selection 1
                      //Default operation as defined by Pm[2:0]
  #define Clo1 5  //SYS_CLK output frequency MSB

  #define Clo0 4  //SYS_CLK output frequency LSB

  #define en_ana 3//Sets pin 12 (ASK/OOK) as an analog output 1
                  //Default 0
  #define Pm2 2   //Modulation depth MSB

  #define Pm1 1   //Modulation depth

  #define Pm0 0   //Modulation depth LSB
/*****************************************************************************/
#define RXSSR 0x0A//RX Special Setting Register
  #define C212 7  //Band-pass 110kHz to 570kHz

  #define C424 6  //Band-pass 200kHz to 900kHz

  #define M848 5  //Band-pass 450kHz to 1.5MHz

  #define hbt 4   //Band-pass 100kHz to 1.5MHz, Gain reduced for 18dB

  #define gd1 3   //Gain Reduction

  #define gd2 2   //Gain Reduction
/*****************************************************************************/
#define RIOCR 0x0B//Regulator and I/O Control Register
  #define auto_reg 7//Automatic setting 1
                    //Manual setting 0

  #define en_ext_pa 6//Support for external power amplifier

  #define io_low 5  //enable low peripheral communication voltage 1

  #define vrs2 2    //Voltage set MSB

  #define vrs1 1    //Voltage set

  #define vrs0 0    //Voltage set LSB
/*****************************************************************************/
#define IRQSR 0x0C  //IRQ Status Register
  #define Irq_tx 7  //IRQ set due to end of TX

  #define Irq_srx 6 //IRQ set due to RX start

  #define Irq_fifo 5//Signals the FIFO level

  #define Irq_err1 4//CRC error

  #define Irq_err2 3//Parity error

  #define Irq_err3 2//Byte framing or EOF error

  #define Irq_col 1 //Collision error

  #define Irq_noresp 0  //No response time interrupt
/*****************************************************************************/
#define IMR 0x0D    //Interupt Mask Register
  #define Col9 7    //Bit position of collision MSB

  #define Col8 6    //Bit position of collision

  #define En_irq_fifo 5 //Interrupt enable for FIFO

  #define En_irq_err1 4 //Interrupt enable for CRC

  #define En_irq_err2 3 //Interrupt enable for Parity

  #define En_irq_err3 2 //Interrupt enable for framing error or EOF

  #define En_irq_col 1  //Interrupt enable for collision error

  #define En_irq_noresp 0 //Enables no-response interrupt
/*****************************************************************************/
#define CPR 0x0E    //Collision Position Register
  #define Col7 7    //Bit position of collision MSB

  #define Col6 6    //Bit position of collision

  #define Col5 5    //Bit position of collision

  #define Col4 4    //Bit position of collision

  #define Col3 3    //Bit position of collision

  #define Col2 2    //Bit position of collision

  #define Col1 1    //Bit position of collision

  #define Col0 0    //Bit position of collision LSB
/*****************************************************************************/
#define RSSILOSR 0x0F //RSSI Levels and Oscillator Status Register
  #define osc_ok 6  //Crystal oscillator stable indicator

  #define rssi_x2 5 //MSB RSSI value of auxiliary RX (RX_IN2)

  #define rssi_x1 4 //Auxiliary channel RSSI

  #define rssi_x0 3 //MSB RSSI value of auxiliary RX (RX_IN1)

  #define rssi_2 2  //MSB RSSI value of main RX (RX_IN1)

  #define rssi_1 1  //Main channel RSSI

  #define rssi_0 0  //LSB RSSI value of main RX (RX_IN1)
/*****************************************************************************/
#define SFR0 0x10    //Special Functions Register 0
  #define par43 5   //Disables parity checking for ISO/IEC 14443 A

  #define next_slot_37us 4  //Sets the time grid for next slot command in ISO/IEC 15693

  #define Sp_dir_mode 3 //Bit stream transmit for MIFARE at 106kbps

  #define bit_4_RX 2    //Enable 4-bit replay

  #define anticoll_14 1 //Disable anticollision frames for ISO/IEC 14443 A

  #define col_7_6 0 //Selects the number of subcarrier pulses that trigger collision error
/*****************************************************************************/
#define SFR1 0x11    //Special Functions Register 1
  #define irg_srx 0 //Copy of the RX start signal (bit 6) of the IRQ Status register (0x0C)
/*****************************************************************************/
#define AFIFOIRQL 0x14  //Adjustable FIFO IRQ Levels Register
  #define Wlh_1 3   //FIFO high IRQ level (during RX)

  #define Wlh_0 2   //FIFO high IRQ level (during RX)

  #define Wll_1 1   //FIFO low IRQ level (during TX)

  #define Wll_0 0   //FIFO low IRQ level (during TX)
/*****************************************************************************/
#define NFCLFLR 0x16//NFC Low Field Level Register
  #define Clex_dis 7//Disable clock extractor

  #define Hash6 6   //N/A

  #define Hash5 5   //N/A

  #define Hash4 4   //N/A

  #define Hash3 3   //N/A

  #define Rfdet_I2 2//RF field level for RF collision avoidance

  #define Rfdet_I1 1//RF field level for RF collision avoidance

  #define Rfdet_I0 0//RF field level for RF collision avoidance
/*****************************************************************************/
#define NFCID1NR 0x17//NFCID1 Number Register
  /*This register is used to hold the ID of the TRF7970A for use during card
    emulation and NFC peer-to-peer target operations.*/

  /*The procedure for writing the ID into register 0x17 is the following:
      1. Write bits 5, 6, and 7 in register 0x18 to enable SDD anticollision
      (bit 5), and set bit 6 and 7 to select the ID length of 4, 7, or 10 bytes.
      2. Write the ID into register 0x17. This should be done using write
      continuous mode with 4, 7, or 10 bytes(according to what was set in
      register 0x18 bits 6 and 7).
/*****************************************************************************/
#define NFCTDLR 0x18//NFC Target Detection Level Register
  #define Id_s1 7   //NFCID1 size used in 106-kbps passive target SSD

  #define Id_s0 6   //NFCID1 size used in 106-kbps passive target SSD

  #define Sdd_en 5  //Enable automatic SSD using internal state machine and ID
                    //stored in NFCID1 Number Register (0x17)
  #define Hi_rf 3   //Extended range for RF measurements

  #define Rfdet_h2 2//RF field level required for system wakeup

  #define Rfdet_h1 1//RF field level required for system wakeup

  #define Rfdet_h0 0//RF field level required for system wakeup
  /*****************************************************************************/
#define NFCLFLR 0x19//NFC Target Protocol Register
  #define Rf_h 7    //RF level is above the wake-up level setting

  #define Rf_l 6    //RF level is above the RF collision avoidance level stting

  #define FeliCa 4  //FeliCa protocol 1
                    //ISO/IEC 14443 A protocol 0
  #define Pas_106 3 //Passive target at 106kbps or transponder emulation

  #define Pas_14443B 2  //ISO/IEC 14443 B transponder emulation

  #define NFCBR1 1  //Bit rate of first received command

  #define NFCBR0 0  //Bit rate of first received command
/*****************************************************************************/
#define TR0 0x1A    //Test Register 0
  #define OOK_Subc_In 7 //Subcarrier input

  #define MOD_Subc_Out 6//Subcarrier output

  #define MOD_Direct 5  //Direct TX modulation and RX reset

  #define o_sel 4   //First stage output selection

  #define low2 3    //Second stage gain –6 dB

  #define low1 2    //First stage gain –6 dB

  #define zun 1     //Input followers test

  #define Test_AGC 0//AGC test, AGC level is seen on rssi_210 bits
/*****************************************************************************/
#define TR1 0x1B    //Test Register 1
  #define test_rf_level3 7  //RF level test

  #define test_rf_level2 6  //RF level test

  #define test_rf_level1 5  //RF level test

  #define test_rf_level0 4  //RF level test

  #define test_io1 3//I/O test

  #define test_io0 2//I/O test

  #define test_dec 1//Decoder test mode

  #define clock_su 0//Coder clock 13.56 MHz
/*****************************************************************************/
#define FIFOSR 0x1C //FIFO Status Register
  #define Foverflow 7 //FIFO overflow error

  #define Fb6 6     //FIFO bytes fb[6]

  #define Fb5 5     //FIFO bytes fb[5]

  #define Fb4 4     //FIFO bytes fb[4]

  #define Fb3 3     //FIFO bytes fb[3]

  #define Fb2 2     //FIFO bytes fb[2]

  #define Fb1 1     //FIFO bytes fb[1]

  #define Fb0 0     //FIFO bytes fb[0]
/*****************************************************************************/
#define TXLB1R 0x1D //TX Length Byte 1 Register
  #define Txl11 7   //Number of complete byte bn[11]

  #define Txl10 6   //Number of complete byte bn[10]

  #define Txl9 5    //Number of complete byte bn[9]

  #define Txl8 4    //Number of complete byte bn[8]

  #define Txl7 3    //Number of complete byte bn[7]

  #define Txl6 2    //Number of complete byte bn[6]

  #define Txl5 1    //Number of complete byte bn[5]

  #define Txl4 0    //Number of complete byte bn[4]
/*****************************************************************************/
#define TXLB2R 0x1E //TX Length Byte 2 Register
  #define Txl3 7    //Number of complete byte bn[3]

  #define Txl2 6    //Number of complete byte bn[2]

  #define Txl1 5    //Number of complete byte bn[1]

  #define Txl0 4    //Number of complete byte bn[0]

  #define Bb2 3     //Broken byte number of bitsbb[2]

  #define Bb1 2     //Broken byte number of bitsbb[1]

  #define Bb0 1     //Broken byte number of bitsbb[0]

  #define Bbf 0     //Broken byte flat
/*****************************************************************************/


#endif /* HEADERS_COMMS_H_ */
