//############################################################################
//
// File:           dsp_matrix.h
// Version:        0.1
//
// Description:    Preprocessor definitions and function declarations for matrix 
//                calculations.
//
//############################################################################
// Author: Rogério Lima
// Release Date: July 2012
//############################################################################


#ifndef DSP_MATRIX_H
#define DSP_MATRIX_H

#define   MATRIX_MAX_ROWS      12
#define   MATRIX_MAX_COLUMNS   12

typedef struct _fMatrix {
     int rows;
     int columns;
     float data[MATRIX_MAX_ROWS][MATRIX_MAX_COLUMNS];
} fMatrix;

// Matrix operations
int mat_add( fMatrix* src1, fMatrix* src2, fMatrix* dest );
int mat_mult( fMatrix* src1, fMatrix* src2, fMatrix* dest );
int mat_scalar_mult( float scalar, fMatrix* src, fMatrix* dest );
int mat_determinant( fMatrix* src, float* det );
int mat_transpose( fMatrix* src, fMatrix* dest );
int mat_create_identity( fMatrix* dest, int rows, int columns );
int mat_zero( fMatrix* dest, int rows, int columns );
int mat_copy( fMatrix* src, fMatrix* dest );

//int mat_print( fMatrix* matrix );
//void hexPrint16( short byte );

#endif
