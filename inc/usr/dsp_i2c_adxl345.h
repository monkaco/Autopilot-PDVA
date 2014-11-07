/******************************************************************************
* FILENAME:    dsp_i2c_adxl345.h
*
* DESCRIPTION:
*       Function prototypes and defines of ADXL345 driver.
*
* FUNCTIONS:
*    int32_t    ADXL_init (uint8_t*)U
*    int32_t    ADXL_self_test (uint8_t*)U
*    int32_t    ADXL_get_data (void)U
*
* VERSION DATE        WHO                    DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     30 Aug 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

#ifndef DSP_I2C_ADXL345_H
#define DSP_I2C_ADXL345_H

/* ADXL345 function prototypes */
uint8_t adxl_init (void);
uint8_t adxl_self_test (void);
uint8_t adxl_get_data (void);

/*Register addresses for the ADXL345 */
#define ADXL_SLAVE_ADDRESS7     0x53U    // Accelerometer slave address ADXL345 (Pin 12 GND)
#define ADXL_ODR_6_25HZ         0x06U   // Normal power mode,    6.25 Hz output data rate
#define ADXL_ODR_12_50HZ        0x07U   // Normal power mode,   12.50 Hz output data rate
#define ADXL_ODR_25HZ           0x08U   // Normal power mode,   25.00 Hz output data rate
#define ADXL_ODR_50HZ           0x09U   // Normal power mode,   50.00 Hz output data rate
#define ADXL_ODR_100HZ          0x0AU   // Normal power mode,  100.00 Hz output data rate
#define ADXL_ODR_200HZ          0x0BU   // Normal power mode,  200.00 Hz output data rate
#define ADXL_ODR_400HZ          0x0CU   // Normal power mode,  400.00 Hz output data rate
#define ADXL_ODR_800HZ          0x0DU   // Normal power mode,  800.00 Hz output data rate
#define ADXL_ODR_1600HZ         0x0EU   // Normal power mode, 1600.00 Hz output data rate
#define ADXL_ODR_3200HZ         0x0FU   // Normal power mode, 3200.00 Hz output data rate
#define ADXL_DEVID              0x00U    //    R     11100101  Device ID.
#define ADXL_THRESH_TAP         0x1DU   //    R/W   00000000  Tap threshold.
#define ADXL_OFSX               0x1EU    //    R/W   00000000  X-axis offset.
#define ADXL_OFSY               0x1FU    //    R/W   00000000  Y-axis offset.
#define ADXL_OFSZ               0x20U    //    R/W   00000000  Z-axis offset.
#define ADXL_DUR                0x21U    //    R/W   00000000  Tap duration.
#define ADXL_Latent             0x22U    //    R/W   00000000  Tap latency.
#define ADXL_Window             0x23U    //    R/W   00000000  Tap window.
#define ADXL_THRESH_ACT         0x24U    //    R/W   00000000  Activity threshold.
#define ADXL_THRESH_INACT       0x25U    //    R/W   00000000  Inactivity threshold.
#define ADXL_TIME_INACT         0x26U    //    R/W   00000000  Inactivity time.
#define ADXL_ACT_INACT_CTL      0x27U    //    R/W   00000000  Axis enable control for activity and inactivity detection.
#define ADXL_THRESH_FF          0x28U    //    R/W   00000000  Free-fall threshold.
#define ADXL_TIME_FF            0x29U    //    R/W   00000000  Free-fall time.
#define ADXL_TAP_AXES           0x2AU    //    R/W   00000000  Axis control for tap/double tap.
#define ADXL_ACT_TAP_STATU      0x2BU    //    R     00000000  Source of tap/double tap.
#define ADXL_BW_RATE            0x2CU    //    R/W   00001010  Data rate and power mode control.
#define ADXL_POWER_CTL          0x2DU    //    R/W   00000000  Power-saving features control.
#define ADXL_INT_ENABLE         0x2EU    //    R/W   00000000  Interrupt enable control.
#define ADXL_INT_MAP            0x2FU    //    R/W   00000000  Interrupt mapping control.
#define ADXL_INT_SOURCE         0x30U    //    R     00000010  Source of interrupts.
#define ADXL_DATA_FORMAT        0x31U    //    R/W   00000000  Data format control.
#define ADXL_DATAX0             0x32U    //    R     00000000  X-Axis Data 0.
#define ADXL_DATAX1             0x33U    //    R     00000000  X-Axis Data 1.
#define ADXL_DATAY0             0x34U    //    R     00000000  Y-Axis Data 0.
#define ADXL_DATAY1             0x35U    //    R     00000000  Y-Axis Data 1.
#define ADXL_DATAZ0             0x36U    //    R     00000000  Z-Axis Data 0.
#define ADXL_DATAZ1             0x37U    //    R     00000000  Z-Axis Data 1.
#define ADXL_FIFO_CTL           0x38U    //    R/W   00000000  FIFO control.
#define ADXL_FIFO_STATUS        0x39U    //    R     00000000  FIFO status.

#endif
