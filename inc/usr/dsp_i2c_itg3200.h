/******************************************************************************
* FILENAME:    dsp_system.c
*
* DESCRIPTION:
*       Peripheral and I/Os configuration routines.
*       Functions used to configure I/Os, peripherals, clocks, etc;
*       See TMS320F28335 for detailed description.
*
* FUNCTIONS:
*       void    Gpio_Select (void)
*
* VERSION DATE        WHO                    DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     30 Aug 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

#ifndef    DSP_I2C_ITG3200_H
#define    DSP_I2C_ITG3200_H

/* ITG3200 function prototypes */
uint8_t itg_init (void);
uint8_t itg_get_data (void);

/* Register addresses for the ITG3200 */
#define    ITG_SLAVE_ADDRESS7    0x68U
#define    ITG_REG_WHOAMI        0x00U
#define    ITG_REG_SMPL          0x15U
#define    ITG_REG_DLPF_FSSEL    0x16U
#define    ITG_REG_INTCONF       0x17U
#define    ITG_REG_INTSTAT       0x18U
#define    ITG_REG_TEMP_HIGH     0x1BU
#define    ITG_REG_TEMP_LOW      0x1CU
#define    ITG_REG_GYRO_X_HIGH   0x1DU
#define    ITG_REG_GYRO_X_LOW    0x1EU
#define    ITG_REG_GYRO_Y_HIGH   0x1FU
#define    ITG_REG_GYRO_Y_LOW    0x20U
#define    ITG_REG_GYRO_Z_HIGH   0x21U
#define    ITG_REG_GYRO_Z_LOW    0x22U
#define    ITG_REG_PWR           0x3EU

#endif
