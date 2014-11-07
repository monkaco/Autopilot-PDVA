//############################################################################
//
// File:           EKF_Predict.c
// Version:        0.1
//
// Description:    Implementation of EKF prediction functions.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################

#include "dsp_sensorhead_types.h"
#include "dsp_ekf.h"
#include "dsp_matrix.h"
#include <math.h>

// EKF prediction step
void ekf_prediction (ahrs_states_t* estimated_states, sensor_data_scaled_t* scaled_data)
{
    fMatrix F;

    /* Computes state transition matrix */
    ekf_stm (estimated_states, &F, scaled_data);
    
    // Computes a priori covariance matrix: 
    // P[k]_ = F[k-1]*P[k-1]*F[k-1]' + L[k-1] *Q[k-1]*L[k-1]'
    ekf_apriori_covariance (estimated_states, &F);

    ekf_apriori_estimate (estimated_states, scaled_data);
    // Continuar daqui...

    compute_euler_angles (estimated_states);
    // Quaternion normalization
    quat_norm (&estimated_states->qib);

    // debug
    estimated_states->quat_debug.a = estimated_states->qib.a;
    estimated_states->quat_debug.b = estimated_states->qib.b;
    estimated_states->quat_debug.c = estimated_states->qib.c;
    estimated_states->quat_debug.d = estimated_states->qib.d;
    // debug
}

/*******************************************************************************
* Function Name  : ekf_stm
* Input          : AHRS_states* estimated_states
* Output         : None
* Return         : None
* Description    : Computes the state transition matrix based on previous step
*                    states (quaternions, gyros and gyro biases).
*******************************************************************************/
void ekf_stm(ahrs_states_t* estimated_states, fMatrix* stm, sensor_data_scaled_t* scaled_data){

    float q0, q1, q2, q3, p, q, r, bp, bq, br,t;
    
    stm->rows = 7U;
    stm->columns = 7U;

    // quaternion variables
    q0 = estimated_states->qib.a;
    q1 = estimated_states->qib.b;
    q2 = estimated_states->qib.c;
    q3 = estimated_states->qib.d;
    // angular rates [rad/s]
    p = scaled_data->gyro_x;
    q = scaled_data->gyro_y;
    r = scaled_data->gyro_z;
    // gyro bias [rad/s]
    bp = estimated_states->bias_p;
    bq = estimated_states->bias_q;
    br = estimated_states->bias_r;
    // time sampling [s]
    t = estimated_states->Ts;

    mat_zero( stm, stm->rows, stm->columns );

    stm->data[0][0] = 1.0F;
    stm->data[0][1] = t * (bp * (1.0F / 4.0F) - (p * (1.0F / 2.0F)));
    stm->data[0][2] = t * (bq * (1.0F / 4.0F) - (q * (1.0F / 2.0F)));
    stm->data[0][3] = t * (br * (1.0F / 4.0F) - (r * (1.0F / 2.0F)));
    stm->data[0][4] = q1 * t * (1.0F / 4.0F);
    stm->data[0][5] = q2 * t * (1.0F / 4.0F);
    stm->data[0][6] = q3 * t * (1.0F / 4.0F);
    stm->data[1][0] = -t * (bp * (1.0F / 4.0F) - (p * (1.0F / 2.0F)));
    stm->data[1][1] = 1.0F;
    stm->data[1][2] = -t * (br * (1.0F / 4.0F) - (r * (1.0F / 2.0F)));
    stm->data[1][3] = t * (bq * (1.0/4.0) - (q * (1.0F / 2.0F)));
    stm->data[1][4] = q0 * t * (-1.0F / 4.0F);
    stm->data[1][5] = q3 * t * (1.0F / 4.0F);
    stm->data[1][6] = q2 * t * (-1.0F / 4.0F);
    stm->data[2][0] = -t * (bq * (1.0F / 4.0F) - (q * (1.0F / 2.0F)));
    stm->data[2][1] = t * (br * (1.0F / 4.0F) - (r * (1.0F / 2.0F)));
    stm->data[2][2] = 1.0F;
    stm->data[2][3] = -t * (bp * (1.0F / 4.0F) - (p * (1.0F / 2.0F)));
    stm->data[2][4] = q3 * t * (-1.0F / 4.0F);
    stm->data[2][5] = q0 * t * (-1.0F / 4.0F);
    stm->data[2][6] = q1 * t * (1.0F / 4.0F);
    stm->data[3][0] = -t * (br * (1.0F / 4.0F) - (r * (1.0F / 2.0F)));
    stm->data[3][1] = -t * (bq * (1.0F / 4.0F) - (q * (1.0F / 2.0F)));
    stm->data[3][2] = t * (bp * (1.0/4.0) - p * (1.0/2.0));
    stm->data[3][3] = 1.0F;
    stm->data[3][4] = q2 * t * (1.0F / 4.0F);
    stm->data[3][5] = q1 * t * (-1.0F / 4.0F);
    stm->data[3][6] = q0 * t * (-1.0F / 4.0F);
//    // Fill some matrix entries with zeroes
//    for( i = 4U; i < 7U ; i++ )
//        for( j = 0U; j < 7U; j++ )
//            stm->data[i][j] = 0.0;
//    // ************************************************
    stm->data[4][4] = 1.0F;
    stm->data[5][5] = 1.0F;
    stm->data[6][6] = 1.0F;
}



/*******************************************************************************
* Function Name  : apriori_Covariance
* Input          : AHRS_states* estimated_states, fMatrix* F
* Output         : None
* Return         : None
* Description    : Computes the state transition matrix based on previous step
*                    states (quaternions, gyros and gyro biases).
*******************************************************************************/
void ekf_apriori_covariance (ahrs_states_t* estimated_states, fMatrix* F){

    fMatrix L;
    fMatrix Ltranspose;
    fMatrix Ftranspose;
    fMatrix FPF;
    fMatrix LQL;
    float q0;
    float q1;
    float q2;
    float q3;

    Ftranspose.rows = 7U;    Ftranspose.columns = 7U;    
    L.rows = 7U;            L.columns = 6U;    
    FPF.rows = 7U;            FPF.columns = 7U;
    Ltranspose.rows = 6U;    Ltranspose.columns = 7U;
    LQL.rows = 7U;            LQL.columns = 7U;

    // Initializes the sum vector
    mat_zero( &L, L.rows, L.columns );

    // quaternion variables
    q0 = estimated_states->qib.a;
    q1 = estimated_states->qib.b;
    q2 = estimated_states->qib.c;
    q3 = estimated_states->qib.d;

    L.data[0][0] = q1 * (-1.0F / 2.0F);
    L.data[0][1] = q2 * (-1.0F / 2.0F);
    L.data[0][2] = q3 * (-1.0F / 2.0F);
    L.data[1][0] = q0 * (1.0F / 2.0F);
    L.data[1][1] = q3 * (-1.0F / 2.0F);
    L.data[1][2] = q2 * (1.0F / 2.0F);
    L.data[2][0] = q3 * (1.0F / 2.0F);
    L.data[2][1] = q0 * (1.0F / 2.0F);
    L.data[2][2] = q1 * (-1.0F / 2.0F);
    L.data[3][0] = q2 * (-1.0F / 2.0F);
    L.data[3][1] = q1 * (1.0F / 2.0F);
    L.data[3][2] = q0 * (1.0F / 2.0F);
    L.data[4][3] = 1.0F;
    L.data[5][4] = 1.0F;
    L.data[6][5] = 1.0F;

    // Compute "a priori" error covariance matrix
    // FPF'
    mat_transpose (F, &Ftranspose);
    mat_mult (F, &estimated_states->P, F);
    mat_mult (F, &Ftranspose, &FPF);
    // LQL'
    mat_transpose (&L, &Ltranspose);
    mat_mult (&L, &estimated_states->Q, F);
    mat_mult (F, &Ltranspose, &LQL);
    // P = FPF' + LQL'
    mat_add (&FPF, &LQL, &estimated_states->P);
    
}



/*******************************************************************************
* Function Name  : apriori_Estimate
* Input          : AHRS_states* estimated_states, fMatrix* F
* Output         : None
* Return         : None
* Description    : Computes the state transition matrix based on previous step
*                    states (quaternions, gyros and gyro biases).
*******************************************************************************/
void ekf_apriori_estimate (ahrs_states_t* estimated_states, sensor_data_scaled_t* scaled_data){

    float q0, q1, q2, q3, p, q, r, bp, bq, br,t;

    // quaternion variables
    q0 = estimated_states->qib.a;
    q1 = estimated_states->qib.b;
    q2 = estimated_states->qib.c;
    q3 = estimated_states->qib.d;
    // angular rates [rad/s]
    p = scaled_data->gyro_x;
    q = scaled_data->gyro_y;
    r = scaled_data->gyro_z;
    // gyro bias [rad/s]
    bp = estimated_states->bias_p;
    bq = estimated_states->bias_q;
    br = estimated_states->bias_r;
    // time sampling [s]
    t = estimated_states->Ts;

    //mat_zero( stm, stm->rows, stm->columns );

    estimated_states->qib.a = q0+q1*t*bp*(1.0/4.0)+q2*t*bq*(1.0/4.0)+q3*t*br*(1.0/4.0)+t*q1*(bp*(1.0/4.0)-p*(1.0/2.0))+t*q2*(bq*(1.0/4.0)-q*(1.0/2.0))+t*q3*(br*(1.0/4.0)-r*(1.0/2.0));
    estimated_states->qib.b = q1-q0*t*bp*(1.0/4.0)-q2*t*br*(1.0/4.0)+q3*t*bq*(1.0/4.0)-t*q0*(bp*(1.0/4.0)-p*(1.0/2.0))+t*q3*(bq*(1.0/4.0)-q*(1.0/2.0))-t*q2*(br*(1.0/4.0)-r*(1.0/2.0));
    estimated_states->qib.c = q2-q0*t*bq*(1.0/4.0)+q1*t*br*(1.0/4.0)-q3*t*bp*(1.0/4.0)-t*q3*(bp*(1.0/4.0)-p*(1.0/2.0))-t*q0*(bq*(1.0/4.0)-q*(1.0/2.0))+t*q1*(br*(1.0/4.0)-r*(1.0/2.0));
    estimated_states->qib.d = q3-q0*t*br*(1.0/4.0)-q1*t*bq*(1.0/4.0)+q2*t*bp*(1.0/4.0)+t*q2*(bp*(1.0/4.0)-p*(1.0/2.0))-t*q1*(bq*(1.0/4.0)-q*(1.0/2.0))-t*q0*(br*(1.0/4.0)-r*(1.0/2.0));
    estimated_states->bias_p = bp;
    estimated_states->bias_q = bq;
    estimated_states->bias_r = br;
}
