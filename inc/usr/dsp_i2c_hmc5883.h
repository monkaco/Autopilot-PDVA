/******************************************************************************
* FILENAME:    dsp_hmc5883.h
*
* DESCRIPTION:
*       Function prototypes and defines of HMC5883 driver.
*
* FUNCTIONS:
*    int32_t HMC_init (uint8_t*)
*    int32_t HMC_get_data (void)
*
* VERSION DATE        WHO                    DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     30 Aug 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

#ifndef    DSP_I2C_HMC5883_H
#define    DSP_I2C_HMC5883_H

/* Function prototypes */
uint8_t hmc_init ();
uint8_t hmc_get_data (void);

#define      MAG_SLAVE_ADDRESS7     0x1EU
#define      HMC_ODR_0_75HZ         0x00U    /*  0.75 Hz */
#define      HMC_ODR_1_50HZ         0x04U    /*  1.50 Hz */
#define      HMC_ODR_3HZ            0x08U    /*  3.00 Hz */
#define      HMC_ODR_7_50HZ         0x0CU    /*  7.50 Hz */
#define      HMC_ODR_15HZ           0x10U    /* 15.00 Hz */
#define      HMC_ODR_30HZ           0x14U    /* 30.00 Hz */
#define      HMC_ODR_75HZ           0x18U    /* 75.00 Hz */
#define      HMC_RANGE_8_1GAUSS     0xE0U    /* +/- 8.1 Gauss */
#define      HMC_RANGE_5_6GAUSS     0xC0U    /* +/- 5.6 Gauss */
#define      HMC_RANGE_4_7GAUSS     0xA0U    /* +/- 4.7 Gauss */
#define      HMC_RANGE_4_0GAUSS     0x80U    /* +/- 4.0 Gauss */
#define      HMC_RANGE_2_5GAUSS     0x60U    /* +/- 2.5 Gauss */
#define      HMC_RANGE_1_9GAUSS     0x40U    /* +/- 1.9 Gauss */
#define      HMC_RANGE_1_3GAUSS     0x20U    /* +/- 1.3 Gauss */
#define      HMC_RANGE_0_88GAUSS    0x00U    /* +/- 0.88 Gauss */
#define      HMC_REG0_FAILED        0x01U
#define      HMC_REG1_FAILED        0x02U
#define      HMC_REG2_FAILED        0x03U

#endif
