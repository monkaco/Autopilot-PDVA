//############################################################################
//
// File:           EKF_Funcs.h
// Version:        0.1
//
// Description:    Preprocessor definitions and function declarations for EKF 
//                calculations.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################

#ifndef DSP_EKF_H
#define DSP_EKF_H

/* Function prototypes */

void ekf_init ( ahrs_states_t* estimated_states );

/* EKF prediction functions */
void ekf_prediction (ahrs_states_t* estimated_states, sensor_data_scaled_t* scaled_data);
void ekf_stm (ahrs_states_t* estimated_states, fMatrix* stm, sensor_data_scaled_t* scaled_data);
void ekf_apriori_covariance (ahrs_states_t* estimated_states, fMatrix* F);
void ekf_apriori_estimate (ahrs_states_t* estimated_states, sensor_data_scaled_t* scaled_data);

/* EKF correction functions */
void ekf_correction (ahrs_states_t* estimated_states, sensor_data_scaled_t* scaled_data);
void ekf_h_matrix (ahrs_states_t* estimated_states, fMatrix* H);

/* General functions */
void ekf_estimate_states (ahrs_states_t* states, sensor_data_scaled_t* scaled_data);

// General functions
//void EKF_Init( ahrs_states_t* estimated_states );
//void EKF_InitFromSensors( ahrs_states_t* estimated_states, sensor_data_raw_t* sensor_data );
//void EKF_EstimateStates( ahrs_states_t* estimated_states, sensor_data_raw_t* sensor_data );
//void EKF_Predict( ahrs_states_t* estimated_states, sensor_data_raw_t* sensor_data );
//void EKF_Update( ahrs_states_t* estimated_states, sensor_data_raw_t* sensor_data );
//void EKF_Correction( fMatrix* C, float sensor_data, float sensor_hat, float sensor_covariance, ahrs_states_t* estimated_states, int sensor_type );

/* Digital filtering prototype functions */
void lpf_butterworth_init (digital_filter_data_t* filtered_dat);
void lpf_butterworth (sensor_data_scaled_t* input_scaled_data, digital_filter_data_t* filtered_dat);

#endif
