//############################################################################
//
// File:   		dsp_sensorhead_types.h
// Version:		0.1
//
// Description:	Structure and variable definitions.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################
#ifndef DSP_SENSORHEAD_TYPES_H
#define DSP_SENSORHEAD_TYPES_H

#include "dsp_types.h"
#include "dsp_quat.h"
#include "dsp_matrix.h"


#define     SUCCESS                    (1 == 1)
#define	    FAIL                       (0 == 1)
#define		MAG_UPDATE					0
#define		ACCEL_UPDATE				1
															// Original values
#define		ACCEL_VARIANCE				223.59E-4f			// 223.59E-6 [223.59E-9]
#define		GYRO_VARIANCE				68.81E-5f			// 68.81E-5 [68.81E-6]
#define		GYRO_BIAS_VARIANCE			201.93E-3f			// 201.93E-6
#define		MAGNETO_VARIANCE			48.12E-5f			// 48.12E-6
#define		GPS_VARIANCE				1.6E-3f				// 1.6E-3
#define		QUATERNION_NORM_VARIANCE	1.0E-9f				// 1.6E-3

#define 	ACCEL_SCALE_FACTOR			0.03830859375f	// -> (9.807)*(1/256) [g]
#define 	GYRO_SCALE_FACTOR_DEG		0.06956521739f	// -> 1/14.375	[deg]
#define 	GYRO_SCALE_FACTOR_RAD		0.00121414208f	// -> (1/14.375)*(3.14159/180)	[rad]
#define 	MAG_SCALE_FACTOR			0.00151515151f	// -> 1/660

#define 	RAD2DEG						57.2957795130f
#define 	DEG2RAD						0.01745329251f
#define 	KM2M						0.27777777778f

//#define 	ABS_PRESSURE_SCALE_FACTOR		// -> Transfer function
//#define 	DIFF_PRESSURE_SCALE_FACTOR		// -> Transfer function


/* Structure for holding raw sensor data */
typedef struct sensor_data_raw{
	int16_t gyro_x;
	int16_t gyro_y;
	int16_t gyro_z;

	int16_t new_gyro_data;

	int16_t accel_x;
	int16_t accel_y;
	int16_t accel_z;

	// Flag specifies whether there is new accel data in the sensor data structure
	int16_t new_accel_data;

	int16_t mag_x;
	int16_t mag_y;
	int16_t mag_z;

	// Flag specifies whether there is new magnetometer data in the sensor data structure
	int16_t new_mag_data;

	// Rate gyro temperature measurement
	int16_t gyro_temperature;

	int32_t abs_pressure;
	int16_t new_abs_pressure_data;

	int16_t diff_pressure;
	int16_t new_diff_pressure_data;

} sensor_data_raw_t;

/* Structure for holding scaled sensor data */
typedef struct {
	float gyro_x;
	float gyro_y;
	float gyro_z;

	float accel_x;
	float accel_y;
	float accel_z;

	float mag_x;
	float mag_y;
	float mag_z;

	float gyro_temperature;

	float abs_pressure;
	float baro_altitude;

	float diff_pressure;
	float airspeed;

	/* GPS data */

	/* Latitude */
	int16_t gps_lat_deg;
	uint32_t gps_lat_min;
	uint8_t gps_lat_sector;

	/* Longitude */
	int16_t gps_lon_deg;
	uint32_t gps_lon_min;
	uint8_t gps_lon_sector;

	/* Altitude */
	int32_t gps_alt;

	/* Speed */
	int32_t gps_speed;
	int32_t gps_course;

	/* Time */
	uint16_t gps_hour;
	uint16_t gps_min;
	float gps_sec;

	// Status
	uint16_t gps_position_fix_status;
	uint16_t gps_no_sv;
	float gps_hdop;
	uint16_t gps_new_message;

} sensor_data_scaled_t;

// Structure for storing AHRS states and other data related to state computation
// This structure is, in a way, redundant because all this data is also stored in the
// UM6_config or UM6_data structures.  However, in the config and data strucutres, the
// data is packaged as UInt32 entries into an array for convenience with communication.
// To use the data as floats, special formatting is required.  This structure provides
// a place to store that data in the expected format, which makes accessing it easier.
typedef struct {

	/* Attitude states */
	float psi;
	float theta;
	float phi;

	/* Angle rate states */
	float psi_dot;
	float theta_dot;
	float phi_dot;

	/* Quaternion states "qib" = Quaternion from Inertial to Body */
	quat qib;
	quat quat_debug;

	/* Gyro biases */
	float bias_p;
	float bias_q;
	float bias_r;

	/* Accelerometer biases */
	float bias_accel_x;
	float bias_accel_y;
	float bias_accel_z;

	/* Magnetometer biases */
	float bias_mag_x;
	float bias_mag_y;
	float bias_mag_z;

	/* State Transition Matrix (jacobian of system matrix 'f') */
	fMatrix jac_f;

	/* Linearized measurement equation (jacobian of output equation 'h') */
	fMatrix jac_h;

	/* Measurement noise matrix */
	fMatrix R;

	/* Auxiliary construction measurement matrix for phi and theta angles. */
	fMatrix R_phi_theta;

	/* Auxiliary construction measurement matrix for psi angle. */
	fMatrix R_psi;

	/* Process noise matrix */
	fMatrix Q;

	/* Accelerometer alignment matrix */
	fMatrix accel_align_mat;

	/* Gyro alignment matrix */
	fMatrix gyro_align_mat;

	/* Magnetometer calibration matrix */
	fMatrix mag_align_mat;

	// Error covariance matrix
	fMatrix P;

	/* Magnetic field reference vector */
	float mag_ref_x;
	float mag_ref_y;
	float mag_ref_z;

	/* Accelerometer reference vector */
	float accel_ref_x;
	float accel_ref_y;
	float accel_ref_z;

	/* Accelerometer variance */
	float accel_var;

	/* Gyrometer variance */
	float gyro_var;

	/* Gyro bias variance */
	float gyro_bias_var;

	/* Magnetometer variance */
	float mag_var;

	/* GPS velocity variance */
	float gps_var;

	float U;
	float V;
	float W;
	float U_ant;
	float V_ant;
	float W_ant;
	float U_dot;
	float V_dot;
	float W_dot;

	float temperature;
	// Time sampling
	float Ts;				// In seconds

	float debug_misc[5];

	// GPS stuffs
	float GPS_north;		// In meters
	float GPS_east;
	float GPS_h;
	float GPS_h_ant;
	float GPS_speed;		// In m/s
	float GPS_speed_ant;	// past speed
	float GPS_heading;		// In m/s
	float GPS_Ts;

	float GPS_lat_home;
	float GPS_lon_home;
	float GPS_alt_home;
} ahrs_states_t;


// Structure for holding raw sensor data
typedef struct {
	// input
	float xk[9];
	float xk_1[9];
	float xk_2[9];
	// output
	float yk[9];
	float yk_1[9];
	float yk_2[9];

	float a[5];	// denominator coefficient
	float b[5];	// numerator coefficient

} digital_filter_data_t;

void compute_euler_angles( ahrs_states_t* estimated_states );

void unroll_states( ahrs_states_t* states );

#endif
