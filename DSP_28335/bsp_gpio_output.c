
#include "bsp_gpio_output.h"

void bsp_GpioOutputInit(void)
{
    EALLOW;

    //Config the GPIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0; //Gpio set as GPIO function
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 1;  //Gpio set as output
    GpioCtrlRegs.GPAQSEL1.bit.GPIO0 = 0;//

    //Config the GPIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0; //Gpio set as GPIO function
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 1;  //Gpio set as output
    GpioCtrlRegs.GPAQSEL1.bit.GPIO1 = 0;//
    //Config the GPIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO3 = 0; //Gpio set as GPIO function
    GpioCtrlRegs.GPADIR.bit.GPIO3 = 1;  //Gpio set as output
    GpioCtrlRegs.GPAQSEL1.bit.GPIO3 = 0;//
    EDIS;
}


