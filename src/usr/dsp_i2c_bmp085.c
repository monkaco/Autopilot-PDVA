/* ------------------------------------------------------------------------------
  File: DSP_BMP085.c
  Author: Adapted from CH Robotics
  Version: 1.0
  
  Description: Functions for interacting with BMP085 static pressure sensor
------------------------------------------------------------------------------ */ 
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "dsp_types.h"
#include "dsp_sensorhead_types.h"
#include "dsp_i2c.h"
#include "dsp_i2c_bmp085.h"

extern int16_t temperature = 0;
extern int32_t pressure = 0;
extern uint8_t g_i2cTxBuf[I2C_TX_BUFSIZE];
extern uint8_t g_i2cRxBuf[I2C_RX_BUFSIZE];
uint8_t oversampling_setting = 0;
const uint8_t pressure_conversiontime[4] = { 5, 8, 14, 26 };
bmp085_data_t* bmp_data_buffer;

int16_t AC1 = 0;
int16_t AC2 = 0;
int16_t AC3 = 0;
uint16_t AC4 = 0;
uint16_t AC5 = 0;
uint16_t AC6 = 0;
int16_t B1 = 0;
int16_t B2 = 0;
int16_t MB = 0;
int16_t MC = 0;
int16_t MD = 0;

int16_t UT = 0;
int16_t UP = 0;



/*******************************************************************************
* Function Name  : BMP_init
* Input          : None
* Output         : uint8_t* status_flag
* Return         : 1 if success, 0 if fail
* Description    : Initializes the BMP085 pressure sensor

*******************************************************************************/
uint8_t bmp_init (bmp085_data_t* bmp_data)
{
    uint8_t returnval;

    returnval = i2cBatchRead (BMP_SLAVE_ADDRESS7, BMP_REG_COEF_CALIB_ADD, g_i2cRxBuf, 22U);
    
    if (returnval != 0U)
    {
        /* parameters AC1-AC6 */
        bmp_data->AC1 = (g_i2cRxBuf[0] << 8U) | g_i2cRxBuf[1];
        bmp_data->AC2 = (g_i2cRxBuf[2] << 8U) | g_i2cRxBuf[3];
        bmp_data->AC3 = (g_i2cRxBuf[4] << 8U) | g_i2cRxBuf[5];
        bmp_data->AC4 = (g_i2cRxBuf[6] << 8U) | g_i2cRxBuf[7];
        bmp_data->AC5 = (g_i2cRxBuf[8] << 8U) | g_i2cRxBuf[9];
        bmp_data->AC6 = (g_i2cRxBuf[10] << 8U) | g_i2cRxBuf[11];
        /* parameters B1, B2 */
        bmp_data->B1 = (g_i2cRxBuf[12] << 8U) | g_i2cRxBuf[13];
        bmp_data->B2 = (g_i2cRxBuf[14] << 8U) | g_i2cRxBuf[15];
        /* parameters MB, MC, MD */
        bmp_data->MB = (g_i2cRxBuf[16] << 8U) | g_i2cRxBuf[17];
        bmp_data->MC = (g_i2cRxBuf[18] << 8U) | g_i2cRxBuf[19];
        bmp_data->MD = (g_i2cRxBuf[20] << 8U) | g_i2cRxBuf[21];
    }


    return (returnval);
}


/*******************************************************************************
* Function Name  : BMP_UT_request
* Input          : None
* Output         : uint8_t* i2cBuf
* Return         : 1 if success, 0 if fail
* Description    : Request temperature data from the BMP085 pressure sensor
*******************************************************************************/
uint8_t bmp_ut_request ( )
{
    static uint8_t returnval;
    
    g_i2cTxBuf[0] = BMP_REG_CTL_ADDRESS;
    g_i2cTxBuf[1] = BMP_REG_CTL_TEMPERATURE;

    returnval = i2cBatchWrite (BMP_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);
 
    return (returnval);

}


/*******************************************************************************
* Function Name  : BMP_UP_request
* Input          : None
* Output         : uint8_t* i2cBuf
* Return         : 1 if success, 0 if fail
* Description    : Request pressure data from the BMP085 pressure sensor
*******************************************************************************/
uint8_t bmp_up_request (const uint8_t oss)
{
    static uint8_t returnval;
    
    g_i2cTxBuf[0] = BMP_REG_CTL_ADDRESS;

    switch (oss)
     {
        case 0:     g_i2cTxBuf[1] = BMP_REG_CTL_PRESSURE_0;
                    break;
        case 1:     g_i2cTxBuf[1] = BMP_REG_CTL_PRESSURE_1;
                    break;
        case 2:     g_i2cTxBuf[1] = BMP_REG_CTL_PRESSURE_2;
                    break;
        case 3:     g_i2cTxBuf[1] = BMP_REG_CTL_PRESSURE_3;
                    break;
        default:    g_i2cTxBuf[1] = BMP_REG_CTL_PRESSURE_0;
     }

    returnval = i2cBatchWrite (BMP_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);

    return (returnval);
}


/*******************************************************************************
* Function Name  : getBMPTemperatureData
* Input          : None
* Output         : uint8_t* i2cBuf
* Return         : 1 if success, 0 if fail
* Description    : Gets the temperature from the BMP085 pressure sensor
*******************************************************************************/
uint8_t bmp_temp_get_data (bmp085_data_t* bmp_data)
{
    static uint8_t returnval;
    static int32_t x1;
    static int32_t x2;
    static int32_t b5;

    returnval = i2cBatchRead (BMP_SLAVE_ADDRESS7, BMP_REG_RESULT_ADDRESS, g_i2cRxBuf, 2U);

    if (returnval != 0U)
    {
    	bmp_data->UT = (g_i2cRxBuf[0] << 8U) | (g_i2cRxBuf[0]);

        /* calculate true temperature */
        x1 = ((int32_t)bmp_data->UT - bmp_data->AC6) * bmp_data->AC5 >> 15U;
        x2 = ((int32_t)bmp_data->MC << 11U) / (x1 + bmp_data->MD);
        b5 = x1 + x2;
        bmp_data->true_T = (b5 + 8U) >> 4U;
    }

    return (returnval);
}



/*******************************************************************************
* Function Name  : BMP_Pressure_get_data
* Input          : None
* Output         : uint8_t* i2cBuf
* Return         : 1 if success, 0 if fail
* Description    : Gets the pressure from the BMP085 pressure sensor
*******************************************************************************/
uint8_t bmp_pressure_get_data(bmp085_data_t* bmp_data)
{
    static int8_t returnval;
    static int32_t pressure;
    static int32_t x1;
    static int32_t x2;
    static int32_t x3;
    static int32_t b3;
    static int32_t b5;
    static int32_t b6;
    static int32_t p;
    static uint32_t b4;
    static uint32_t b7;

    returnval = i2cBatchRead (BMP_SLAVE_ADDRESS7, BMP_REG_RESULT_ADDRESS, g_i2cRxBuf, 3U);

    if (returnval != 0U)
    {
    	bmp_data->UP = (((int32_t)g_i2cRxBuf[0] << 16U) | ((int32_t)g_i2cRxBuf[1] << 8U) | ((int32_t)g_i2cRxBuf[2])) >> (8U - oversampling_setting);

        /* Calculate true temperature */
        x1 = (((int32_t)UT - bmp_data->AC6) * bmp_data->AC5) >> 15U;
        x2 = ((int32_t) bmp_data->MC << 11U) / (x1 + bmp_data->MD);
        b5 = x1 + x2;
        /* Calculate true pressure */
        b6 = b5 - 4000U;
        x1 = (bmp_data->B2 * (b6 * b6 >> 12U)) >> 11U;
        x2 = bmp_data->AC2 * b6 >> 11U;
        x3 = x1 + x2;
        b3 = (((int32_t)bmp_data->AC1 * 4U + x3) << bmp_data->oversampling_setting + 2U) >> 2U;
        x1 = bmp_data->AC3 * b6 >> 13U;
        x2 = (bmp_data->B1 * ((b6 * b6) >> 12U)) >> 16U;
        x3 = ((x1 + x2) + 2U) >> 2U;
        b4 = (bmp_data->AC4 * (uint32_t) (x3 + 32768U)) >> 15U;
        b7 = ((uint32_t) bmp_data->UP - b3) * (50000U >> bmp_data->oversampling_setting);
        p = b7 < 0x80000000U ? (b7 * 2U) / b4 : (b7 / b4) * 2U;

        x1 = (p >> 8U) * (p >> 8U);
        x1 = (x1 * 3038) >> 16U;
        x2 = (-7357 * p) >> 16U;
        bmp_data->true_P = p + ((x1 + x2 + 3791) >> 4U);
    }


    return (returnval);
}
