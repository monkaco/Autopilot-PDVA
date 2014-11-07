//############################################################################
//
// File:           EKF_Init.c
// Version:        0.1
//
// Description:    Function implementations of EKF.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################

#include "dsp_sensorhead_types.h"
#include "dsp_ekf.h"
#include <math.h>

// ---------------------------------------------------------------------------
// Function Name  : ekf_init
// Input          : None
// Output         : Pre-initialized state estimate structure
// Return         : None
// Description    : Fills an AHRS_states structure with zero initial values.
// ---------------------------------------------------------------------------

void ekf_init ( ahrs_states_t* estimated_states )
{
    float phi_, the_, psi_, cos_phi;
    float Ax, Ay, Az, q0, q1, q2, q3;
    float Hx, Hy, Hz, H1, H2;

    // Filter update rate
    estimated_states->Ts = 0.02F;
    // GPS update rate
    estimated_states->GPS_Ts = 0.2F;
    /*
    // Accel     
    Ax = estimated_states->accel_x;
    Ay = estimated_states->accel_y;
    Az = estimated_states->accel_z;
    // Gyro
    Hx = estimated_states->mag_x;
    Hy = estimated_states->mag_y;
    Hz = estimated_states->mag_z;
    // H1 and H2 calculations
    phi_ = atan2(Ay,Az);
    cos_phi = cos(phi_);
    the_ = atan2(-Ax*cos_phi,Az);

    H1 = Hx*cos(the_) + Hy*sin(phi_)*sin(the_) + Hz*cos(phi_)*sin(the_);
    H2 = Hy*cos(phi_) - Hz*sin(phi_);

    psi_ = atan2(H1,H2);
    */
    phi_ = 0.0F;
    the_ = 0.0F;
    psi_ = 0.0F;

    q0 = (cos(phi_ / 2) * cos(the_ / 2) * cos(psi_ / 2)) + (sin(phi_ / 2) * sin(the_ / 2) * sin(psi_ / 2));
    q1 = (sin(phi_ / 2) * cos(the_ / 2) * cos(psi_ / 2)) - (cos(phi_ / 2) * sin(the_ / 2) * sin(psi_ / 2));
    q2 = (cos(phi_ / 2) * sin(the_ / 2) * cos(psi_ / 2)) + (sin(phi_ / 2) * cos(the_ / 2) * sin(psi_ / 2));
    q3 = (cos(phi_ / 2) * cos(the_ / 2) * sin(psi_ / 2)) - (sin(phi_ / 2) * sin(the_ / 2) * cos(psi_ / 2));

     estimated_states->phi = phi_;
     estimated_states->theta = the_;
     estimated_states->psi = psi_;
     
     estimated_states->phi_dot = 0.0;
     estimated_states->theta_dot = 0.0;
     estimated_states->psi_dot = 0.0;

     estimated_states->bias_p = 0.0;
     estimated_states->bias_q = 0.0;
     estimated_states->bias_r = 0.0;

     estimated_states->accel_var = ACCEL_VARIANCE;
     estimated_states->gyro_var = GYRO_VARIANCE;
     estimated_states->gyro_bias_var = GYRO_BIAS_VARIANCE;
     estimated_states->mag_var = MAGNETO_VARIANCE;
     estimated_states->gps_var = GPS_VARIANCE;

     

    mat_create_identity( &estimated_states->P, 7, 7 );    // Error covariance matrix
    estimated_states->P.data[0][0] = 10;
    estimated_states->P.data[1][1] = 10;
    estimated_states->P.data[2][2] = 10;
    estimated_states->P.data[3][3] = 10;
    //mat_print(&estimated_states->P);
    
    mat_zero( &estimated_states->Q, 6, 6 );    // Process covariance matrix
    mat_zero( &estimated_states->R, 4, 4 );    // Measurement covariance matrix
          
    // Process covariance matrix
    estimated_states->Q.data[0][0] = estimated_states->gyro_var;
    estimated_states->Q.data[1][1] = estimated_states->gyro_var;
    estimated_states->Q.data[2][2] = estimated_states->gyro_var;
    estimated_states->Q.data[3][3] = estimated_states->gyro_bias_var;
    estimated_states->Q.data[4][4] = estimated_states->gyro_bias_var;
    estimated_states->Q.data[5][5] = estimated_states->gyro_bias_var;

    /*    TBD    
    estimated_states->R.data[0][0] = estimated_states->process_var*0.00001;
    estimated_states->R.data[1][1] = estimated_states->process_var*0.00001;
    estimated_states->R.data[2][2] = estimated_states->process_var*0.00001;
    estimated_states->R.data[3][3] = estimated_states->process_var*0.00001;
    */
     
    // Quaternions initialization
    estimated_states->qib.a = q0;
    estimated_states->qib.b = q1;
    estimated_states->qib.c = q2;
    estimated_states->qib.d = q3;
     
    // R_phi_theta
    mat_zero( &estimated_states->R_phi_theta, 12, 12 );
    estimated_states->R_phi_theta.data[0][0] = estimated_states->accel_var;
    estimated_states->R_phi_theta.data[1][1] = estimated_states->accel_var;
    estimated_states->R_phi_theta.data[2][2] = estimated_states->accel_var;
    estimated_states->R_phi_theta.data[3][3] = 2*estimated_states->gps_var;
    estimated_states->R_phi_theta.data[4][4] = 2*estimated_states->gps_var;
    estimated_states->R_phi_theta.data[5][5] = 2*estimated_states->gps_var;
    estimated_states->R_phi_theta.data[6][6] = estimated_states->gps_var;
    estimated_states->R_phi_theta.data[7][7] = estimated_states->gps_var;
    estimated_states->R_phi_theta.data[8][8] = estimated_states->gps_var;
    estimated_states->R_phi_theta.data[9][9] = estimated_states->gyro_var;
    estimated_states->R_phi_theta.data[10][10] = estimated_states->gyro_var;
    estimated_states->R_phi_theta.data[11][11] = estimated_states->gyro_var;
    // R_psi
    mat_zero( &estimated_states->R_psi, 3, 3 );
    estimated_states->R_psi.data[0][0] = estimated_states->mag_var;
    estimated_states->R_psi.data[1][1] = estimated_states->mag_var;
    estimated_states->R_psi.data[2][2] = estimated_states->mag_var;

    //CopyConfigArrayToStates();     
}


void lpf_butterworth_init (digital_filter_data_t* filtered_dat)
{
    uint16_t i;
    
    /* Numerator coefficients */
    const float coeff_a0 = 1.0000F;
    const float coeff_a1 = -1.5645F;
    const float coeff_a2 = 0.6437F;
    /* Denominator coefficients */
    const float coeff_b0 = 0.0198F;
    const float coeff_b1 = 0.0396F;
    const float coeff_b2 = 0.0198F;
    
    // denominator
    filtered_dat->a[0] = coeff_a0;
    filtered_dat->a[1] = coeff_a0;
    filtered_dat->a[2] = coeff_a0;
    // numerator
    filtered_dat->b[0] = coeff_b0;
    filtered_dat->b[1] = coeff_b1;
    filtered_dat->b[2] = coeff_b2;

        for (i = 0; i < 6 ; i++)
    {
        filtered_dat->xk[i] = 0.0F;
        filtered_dat->xk_1[i] = 0.0F;
        filtered_dat->xk_2[i] = 0.0F;
        filtered_dat->yk[i] = 0.0F;
        filtered_dat->yk_1[i] = 0.0F;
        filtered_dat->yk_2[i] = 0.0F;
    }
}

void lpf_butterworth (sensor_data_scaled_t* input_scaled_data, digital_filter_data_t* filtered_dat)
{
    uint16_t i;
    /* accel data */
    filtered_dat->xk[0] = input_scaled_data->accel_x;
    filtered_dat->xk[1] = input_scaled_data->accel_y;
    filtered_dat->xk[2] = input_scaled_data->accel_z;
    /* gyro data */
    filtered_dat->xk[3] = input_scaled_data->gyro_x;
    filtered_dat->xk[4] = input_scaled_data->gyro_y;
    filtered_dat->xk[5] = input_scaled_data->gyro_z;
    /* magneto data */
    filtered_dat->xk[6] = input_scaled_data->mag_x;
    filtered_dat->xk[7] = input_scaled_data->mag_y;
    filtered_dat->xk[8] = input_scaled_data->mag_z;


    /* xk and yk indices defines different variables */
    /* Accelerometer data */
    /* accel-x */
    filtered_dat->yk[0] = (filtered_dat->b[0] * filtered_dat->xk[0]) + (filtered_dat->b[1] * filtered_dat->xk_1[0]) + (filtered_dat->b[2] * filtered_dat->xk_2[0]) - (filtered_dat->a[1] * filtered_dat->yk_1[0]) - (filtered_dat->a[2] * filtered_dat->yk_2[0]);
    /* accel-y */
    filtered_dat->yk[1] = (filtered_dat->b[0] * filtered_dat->xk[1]) + (filtered_dat->b[1] * filtered_dat->xk_1[1]) + (filtered_dat->b[2] * filtered_dat->xk_2[1]) - (filtered_dat->a[1] * filtered_dat->yk_1[1]) - (filtered_dat->a[2] * filtered_dat->yk_2[1]);
    /* accel-z */
    filtered_dat->yk[2] = (filtered_dat->b[0] * filtered_dat->xk[2]) + (filtered_dat->b[1] * filtered_dat->xk_1[2]) + (filtered_dat->b[2] * filtered_dat->xk_2[2]) - (filtered_dat->a[1] * filtered_dat->yk_1[2]) - (filtered_dat->a[2] * filtered_dat->yk_2[2]);
    /* Gyrometer data */
    /* p */
    filtered_dat->yk[3] = (filtered_dat->b[0] * filtered_dat->xk[3]) + (filtered_dat->b[1] * filtered_dat->xk_1[3]) + (filtered_dat->b[2] * filtered_dat->xk_2[3]) - (filtered_dat->a[1] * filtered_dat->yk_1[3]) - (filtered_dat->a[2] * filtered_dat->yk_2[3]);
    /* q */
    filtered_dat->yk[4] = (filtered_dat->b[0] * filtered_dat->xk[4]) + (filtered_dat->b[1] * filtered_dat->xk_1[4]) + (filtered_dat->b[2] * filtered_dat->xk_2[4]) - (filtered_dat->a[1] * filtered_dat->yk_1[4]) - (filtered_dat->a[2] * filtered_dat->yk_2[4]);
    /* r */
    filtered_dat->yk[5] = (filtered_dat->b[0] * filtered_dat->xk[5]) + (filtered_dat->b[1] * filtered_dat->xk_1[5]) + (filtered_dat->b[2] * filtered_dat->xk_2[5]) - (filtered_dat->a[1] * filtered_dat->yk_1[5]) - (filtered_dat->a[2] * filtered_dat->yk_2[5]);
    /* Magnetometer data */
    /* mag-x */
    filtered_dat->yk[6] = (filtered_dat->b[0] * filtered_dat->xk[6]) + (filtered_dat->b[1] * filtered_dat->xk_1[6]) + (filtered_dat->b[2] * filtered_dat->xk_2[6]) - (filtered_dat->a[1] * filtered_dat->yk_1[6]) - (filtered_dat->a[2] * filtered_dat->yk_2[6]);
    /* mag-y */
    filtered_dat->yk[7] = (filtered_dat->b[0] * filtered_dat->xk[7]) + (filtered_dat->b[1] * filtered_dat->xk_1[7]) + (filtered_dat->b[2] * filtered_dat->xk_2[7]) - (filtered_dat->a[1] * filtered_dat->yk_1[7]) - (filtered_dat->a[2] * filtered_dat->yk_2[7]);
    /* mag-z */
    filtered_dat->yk[8] = (filtered_dat->b[0] * filtered_dat->xk[8]) + (filtered_dat->b[1] * filtered_dat->xk_1[8]) + (filtered_dat->b[2] * filtered_dat->xk_2[8]) - (filtered_dat->a[1] * filtered_dat->yk_1[8]) - (filtered_dat->a[2] * filtered_dat->yk_2[8]);

    for (i = 0; i < 6 ; i++)
    {
        filtered_dat->xk_1[i] = filtered_dat->xk[i];
        filtered_dat->xk_2[i] = filtered_dat->xk_1[i];
        filtered_dat->yk_1[i] = filtered_dat->yk[i];
        filtered_dat->yk_2[i] = filtered_dat->yk_1[i];
    }

    /* accel data */
    input_scaled_data->accel_x = filtered_dat->yk[0];
    input_scaled_data->accel_y = filtered_dat->yk[1];
    input_scaled_data->accel_z = filtered_dat->yk[2];
    /* gyro data */
    input_scaled_data->gyro_x = filtered_dat->yk[3];
    input_scaled_data->gyro_y = filtered_dat->yk[4];
    input_scaled_data->gyro_z = filtered_dat->yk[5];
    /* magneto data */
    input_scaled_data->mag_x = filtered_dat->yk[6];
    input_scaled_data->mag_y = filtered_dat->yk[7];
    input_scaled_data->mag_z = filtered_dat->yk[8];

}



void ekf_estimate_states( ahrs_states_t* states, sensor_data_scaled_t* scaled_data )
{
    ekf_prediction (states, scaled_data);    /* Predict states */
    ekf_correction (states, scaled_data);    /* Correct states */
}
