#ifndef GUMSTIX_H
#define GUMSTIX_H

// Gumstix variables
extern char gtx_msg_ind_in;			// Variable to index Gumstix_Message_in
extern char gtx_msg_ind_out;		// Variable to index Gumstix_Message_out
extern uint16_t Gumstix_Message_in[MAVLINK_MAX_PACKET_LEN];
extern uint16_t Gumstix_Message_out[MAVLINK_MAX_PACKET_LEN];



// Gumstix functions
void SPI_Gumstix_write( ahrs_states_t* ekf_states, sensor_data_raw_t* i2c_dat);

int SPI_Gumstix_read();

#endif  // GUMSTIX_H 
