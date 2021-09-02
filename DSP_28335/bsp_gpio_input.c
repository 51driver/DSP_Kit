
#include "bsp_gpio_input.h"

void bsp_GpioInputInit(void)
{
    EALLOW;

    //Config the GPIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO0 = 0; //Gpio set as GPIO function
    GpioCtrlRegs.GPADIR.bit.GPIO0 = 0;  //Gpio set as output
    GpioCtrlRegs.GPAQSEL1.bit.GPIO0 = 0;//

    //Config the GPIO
    GpioCtrlRegs.GPAMUX1.bit.GPIO1 = 0; //Gpio set as GPIO function
    GpioCtrlRegs.GPADIR.bit.GPIO1 = 0;  //Gpio set as output
    GpioCtrlRegs.GPAQSEL1.bit.GPIO1 = 0;//

    EDIS;
}
