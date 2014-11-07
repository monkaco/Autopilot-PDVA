/******************************************************************************
* FILENAME:    dsp_i2c.h
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
* VERSION DATE        WHO                    DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     30 Aug 2014 Rogerio Lima         Improving code quality rewriting the
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

#ifndef DSP_I2C_H
#define DSP_I2C_H

#define    I2C_TX_BUFSIZE            16U
#define    I2C_RX_BUFSIZE            24U
#define    I2C_ACK_ATTEMPTS          5000U
#define    MAX_RETRIES               10000U
#define    I2C_TRANSMITTER           I2C_Direction_Transmitter
#define    I2C_RECEIVER              I2C_Direction_Receiver
#define    I2C_BIT_SET               1U
#define    I2C_BIT_CLEAR             0U
#define    I2C_ACK_DISABLE           1U
#define    I2C_ACK_ENABLE            0U
#define    I2C_SEND_START            1U
#define    I2C_NO_START              0U
#define    I2C_SEND_STOP             1U
#define    I2C_NO_STOP               0U
#define    I2C_SCL_PIN               GPIO_Pin_6
#define    I2C_SDA_PIN               GPIO_Pin_7
#define    I2C_PORT                  GPIOB
#define    I2C_ARBITRATION_LOST      10U
#define    I2C_NACK                  1U
#define    I2C_TIMEOUT               11U

/*------------------------------------------------------------------------------
  F28335 Register I2CMDR     
------------------------------------------------------------------------------*/
// BC Bits
#define I2C_BC_8BITS            0x0000
#define I2C_BC_1BITS            0x0001
#define I2C_BC_2BITS            0x0002
#define I2C_BC_3BITS            0x0003
#define I2C_BC_4BITS            0x0004
#define I2C_BC_5BITS            0x0005
#define I2C_BC_6BITS            0x0006
#define I2C_BC_7BITS            0x0007
// FDF
#define I2C_NO_FREE_DATA_FORMAT    0x0000
#define I2C_FREE_DATA_FORMAT    0x0008
// STB
#define I2C_NO_START_BYTE        0x0000
#define I2C_START_BYTE            0x0010
// IRS
#define I2C_RESET                0x0000
#define I2C_ENABLED                0x0020
// DLB
#define I2C_NO_LOOPBACK            0x0000
#define I2C_LOOPBACK            0x0040
// RM
#define I2C_NO_REPEAT            0x0000
#define I2C_REPEAT                0x0080
/* Defines the length of time the i2c software will wait for clock stretching *
 * the number of attempts simply corresponds with the number of iterations    *
 * through a for loop.                                                           */
#define    I2C_MAX_ATTEMPTS        1000
/* Macro definitions */
#define    I2C_DELAY_INIT()        int16_t _counter;
#define    I2C_DELAY()                for( _counter = 0; _counter < 5; _counter++ ) { asm volatile("mov r0, r0"); }
#define    I2C_DELAY_SHORT()        asm volatile("mov r0, r0")


/* Structure for holding raw sensor data from I2C bus
typedef struct __I2CData {
     Gyrometers
    int16_t W_x;
    int16_t W_y;
    int16_t W_z;

    int16_t new_gyro_data;

     Accelerometers
    int16_t A_x;
    int16_t A_y;
    int16_t A_z;

     Flag specifies whether there is new accel data in the sensor data structure
    int16_t new_accel_data;

     Magnetometers
    int16_t H_x;
    int16_t H_y;
    int16_t H_z;

     Flag specifies whether there is new magnetometer data in the sensor data structure
    int16_t new_mag_data;
    
     Rate gyro temperature measurement
    int16_t gyro_temperature;

     Differential pressure
    int16_t diff_press;

     Flag specifies whether there is new differential pressure data in the sensor data structure
    int16_t new_diff_press_data;

     Absolute pressure
    int16_t abs_press;

     Flag specifies whether there is new differential pressure data in the sensor data structure
    int16_t new_abs_press_data;


} I2C_RawSensorData;*/

// Prototype statements for functions found within this file.
void Gpio_select_I2C(void);

// Software-emulated i2c function calls.  Use these ones.
uint8_t i2cBatchWrite (const uint8_t address7, uint8_t* txBuffer, const uint8_t bytesToWrite);
uint8_t i2cBatchRead (const uint8_t address7, const uint8_t device_start_address, uint8_t* rxBuffer, const uint8_t bytesToRead);

void i2c_get_data (sensor_data_raw_t* raw_data);
void i2c_init_sensors (void);


#endif
