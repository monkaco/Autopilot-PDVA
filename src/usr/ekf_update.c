//############################################################################
//
// File:           EKF_Update.c
// Version:        0.1
//
// Description:    Implementation EKF update functions.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################

#include "dsp_sensorhead_types.h"
#include "dsp_matrix.h"
#include "dsp_ekf.h"
#include <math.h>

uint8_t NewGpsMessage = 1U;


void ekf_correction (ahrs_states_t* estimated_states, sensor_data_scaled_t* scaled_data)
{
    fMatrix Mxyz, MxyzTranspose;
    fMatrix H, h, PhT, sigma2_phi_theta, M_phi_theta, M_phi_thetaTranspose;
    fMatrix M_H12, M_H12Transpose, M_psi, M_psiTranspose, sigma2_psi;
    fMatrix temp11, temp71, temp77, temp77_, temp2_12, temp23, sum;
    fMatrix temp12, temp13;
    fMatrix y, h_meas, h_meas_aux, error, K;
    float q0, q1, q2, q3, scalar, H1, H2, temp;
    float phi_, the_, psi_, cos_phi, sin_phi, cos_the, sin_the;
    float Ax, Ay, Az, Wx, Wy, Wz, bWx, bWy, bWz, gx, gy, gz;
    float Hx, Hy, Hz, U, V, W, U_dot, V_dot, W_dot;
    float phi_apriori, theta_apriori;
    float cos_phi_apriori, sin_phi_apriori, cos_theta_apriori, sin_theta_apriori;
    int k;

    H.rows = 7U;                            H.columns = 7U;                        
    h.rows = 1U;                            h.columns = 7U;
    PhT.rows = 7U;                        PhT.columns = 1U;                    
    sigma2_phi_theta.rows = 2U;            sigma2_phi_theta.columns = 2U;
    sigma2_psi.rows = 1U;                sigma2_psi.columns = 1U;
    y.rows = 4U;                            y.columns = 1U;
    h_meas.rows = 4U;                    h_meas.columns = 1U;
    h_meas_aux.rows = 4U;                h_meas_aux.columns = 1;
    error.rows = 4U;                        error.columns = 1U;
    Mxyz.rows = 3U;                        Mxyz.columns = 12U;
    MxyzTranspose.rows = 12U;            MxyzTranspose.columns = 3U;
    M_phi_theta.rows = 2U;                M_phi_theta.columns = 3U;
    M_phi_thetaTranspose.rows = 3U;        M_phi_thetaTranspose.columns = 2U;
    M_psi.rows = 1U;                        M_psi.columns = 2U;
    M_psiTranspose.rows = 2U;            M_psiTranspose.columns = 1U;
    M_H12.rows = 2U;                        M_H12.columns = 3U;
    M_H12Transpose.rows = 3;            M_H12Transpose.columns = 2;
    sum.rows = 7;                        sum.columns = 1;
    K.rows = 7;                            K.columns = 1;
    temp11.rows = 1;                    temp11.columns = 1;    //temp3
    temp12.rows = 1;                    temp12.columns = 2;
    temp13.rows = 1;                    temp13.columns = 3;
    temp23.rows = 2;                    temp23.columns = 3;     // temp6
    temp2_12.rows = 2;                    temp2_12.columns = 12;    // temp5
    temp71.rows = 7;                    temp71.columns = 1;    // temp1
    temp77.rows = 7;                    temp77.columns = 7;    // temp4
    temp77_.rows = 7;                    temp77_.columns = 7;     // temp4_
    
    // quaternion variables
    q0 = estimated_states->qib.a;
    q1 = estimated_states->qib.b;
    q2 = estimated_states->qib.c;
    q3 = estimated_states->qib.d;
    // Accelerometer variables
    Ax = scaled_data->accel_x;
    Ay = scaled_data->accel_y;
    Az = scaled_data->accel_z;
    // Gyrometer variables
    Wx = scaled_data->gyro_x;
    Wy = scaled_data->gyro_y;
    Wz = scaled_data->gyro_z;
    bWx = estimated_states->bias_p;
    bWy = estimated_states->bias_q;
    bWz = estimated_states->bias_r;
    // force gyro bias to zero
    //bWx = 0;
    //bWy = 0;
    //bWz = 0;
    // Magnetometer variables
    Hx = scaled_data->mag_x;
    Hy = scaled_data->mag_y;
    Hz = scaled_data->mag_z;
    
    // GPS Variables
    // Velocitiy
    U = estimated_states->U;
    V = estimated_states->V;
    W = estimated_states->W;
    // Acceleration
    U_dot = estimated_states->U_dot;
    V_dot = estimated_states->V_dot;
    W_dot = estimated_states->W_dot;


        // Initializes some matrix
    mat_zero( &h, h.rows, h.columns );
    mat_zero( &temp11, temp11.rows, temp11.columns );
    mat_zero( &Mxyz, Mxyz.rows, Mxyz.columns );

    // Gravity acceleration components
    gx = Ax - (U_dot + (W*(Wy-bWy) - V*(Wz-bWz)));
    gy = Ay - (V_dot + (U*(Wz-bWz) - W*(Wx-bWx)));
    gz = Az - (W_dot + (V*(Wx-bWx) - U*(Wy-bWy)));
    
    // "a priori" estimated attitude angles
    phi_apriori = DEG2RAD*estimated_states->phi;
    theta_apriori = DEG2RAD*estimated_states->theta;
    sin_phi_apriori = sin (phi_apriori);
    cos_phi_apriori = cos (phi_apriori);
    sin_theta_apriori = sin (theta_apriori);
    cos_theta_apriori = cos (theta_apriori);

    phi_ = atan2 (gy, gz);
    cos_phi = cos (phi_);
    the_ = atan2 (-gx*cos_phi, gz);

    // H1 and H2 calculations
    H1 = Hx*cos_theta_apriori + Hy*sin_phi_apriori*sin_theta_apriori + Hz*cos_phi_apriori*sin_theta_apriori;
    H2 = Hy*cos_phi_apriori - Hz*sin_phi_apriori;
 
    psi_ = atan2(H1, H2);                     // [heading from magnetometer]
    //psi_ = estimated_states->GPS_heading;    // [heading from GPS]

    sin_phi = sin(phi_);
    cos_phi = cos(phi_);
    sin_the = sin(the_);
    cos_the = cos(the_);

    // **********************************************************************************
    // Phi and Theta variances
    // Matrix Mxyz - Declarar esta matriz na estrutura AHRS_state para reduzir cálculos
    Mxyz.data[0][0] = 1.0f;
    Mxyz.data[0][3] = -1.0f;
    Mxyz.data[0][7] = Wz;
    Mxyz.data[0][8] = -Wy;
    Mxyz.data[0][10] = -W;
    Mxyz.data[0][11] = V;
    Mxyz.data[1][1] = 1.0f;
    Mxyz.data[1][4] = -1.0f;
    Mxyz.data[1][6] = -Wz;
    Mxyz.data[1][8] = Wx;
    Mxyz.data[1][9] = W;
    Mxyz.data[1][11] = -U;
    Mxyz.data[2][2] = 1.0f;
    Mxyz.data[2][5] = -1.0f;
    Mxyz.data[2][6] = Wy;
    Mxyz.data[2][7] = -Wx;
    Mxyz.data[2][9] = -V;
    Mxyz.data[2][10] = U;
    // Mxyz'
    mat_transpose( &Mxyz, &MxyzTranspose );
    
    // Matrix M_phi_theta
    // Matrix M_phi_theta
    M_phi_theta.data[0][0] = 0.0f;
    M_phi_theta.data[0][1] =  gz/(gy*gy + gz*gz);
    M_phi_theta.data[0][2] = -gy/(gy*gy + gz*gz);
    M_phi_theta.data[1][0] = -gz*cos_phi/( gx*gx*cos_phi*cos_phi + gz*gz);
    M_phi_theta.data[1][1] =  gx*gz*gz*sin_phi/((gy*gy + gz*gz)*(gx*gx*cos_phi*cos_phi+gz*gz ));
    M_phi_theta.data[1][2] = ( (gy*gy + gz*gz)*gx*cos_phi - gx*gy*gz*sin_phi )/( (gy*gy + gz*gz)*(gx*gx*cos_phi*cos_phi + gz*gz) );
    // M_phi_theta'
    mat_transpose( &M_phi_theta, &M_phi_thetaTranspose );
    
    // Roll (phi) and pitch (theta) variances
    // sigma2_phi_theta = M_phi_theta * Mxyz * R_phi_theta * Mxyz' * M_phi_theta'
    // temp5(2,12) = M_phi_theta(2,3)*Mxyz(3,12)
    mat_mult( &M_phi_theta, &Mxyz, &temp2_12 );
    
    // temp5(2,12) = temp5(2,12)*R_phi_theta(12,12)
    mat_mult( &temp2_12, &estimated_states->R_phi_theta, &temp2_12 );

    // temp6(2,3) = temp5(2,12)*MxyzTranspose(12,3)
    mat_mult( &temp2_12, &MxyzTranspose, &temp23 );

    // sigma2_phi_theta(2,2) = temp6(2,3)*MxyzTranspose(12,3)
    mat_mult( &temp23, &M_phi_thetaTranspose, &sigma2_phi_theta );

    estimated_states->R.data[0][0] = sigma2_phi_theta.data[0][0];    // sigma_theta^2
    estimated_states->R.data[1][1] = sigma2_phi_theta.data[1][1];    // sigma_phi^2

    // 444 flops
    // **********************************************************************************

    
    // **********************************************************************************
    // Psi variance
    // Matrix Mxyz - Declarar esta matriz na estrutura AHRS_state para reduzir cálculos
    M_H12.data[0][0] = cos_the;
    M_H12.data[0][1] = sin_the*sin_phi;
    M_H12.data[0][2] = cos_phi*sin_the;
    M_H12.data[1][0] = 0.0;
    M_H12.data[1][1] = cos_phi;
    M_H12.data[1][2] = -sin_phi;
    // Mxyz'
    mat_transpose( &M_H12, &M_H12Transpose );
    
    // Matrix M_psi
    M_psi.data[0][0] = -H2/(H1*H1 + H2*H2);
    M_psi.data[0][1] =  H1/(H1*H1 + H2*H2);
    // M_psi'
    mat_transpose( &M_psi, &M_psiTranspose );

    // Heading (psi) variance
    // sigma2_psi = M_psi * M_H12 * R_psi *  M_H12' * M_psi'
    // temp13(1,3) = M_psi(1,2) * M_H12(2,3)
    mat_mult( &M_psi, &M_H12, &temp13 );

    // temp13(1,3) = temp13(1,3) * R_psi(3,3)
    mat_mult( &temp13, &estimated_states->R_psi, &temp13 );
    
    // temp12(1,2) = temp13(1,3) * M_H12Transpose(3,2)
    mat_mult( &temp13, &M_H12Transpose, &temp12 );

    // sigma2_psi(1,1) = temp12(1,2) * M_psiTranspose(2,1)
    mat_mult( &temp12, &M_psiTranspose, &sigma2_psi );
    
    estimated_states->R.data[2][2] = sigma2_psi.data[0][0];    // sigma_psi^2

    estimated_states->R.data[3][3] = QUATERNION_NORM_VARIANCE;    // sigma_psi^2

    // xxx flops
    // **********************************************************************************

    // y: measurement vector
    y.data[0][0] = phi_;
    y.data[1][0] = the_;
    y.data[2][0] = psi_;
    y.data[3][0] = 1.0F;
    
    // Forced normalization
    quat_norm(&estimated_states->qib);
    // quaternion variables
    q0 = estimated_states->qib.a;
    q1 = estimated_states->qib.b;
    q2 = estimated_states->qib.c;
    q3 = estimated_states->qib.d;

    // h_meas: output equation measurement
    h_meas.data[0][0] = atan2((q0*q1*2.0+q2*q3*2.0), (q0*q0-q1*q1-q2*q2+q3*q3));
    h_meas.data[1][0] = asin(q0*q2*2.0-q1*q3*2.0);
    h_meas.data[2][0] = atan2((q0*q3*2.0+q1*q2*2.0), (q0*q0+q1*q1-q2*q2-q3*q3));
    h_meas.data[3][0] = q0*q0+q1*q1+q2*q2+q3*q3;

/*    Used when heading comes from GPS
    // h_meas: output equation measurement
    temp = atan2((q0*q3*2.0+q1*q2*2.0), (q0*q0+q1*q1-q2*q2-q3*q3));
    
    h_meas.data[0][0] = atan2((q0*q1*2.0+q2*q3*2.0), (q0*q0-q1*q1-q2*q2+q3*q3));
    h_meas.data[1][0] = asin(q0*q2*2.0-q1*q3*2.0);
    if (temp < -0.01)    // converts heading range from: -180..+180 -> 0..360
        h_meas.data[2][0] = 6.283185307179 + temp;
    else
        h_meas.data[2][0] = temp;
    h_meas.data[3][0] = q0*q0+q1*q1+q2*q2+q3*q3;
*/

    // Computes linearized measurement equation
    H_Matrix(estimated_states, &H);

    // Computes Kalman gain and Process covariance serially

    // Initializes the sum vector
    mat_zero( &sum, sum.rows, sum.columns );
    //mat_zero( &error, error.rows, error.columns );

    for(k = 0; k < 4; k++)
    {
        // h = H(k,:)
        h.data[0][0] = H.data[k][0];
        h.data[0][1] = H.data[k][1];
        h.data[0][2] = H.data[k][2];
        h.data[0][3] = H.data[k][3];
        h.data[0][4] = H.data[k][4];
        h.data[0][5] = H.data[k][5];
        h.data[0][6] = H.data[k][6];

        // *** PhT ***
        // temp1 = hT
        mat_transpose( &h, &temp71 );    
        // PhT = P*hT = P*temp1
        mat_mult( &estimated_states->P, &temp71, &PhT );
        
        // *** h*PhT ***
        // temp3 = h*PhT
        mat_mult( &h, &PhT, &temp11 );

        // *** h*PhT + R(k,k) ***
        scalar = temp11.data[0][0] + estimated_states->R.data[k][k];

        // *** K = PhT/( h*PhT + R(k,k) ) ***
        // temp1 = K
        //mat_scalar_mult( 1.0/scalar, &PhT, &temp71 );
        mat_scalar_mult( 1.0/scalar, &PhT, &K );

        // *** K*PhT' ***
        // PhT2 = PhT' = temp17
//        mat_transpose( &PhT, &temp17 );
        // K*PhT' = temp1*temp2 = temp4
        //mat_mult( &temp71, &temp17, &temp77 );
        mat_mult( &K, &h, &temp77 );

        // K*h*P = K*temp77 = temp77
        mat_mult( &temp77, &estimated_states->P, &temp77 );
        
        // *** -K*PhT' ***
        mat_scalar_mult( -1.0, &temp77, &temp77_ );

        // *** P = P_ - K*PhT' ***
        mat_add( &estimated_states->P, &temp77_, &estimated_states->P );

        // Updated error covariance matrix
        //mat_copy( &temp4, &estimated_states.P);

        // error(k) = y(k) - h_meas(k)
        mat_scalar_mult( -1.0, &h_meas, &h_meas_aux );
        mat_add( &y, &h_meas_aux, &error );
        // K = temp1
        // K*error(k) = K*( y(k) - h_meas(k) )
        temp11.data[0][0] = error.data[k][0];
        // temp3 = error(k)
        //mat_mult( &temp71, &temp11, &temp71 );
        mat_mult( &K, &temp11, &temp71 );
        // temp1 = K*error
        mat_add( &sum, &temp71, &sum );
        // sum = sum + K*( y(k) - h_meas(k) )

        // debug
        estimated_states->debug_misc[k] = error.data[k][0];

    }

    estimated_states->qib.a = estimated_states->qib.a + sum.data[0][0];
    estimated_states->qib.b = estimated_states->qib.b + sum.data[1][0];
    estimated_states->qib.c = estimated_states->qib.c + sum.data[2][0];
    estimated_states->qib.d = estimated_states->qib.d + sum.data[3][0];
    estimated_states->bias_p = sum.data[4][0];
    estimated_states->bias_q = sum.data[5][0];
    estimated_states->bias_r = sum.data[6][0];

    // Symmetrize Error Covariance Matrix 
    // *** Psym = (P + P')/2 ***
    // temp77 = P'
    mat_transpose (&estimated_states->P, &temp77);
    // temp77_ = (P + P')/2;
    mat_add (&estimated_states->P, &temp77, &temp77_);
    mat_scalar_mult (0.5F, &temp77_, &estimated_states->P);

    // Quaternion normalization
    quat_norm (&estimated_states->qib);

    compute_euler_angles (estimated_states);

}



void ekf_h_matrix (ahrs_states_t* estimated_states, fMatrix* H){

    float q0, q1, q2, q3, aux1, aux2, aux3, aux4, aux5, p_aux1, p_aux2, p_aux3;

    // quaternion variables
    q0 = estimated_states->qib.a;
    q1 = estimated_states->qib.b;
    q2 = estimated_states->qib.c;
    q3 = estimated_states->qib.d;
    // temp variables to speedup the code
    aux1 = q0*q0-q1*q1-q2*q2+q3*q3;
    aux2 = q0*q1*2.0+q2*q3*2.0;
    aux3 = q0*q2*2.0-q1*q3*2.0;
    aux4 = q0*q0+q1*q1-q2*q2-q3*q3;
    aux5 = q0*q3*2.0+q1*q2*2.0;

    // Verificar estas equações. O 1o. parêntese que se abre nas linhas 245 e 247 foi colocado sem certeza.
    p_aux1 = (aux2/(aux1*aux1)*2.0)/( (aux2*aux2)/(aux1*aux1)+1.0);
    p_aux2 = 1.0/sqrt(-(aux3*aux3)+1.0);    
    p_aux3 = (aux5/(aux4*aux4)*2.0)/((aux5*aux5)/(aux4*aux4)+1.0);

    H->data[0][0] = (q1*2.0)/(aux1)-q0*p_aux1;
    H->data[0][1] = (q0*2.0)/(aux1)+q1*p_aux1;
    H->data[0][2] = (q3*2.0)/(aux1)+q2*p_aux1;
    H->data[0][3] = (q2*2.0)/(aux1)-q3*p_aux1;
    H->data[0][4] = 0.0;
    H->data[0][5] = 0.0;
    H->data[0][6] = 0.0;
    H->data[1][0] = q2*p_aux2*2.0;
    H->data[1][1] = q3*p_aux2*(-2.0);
    H->data[1][2] = q0*p_aux2*2.0;
    H->data[1][3] = q1*p_aux2*(-2.0);
    H->data[1][4] = 0.0;
    H->data[1][5] = 0.0;
    H->data[1][6] = 0.0;
    H->data[2][0] = (q3*2.0)/(aux4)-q0*p_aux3;
    H->data[2][1] = (q2*2.0)/(aux4)-q1*p_aux3;
    H->data[2][2] = (q1*2.0)/(aux4)+q2*p_aux3;
    H->data[2][3] = (q0*2.0)/(aux4)+q3*p_aux3;
    H->data[2][4] = 0.0;
    H->data[2][5] = 0.0;
    H->data[2][6] = 0.0;
    H->data[3][0] = q0*2.0;
    H->data[3][1] = q1*2.0;
    H->data[3][2] = q2*2.0;
    H->data[3][3] = q3*2.0;
    H->data[3][4] = 0.0;
    H->data[3][5] = 0.0;
    H->data[3][6] = 0.0;

}



//void Psi_Variance(ahrs_states_t* estimated_states, fMatrix* R){}

/*******************************************************************************
* Function Name  : compute_euler_angles
* Input          : AHRS_states* states
* Output         : None
* Return         : None
* Description    : Converts quaternion attitude estimate to euler angles (yaw, pitch, roll)
*******************************************************************************/
void compute_euler_angles( ahrs_states_t* estimated_states )
{
     float q0, q1, q2, q3;
     
     q0 = estimated_states->qib.a;
     q1 = estimated_states->qib.b;
     q2 = estimated_states->qib.c;
     q3 = estimated_states->qib.d;     

     estimated_states->phi = atan2(2*(q0*q1 + q2*q3), q3*q3 - q2*q2 - q1*q1 + q0*q0)*180/3.14159;
     estimated_states->theta = -asin(2*(q1*q3 - q0*q2))*180/3.14159;
     estimated_states->psi = atan2(2*(q0*q3+q1*q2), q1*q1 + q0*q0 - q3*q3 - q2*q2)*180/3.14159;
}
