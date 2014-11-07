/******************************************************************************
* FILENAME:    dsp_i2c_adxl345.h
*
* DESCRIPTION:
*       Function prototypes and defines of ADXL345 driver.
*
* FUNCTIONS:
*    int32_t    ADXL_init (uint8_t*);
*    int32_t    ADXL_self_test (uint8_t*);
*    int32_t    ADXL_get_data (void);
*
* NOTES:
*       Functions and defines configure and gather data from the digital accelerometer ADXL345.
*
* REFERENCES:
*       Adapted from CH Robotics
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
#include "dsp_i2c_adxl345.h"

uint8_t g_ADXL_Initialized = 0;
uint8_t g_ADXL_Tested = 0;
extern uint8_t g_i2cTxBuf[I2C_TX_BUFSIZE];
extern uint8_t g_i2cRxBuf[I2C_RX_BUFSIZE];


/*******************************************************************************
* Function Name  : ADXL_init
* Input          : None
* Output         : uint8_t* status_flag
* Return         : 1 if success, 0 if fail
* Description    : Initializes the ADXL345 accelerometer

*******************************************************************************/
uint8_t adxl_init ()
{
    uint8_t returnval;

    g_i2cTxBuf[0] = ADXL_POWER_CTL;     /* Power-saving features control */
    g_i2cTxBuf[1] = 0x00U;                 /* Go into standby mode to configure the device. */
    returnval = i2cBatchWrite( ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2 );
    DELAY_US(5);


    if (returnval != 0)                 /* Return 0 if occur an error */
    {
        g_i2cTxBuf[0] = ADXL_DATA_FORMAT;    /* Data format control  */
        g_i2cTxBuf[1] = 0x08U;    // +/-2g, right justified, full resolution, self-test disabled */
        returnval = i2cBatchWrite( ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2 );
        DELAY_US(5);
    }
    else if (returnval != 0)            /* Return 0 if occur an error */
    {
        g_i2cTxBuf[0] = ADXL_OFSX;        /* Configura offset dos 3 eixos */
        g_i2cTxBuf[1] = 0x00U;            /* Offset-x */
        g_i2cTxBuf[2] = 0x00U;            /* Offset-y */
        g_i2cTxBuf[3] = 0x00U;            /* Offset-z */
        returnval = i2cBatchWrite( ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 4 );
    }
    else if (returnval != 0U)            /* Return 0 if occur an error */
    {
        g_i2cTxBuf[0] = ADXL_BW_RATE;    /* Data rate and power mode control */
        g_i2cTxBuf[1] = ADXL_ODR_50HZ;    /* 50.00 Hz output data rate */
        returnval = i2cBatchWrite( ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2 );
        DELAY_US(5);
    }
    else if ( returnval != 0U )            /* Return 0 if occur an error */
    {
        g_i2cTxBuf[0] = ADXL_POWER_CTL;     /* Power-saving features control */
        g_i2cTxBuf[1] = 0x08U;              /* Places the accel into measurement mode */
        returnval = i2cBatchWrite( ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2 );
        DELAY_US(5);
    }


     return (returnval);
}


/* ...+++SHALL BE STANDARDIZED+++... */
/*******************************************************************************
* Function Name  : ADXL_self_test
* Input          : None
* Output         : None
* Return         : 1 if success, 0 if fail
* Description    : 
*******************************************************************************/
uint8_t adxl_self_test ()
{
    static uint16_t i;
    static uint8_t returnval;
    static int16_t X_ST;
    static int16_t Y_ST;
    static int16_t Z_ST;
    static int16_t X_ST_ON[100];
    static int16_t Y_ST_ON[100];
    static int16_t Z_ST_ON[100];
    static int16_t X_ST_OFF[100];
    static int16_t Y_ST_OFF[100];
    static int16_t Z_ST_OFF[100];
    static int32_t X_ON;
    static int32_t Y_ON;
    static int32_t Z_ON;
    static int32_t X_OFF;
    static int32_t Y_OFF;
    static int32_t Z_OFF;

    /* Standby mode: goes to configuration mode */
    g_i2cTxBuf[0] = ADXL_POWER_CTL;    /* Power-saving features control */
    g_i2cTxBuf[1] = 0x00U;             /* Go into standby mode to configure the device */
    returnval = i2cBatchWrite (ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);
    DELAY_US(5);

    if (returnval != 0U)
    {
        g_i2cTxBuf[0] = ADXL_DATA_FORMAT;    /* Data format control */
        g_i2cTxBuf[1] = 0x8CU;    /* +/-16g, right justified, full resolution, self-test enabled */
        returnval = i2cBatchWrite (ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);
        DELAY_US(5);
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        g_i2cTxBuf[0] = ADXL_BW_RATE;    /* Data rate and power mode control */
        g_i2cTxBuf[1] = ADXL_ODR_1600HZ;    /* Normal power mode, 1600.00 Hz output data rate */
        returnval = i2cBatchWrite (ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);
        DELAY_US(5);
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        g_i2cTxBuf[0] = ADXL_FIFO_CTL;  /* FIFO control */
        g_i2cTxBuf[1] = 0x00U;              /* Bypass FIFO MODE don't require set the register */
        returnval = i2cBatchWrite (ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2);
        DELAY_US(5);
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        /* Measuremente mode: exits from configuration mode */
        g_i2cTxBuf[0] = ADXL_POWER_CTL;    /* Power-saving features control */
        g_i2cTxBuf[1] = 0x08U;                /* Places the accel into measurement mode */
        returnval = i2cBatchWrite (ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2);
        DELAY_US(5);
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        for (i = 0; i < 100; i++)
        {
            returnval = i2cBatchRead(ADXL_SLAVE_ADDRESS7, ADXL_DATAX0, g_i2cRxBuf, 6U);
            if (returnval != 0U)
            {
                X_ST_ON[i] = ((g_i2cRxBuf[1] << 8) | g_i2cRxBuf[0]);
                Y_ST_ON[i] = ((g_i2cRxBuf[3] << 8) | g_i2cRxBuf[2]);
                Z_ST_ON[i] = ((g_i2cRxBuf[5] << 8) | g_i2cRxBuf[4]);
            }
        }
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        /* Standby mode: goes to configuration mode */
        g_i2cTxBuf[0] = ADXL_POWER_CTL;    /* Power-saving features control */
        g_i2cTxBuf[1] = 0x00U;              /* Go into standby mode to configure the device */
        returnval = i2cBatchWrite (ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);
        DELAY_US(5);
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        g_i2cTxBuf[0] = ADXL_DATA_FORMAT;    /* Data format control */
        g_i2cTxBuf[1] = 0x0CU;    /* +/-16g, right justified, full resolution, self-test disabled */
        returnval = i2cBatchWrite (ADXL_SLAVE_ADDRESS7, g_i2cTxBuf, 2U);
        DELAY_US(5);
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        for (i = 0; i < 100; i++)
        {
            returnval = i2cBatchRead (ADXL_SLAVE_ADDRESS7, ADXL_DATAX0, g_i2cRxBuf, 6U);
            if (returnval != 0U)
            {
                 X_ST_OFF[i] = ((g_i2cRxBuf[1] << 8U) | g_i2cRxBuf[0]);
                 Y_ST_OFF[i] = ((g_i2cRxBuf[3] << 8U) | g_i2cRxBuf[2]);
                 Z_ST_OFF[i] = ((g_i2cRxBuf[5] << 8U) | g_i2cRxBuf[4]);
            }
        }
    }
    else if (returnval != 0U)    /* Return 0 if occur an error */
    {
        for (i = 0; i < 100; i++)
            {
                X_ON += X_ST_ON[i];
                Y_ON += Y_ST_ON[i];
                Z_ON += Z_ST_ON[i];

                X_OFF += X_ST_OFF[i];
                Y_OFF += Y_ST_OFF[i];
                Z_OFF += Z_ST_OFF[i];
            }

            X_ON = X_ON / 100;
            Y_ON = Y_ON / 100;
            Z_ON = Z_ON / 100;
            X_OFF = X_OFF / 100;
            Y_OFF = Y_OFF / 100;
            Z_OFF = Z_OFF / 100;

            X_ST = (int16_t)X_ON - (int16_t)X_OFF;
            Y_ST = (int16_t)Y_ON - (int16_t)Y_OFF;
            Z_ST = (int16_t)Z_ON - (int16_t)Z_OFF;

            if ((X_ST < 50) || (X_ST > 540))
            {
                g_ADXL_Tested = 0x00U;
            }

            else if ((Y_ST < -540) || (Y_ST > -50))
            {
                g_ADXL_Tested = 0x00U;
            }

            else if ((Z_ST < 75) || (Z_ST > 875))
            {
                g_ADXL_Tested = 0x00U;
            }
            else
            {
            	g_ADXL_Tested = 0x01U;
            }
    }


    return (returnval);
}



/*******************************************************************************
* Function Name  : ADXL_get_data
* Input          : None
* Output         : uint8_t* i2cBuf
* Return         : 1 if success, 0 if fail
* Description    : 
*******************************************************************************/
uint8_t adxl_get_data ( )
{
    uint8_t returnval;

    returnval = i2cBatchRead (ADXL_SLAVE_ADDRESS7, ADXL_DATAX0, g_i2cRxBuf, 6U);

    return (returnval);
}
