/******************************************************************************
* FILENAME:    dsp_system.c
*
* DESCRIPTION:
*       Peripheral and I/Os configuration routines.
*
* FUNCTIONS:
*       void    Gpio_Select (void)
*
* NOTES:
*       Functions used to configure I/Os, peripherals, clocks, etc;
*       See TMS320F28335 for detailed description.
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

#include "dsp_system.h"
#include "DSP2833x_Device.h"
#include "DSP2833x_Gpio.h"

/******************************************************************************
* FUNCTION NAME  : GPIO_Select
* INPUT          : None
* OUTPUT         : None
* RETURN         : No return
* DESCRIPTION    : Configure peripheral modules in use as its functionalities.
******************************************************************************/
void gpio_select(void)
{
    EALLOW;
    GpioCtrlRegs.GPAMUX1.all = 0U;           /* GPIO15 ... GPIO0 = General Puropse I/O  */
    GpioCtrlRegs.GPAMUX2.all = 0U;           /* GPIO31 ... GPIO16 = General Purpose I/O */

    /* SCI-A I/O config */
    GpioCtrlRegs.GPAMUX2.bit.GPIO28 = 1U;    /* SCIRXDA */
    GpioCtrlRegs.GPAMUX2.bit.GPIO29 = 1U;    /* SCITXDA*/

    /* SPI-A I/O config  */
    GpioCtrlRegs.GPAPUD.bit.GPIO16 = 0U;     /* Enable pull-up GPIO16 (SPISIMOA) */
    GpioCtrlRegs.GPAPUD.bit.GPIO17 = 0U;     /* Enable pull-up GPIO17 (SPISOMIA) */
    GpioCtrlRegs.GPAPUD.bit.GPIO18 = 0U;     /* Enable pull-up GPIO18 (SPICLKA)  */
    GpioCtrlRegs.GPAPUD.bit.GPIO19 = 0U;     /* Enable pull-up GPIO19 (SPISTEA)  */

    /* Set qualification for selected pins to asynch only
       This will select asynch (no qualification) for the selected pins.    */
    GpioCtrlRegs.GPAQSEL2.bit.GPIO16 = 3U;   /* Asynch input GPIO16 (SPISIMOA) */
    GpioCtrlRegs.GPAQSEL2.bit.GPIO17 = 3U;   /* Asynch input GPIO17 (SPISOMIA) */
    GpioCtrlRegs.GPAQSEL2.bit.GPIO18 = 3U;   /* Asynch input GPIO18 (SPICLKA)  */
    GpioCtrlRegs.GPAQSEL2.bit.GPIO19 = 3U;   /* Asynch input GPIO19 (SPISTEA)  */

    /* Configure SPI-A pins using GPIO regs
       This specifies which of the possible GPIO pins will be SPI functional
       pins. */
    GpioCtrlRegs.GPAMUX2.bit.GPIO16 = 1U;    /* Configure GPIO16 as SPISIMOA */
    GpioCtrlRegs.GPAMUX2.bit.GPIO17 = 1U;    /* Configure GPIO17 as SPISOMIA */
    GpioCtrlRegs.GPAMUX2.bit.GPIO18 = 1U;    /* Configure GPIO18 as SPICLKA  */
    GpioCtrlRegs.GPAMUX2.bit.GPIO19 = 1U;    /* Configure GPIO19 as SPISTEA  */

    
    /* I2C-A I/O config */
    GpioCtrlRegs.GPBMUX1.bit.GPIO32 = 1U;    /* GPIO32 = I2C - SDA */
    GpioCtrlRegs.GPBMUX1.bit.GPIO33 = 1U;    /* GPIO33 = I2C - SCL */

    GpioCtrlRegs.GPBPUD.bit.GPIO32 = 0U;     /* Enable pull-up for GPIO32 (SDAA)*/
    GpioCtrlRegs.GPBPUD.bit.GPIO33 = 0U;     /* Enable pull-up for GPIO33 (SCLA)*/

    GpioCtrlRegs.GPBQSEL1.bit.GPIO32 = 3U;   /* Asynch input GPIO32 (SDAA)*/
    GpioCtrlRegs.GPBQSEL1.bit.GPIO33 = 3U;   /* Asynch input GPIO33 (SCLA)*/

    GpioCtrlRegs.GPBDIR.bit.GPIO32 = 0U;     /* GPIO32 (SDAA) as input*/
    GpioCtrlRegs.GPBDIR.bit.GPIO33 = 0U;     /* GPIO33 (SCLA) as input */


    /* XINT1 I/O config => Make GPIO23 the input source for XINT1 */
    GpioCtrlRegs.GPAPUD.bit.GPIO23 = 0U;     /* Enable pull-up on GPIO23 */
    GpioCtrlRegs.GPAMUX2.bit.GPIO23 = 0U;    /* GPIO23 = GPIO23 */
    GpioCtrlRegs.GPADIR.bit.GPIO23 = 0U;     /* GPIO23 = input */
    GpioIntRegs.GPIOXINT1SEL.all = 23U;      /* XINT1 connected to GPIO23 */


    /* XINT2 I/O config => Make GPIO20 the input source for XINT2 */
    GpioCtrlRegs.GPAPUD.bit.GPIO20 = 0U;     /* Enable pull-up on GPIO20 */
    GpioCtrlRegs.GPAMUX2.bit.GPIO20 = 0U;    /* GPIO20 = GPIO20 */
    GpioCtrlRegs.GPADIR.bit.GPIO20 = 0U;     /* GPIO20 = input */
    GpioIntRegs.GPIOXINT2SEL.all = 20U;      /* XINT2 connected to GPIO20 */

    /* GPIO06 I/O config  => GPIO set for output to generate an output signal for GPS timing*/
    GpioCtrlRegs.GPAMUX1.bit.GPIO6 = 0U;     /* GPIO06 = General Purpose I/O */
    GpioCtrlRegs.GPADIR.bit.GPIO6 = 1U;      /* Output: Buzzer at GPIO06 */

    EDIS;
} 



void setup_epwm1a (void)
{
    EPwm1Regs.TBCTL.bit.CLKDIV =  4U;    // CLKDIV = 4         (0x0100) /16
    EPwm1Regs.TBCTL.bit.HSPCLKDIV = 2U;    // HSPCLKDIV = 2    (0x0001) /2
                                        // CLKDIV*HSPCLKDIV -> Divided by 32
    EPwm1Regs.TBCTL.bit.CTRMODE = 0U;    // up mode

    EPwm1Regs.AQCTLA.all = 0x0008U;        // set ePWM1A on CTR = PRD

    EPwm1Regs.TBPRD = 46875U;            // timer period for 50 Hz

//    EPwm1Regs.CMPA.half.CMPA = EPwm1Regs.TBPRD / 2;    // 50% duty cycle first

    EPwm1Regs.ETSEL.all = 0U;
    EPwm1Regs.ETSEL.bit.INTEN = 0U;        // interrupt disable for ePWM1 (enable at Timer0 ISR)
    EPwm1Regs.ETSEL.bit.INTSEL = 2U;        // interrupt on CTR = PRD
    EPwm1Regs.ETPS.bit.INTPRD = 1U;        // interrupt on first event

} 
