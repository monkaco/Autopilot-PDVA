#include "dsp_sensorhead_types.h"
#include "dsp_conversions.h"


/*******************************************************************************
* Function Name  : apply_sensors_scale_factor
* Input          : sensor_data_raw_t* sensor_data
* Output         : ahrs_state_data_t* estimated_states
* Return         : None
* Description    :

Converts the raw sensor data in sensor_data to actual data (angular rates,
acceleration in gravities, etc. and stores in state_data.  Also performs
calibration functions.

*******************************************************************************/
void apply_sensors_scale_factor (sensor_data_scaled_t* scaled_data, sensor_data_raw_t* raw_data)
{
//    float aux_mag_x, aux_mag_y, aux_mag_z;
//    float scaleFactor_SI;                // Scale factor for Soft-Iron correction
//    float theta_SI;                    // Rotation angle for Soft-Iron correction
//    float rotMx, rotMy, rotMxCorr;    // Auxilary variables for Soft-Iron correction
//    float gps_ground_speed_kph, gps_heading_rad, V_N, V_E, V_D;
//    float sin_phi, cos_phi, sin_the, cos_the, sin_psi, cos_psi;
//
//
//    sin_phi = sin(DEG2RAD*scaled_data->phi);
//    cos_phi = cos(DEG2RAD*scaled_data->phi);
//    sin_the = sin(DEG2RAD*scaled_data->theta);
//    cos_the = cos(DEG2RAD*scaled_data->theta);
////    Using heading angle from GPS as psi angle
////    sin_psi = sin(DEG2RAD*scaled_data->psi);
////    cos_psi = cos(DEG2RAD*scaled_data->psi);
//
//    // Soft-Iron parameters
//    //        theta: 0.7243
//    //        scaleFactor: 1.2538
//    theta_SI = -0.1529;
//    scaleFactor_SI = 1.2131;
//
//    // Converts accel count unit to the physical quantity units
//    scaled_data->accel_x = (float)raw_data->accel_x*(-ACCEL_SCALE_FACTOR);
//    scaled_data->accel_y = (float)raw_data->accel_y*(-ACCEL_SCALE_FACTOR);
//    scaled_data->accel_z = (float)raw_data->accel_z*(-ACCEL_SCALE_FACTOR);
//
//    // Converts gyro count unit to the physical quantity units
//    scaled_data->gyro_x = (float)raw_data->gyro_x*GYRO_SCALE_FACTOR_RAD;
//    scaled_data->gyro_y = (float)raw_data->gyro_y*GYRO_SCALE_FACTOR_RAD;
//    scaled_data->gyro_z = (float)raw_data->gyro_z*GYRO_SCALE_FACTOR_RAD;
//
//    // Converts magneto count unit to the physical quantity units
//    aux_mag_x = (float)raw_data->mag_x*MAG_SCALE_FACTOR;
//    aux_mag_y = (float)raw_data->mag_z*MAG_SCALE_FACTOR;    // Eixo-y trocado com o
//    aux_mag_z = (float)raw_data->mag_y*MAG_SCALE_FACTOR;    // eixo-z
//    // Hard-Iron Correction for magnetometers
//    aux_mag_x = aux_mag_x + 0.0500;
//    aux_mag_y = aux_mag_y - 0.0515;
//
//    // Soft-Iron Correction for magnetometers
//    rotMx = aux_mag_x*cos(theta_SI) + aux_mag_y*sin(theta_SI);
//    rotMy = aux_mag_y*cos(theta_SI) - aux_mag_x*sin(theta_SI);
//    // Rotation matrix correction
//    rotMxCorr = rotMx/scaleFactor_SI;
//    // rotate back to original position
//    scaled_data->mag_x = rotMxCorr*cos(-theta_SI) + rotMy*sin(-theta_SI);
//    scaled_data->mag_y = rotMy*cos(-theta_SI) - rotMxCorr*sin(-theta_SI);
//    scaled_data->mag_z = aux_mag_z;
//
//
//    // GPS data should be updated only if there is new GPS message
//    if (raw_data->new_GPS_data)
//    {
//        raw_data->new_GPS_data = 0; // this variable is set in Process_GPS();
//
//        scaled_data->GPS_h = (float)raw_data->GPS_altitude;
//
//        // Saturation speed
//        if( raw_data->GPS_speed < 10.0 )
//        {
//            gps_ground_speed_kph = 0.0;
//            gps_heading_rad = 0.0;
//        }
//        else
//        {
//            gps_ground_speed_kph = (float)raw_data->GPS_speed;
//            gps_heading_rad = (float)raw_data->GPS_course*DEG2RAD;
//        }
//
//        scaled_data->GPS_heading = gps_heading_rad;
//
//        sin_psi = sin(gps_heading_rad);
//        cos_psi = cos(gps_heading_rad);
//
//        V_N = (float)KM2M*gps_ground_speed_kph*cos(gps_heading_rad);
//        V_E = (float)KM2M*gps_ground_speed_kph*sin(gps_heading_rad);
//        V_D = (float)(scaled_data->GPS_h - scaled_data->GPS_h_ant)/scaled_data->GPS_Ts;
//
//        scaled_data->U = cos_psi*cos_the*V_N + sin_psi*cos_the*V_E - sin_the*V_D;
//        scaled_data->V = (-sin_psi*cos_phi + cos_psi*sin_the*sin_phi)*V_N + (cos_psi*cos_phi + sin_psi*sin_the*sin_phi)*V_E + cos_the*sin_phi*V_D;
//        scaled_data->W = (sin_psi*sin_phi + cos_psi*sin_the*cos_phi)*V_N + (-cos_psi*sin_phi + sin_psi*sin_the*cos_phi)*V_E + cos_the*cos_phi*V_D;
//
//        scaled_data->U_dot = (scaled_data->U - scaled_data->U_ant)/scaled_data->GPS_Ts;
//        scaled_data->V_dot = (scaled_data->V - scaled_data->V_ant)/scaled_data->GPS_Ts;
//        scaled_data->W_dot = (scaled_data->W - scaled_data->W_ant)/scaled_data->GPS_Ts;
//
//        // Update past variables
//        scaled_data->GPS_h_ant = scaled_data->GPS_h;
//        scaled_data->U_ant = scaled_data->U;
//        scaled_data->V_ant = scaled_data->V;
//        scaled_data->W_ant = scaled_data->W;
//    }
}


