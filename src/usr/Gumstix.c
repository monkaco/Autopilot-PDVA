#include "DSP2833x_Device.h"
#include "Application_Control_Variables.h"
#include "dsp_sensorhead_types.h"
#include "Gumstix.h"
#include "dsp_i2c.h"
//#include "Tradutor_NMEA.h"


#include "mavlink_bridge.h"

uint16_t Gumstix_Message_in[MAVLINK_MAX_PACKET_LEN];
uint16_t Gumstix_Message_out[MAVLINK_MAX_PACKET_LEN];

mavlink_sensor_head_command_t command;


mavlink_system_t mavlink_system;

// Write message on 'Gumstix_Message_out'
void SPI_Gumstix_write (ahrs_states_t* ekf_states, sensor_data_scaled_t* scaled_data)
{
	int i, bytes;
	uint16_t *u;


	mavlink_sensor_head_data_t dp;
	mavlink_message_t msg;

    mavlink_system.sysid = 0;
    mavlink_system.compid = MAV_COMP_ID_IMU;
    mavlink_system.type = MAV_TYPE_FIXED_WING;
    mavlink_system.state = MAV_STATE_BOOT;
    mavlink_system.mode = MAV_MODE_PREFLIGHT;
    mavlink_system.nav_mode = 0;


    memset(&dp, 0, sizeof(dp));

	// Attitude
	dp.att_est[0] = DEG2RAD * ekf_states->phi;
	dp.att_est[1] = DEG2RAD * ekf_states->theta;
	dp.att_est[2] = DEG2RAD * ekf_states->psi;

	// Airspeed
	dp.airspeed = scaled_data->diff_pressure; //TODO: must be implemented
	// Altitude
	dp.altitude = (int32)(scaled_data->abs_pressure); //TODO: must be implemented

	// Accelerometer (correcting sign)
	dp.acc[0] = - scaled_data->accel_x;
	dp.acc[1] = - scaled_data->accel_y;
	dp.acc[2] = - scaled_data->accel_z;
	// Gyrometer
	dp.gyro[0] = scaled_data->gyro_x;
	dp.gyro[1] = scaled_data->gyro_y;
	dp.gyro[2] = scaled_data->gyro_z;
	dp.gyro_temp = (int16) scaled_data->gyro_temperature;
	// Magnetometer (correcting axes)
	dp.mag[0] = scaled_data->mag_z;
	dp.mag[1] = - scaled_data->mag_x;
	dp.mag[2] = scaled_data->mag_y;
	// Absolute pressure
	dp.stat_press = scaled_data->abs_pressure;
	// Differential pressure
	dp.dyn_press = scaled_data->diff_pressure;
	// GPS data
	dp.time_gps_ms = (int32)(scaled_data->gps_sec*1000) + 60000* ((int32)scaled_data->gps_min + 60*(int32)scaled_data->gps_hour); // Time in ms
	dp.lat_gps = (int32)(scaled_data->gps_lat_min * 1.0e7 / 60.0) + scaled_data->gps_lat_deg * 10000000;     // Latitude deg*1e7
	dp.lon_gps = (int32)(scaled_data->gps_lon_min * 1.0e7 / 60.0) + scaled_data->gps_lon_deg * 10000000;   // Longitude deg*1e7
	dp.alt_gps = (int32)(scaled_data->gps_alt*1000);                                                         // Altitude
	dp.speed_gps = (unsigned short)(scaled_data->gps_speed*100);                                                          // Speed Over Ground
	dp.hdg_gps = (int16)(scaled_data->gps_course*1000);                                                           // True course (heading)
	dp.pos_fix_gps = scaled_data->gps_position_fix_status;                                                        // Position Fix Status
	dp.nosv_gps = scaled_data->gps_no_sv;                                                                          // Number of Satellites Used
	dp.hdop_gps = (int16)(scaled_data->gps_hdop*100);                                                             // Horizontal Dilution of Precision

	/*printf("att_est %f %f %f\n", dp.att_est[0], dp.att_est[1], dp.att_est[2]);
	printf("airspeed %u\n", dp.airspeed);
	printf("altitude %ld\n", dp.altitude);
	printf("acc %d %d %d\n", dp.acc[0], dp.acc[1], dp.acc[2]);
	printf("gyro %d %d %d\n", dp.gyro[0], dp.gyro[1], dp.gyro[2]);
	printf("gyro_temp %d\n", dp.gyro_temp);
	printf("mag %d %d %d\n", dp.mag[0], dp.mag[1], dp.mag[2]);
	printf("stat_press %d\n", dp.stat_press);
	printf("dyn_press %d\n", dp.dyn_press);
	printf("time_gps_ms %ld\n", dp.time_gps_ms);
	printf("lat_gps %ld\n", dp.lat_gps);
	printf("lon_gps %ld\n", dp.lon_gps);
	printf("alt_gps %ld\n", dp.alt_gps);
	printf("speed_gps %u\n", dp.speed_gps);
	printf("hdg_gps %d\n", dp.hdg_gps);
	printf("pos_fix_gps %d\n", dp.pos_fix_gps);
	printf("nosv_gps %d\n", dp.nosv_gps);
	printf("hdop_gps %d\n", dp.hdop_gps);*/


	memset(Gumstix_Message_out, 0, sizeof(Gumstix_Message_out));
	//memset(Gumstix_Message_out, 0x0f07, sizeof(Gumstix_Message_out));

	create_message(mavlink_system.sysid, mavlink_system.compid, GUMSTIX_COMM_CHANNEL, Gumstix_Message_out, &dp);

	bytes = (MAVLINK_MSG_ID_SENSOR_HEAD_DATA_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES)/2;
/*
	for(i=0; i<bytes; ++i){
		if(i%10==0)
			printf("\n");
		//c = (int32) Gumstix_Message_out[i];
		printf("%u, %u; ", (Gumstix_Message_out[i]) & 0xff, (Gumstix_Message_out[i] >> 8) & 0xff);
	}
	printf("\n");
	printf("\nSTART DP\n");
	u = (uint16_t *) &dp;
	for(i=0; i<(int)sizeof(dp); ++i){
		if(i%10==0)
			printf("\n");
		//c = (int32) Gumstix_Message_out[i];
		printf("%u, %u; ", (*u) & 0xff, (*u >> 8) & 0xff);
		u++;
	}
	printf("\nEND DP\n");
*/

	scaled_data->gps_new_message = 0;
}

// Read from 'Gumstix_Message_in' and translate message to variable 'command'.
int SPI_Gumstix_read(){
	mavlink_message_t msg;
	mavlink_status_t status;
	int i;
	uint16_t buffer[MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES];

	//if(Gumstix_Message_in[0] != 0xfe)
	//	return -1;

	memset(buffer, 0, sizeof(buffer));

	//printf("\nGUMSTIX_INFORMATION: Reading new message...\n");

	mavlink_reset_channel_status(GUMSTIX_COMM_CHANNEL);

	for (i = 0; i < MAVLINK_MSG_ID_SENSOR_HEAD_COMMAND_LEN + MAVLINK_NUM_NON_PAYLOAD_BYTES; i++){
		if(i%2==0){
			buffer[i/2] |= Gumstix_Message_in[i];
		}else{
			buffer[i/2] |= Gumstix_Message_in[i] << 8;
		}
				//if(i%10==0)
				//	printf("\n");

				//printf("%d=%d,", i, (int)Gumstix_Message_in[i]);
	}
	if(parse_message(buffer, &command)){
	    //Retrieve the message payload and return

		printf("\nGUMSTIX_INFORMATION: New message read\n");
		//printf("\nAileron %u, Elevator %u, Throttle %u, Rudder %u.\n", command.aileron, command.elevator, command.throttle, command.rudder);
	    // SUCCESS
	    return 0;
	}

	//printf("\nGUMSTIX_INFORMATION: Failed to parse message...\n");
	// FAIL
	return -1;

}
