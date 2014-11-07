//############################################################################
//
// File:   		EKF_Types.h
// Version:		0.1
//
// Description:	Structure and variable definitions.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################

#include "dsp_quat.h"
#include "dsp_matrix.h"
//#include "EKF_Funcs.h"


#ifndef _EKF_TYPES__
#define _EKF_TYPES__


#define		MAG_UPDATE					0
#define		ACCEL_UPDATE				1
															// Original values
#define		ACCEL_VARIANCE				223.59E-4			// 223.59E-6 [223.59E-9]
#define		GYRO_VARIANCE				68.81E-5			// 68.81E-5 [68.81E-6]
#define		GYRO_BIAS_VARIANCE			201.93E-3			// 201.93E-6
#define		MAGNETO_VARIANCE			48.12E-5			// 48.12E-6
#define		GPS_VARIANCE				1.6E-3				// 1.6E-3
#define		QUATERNION_NORM_VARIANCE	1.0E-9				// 1.6E-3

#define 	ACCEL_SCALE_FACTOR			0.03830859375	// -> (9.807)*(1/256) [g]
#define 	GYRO_SCALE_FACTOR_DEG		0.06956521739	// -> 1/14.375	[deg]
#define 	GYRO_SCALE_FACTOR_RAD		0.00121414208	// -> (1/14.375)*(3.14159/180)	[rad]
#define 	MAG_SCALE_FACTOR			0.00151515151	// -> 1/660

#define 	RAD2DEG						57.2957795130
#define 	DEG2RAD						0.01745329251
#define 	KM2M						0.27777777778

//#define 	ABS_PRESSURE_SCALE_FACTOR		// -> Transfer function
//#define 	DIFF_PRESSURE_SCALE_FACTOR		// -> Transfer function


// Structure for holding raw sensor data
typedef struct __RawSensorData {
	int gyro_x;
	int gyro_y;
	int gyro_z;

	int new_gyro_data;

	int accel_x;
	int accel_y;
	int accel_z;

	// Flag specifies whether there is new accel data in the sensor data structure
	int new_accel_data;

	int mag_x;
	int mag_y;
	int mag_z;

	// Flag specifies whether there is new magnetometer data in the sensor data structure
	int new_mag_data;
    
	// Rate gyro temperature measurement
	int temperature;

	// GPS stuffs
	// latitude
	int GPS_lat_deg;
	double GPS_lat_min;
	char GPS_lat_sector;
	// longitude
	int GPS_lon_deg;
	double GPS_lon_min;
	char GPS_lon_sector;
	// altitude
	double GPS_altitude;
	// speed
	double GPS_speed;
	double GPS_course;
	// time
	char GPS_hour;
	char GPS_min;
	float GPS_sec;
	// status
	char GPS_position_fix_status;
	char GPS_NoSV;
	float GPS_HDOP;

	unsigned char new_GPS_data;

} RawSensorData;


// Structure for storing AHRS states and other data related to state computation
// This structure is, in a way, redundant because all this data is also stored in the
// UM6_config or UM6_data structures.  However, in the config and data strucutres, the 
// data is packaged as UInt32 entries into an array for convenience with communication.
// To use the data as floats, special formatting is required.  This structure provides
// a place to store that data in the expected format, which makes accessing it easier.
typedef struct __AHRS_state_data {
	 
	// Attitude states
	float psi;
	float theta;
	float phi;

	// Angle rate states
	float psi_dot;
	float theta_dot;
	float phi_dot;

	// Quaternion states "qib" = Quaternion from Inertial to Body
	quat qib;
	quat quat_debug;

	// Gyro biases
	float bias_p,bias_q,bias_r;
	float debug_bp, debug_bq, debug_br;

	// Accelerometer biases
	float bias_acc_x, bias_acc_y, bias_acc_z;

	// Magnetometer biases
	float bias_mag_x, bias_mag_y, bias_mag_z;

	// State Transition Matrix (jacobian of system matrix 'f')
	fMatrix jac_f;
	
	// Linearized measurement equation (jacobian of output equation 'h')
	fMatrix jac_h;
	
	// Measurement noise matrix
	fMatrix R;

	// Auxiliary construction measurement matrix for phi and theta angles.
	fMatrix R_phi_theta;

	// Auxiliary construction measurement matrix for psi angle.
	fMatrix R_psi;

	// Process noise matrix
	fMatrix Q;

	// Accelerometer alignment matrix
	fMatrix accel_cal;

	// Gyro alignment matrix
	fMatrix gyro_cal;

	// Magnetometer calibration matrix
	fMatrix mag_cal;
		 
	// Error covariance matrix
	fMatrix P;

	// Magnetic field reference vector
	float mag_ref_x;
	float mag_ref_y;
	float mag_ref_z;

	// Accelerometer	reference vector
	float accel_ref_x;
	float accel_ref_y;
	float accel_ref_z;

	// Accelerometer variance
	float accel_var;

	// Gyrometer variance
	float gyro_var;

	// Gyro bias variance
	float gyro_bias_var;
	
	// Magnetometer variance
	float mag_var;

	// GPS velocity variance
	float GPS_var;


	// Entries for storing processed sensor data
	float gyro_x;
	float gyro_y;
	float gyro_z;

	float accel_x;
	float accel_y;
	float accel_z;
		 
	float mag_x;
	float mag_y;
	float mag_z;

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
} AHRS_state_data;


// Structure for holding raw sensor data
typedef struct __digital_filter_data {
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

} digital_filter_data;


extern RawSensorData SensorData;
extern AHRS_state_data StateData;

extern AHRS_state_data states;
extern RawSensorData sensor_dat;
extern digital_filter_data filtered_dat;

void compute_euler_angles( AHRS_state_data* estimated_states );

void unroll_states( AHRS_state_data* states );

#endif
