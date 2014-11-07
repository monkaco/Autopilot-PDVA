/******************************************************************************
* FILENAME:    dsp_i2c_hsc.c
*
* DESCRIPTION:
*       Functions for interacting with HSC differential pressure.
*
* FUNCTIONS:
*       void    HSC_init (uint8_t*)
*       void    HSC_get_data (void)
*
* NOTES:
*       ITG3200 is a tri-axis digital gyrometer which uses protocol I2C to transmit
*       and receive data.
*
*       CODE:   HSC-D-RR-N-010MD-2A3
*               HSC:     Serie
*               D:        DIP (Dual Inline Pin)
*               RR:        Dual radial barbed ports in the same side
*               N:        Gases only, no special options
*               010MD:    +/- 10 mbar
*               2:        I2C, address 0x28
*               A:        10% to 90% of 2^14 counts
*               3:        3.3V supply voltage
*
* REFERENCES:
*       Adapted from CH Robotics
*
* START DATE:    05 Set 2011
*
* CHANGES :
*
* VERSION DATE        WHO                  DETAIL
* 1.0     05 Set 2011 Rogerio Lima         Start-up coding.
*                     Plínio Pereira
* -----------------------------------------------------------------------------
* 2.0     06 Set 2014 Rogerio Lima         Improving code quality rewriting the
*                                          code and correcting errors.
******************************************************************************/

#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"
#include "my_stdint.h"
#include "dsp_sensorhead_types.h"
#include "dsp_i2c.h"
#include "dsp_i2c_hsc.h"

uint8_t gHSC_Initialized = 0U;
uint16_t diff_pressure = 0U;
extern uint8_t g_i2cTxBuf[I2C_TX_BUFSIZE];
extern uint8_t g_i2cRxBuf[I2C_RX_BUFSIZE];


/*******************************************************************************
* Function Name  : HSC_init
* Input          : None
* Output         : None
* Return         : None
* Description    : Initializes the HSC differential pressure sensor

*******************************************************************************/
uint8_t hsc_init ()
{
    return (1U);
}


/*******************************************************************************
* Function Name  : HSC_get_data
* Input          : None
* Output         : uint8_t* i2cBuf
* Return         : 1 if success, 0 if fail
* Description    : 
*******************************************************************************/
uint8_t hsc_get_data ()
{
    static uint8_t returnval;
    static uint16_t i;

    I2caRegs.I2CSAR = HSC_SLAVE_ADDRESS7;        /* I2C slave address register */
    I2caRegs.I2CCNT    = 1U;                        /* Enviar 1 byte */

    /* Send new start condition and initiate read */
    I2caRegs.I2CCNT    = 2U;                        /* Lê 2 bytes do sensor de pressão dinâmica HSC */
    I2caRegs.I2CMDR.all = 0x6C20U;                /* Master-receiver, Start, Stop after all bytes trans. */

    for (i = 0; i < 2; i++)                    /* Lê 2 bytes do sensor de pressão dinâmica HSC */
    {
        /* WARNING */
        while (I2caRegs.I2CSTR.bit.RRDY == 0U);    /* Aguarda dado ficar disponível no registrador */
        /* WARNING */
        g_i2cRxBuf[i] = I2caRegs.I2CDRR;            /* Lê dado do buffer do DSP */
    }

    /* WARNING */
    while (I2caRegs.I2CSTR.bit.SCD == 0U);        /* Aguarda Stop condition */
    /* WARNING */
    I2caRegs.I2CSTR.bit.SCD = 1U;

    diff_pressure = g_i2cRxBuf[0] |= g_i2cRxBuf[1];

    returnval = I2caRegs.I2CSTR.bit.NACK;        /* 0: ACK, 1: NACK */

    return (~returnval);
}
