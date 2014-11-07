/******************************************************************************
* FILENAME:    dsp_hmc5883.c
*
* DESCRIPTION:
*       Functions and macros to implement the HMC5883 driver.
*
* FUNCTIONS:
*    int32_t HMC_init (uint8_t*)
*    int32_t HMC_get_data (void)
*
* NOTES:
*       Functions and defines configure and gather data from the digital accelerometer ADXL345.
*
* REFERENCES:
*
* START DATE:    05 Set 2011
*
* CHANGES :
*
* VERSION DATE        WHO                    DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     30 Aug 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "my_stdint.h"
#include "dsp_sensorhead_types.h"
#include "dsp_i2c.h"
#include "dsp_i2c_hmc5883.h"

uint8_t g_HMC_Initialized = 0U;
extern uint8_t g_i2cTxBuf[I2C_TX_BUFSIZE];
extern uint8_t g_i2cRxBuf[I2C_RX_BUFSIZE];

/*******************************************************************************
* Function Name  : initializeHMC
* Input          : None
* Output         : uint8_t* status_flag
* Return         : 1 if success, 0 if fail
* Description    : Sets the configuration registers of the HMC.  The registers
                         are set in an order that guarantees that the next register
                         accessed during a read will be 0x03 (i.e. getHMCData can be called
                         after initializeHMC is called.

                         If the function succesfully initializes the HMC, then
                         the return value is 1.  If failed, then the function returns 0,
                         and status_flag is filled with one of the following error codes:

                         HMC_REG0_FAILED => Couldn't set register 0
                         HMC_REG1_FAILED => Couldn't set register 1
                         HMC_REG2_FAILED => Couldn't set register 2

*******************************************************************************/
uint8_t hmc_init ()
{
    uint8_t returnval;


    /* Set mag. update frequency to 75 Hz, normal measurement, 1 sample avereged */
    g_i2cTxBuf[0] = 0x00U;              /* Configuration Register A (CRA) address */
    g_i2cTxBuf[1] = HMC_ODR_75HZ;      /* 75.00 Hz */
    returnval = i2cBatchWrite (MAG_SLAVE_ADDRESS7, g_i2cTxBuf, 2);
    DELAY_US(5);

    if (returnval != 0U)    /* Return 0 if occur an error */
    {
        /* Set gain setting on mag. sensor */
        g_i2cTxBuf[0] = 0x01U;    /* Configuration Register B (CRB) address */
        g_i2cTxBuf[1] = HMC_RANGE_2_5GAUSS;    /* +/- 2.5 Gauss */
        returnval = i2cBatchWrite (MAG_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);
        DELAY_US(5);
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        /* Set magnetometer to run in continuous mode */
        g_i2cTxBuf[0] = 0x02U;    /* Mode Register address */
        g_i2cTxBuf[1] = 0x00U;
        returnval = i2cBatchWrite (MAG_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);
        DELAY_US(5);
    }

    return returnval;
}

/*******************************************************************************
* Function Name  : HMC_get_data
* Input          : None
* Output         : None
* Return         : 1 if success, 0 if fail
* Description    : Fills g_i2cRxBuf with 7 bytes of data - the first 6 bytes are
                         the magnetic readings from the x, y, and z axes (respectively)
                         of the HMC5843, while the last byte is the HMC status register.
                         This function call assumes that the internal register address
                         pointer of the HMC is set to register 0x03.
*******************************************************************************/
uint8_t hmc_get_data ( )
{

    static uint8_t returnval;

    returnval = i2cBatchRead (MAG_SLAVE_ADDRESS7, 0x03U, g_i2cRxBuf, 6U);

    return returnval;
}

