/******************************************************************************
* FILENAME:    dsp_system.c
*
* DESCRIPTION:
*       Contain "main" and all other primary functions.
*
* FUNCTIONS:
*       void    main (void)
*
* NOTES:
*       TODO.
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
#include "dsp_system.h"
#include "dsp_comm.h"
#include "dsp_sensorhead_types.h"
#include "dsp_conversions.h"

#include "Application_Control_Variables.h"
#include "Application_IO_Functions.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Gpio.h"
#include "DSP2833x_GlobalPrototypes.h"
#include "DSP2833x_Examples.h"
#include "dsp_gps.h"
#include "dsp_isr.h"
#include "dsp_quat.h"
#include "dsp_matrix.h"
#include "dsp_i2c.h"
#include "dsp_ekf.h"
#include <string.h>


/* Flash functions */
extern Uint16  RamfuncsLoadStart;
extern Uint16  RamfuncsLoadEnd;
extern Uint16  RamfuncsRunStart;


/* Prototype statements for functions found within this file. */
void escalonador (void);
void toggle_led (void);




/* Global variables */
ahrs_states_t g_states;
sensor_data_raw_t g_sensor_data_raw;
sensor_data_scaled_t g_sensor_data_scaled;
digital_filter_data_t filtered_data;



//struct gps_data_translated gps_dat;
//struct gps_data_translated gps_dat;
//unsigned char g_sciTxBuf[68];
//float gps_speed, gps_heading;
// Global Variables
//Uint32 Timer0_count_before=0, Timer0_count_after=0, diff=0;        // Timer0 counter
//Uint32 idMessage = 0;



//###########################################################################
//                        main code                                    
//###########################################################################
void main (void)
{
    InitSysCtrl();    // Basic Core Initialization
                    // SYSCLK=150MHz, HISPCLK=75MHz, LSPCLK=37.5MHz
    EALLOW;
           SysCtrlRegs.WDCR = 0x00E8;    // Re-enable the watchdog 
       EDIS;                            // 0x00E8  to disable the Watchdog , Prescaler = 1
                                       // 0x00AF  to NOT disable the Watchdog, Prescaler = 64

    memcpy(&RamfuncsRunStart, &RamfuncsLoadStart, &RamfuncsLoadEnd - &RamfuncsLoadStart);
    InitFlash();    // call InitFlash in RAM (SARAM - L0)


    gpio_select();    // GPIO9, GPIO11, GPIO34 and GPIO49 as output
                    // to 4 LEDs at Peripheral Explorer        

    InitPieCtrl();        // default status of PIE; in DSP2833x_PieCtrl.c
    
    InitPieVectTable(); // init PIE vector table; in DSP2833x_PieVect.c
    
    // re-map PIE - entry for SCI-A-TX and SCI-A-RX
    EALLOW;  
       PieVectTable.SCITXINTA = &SCIA_TX_isr;
    PieVectTable.SCIRXINTA = &SCIA_RX_isr;
    PieVectTable.SPIRXINTA = &SPI_RxFifoIsr;
    PieVectTable.SPITXINTA = &SPI_TxFifoIsr; 
    //PieVectTable.I2CINT1A = &I2C_basic_isr;
    //PieVectTable.I2CINT2A = &I2C_fifo_isr;  
    PieVectTable.XINT1 = &spi_cs_isr;
    PieVectTable.XINT2 = &timing_isr;
    PieVectTable.TINT0 = &cpu_timer0_isr;
    PieVectTable.XINT13 = &cpu_timer1_isr;
    PieVectTable.EPWM1_INT = &ePWM1A_compare_isr;
       EDIS;    
           
    InitCpuTimers();        /* basic setup CPU Timer0, 1 and 2 */
    setup_epwm1a ();        /* Basic ePWM1A setup */
       scia_init ();              /* Initialize SCI */
       spia_init ();            /* Initialize SPI */
    i2ca_init ();            /* Initialize I2C */
   
    ConfigCpuTimer(&CpuTimer0, 150, 20100);    // CPU - Timer0 at 20.1 milliseconds
    ConfigCpuTimer(&CpuTimer1, 150, 5000);    // CPU - Timer1 at 5 milliseconds
    
    // Enable SPI-A RX Interrupt Group6 interupt 1
    PieCtrlRegs.PIEIER6.bit.INTx1 = 1U;
    // Enable SPI-A TX Interrupt Group6 interupt 2
    PieCtrlRegs.PIEIER6.bit.INTx2 = 1U;
    // Enable SCI-A RX Interrupt Group9 interupt 1
    PieCtrlRegs.PIEIER9.bit.INTx1 = 1U;
    // Enable SCI-A TX Interrupt Group9 interupt 2
    PieCtrlRegs.PIEIER9.bit.INTx2 = 1U;
    // Enable I2C-basic Interrupt Group8 interupt 1
    //PieCtrlRegs.PIEIER8.bit.INTx1 = 1U;   // i2c - basic  
    // Enable I2C-FIFO Interrupt Group8 interupt 2
    //PieCtrlRegs.PIEIER8.bit.INTx2 = 1U;   // i2c - FIFO 
    // Enable GPIO23-SPI_CS External Interrupt (XINT1) Group1 interupt 4 
    PieCtrlRegs.PIEIER1.bit.INTx4 = 1U;
    // Enable GPIO20-Timing External Interrupt (XINT2) Group1 interupt 5 
    PieCtrlRegs.PIEIER1.bit.INTx5 = 1U;
    // Enable Timer0 Interrupt Group1 interrupt 7
    PieCtrlRegs.PIEIER1.bit.INTx7 = 1U;
    // Enable EPWM1A INT in the PIE: Group 3 interrupt 1
       PieCtrlRegs.PIEIER3.bit.INTx1 = 1U;

    // External interrupt XINT1 configuration for spi_cs
    XIntruptRegs.XINT1CR.bit.ENABLE = 1U;     // Enables external interrupt
    XIntruptRegs.XINT1CR.bit.POLARITY = 3U;     // 00 = falling edge (high-to-low transition)
                                            // 01 = rising edge (low-to-high transition)
                                            // 10 = falling edge (high-to-low transition)
                                             // 11 = rising and falling edge

    // External interrupt XINT2 configuration for timing
    XIntruptRegs.XINT2CR.bit.ENABLE = 1U;     // Enables external interrupt
    XIntruptRegs.XINT2CR.bit.POLARITY = 0U;     // 00 = falling edge (high-to-low transition)
                                            // 01 = rising edge (low-to-high transition)
                                            // 10 = falling edge (high-to-low transition)
                                            // 11 = rising and falling edge
    
    // External interrupt XINT13 configuration for CpuTimer1
    EALLOW;
    XIntruptRegs.XNMICR.bit.ENABLE = 0U;     // Timer1 connected to XINT13
     XIntruptRegs.XNMICR.bit.SELECT = 0U;     // Disable NMI
    EDIS;


    // Enable group interrupt
    IER |= 0x01U;        // enable INT1 for /SPISTE and Timing
    IER |= 0x04U;        // enable INT3 for ePWM1
    IER |= 0x20U;        // enable INT6 for SPI
    //IER |= 0x80U;        // enable INT8 for I2C
    IER |= 0x100U;        // enable INT9 for SCIA-TX and SCIA-RX
    IER |= 0x1000U;        // enable INT13 for CPU-Timer 1
    
    // Enable global Interrupts and higher priority real-time debug events:
    EnableInterrupts();
       ERTM;   // Enable Global realtime interrupt DBGM
       
    CpuTimer0Regs.TCR.bit.TSS = 0U;    // start timer0


    DELAY_US(50000);

    // Initializes all I2C sensors
    i2c_init_sensors ();

    // EKF initialization
    ekf_init (&g_states);

    // Low-pass digital filter initialization
    // LPF_Butter_Init(&filtered_dat);

    escalonador();
}     


    
     


//===========================================================================
// End of SourceCode.
//===========================================================================






void escalonador ()
{
    extern int GpsMessageReady;
    extern unsigned char I2CRead_flag;
    extern char SPI_received_ok;
    while (1U)
    {

//        EALLOW;
//        SysCtrlRegs.WDKEY = 0x55U;            // Service watchdog #1
//        SysCtrlRegs.WDKEY = 0xAAU;            // Service watchdog #2
//        EDIS;

        if (GpsMessageReady)
        {
//            Process_GPS(&gps_dat);
            GpsMessageReady = 0U;
        }

        if (I2CRead_flag)
        {
            I2CRead_flag = 0U;
            i2c_get_data (&g_sensor_data_raw);

            apply_sensors_scale_factor (&g_sensor_data_scaled, &g_sensor_data_raw);
            // LPF_Butter( &states, &filtered_dat );
            ekf_estimate_states (&g_states, &g_sensor_data_scaled);
            //SPI_Gumstix_write( &states, &i2c_dat, &gps_dat);
            toggle_led ();
            //printf("acc %d %d %d\n", i2c_dat.A_x, i2c_dat.A_y, i2c_dat.A_z);
            //printf("gyro %d %d %d\n", i2c_dat.W_x, i2c_dat.W_y, i2c_dat.W_z);
            //printf("mag %d %d %d\n", i2c_dat.H_x, i2c_dat.H_y, i2c_dat.H_z);
            //printf("attitude %f %f %f\n", states.phi, states.theta, states.psi);
        } // end-if

        /*
        if (SPI_received_ok){
            SPI_Gumstix_write( &g_states, &g_sensor_data_raw);
            SPI_Gumstix_read();
            SPI_received_ok = 0;
        }
        */

    } // end-while

} // end-Escalonador


void toggle_led ()
{
    GpioDataRegs.GPATOGGLE.bit.GPIO6 = 1U;

//    while(1U)
//    {
//        GpioDataRegs.GPATOGGLE.bit.GPIO6 = 1U;
//         DELAY_US(50000);                        // 50 ms
//    }


}




//        Timer0_count_before = CpuTimer0Regs.TIM.all;
//        GpioDataRegs.GPATOGGLE.bit.GPIO6 = 1;
//        GpioDataRegs.GPACLEAR.bit.GPIO6 = 1;
//        GpioDataRegs.GPASET.bit.GPIO6 = 1;
