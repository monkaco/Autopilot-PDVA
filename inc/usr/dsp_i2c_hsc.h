/******************************************************************************
* FILENAME:    dsp_i2c_hsc.h
*
* DESCRIPTION:
*       Function prototypes and defines for interacting with HSC differential pressure.
*
* FUNCTIONS:
*       void    HSC_init (uint8_t*)
*       void    HSC_get_data (void)
*
* NOTES:
*       ITG3200 is a tri-axis digital gyrometer which uses protocol I2C to transmit
*       and receive data.
*
*       CODE:    HSC-D-RR-N-010MD-2A3
*               HSC:     Serie
*                D:        DIP (Dual Inline Pin)
*                RR:        Dual radial barbed ports in the same side
*                N:        Gases only, no special options
*                010MD:    +/- 10 mbar
*                2:        I2C, address 0x28
*                A:        10% to 90% of 2^14 counts
*                3:        3.3V supply voltage
*
* REFERENCES:
*       Adapted from CH Robotics
*
* START DATE:    05 Set 2011
*
* CHANGES :
*
* VERSION DATE        WHO                  DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     06 Set 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

#ifndef    DSP_I2C_HSC_H
#define    DSP_I2C_HSC_H

/* HSC function prototypes */
uint8_t hsc_init (void);
uint8_t hsc_get_data (void);

/* Register addresses for the HSC */
#define HSC_SLAVE_ADDRESS7         0x28U    /* Differential pressure slave address HSC */
#define OUTPUT_MIN                 0x0666U     /*    10% of 2^14 counts = 1638 */
#define OUTPUT_MAX                 0x3999U     /*    90% of 2^14 counts = 14745 */
#define PRESSURE_MIN              -10.0F     /*    -10.0 mbar */
#define PRESSURE_MAX               10.0F     /*     10.0 mbar */

#endif

