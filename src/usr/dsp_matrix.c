//############################################################################
//
// File:           EKF_Predict.c
// Version:        0.1
//
// Description:    Implementation of matrices operation functions.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################


#include <math.h>
#include "dsp_matrix.h"
#include "Application_IO_Functions.h"

/*******************************************************************************
* Function Name  : mat_add( fMatrix* src1, fMatrix* src2, fMatrix* dest )
* Input          : fMatrix* src1, fMatrix* src2, fMatrix* dest
* Output         : fMatrix* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Performs the operation
  dest = src1 + src2

src1 and src1 must be of the same dimension.  All three input matrices must
have memory allocated before calling this function.
*******************************************************************************/
int mat_add( fMatrix* src1, fMatrix* src2, fMatrix* dest )
{
     int i, j;
     fMatrix result;
     
     // Make sure that rows and columns on all relevant matrices match
     if( (src1->rows != src2->rows) || (src1->columns != src2->columns) )
     {
          return 0;
     }
     
     result.rows = src1->rows;
     result.columns = src1->columns;
     
     // Compute sum
     for (i = 0; i < src1->rows; i++ )
     {
          for( j = 0; j < src1->columns; j++ )
          {
                result.data[i][j] = src1->data[i][j] + src2->data[i][j];
          }
     }
     
     // Copy to destination
     for (i = 0; i < result.rows; i++ )
     {
          for( j = 0; j < result.columns; j++ )
          {
                dest->data[i][j] = result.data[i][j];
          }
     }
     dest->rows = result.rows;
     dest->columns = result.columns;
     
     return 1;
}

/*******************************************************************************
* Function Name  : mat_mult( fMatrix* src1, fMatrix* src2, fMatrix* dest )
* Input          : fMatrix* src1, fMatrix* src2, fMatrix* dest
* Output         : fMatrix* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Performs the operation
  dest = src1*src2

src1 and src1 must have compatible dimensions for matrix multiplication.  
*******************************************************************************/
int mat_mult( fMatrix* src1, fMatrix* src2, fMatrix* dest )
{
     int i,j,k;
     fMatrix result;

     // Make sure dimensions are consistent with matrix multiplation rules
     if( src1->columns != src2->rows )
     {
          return 0;
     }
     
     result.rows = src1->rows;
     result.columns = src2->columns;
     
     // Compute matrix product
     for( i = 0; i < src1->rows; i++ )
     {
          for( j = 0; j < src2->columns; j++ )
          {
                float dot_product = 0;
                for( k = 0; k < src1->columns; k++ )
                {
                     dot_product += src1->data[i][k]*src2->data[k][j];
                }
                                
                result.data[i][j] = dot_product;
          }
     }
     
     // Copy to destination
     for( i=0; i < result.rows; i++ )
     {
          for( j = 0; j < result.columns; j++ )
          {
                dest->data[i][j] = result.data[i][j];
          }
     }
     dest->rows = result.rows;
     dest->columns = result.columns;
     
     return 1;
}

/*******************************************************************************
* Function Name  : mat_scalar_mult( float scalar, fMatrix* src, fMatrix* dest )
* Input          : float scalar, fMatrix* src, fMatrix* dest
* Output         : fMatrix* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Performs the operation
  dest = scalar*src

src and dest matrices must have memory allocated before calling this function.
*******************************************************************************/
int mat_scalar_mult( float scalar, fMatrix* src, fMatrix* dest )
{
     int i, j;

     dest->rows = src->rows;
     dest->columns = src->columns;
     
     for( i = 0; i < src->rows; i++ )
     {
          for( j = 0; j < src->columns; j++ )
          {
                dest->data[i][j] = scalar*src->data[i][j];
          }
     }
     
     return 1;
}

/*******************************************************************************
* Function Name  : mat_determinant( fMatrix* src, float* det )
* Input          : fMatrix* src, fMatrix* dest
* Output         : float* det
* Return         : 0 if failed, 1 if success
* Description    : 

Computes the determinant of the specified matrix and returns it to the float
pointed to be float* det

src must have memory allocated before calling this function
*******************************************************************************/
int mat_determinant( fMatrix* src, float* det )
{
     // TODO: Implement this
     return 0;
}

/*******************************************************************************
* Function Name  : mat_transpose( fMatrix* src, fMatrix* dest )
* Input          : fMatrix* src, fMatrix* dest
* Output         : fMatrix* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Computes the transpose of src and stores it in dest

The dimensions of src and dest must be compatible with the matrix transpose operation
src and dest must have memory allocated before calling this function.


*******************************************************************************/
int mat_transpose( fMatrix* src, fMatrix* dest )
{
     int i, j;
     fMatrix result;
     
     result.rows = src->columns;
     result.columns = src->rows;
     
     // Compute transpose
     for( i = 0; i < src->rows; i++ )
     {
          for( j = 0; j < src->columns; j++ )
          {
                result.data[j][i] = src->data[i][j];
          }
     }
     
     // Copy to destination
     for( i=0; i < result.rows; i++ )
     {
          for( j = 0; j < result.columns; j++ )
          {
                dest->data[i][j] = result.data[i][j];
          }
     }
     dest->rows = result.rows;
     dest->columns = result.columns;
          
     return 1;
}


/*******************************************************************************
* Function Name  : mat_create_identity( fMatrix* dest )
* Input          : fMatrix* dest
* Output         : fMatrix* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Creates an identity matrix and stores it in 'dest'

dest must have memory allocated before calling this function.


*******************************************************************************/
int mat_create_identity( fMatrix* dest, int rows, int columns )
{
     int i, j;
     
     dest->rows = rows;
     dest->columns = columns;
     
     for( i = 0; i < rows; i++ )
     {
          for( j = 0; j < columns; j++ )
          {
                dest->data[i][j] = 0;
                if( i == j)
                {
                     dest->data[i][j] = 1;
                }
          }
     }
     
     return 0;
}

/*******************************************************************************
* Function Name  : mat_zero( fMatrix* dest )
* Input          : fMatrix* dest
* Output         : fMatrix* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Fills the matrix 'dest' with zeroes

dest must have memory allocated before calling this function.


*******************************************************************************/
int mat_zero( fMatrix* dest, int rows, int columns )
{
     int i, j;
     
     dest->rows = rows;
     dest->columns = columns;
     
     for( i = 0; i < dest->rows; i++ )
     {
          for( j = 0; j < dest->columns; j++ )
          {
                dest->data[i][j] = 0;
          }
     }
     
     return 1;
}

/*******************************************************************************
* Function Name  : mat_copy( fMatrix* src, fMatrix* dest )
* Input          : fMatrix* src, fMatrix* dest
* Output         : fMatrix* dest
* Return         : 0 if failed, 1 if success
* Description    : 

Copies the matrix in 'src' to 'dest'.  'src' and 'dest' must be of the same
dimension, and both must have memory allocated before calling this function.


*******************************************************************************/
int mat_copy( fMatrix* src, fMatrix* dest )
{
     int i, j;
     
     dest->rows = src->rows;
     dest->columns = src->columns;
     
     // Perform copy operation
     for( i = 0; i < dest->rows; i++ )
     {
          for( j = 0; j < dest->columns; j++ )
          {
                dest->data[i][j] = src->data[i][j];
          }
     }
     return 1;
}

/*
int mat_print( fMatrix* matrix )
{
    int i, j; 

    for( i = 0; i < matrix->rows; i++ )
    {
        for( j = 0; j < matrix->columns; j++ )
        {
            hexPrint16( (short)matrix->data[i][j] );
            //DelayMs( 100 );
            SCIA_TX_String("\t");    //USART1_transmit("\t",1);
            //DelayMs( 10 );
        }
        SCIA_TX_String("\r\n");        //USART1_transmit("\r\n",2);
    }
    return;
}
*/

/*
void hexPrint16( short byte )
{
    unsigned char char_data[6];
    unsigned char n0 = (byte & 0x0F);
    unsigned char n1 = ((byte >> 4) & 0x0F);
    unsigned char n2 = ((byte >> 8) & 0x0F);
    unsigned char n3 = ((byte >> 12) & 0x0F);
    
    if( n0 < 10 )
    {
        n0 += 48;
    }
    else
    {
        n0 += 55;
    }
     
    if( n1 < 10 )
    {
        n1 += 48;
    }
    else
    {
        n1 += 55;
    }
     
    if( n2 < 10 )
    {
        n2 += 48;
    }
    else
    {
        n2 += 55;
    }
     
    if( n3 < 10 )
    {
        n3 += 48;
    }
    else
    {
        n3 += 55;
    }

    char_data[0] = '0';
    char_data[1] = 'x';
    char_data[2] = n3;
    char_data[3] = n2;
    char_data[4] = n1;
    char_data[5] = n0;
    
    SCIA_TX_String(char_data);        //USART1_transmit( char_data, 6 );          
}
*/


/*
void svd(double **A, double *S2, int n)
{
  int  i, j, k, EstColRank = n, RotCount = n, SweepCount = 0,
       slimit = (n<120) ? 30 : n/4;
  double eps = 1e-15, e2 = 10.0*n*eps*eps, tol = 0.1*eps, vt, p, x0,
       y0, q, r, c0, s0, d1, d2;

  for (i=0; i<n; i++) { for (j=0; j<n; j++) A[n+i][j] = 0.0; A[n+i][i] = 1.0; }
  while (RotCount != 0 && SweepCount++ <= slimit) {
    RotCount = EstColRank*(EstColRank-1)/2;
    for (j=0; j<EstColRank-1; j++) 
      for (k=j+1; k<EstColRank; k++) {
        p = q = r = 0.0;
        for (i=0; i<n; i++) {
          x0 = A[i][j]; y0 = A[i][k];
          p += x0*y0; q += x0*x0; r += y0*y0;
        }
        S2[j] = q; S2[k] = r;
        if (q >= r) {
          if (q<=e2*S2[0] || fabs(p)<=tol*q)
            RotCount--;
          else {
            p /= q; r = 1.0-r/q; vt = sqrt(4.0*p*p+r*r);
            c0 = sqrt(0.5*(1.0+r/vt)); s0 = p/(vt*c0);
            for (i=0; i<2*n; i++) {
              d1 = A[i][j]; d2 = A[i][k];
              A[i][j] = d1*c0+d2*s0; A[i][k] = -d1*s0+d2*c0;
            }
          }
        } else {
          p /= r; q = q/r-1.0; vt = sqrt(4.0*p*p+q*q);
          s0 = sqrt(0.5*(1.0-q/vt));
          if (p<0.0) s0 = -s0;
          c0 = p/(vt*s0);
          for (i=0; i<2*n; i++) {
            d1 = A[i][j]; d2 = A[i][k];
            A[i][j] = d1*c0+d2*s0; A[i][k] = -d1*s0+d2*c0;
          }
        }
      }
    while (EstColRank>2 && S2[EstColRank-1]<=S2[0]*tol+tol*tol) EstColRank--;
  }

//  if (SweepCount > slimit)
//    printf("Warning: Reached maximum number of sweeps (%d) in SVD routine...\n",slimit);

}
*/
