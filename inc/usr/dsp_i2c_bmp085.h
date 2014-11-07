/******************************************************************************
* FILENAME:    dsp_i2c_hsc.h
*
* DESCRIPTION:
*       Functions for interacting with HSC BMP085 static pressure sensor.
*
* FUNCTIONS:
*       void    HSC_init (uint8_t*)
*       void    HSC_get_data (void)
*
* VERSION DATE        WHO                  DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     06 Set 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

#ifndef DSP_I2C_BMP085_H
#define DSP_I2C_BMP085_H

/* Register addresses for the BMP085 */
#define    BMP_SLAVE_ADDRESS7             0x77U
#define    BMP_REG_COEF_CALIB_ADD         0xAAU
#define    BMP_REG_CTL_ADDRESS            0xF4U
#define    BMP_REG_CTL_TEMPERATURE        0x2EU
#define    BMP_REG_CTL_PRESSURE_0         0x34U
#define    BMP_REG_CTL_PRESSURE_1         0x74U
#define    BMP_REG_CTL_PRESSURE_2         0xB4U
#define    BMP_REG_CTL_PRESSURE_3         0xF4U
#define    BMP_REG_RESULT_ADDRESS         0xF6U
#define    BMP_OSS_PRESSURE_16BITS        0x00U
#define    BMP_OSS_PRESSURE_17BITS        0x01U
#define    BMP_OSS_PRESSURE_18BITS        0x02U
#define    BMP_OSS_PRESSURE_19BITS        0x03U


typedef struct
{
	int16_t AC1;
	int16_t AC2;
	int16_t AC3;
	uint16_t AC4;
	uint16_t AC5;
	uint16_t AC6;
	int16_t B1;
	int16_t B2;
	int16_t MB;
	int16_t MC;
	int16_t MD;

	const uint8_t oversampling_setting;

	int32_t UT;
	int32_t UP;
	int32_t true_T;
	int32_t true_P;

}bmp085_data_t;


/* BMP085 function prototypes */
uint8_t bmp_init (bmp085_data_t* bmp_data);
uint8_t bmp_ut_request (void);
uint8_t bmp_up_request (const uint8_t oss);
uint8_t bmp_ut_get (void);
uint8_t bmp_up_get (void);
uint8_t bmp_pressure_get_data (bmp085_data_t* bmp_data);
uint8_t bmp_temp_get_data (bmp085_data_t* bmp_data);



#endif
