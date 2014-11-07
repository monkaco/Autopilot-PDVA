/******************************************************************************
* FILENAME:    dsp_comm.c
*
* DESCRIPTION:
*       Communication routines.
*        Functions used to configure communication peripherals, such as
*       I2C, SPI and UART;
*       See TMS320F28335 for detailed description.
*
* FUNCTIONS:
*       void    Gpio_Select (void)
*
* VERSION DATE        WHO                DETAIL
* 1.0     30 Aug 2014 Rogerio Lima       Comm's function grouped in this file.
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

#include "dsp_types.h"
#include "dsp_comm.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Gpio.h"

uint8_t* SCI_TX_Message;
uint8_t SciTxQtd;            // quantity to be send
uint8_t SciTxStatus;
uint16_t SpiTxQtd;
uint8_t SpiTxStatus;

#ifdef ___SPI_8BITS
uint8_t* SPI_TX_Message_C;
uint8_t SPI_RX_Message[16];
#endif

#ifdef ___SPI_16BITS
uint16_t *SPI_TX_Message_W;
uint16_t SPI_RX_Message[16];
#endif



/******************************************************************************
* FUNCTION NAME  : SCIA_Init
* INPUT          : None
* OUTPUT         : None
* RETURN         : No return
* DESCRIPTION    : Configure UART SCI-A.
******************************************************************************/
void scia_init ()
{
    SciaRegs.SCICCR.all = 0x0007;            /* 1 stop bit,  No loopback
                                               No parity,8 uint8_t bits,
                                                 async mode, idle-line protocol */

    SciaRegs.SCICTL1.all = 0x0003;              /* enable TX, RX, internal SCICLK,
                                               Disable RX ERR, SLEEP, TXWAKE  */

    /* SYSCLOCKOUT = 150MHz;
     * LSPCLK = 1/4 = 37.5 MHz
     * BRR = (LSPCLK / (9600 x 8)) -1
     * BRR = 487  gives 9605 Baud
     * BRR = 121  gives 38422 Baud
     * BRR =  40  gives 114329 Baud */
    SciaRegs.SCIHBAUD    = 40 >> 8U;         /* Highbyte */
    SciaRegs.SCILBAUD    = 40 & 0x00FF;        /* Lowbyte */

    SciaRegs.SCICTL2.bit.TXINTENA = 0U;      /* Disable SCI-A Tx-ISR buffer */
    SciaRegs.SCICTL2.bit.RXBKINTENA = 1U;    /* Disable SCI_A Rx-ISR buffer */

    SciaRegs.SCIFFTX.all = 0xC060U;            /* bit 15 = 1 : relinquish from Reset */
                                            /* bit 14 = 1 : Enable FIFO */
                                            /* bit 6 = 1 :  CLR TXFFINT-Flag */
                                            /* bit 5 = 1 :  enable TX FIFO match */
                                            /* bit 4-0 :  TX-ISR, if TX FIFO is 0(empty) */

    SciaRegs.SCIFFCT.all = 0x0000U;          /* Set FIFO transfer delay to 0 */
    SciaRegs.SCIFFRX.all = 0xE070U;          /* Rx interrupt level = 16 */
    SciaRegs.SCICTL1.all = 0x0023U;          /* Relinquish SCI from Reset */
}



/******************************************************************************
* FUNCTION NAME  : SPIA_Init
* INPUT          : None
* OUTPUT         : None
* RETURN         : No return
* DESCRIPTION    : Configure SPI-A.
******************************************************************************/
void spia_init ()
{
    // InitSpiaGpio();

    /* Reset SPI => Initialize SPI FIFO registers */
    SpiaRegs.SPICCR.bit.SPISWRESET = 0U;

    /* SPICCR: SPI-A Configuration Control Register */
    SpiaRegs.SPICCR.bit.SPICHAR = 0x7;      /* 8-bit uint8_tacter */
    SpiaRegs.SPICCR.bit.CLKPOLARITY = 1;    /* Falling edge data transfer */

    /* SPICTL: SPI-A Operation Control Register */
    SpiaRegs.SPICTL.all = 0U;
    SpiaRegs.SPICTL.bit.SPIINTENA = 1;      /* Disable interrupt */
    SpiaRegs.SPICTL.bit.TALK = 1;           /* Transmission enabled */
    SpiaRegs.SPICTL.bit.MASTER_SLAVE = 0U;   /* Slave */
    SpiaRegs.SPICTL.bit.CLK_PHASE = 0U;      /* No clock delay */
    SpiaRegs.SPICTL.bit.OVERRUNINTENA = 0U;  /* Disable overrun interrupt */

    SpiaRegs.SPISTS.all = 0x0000U;             /* SPISTS: SPI-A Status Register */

    /* SPIFFTX: SPI-A FIFO Transmit Register */
    SpiaRegs.SPIFFTX.all = 0U;               /* Reset TX FIFO */
    SpiaRegs.SPIFFTX.bit.TXFFIL = 0U;        /* TX-ISR, if TX FIFO is 0 (empty) */
    SpiaRegs.SPIFFTX.bit.TXFFIENA = 1U;      /* Do not enable TX FIFO interrupt... */
                                            /* ...until there is something to send  */
                                            /* ...enable interrupt on TX FIFO match */
    SpiaRegs.SPIFFTX.bit.TXFFINTCLR = 1U;    /* Clear TXFFINT flag */
    SpiaRegs.SPIFFTX.bit.TXFIFO = 0U;        /* Reset TX FIFO (pointer to 0) */
    SpiaRegs.SPIFFTX.bit.SPIFFENA = 1U;      /* Enable SPI FIFO Enhancements */
    SpiaRegs.SPIFFTX.bit.SPIRST = 1U;        /* Resumes SPI FIFO for transmit and receive */

    /* SPIFFRX: SPI-A FIFO Receive Register*/
    SpiaRegs.SPIFFRX.all = 0U;               /* Reset RX FIFO */
    SpiaRegs.SPIFFRX.bit.RXFFIL = 16U;       /* RX-ISR, if RX FIFO is 16 (full) */
    SpiaRegs.SPIFFRX.bit.RXFFIENA = 1U;      /* Enable interrupt on RX FIFO match */
    SpiaRegs.SPIFFRX.bit.RXFFINTCLR = 1U;    /* Clear RXFFINT flag */
    SpiaRegs.SPIFFRX.bit.RXFIFORESET = 1U;   /* Reset RX FIFO (pointer to 0) */
    SpiaRegs.SPIFFRX.bit.RXFFOVFCLR = 1U;    /* Clear RXFFOVF flag */

    /* SPIFFCT: SPI-A FIFO Control Register */
      SpiaRegs.SPIFFCT.all = 0x00U;            /* Set FIFO transmit delay to 0 */

    /* SPIPRI: SPI-A Priority Control Register */
    SpiaRegs.SPIPRI.bit.FREE = 1U;           /* Halts due emulation don't stop transmission...*/
    SpiaRegs.SPIPRI.bit.SOFT = 1U;           /* ...of bytes or FIFOs */

    SpiaRegs.SPICCR.bit.SPISWRESET = 1U;     /* Enable SPI */

    SpiaRegs.SPIFFTX.bit.SPIRST = 0U;        /* Reset the TX & RX Buffers */
    SpiaRegs.SPIFFTX.bit.SPIRST = 1U;

    SpiaRegs.SPIFFTX.bit.TXFIFO = 1U;          /* Re-enable TX FIFO operation */

}


/******************************************************************************
* FUNCTION NAME  : I2CA_Init
* INPUT          : None
* OUTPUT         : None
* RETURN         : No return
* DESCRIPTION    : Configure I2C-A.
******************************************************************************/
void i2ca_init(void)
{
    I2caRegs.I2CMDR.bit.IRS = 0U;            /* Reset the I2C module */

    /* I2C Prescale Register */
    I2caRegs.I2CPSC.all = 14U;       /* Internal I2C module clock = SYSCLK/(PSC +1) */
                                    /*                           = 10 MHz */

    I2caRegs.I2CCLKL = 45U;          /* Tmaster = (PSC +1)[ICCL + 5 + ICCH + 5] / 150MHz */
    I2caRegs.I2CCLKH = 45U;          /* Tmaster =  15 [ICCL + ICCH + 10] / 150 MHz
                                     * d = 5  for IPSC > 1

                                     * for I2C 10 kHz:
                                     * Tmaster = 100 탎 * 150 MHz / 15
                                     *         = 1000
                                     *         = (ICCL + ICCH +10)
                                     * ICCL + ICCH = 990
                                     * ICCL = ICH = 990/2 = 495

                                     * for I2C 50 kHz:
                                     * Tmaster = 20 탎 * 150 MHz / 15
                                               = 200
                                               = (ICCL + ICCH +10)
                                     * ICCL + ICCH = 190
                                     * ICCL = ICH = 190/2 = 95

                                     * for I2C 100 kHz:
                                     * Tmaster = 10 탎 * 150 MHz / 15
                                     *         = 100
                                     *         = (ICCL + ICCH +10)
                                     * ICCL + ICCH = 90
                                     * ICCL = ICH = 90/2 = 45

                                     * for I2C 400 kHz:
                                     * Tmaster = 2.5 탎 * 150 MHz / 15
                                     *         = 25
                                     *         = (ICCL + ICCH +10)
                                     * ICCL + ICCH = 15
                                     * ICCL = 10
                                     * ICH = 5
                                     */

    I2caRegs.I2CMDR.bit.IRS = 1U;    /* Take I2C out of reset */
}
