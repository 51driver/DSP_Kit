#include "DSP2833x_Device.h"
#include "DSP2833x_Examples.h"

#include "bsp_gpio_interrupt.h"

extern void bsp_GpioExtInt_isr(void);

//External GPIO init
void bsp_GpioExtIntGpioInit(void)
{
    EALLOW;

    //Config the GPIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO13 = 0; //Gpio set as GPIO function
    GpioCtrlRegs.GPADIR.bit.GPIO13 = 0;  //Gpio set as input
    GpioCtrlRegs.GPAQSEL1.bit.GPIO13 = 0;//

    EDIS;
}
//GPIO external interrupt initialize
void bsp_GpioExtIntInit(void)
{
    EALLOW;

    //Gpio interrupt config
    GpioIntRegs.GPIOXINT1SEL.bit.GPIOSEL = 13; //Select GPIO13 as external input for XINT
    XIntruptRegs.XINT1CR.bit.POLARITY = 0; //Falling edge trip the interrupt
    XIntruptRegs.XINT1CR.bit.ENABLE = 1;   //Enable the XINT interrupt

    //Interrupt ISR remap
    PieVectTable.XINT1 = &bsp_GpioExtInt_isr; //Remap the interrupt ISR

    //Enable Group interrupt and PIE vector table fetching
    IER |= M_INT1;                       //Enable the first group interrupt
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   //Enable vector fetching
    PieCtrlRegs.PIEIER1.bit.INTx4= 1;    //Enable the PIE first group channel-4(Ext.int.1) interrupt

    EDIS;
}
//
void bsp_GpioExtInt_isr(void)
{
    //EALLOW;

    //Interrupt service
    if(GpioDataRegs.GPADAT.bit.GPIO13 == 0)
    {
        //LED1 = ~LED1;
    }

    //Clear the specified interrupt group bit
    //PieCtrlRegs.PIEACK.all = PIEACK_GROUP1;
    PieCtrlRegs.PIEACK.bit.ACK1 = 1; //Clear the specified interrupt group bit to enable the next interrupt

    //
    //EDIS;
}

    
    
