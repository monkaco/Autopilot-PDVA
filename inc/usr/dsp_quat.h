//############################################################################
//
// File:   		EKF_Quat.h
// Version:		0.1
//
// Description:	Preprocessor definitions and function declarations for quater- 
//				nion calculations.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################

#ifndef __EKF_quat_h
#define __EKF_quat_h

typedef struct _quat {
	 float a,b,c,d;
} quat;

int16_t quat_mult( quat* src1, quat* src2, quat* dest );
int16_t quat_conj( quat* src, quat* dest );
int16_t quat_norm( quat* src );
int16_t quat_add( quat* src1, quat* src2, quat* dest );
int16_t quat_subtract( quat* src1, quat*src2, quat* dest );
int16_t quat_scalar_mult( quat* qsrc, float scalar, quat* dest );

#endif
