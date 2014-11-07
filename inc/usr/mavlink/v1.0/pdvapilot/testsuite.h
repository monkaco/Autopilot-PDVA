/** @file
 *	@brief MAVLink comm protocol testsuite generated from pdvapilot.xml
 *	@see http://qgroundcontrol.org/mavlink/
 */
#ifndef PDVAPILOT_TESTSUITE_H
#define PDVAPILOT_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL
static void mavlink_test_common(uint8_t, uint8_t, mavlink_message_t *last_msg);
static void mavlink_test_pdvapilot(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_common(system_id, component_id, last_msg);
	mavlink_test_pdvapilot(system_id, component_id, last_msg);
}
#endif

#include "../common/testsuite.h"


static void mavlink_test_sensor_head_data(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sensor_head_data_t packet_in = {
		963497464,
	}963497672,
	}963497880,
	}963498088,
	}{ 129.0, 130.0, 131.0 },
	}963498920,
	}18899,
	}19003,
	}19107,
	}19211,
	}19315,
	}{ 19419, 19420, 19421 },
	}{ 19731, 19732, 19733 },
	}20043,
	}{ 20147, 20148, 20149 },
	}20459,
	}20563,
	}20667,
	};
	mavlink_sensor_head_data_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.time_gps_ms = packet_in.time_gps_ms;
        	packet1.lat_gps = packet_in.lat_gps;
        	packet1.lon_gps = packet_in.lon_gps;
        	packet1.alt_gps = packet_in.alt_gps;
        	packet1.altitude = packet_in.altitude;
        	packet1.hdg_gps = packet_in.hdg_gps;
        	packet1.speed_gps = packet_in.speed_gps;
        	packet1.pos_fix_gps = packet_in.pos_fix_gps;
        	packet1.nosv_gps = packet_in.nosv_gps;
        	packet1.hdop_gps = packet_in.hdop_gps;
        	packet1.gyro_temp = packet_in.gyro_temp;
        	packet1.dyn_press = packet_in.dyn_press;
        	packet1.stat_press = packet_in.stat_press;
        	packet1.airspeed = packet_in.airspeed;
        
        	mav_array_memcpy(packet1.att_est, packet_in.att_est, sizeof(float)*3);
        	mav_array_memcpy(packet1.acc, packet_in.acc, sizeof(int16_t)*3);
        	mav_array_memcpy(packet1.gyro, packet_in.gyro, sizeof(int16_t)*3);
        	mav_array_memcpy(packet1.mag, packet_in.mag, sizeof(int16_t)*3);
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sensor_head_data_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sensor_head_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sensor_head_data_pack(system_id, component_id, &msg , packet1.time_gps_ms , packet1.lat_gps , packet1.lon_gps , packet1.alt_gps , packet1.hdg_gps , packet1.speed_gps , packet1.pos_fix_gps , packet1.nosv_gps , packet1.hdop_gps , packet1.acc , packet1.gyro , packet1.gyro_temp , packet1.mag , packet1.dyn_press , packet1.stat_press , packet1.att_est , packet1.airspeed , packet1.altitude );
	mavlink_msg_sensor_head_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sensor_head_data_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.time_gps_ms , packet1.lat_gps , packet1.lon_gps , packet1.alt_gps , packet1.hdg_gps , packet1.speed_gps , packet1.pos_fix_gps , packet1.nosv_gps , packet1.hdop_gps , packet1.acc , packet1.gyro , packet1.gyro_temp , packet1.mag , packet1.dyn_press , packet1.stat_press , packet1.att_est , packet1.airspeed , packet1.altitude );
	mavlink_msg_sensor_head_data_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sensor_head_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sensor_head_data_send(MAVLINK_COMM_1 , packet1.time_gps_ms , packet1.lat_gps , packet1.lon_gps , packet1.alt_gps , packet1.hdg_gps , packet1.speed_gps , packet1.pos_fix_gps , packet1.nosv_gps , packet1.hdop_gps , packet1.acc , packet1.gyro , packet1.gyro_temp , packet1.mag , packet1.dyn_press , packet1.stat_press , packet1.att_est , packet1.airspeed , packet1.altitude );
	mavlink_msg_sensor_head_data_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_sensor_head_command(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
	mavlink_sensor_head_command_t packet_in = {
		17235,
	}17339,
	}17443,
	}17547,
	};
	mavlink_sensor_head_command_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        	packet1.aileron = packet_in.aileron;
        	packet1.elevator = packet_in.elevator;
        	packet1.throttle = packet_in.throttle;
        	packet1.rudder = packet_in.rudder;
        
        

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sensor_head_command_encode(system_id, component_id, &msg, &packet1);
	mavlink_msg_sensor_head_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sensor_head_command_pack(system_id, component_id, &msg , packet1.aileron , packet1.elevator , packet1.throttle , packet1.rudder );
	mavlink_msg_sensor_head_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sensor_head_command_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.aileron , packet1.elevator , packet1.throttle , packet1.rudder );
	mavlink_msg_sensor_head_command_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
        	comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
	mavlink_msg_sensor_head_command_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
	mavlink_msg_sensor_head_command_send(MAVLINK_COMM_1 , packet1.aileron , packet1.elevator , packet1.throttle , packet1.rudder );
	mavlink_msg_sensor_head_command_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_pdvapilot(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
	mavlink_test_sensor_head_data(system_id, component_id, last_msg);
	mavlink_test_sensor_head_command(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // PDVAPILOT_TESTSUITE_H
