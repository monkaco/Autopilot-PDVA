/******************************************************************************
* FILENAME:    dsp_i2c_itg3200.c
*
* DESCRIPTION:
*       Functions and routines to implement driver for the ITG3200.
*
* FUNCTIONS:
*       void    Gpio_Select (void)
*
* NOTES:
*       ITG3200 is a tri-axis digital gyrometer which uses protocol I2C to transmit 
*       and receive data.
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
#include "dsp_i2c_itg3200.h"

uint8_t g_ITG_Initialized = 0U;
extern uint8_t g_i2cTxBuf[I2C_TX_BUFSIZE];
extern uint8_t g_i2cRxBuf[I2C_RX_BUFSIZE];


/*******************************************************************************
* Function Name  : ITG_init
* Input          : None
* Output         : uint8_t* status_flag
* Return         : 1 if success, 0 if fail
* Description    : Initializes the ITG3200 angular rate sensor.
*******************************************************************************/
uint8_t itg_init ()
{
    static uint8_t txBuf[4];
    static uint8_t returnval;
    
    txBuf[0] = ITG_REG_SMPL;
    txBuf[1] = 0x04U;     /* Sample rate division = 4+1 -> 1kHz/(4+1) = 200Hz */
    txBuf[2] = 0x1CU;     /* Internal LPF at 20 Hz, +/- 2000 deg/s full-scale range */
    txBuf[3] = 0x90U;     /* No interrupt pins utilized (gyros sampled as soon as the processor is ready to get new data. */
    
    returnval = i2cBatchWrite (ITG_SLAVE_ADDRESS7, txBuf, 4U);

    if (returnval != 0U)    /* Return 0 if occur an error */
    {
        // Delay necessário para configuração
        DELAY_US(2000);
        EALLOW;
            SysCtrlRegs.WDKEY = 0x55U;    /* service WD #1 */
            SysCtrlRegs.WDKEY = 0xAAU;    /* service WD #2 */
        EDIS;
        DELAY_US(2000);
        
        txBuf[0] = ITG_REG_PWR;
        txBuf[1] = 0x01U;                /* Set clock to X Gyro reference */
        
        returnval = i2cBatchWrite (ITG_SLAVE_ADDRESS7, txBuf, 2U);
        DELAY_US(10);
    }

    return (returnval);
}


/*******************************************************************************
* Function Name  : ITG_get_data
* Input          : None
* Output         : uint8_t* i2cBuf
* Return         : 1 if success, 0 if fail
* Description    : Collect data from the gyro sensor
*******************************************************************************/
uint8_t itg_get_data (void)
{
    static int8_t returnval;
    
    returnval = i2cBatchRead (ITG_SLAVE_ADDRESS7, ITG_REG_TEMP_HIGH, g_i2cRxBuf, 8U);
  
    return (returnval);

}
