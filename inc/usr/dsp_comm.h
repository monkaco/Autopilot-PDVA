/******************************************************************************
* FILENAME:    dsp_comm.h
*
* DESCRIPTION:
*       Function prototypes of communication peripherals.
*
* FUNCTIONS:
*       void    scia_init (void)
*       void    spia_init (void)
*       void    i2ca_init (void)
*
* VERSION DATE        WHO                    DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     30 Aug 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

#ifndef DSP_COMM_H
#define DSP_COMM_H

#define SPI_8BITS /* SPI_16BITS */

/* Function prototypes */
void scia_init (void);
void spia_init (void);
void i2ca_init (void);

#endif
