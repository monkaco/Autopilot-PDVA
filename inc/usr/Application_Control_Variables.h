#ifndef APPLICATION_CONTROL_VARIABLES_H
#define APPLICATION_CONTROL_VARIABLES_H

#include "DSP2833x_Device.h"

#define ___SPI_8BITS
//#define ___SPI_16BITS


//extern char *SCI_TX_Message;
//extern char SciTxQtd;			// quantity to be send
//extern char SciTxStatus;
//
//extern char *SPI_TX_Message_C;
//#ifdef ___SPI_8BITS
//extern char SPI_RX_Message[16];
//#endif
//#ifdef ___SPI_16BITS
//extern Uint16 *SPI_TX_Message_W;
//extern Uint16 SPI_RX_Message[16];
//#endif
//extern int SpiTxQtd;
//extern char SpiTxStatus;
//
//extern char line[80];
//extern char gps_in[200];
//extern char gps_in_index;
//extern char gps_in_flag;
//extern int GpsMessageReady;
//extern char NewGpsMessage;
//extern Uint32 idMessage;
//extern struct gps_data_translated gps_dat;
//
//extern char SPI_received_ok;		// It's warn when one message is received by SPI
////extern char gtx_msg_ind_in;			// Variable to index Gumstix_Message_in
////extern char gtx_msg_ind_out;		// Variable to index Gumstix_Message_out
////extern char Gumstix_Message_in[80];
////extern char Gumstix_Message_out[80];
//
//extern Uint32 Timer0_count_before, Timer0_count_after, diff;		// Timer0 counter
////extern char internal_timing;	// 0: external timing - GPS
//
//extern unsigned char I2CRead_flag;							// 1: internal timing - DSP

#endif  // APPLICATION_CONTROL_VARIABLES_H
