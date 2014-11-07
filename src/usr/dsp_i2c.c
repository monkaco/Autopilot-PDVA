/******************************************************************************
* FILENAME:    dsp_i2c.c
*
* DESCRIPTION:
*       High-level functions for I2C module..
*
* FUNCTIONS:
*    uint8_t i2cBatchWrite ( uint8_t, uint8_t*, uint8_t)
*    uint8_t i2cBatchRead ( uint8_t, uint8_t, uint8_t*, uint8_t)
*       void I2C_get_data (I2C_RawSensorData*)
*       void I2C_init_sensors (void)
*
* NOTES:
*       Functions to implement high-level procedures of the I2C peripheral.
*
* REFERENCES:
*       Adapted from CH Robotics.
*
* START DATE:    05 Set 2011
*
* CHANGES :
*
* VERSION DATE        WHO                    DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     06 Set 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

/*
 * SECTION ORDER
 *     1. Comment block
 *     2. Include statements
 *     3. Definitions: data type, constants, macros
 *     4. Static data declarations
 *     5. Private functions prototypes
 *     6. Public function bodies
 *     7. Private function bodies
 *
 */

#include "my_stdint.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "DSP2833x_Device.h"
#include "dsp_sensorhead_types.h"
#include "dsp_i2c.h"
#include "dsp_i2c_hsc.h"
#include "dsp_i2c_bmp085.h"
#include "dsp_i2c_adxl345.h"
#include "dsp_i2c_hmc5883.h"
#include "dsp_i2c_itg3200.h"



/* Global definitions of i2c data types are made here. Their declarations
 * occurs on the dependencies (dsp_i2c_xxxx.c source-files) using the
 * keyword "extern".                                                         */
uint8_t g_i2cTxBuf[I2C_TX_BUFSIZE];
uint8_t g_i2cRxBuf[I2C_RX_BUFSIZE];
uint8_t g_i2cBytesToTransmit;
uint8_t g_i2cBytesToReceive;
uint8_t g_i2cReadPrelude;
uint8_t g_i2cTxPtr;
uint8_t g_i2cRxPtr;
uint8_t g_i2cBusy;
uint8_t g_i2cBusError;
uint8_t g_i2cDirection;
uint8_t g_i2cCurrentSlaveAddress;
uint8_t* i2c_status_flag;
/* Variable declared at source file "dsp_i2c_bmp085" */
extern bmp085_data_t bmp_data_buffer;


/*******************************************************************************
* Function Name  : i2cBatchWrite
* Input          : uint8_t address7, uint8_t* txBuffer, uint8_t bytesToWrite
* Output         : uint8_t* status_flag
* Return         : 1 if success, 0 if fail
* Description    : Writes a pre-defined number of bytes (bytesToWrite) stored
                  in (txBuffer) into the slave addressed by (address7) address.
*******************************************************************************/
uint8_t i2cBatchWrite (const uint8_t address7, uint8_t* txBuffer, const uint8_t bytesToWrite)
{
    static uint16_t i;
    static uint8_t returnval;

    I2caRegs.I2CSAR = address7;    /* I2C slave address register */

    I2caRegs.I2CCNT    = bytesToWrite;                /* Number of bytes to send */
    I2caRegs.I2CMDR.all = 0x6E20;                /* Master-transmitter, Start, Stop */

    for (i = 0U; i < bytesToWrite; i++)        /* Send data bytes */
    {
        I2caRegs.I2CDXR = txBuffer[i];            /* Loads DSP's buffet to transmit data */
        while (I2caRegs.I2CSTR.bit.XRDY == 0U);    /* Aguarda fim da transmissão */
    }

    /*##### WARNING #####*/
    while (I2caRegs.I2CSTR.bit.SCD == 0U);        /* Aguarda Stop condition */

    I2caRegs.I2CSTR.bit.SCD = 1;                /* Clear Stop condition flag */

    returnval = I2caRegs.I2CSTR.bit.NACK;        /* 0: ACK, 1: NACK */

    return returnval;
}


/*******************************************************************************
* Function Name  : i2cBatchRead
* Input          : uint8_t address7, uint8_t device_start_address, 
                   uint8_t bytesToRead
* Output         : uint8_t* rxBuffer
* Return         : 1 if success, 0 if fail
* Description    : Reads a pre-defined number of bytes (bytesToRead) stored
                  in (rxBuffer) started in the register (device_start_address)
                  from the slave addressed by (address7) address.
*******************************************************************************/
uint8_t i2cBatchRead (uint8_t address7, uint8_t device_start_address, uint8_t* rxBuffer, uint8_t bytesToRead)
{
    static int16_t i;
    static uint8_t returnval;

    I2caRegs.I2CSAR = address7;                    /* I2C slave address register */
    I2caRegs.I2CCNT = 1;                        /* Enviar 1 byte */
    // Send start address for read
    I2caRegs.I2CDXR = device_start_address;        /* Endereço do registrador */
    I2caRegs.I2CMDR.all = 0x6620;                /* Master-transmitter, Start, No_Stop */
    while (I2caRegs.I2CSTR.bit.ARDY == 0U);        /* 1 = a previous cycle has completed (wait for access ready condition) */

    returnval = I2caRegs.I2CSTR.bit.NACK;        /* 0: ACK, 1: NACK */

     // Send new start condition and initiate read
    I2caRegs.I2CCNT    = bytesToRead;                /* Enviar 1 byte */
    I2caRegs.I2CMDR.all = 0x6C20;                /* Master-receiver, Start, Stop after all bytes trans */

    for (i = 0; i < bytesToRead; i++)
    {
        while (I2caRegs.I2CSTR.bit.RRDY == 0U);    /* Aguarda dado ficar disponível no registrador */
        rxBuffer[i] = I2caRegs.I2CDRR;            /* Lê dado do buffer do DSP */
    }

    while (I2caRegs.I2CSTR.bit.SCD == 0U);        /* Aguarda Stop condition */
    I2caRegs.I2CSTR.bit.SCD = 1;

    return returnval;
}

/*******************************************************************************
* Function Name  : i2cBatchRead
* Input          : uint8_t address7, uint8_t device_start_address, 
                   uint8_t bytesToRead
* Output         : uint8_t* g_sensor_data_raw
* Return         : 1 if success, 0 if fail
* Description    : Reads a pre-defined number of bytes (bytesToRead) stored
                  in (rxBuffer) started in the register (device_start_address)
                  from the slave addressed by (address7) address.
*******************************************************************************/
void i2c_get_data (sensor_data_raw_t* raw_data)
{

    /* Solicita dados de pressão barométrica - BMP085 */
    bmp_up_request(bmp_data_buffer.oversampling_setting);
    DELAY_US(5);

    itg_get_data ();
    DELAY_US(5);
    raw_data->gyro_temperature = ((g_i2cRxBuf[0] << 8) | g_i2cRxBuf[1]);
    raw_data->gyro_x = ((g_i2cRxBuf[2] << 8) | g_i2cRxBuf[3]);    /* Wx */
    raw_data->gyro_y = ((g_i2cRxBuf[4] << 8) | g_i2cRxBuf[5]);    /* Wy */
    raw_data->gyro_z = ((g_i2cRxBuf[6] << 8) | g_i2cRxBuf[7]);    /* Wz */
    raw_data->new_gyro_data = 1;

    adxl_get_data ( );
    DELAY_US(5);
    raw_data->accel_x = ((g_i2cRxBuf[1] << 8) | g_i2cRxBuf[0]);    /* Ax */
    raw_data->accel_y = ((g_i2cRxBuf[3] << 8) | g_i2cRxBuf[2]);    /* Ay */
    raw_data->accel_z = ((g_i2cRxBuf[5] << 8) | g_i2cRxBuf[4]);    /* Az */
    raw_data->new_accel_data = 1;

    hmc_get_data ( );
    DELAY_US(5);
    raw_data->mag_x = ((g_i2cRxBuf[0] << 8) | g_i2cRxBuf[1]);    /* Hx */
    raw_data->mag_y = ((g_i2cRxBuf[2] << 8) | g_i2cRxBuf[3]);    /* Hy */
    raw_data->mag_z = ((g_i2cRxBuf[4] << 8) | g_i2cRxBuf[5]);    /* Hz */
    raw_data->new_mag_data = 1;

    hsc_get_data ();
    DELAY_US(5);
    raw_data->diff_pressure = ((g_i2cRxBuf[0] << 8) | g_i2cRxBuf[1]);
    raw_data->new_diff_pressure_data = 1;

    bmp_pressure_get_data (&bmp_data_buffer);    // Realiza leitura no barômetro BMP085
    raw_data->abs_pressure = bmp_data_buffer.UP;
    raw_data->new_abs_pressure_data = 1;

}


/*******************************************************************************
* Function Name  : I2C_Read
* Input          : none
* Output         : I2C_RawSensorData* i2c_data
* Return         : 1 if success, 0 if fail
* Description    : Reads all data from the sensors which are connected to the 
                   I2C bus.
*******************************************************************************/
void i2c_init_sensors()
{

    DELAY_US(5);
    bmp_init (&bmp_data_buffer);

    DELAY_US(5);
    itg_init ();       /* Initialises gyrometer */

    DELAY_US(5);
    adxl_init ();          /* Initialises accelerometer */

    DELAY_US(5);
    hmc_init ();           /* Initialises magnetometer */

    DELAY_US(5);

}
