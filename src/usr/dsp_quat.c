//############################################################################
//
// File:           EKF_Predict.c
// Version:        0.1
//
// Description:    Implementation of quaternions operation functions.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################

#include <math.h>
#include "dsp_types.h"
#include "dsp_quat.h"

/*******************************************************************************
* Function Name  : quat_mult( quat* src1, quat* src2, quat* dest )
* Input          : quat* src1, quat* src2
* Output         : quat* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Performs the quaternion operation dest = src1*src2

*******************************************************************************/
int16_t quat_mult( quat* src1, quat* src2, quat* dest )
{
     float a1,b1,c1,d1;
     float a2,b2,c2,d2;
     
     a1 = src1->a;
     b1 = src1->b;
     c1 = src1->c;
     d1 = src1->d;
     
     a2 = src2->a;
     b2 = src2->b;
     c2 = src2->c;
     d2 = src2->d;
     
     dest->a = (a1 * a2) - (b1 * b2) - (c1 * c2) - (d1 * d2);
     dest->b = (a1 * b2) + (b1 * a2) + (c1 * d2) - (d1 * c2);
     dest->c = (a1 * c2) - (b1 * d2) + (c1 * a2) + (d1 * b2);
     dest->d = (a1 * d2) + (b1 * c2) - (c1 * b2) + (d1 * a2);
     
     return 1;
}

/*******************************************************************************
* Function Name  : quat_conj( quat* src, quat* dest )
* Input          : quat* src
* Output         : quat* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Computes the quaternion conjugate of src and places it in dest

*******************************************************************************/
int16_t quat_conj (quat* src, quat* dest)
{
     dest->a = src->a;
     dest->b = -src->b;
     dest->c = -src->c;
     dest->d = -src->d;     
     
     return 1;
}

/*******************************************************************************
* Function Name  : quat_norm( quat* src )
* Input          : quat* src
* Output         : quat* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Normalizes the quaternion in src

*******************************************************************************/
int16_t quat_norm( quat* src )
{
     float norm = src->a*src->a + src->b*src->b + src->c*src->c + src->d*src->d;
     norm = sqrt(norm);
     
     src->a = src->a/norm;
     src->b = src->b/norm;
     src->c = src->c/norm;
     src->d = src->d/norm;
     
     return 1;
}

/*******************************************************************************
* Function Name  : quat_subtract( quat* src1, quat* src2, quat* dest )
* Input          : quat* src, quat* src2
* Output         : quat* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Performs the operation dest = src1 - src2

*******************************************************************************/
int16_t quat_subtract( quat* src1, quat* src2, quat* dest )
{
     dest->a = src1->a - src2->a;
     dest->b = src1->b - src2->b;
     dest->c = src1->c - src2->c;
     dest->d = src1->d - src2->d;
     
     return 1;
}


/*******************************************************************************
* Function Name  : quat_add( quat* src1, quat* src2, quat* dest )
* Input          : quat* src, quat* src2
* Output         : quat* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Performs the operation dest = src1 + src2

*******************************************************************************/
int16_t quat_add( quat* src1, quat* src2, quat* dest )
{
     dest->a = src1->a + src2->a;
     dest->b = src1->b + src2->b;
     dest->c = src1->c + src2->c;
     dest->d = src1->d + src2->d;
     
     return 1;
}

/*******************************************************************************
* Function Name  : quat_scalar_mult( quat* qsrc, float scalar, quat* dest )
* Input          : quat* src, float scalar
* Output         : quat* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Performs the operation dest = qsrc*scalar;

*******************************************************************************/
int16_t quat_scalar_mult( quat* qsrc, float scalar, quat* dest )
{
     dest->a = qsrc->a * scalar;
     dest->b = qsrc->b * scalar;
     dest->c = qsrc->c * scalar;
     dest->d = qsrc->d * scalar;
     
     return 1;
}
