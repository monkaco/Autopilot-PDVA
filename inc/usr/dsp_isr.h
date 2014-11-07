#ifndef DSP_ISR_H
#define DSP_ISR_H

/* SCI-A Transmit Interrupt Service */
interrupt void SCIA_TX_isr (void);

/* SCI-A Receive Interrupt Service */
interrupt void SCIA_RX_isr (void);

/* Timer0 Interrupt Service */
interrupt void cpu_timer0_isr (void);

/* Timer0 Interrupt Service */
interrupt void cpu_timer1_isr (void);

/* SPI Tx Interrupt Service */
interrupt void SPI_TxFifoIsr (void);

/* SPI Rx Interrupt Service */
interrupt void SPI_RxFifoIsr (void);

/* SPI Chip Select Interrupt Service */
interrupt void spi_cs_isr(void);

/* SPI Chip Select Interrupt Service */
interrupt void timing_isr(void);

/* ePWM1 Interrupt Service */
interrupt void ePWM1A_compare_isr(void);

/* I2C FIFO Interrupt Service */
/*interrupt void I2C_fifo_isr(void); */

/* I2C basic Interrupt Service */
/* interrupt void I2C_basic_isr(void); */


#endif // DSP_ISR_H
