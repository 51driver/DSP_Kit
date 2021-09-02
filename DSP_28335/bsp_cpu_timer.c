#include "bsp_cpu_timer.h"

interrupt void bsp_CPUTimer_0_isr(void);
interrupt void bsp_CPUTimer_1_isr(void);
interrupt void bsp_CPUTimer_2_isr(void);

void bsp_CPUTimer_0_Init(void)
{
    DINT; //DISable CPU Golabel interrupts
    EALLOW; //This is needed to disable write to EALLOW protected registers

    InitCpuTimers();  //初始化系统时钟，这个TI的DSP2833X_CpuTimes.c文件自带

    /***@Begin  Initial the timer0 interrupt ***************************/
    // Configure CPU-Timer 0, 1, and 2 to interrupt every second:
    // 100MHz CPU Freq, 1 second Period (in uSeconds)
    ConfigCpuTimer(&CpuTimer0, 150, 1000000); //1000000=1000000us
    /***@END  Initial the timer0 interrupt ***************************/
  
    /***@Begin  Initial the timer0 interrupt ***************************/
    PieCtrlRegs.PIECTRL.bit.ENPIE = 1;   // Enable the PIE block

    PieVectTable.TINT0 = &bsp_CPUTimer_0_isr;

    PieCtrlRegs.PIEIER1.bit.INTx7=1;     //使能INT1.7即定时器0中断
    IER |= M_INT1;                       //ENABLE CPU INT1
    /***@END  Initial the timer0 interrupt ***************************/

    //StartCpuTimer0();
    EDIS; //This is needed to disable write to EALLOW protected registers
    EINT; // Enable Global interrupt INTM

    ERTM;   // Enable Global realtime interrupt DBGM
}
  
unsigned int g_iTimer0ISRCnt = 0;
//eCapture-1 中断服务函数
interrupt void bsp_CPUTimer_0_isr(void)
{
    g_iTimer0ISRCnt++;
    //Timer0 interrupt ack
    PieCtrlRegs.PIEACK.all=PIEACK_GROUP1;  //使能CPU接受第一组中断

    /* Clear the interrupt flag
     * Enable the reload
     * */
    CpuTimer0Regs.TCR.bit.TIF=1;  //清除中断标志位
    CpuTimer0Regs.TCR.bit.TRB=1;  //使能重载
}

///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
void bsp_CPUTimer_1_Init(void)
{
    DINT; //DISable CPU Golabel interrupts
    EALLOW; //This is needed to disable write to EALLOW protected registers

    InitCpuTimers();  //初始化系统时钟，这个TI的DSP2833X_CpuTimes.c文件自带
    /***@Begin  Initial the timer0 interrupt ***************************/
    // Configure CPU-Timer 0, 1, and 2 to interrupt every second:
    // 100MHz CPU Freq, 1 second Period (in uSeconds)
    ConfigCpuTimer(&CpuTimer1, 150, 1000000); //1000000=1000000us
    /***@END  Initial the timer0 interrupt ***************************/
    /***@Begin  Initial the timer0 interrupt ***************************/
    PieVectTable.TINT0 = &bsp_CPUTimer_1_isr;

    IER |= M_INT13;  //ENABLE CPU group-13 (INT13) interrupt

    /***@END  Initial the timer0 interrupt ***************************/
  
      //StartCpuTimer0();
    EDIS; //This is needed to disable write to EALLOW protected registers
    EINT; // Enable Global interrupt INTM

    ERTM;   // Enable Global realtime interrupt DBGM
}

unsigned int g_iTimer1ISRCnt = 0;
//eCapture-1 中断服务函数
interrupt void bsp_CPUTimer_1_isr(void)
{
    g_iTimer1ISRCnt++;

    //Interrupt service


    //Timer1 interrupt ack
    //直接确认，无需PIE

    /* Clear the interrupt flag
     * Enable the reload
     * */
    CpuTimer1Regs.TCR.bit.TIF=1;  //清除中断标志位
    CpuTimer1Regs.TCR.bit.TRB=1;  //使能重载
}


///////////////////////////////////////////////////////////////////
//////////////////////////////////////////////////////////////////
void bsp_CPUTimer_2_Init(void)
{
    DINT; //DISable CPU Golabel interrupts
    EALLOW; //This is needed to disable write to EALLOW protected registers

    InitCpuTimers();  //初始化系统时钟，这个TI的DSP2833X_CpuTimes.c文件自带
    /***@Begin  Initial the timer0 interrupt ***************************/
    // Configure CPU-Timer 0, 1, and 2 to interrupt every second:
    // 100MHz CPU Freq, 1 second Period (in uSeconds)
    ConfigCpuTimer(&CpuTimer2, 150, 1000000); //1000000=1000000us
    /***@END  Initial the timer0 interrupt ***************************/

    /***@Begin  Initial the timer-2 interrupt ***************************/
    PieVectTable.TINT2 = &bsp_CPUTimer_2_isr;
    IER |= M_INT14;  //ENABLE CPU group-13 (INT13) interrupt

    /***@END  Initial the timer0 interrupt ***************************/

    //StartCpuTimer0();
    EDIS; //This is needed to disable write to EALLOW protected registers
    EINT; // Enable Global interrupt INTM

    ERTM;   // Enable Global realtime interrupt DBGM
}


unsigned int g_iTimer2ISRCnt = 0;
//eCapture-1 中断服务函数
interrupt void bsp_CPUTimer_2_isr(void)
{
    g_iTimer2ISRCnt++;

    //Interrupt service


    //Timer1 interrupt ack
    //直接确认，无需PIE


    /* Clear the interrupt flag
     * Enable the reload
     * */
    CpuTimer2Regs.TCR.bit.TIF=1;  //清除中断标志位
    CpuTimer2Regs.TCR.bit.TRB=1;  //使能重载
}





unsigned int g_iTimer2ISRCnt = 0;
//eCapture-1 中断服务函数
interrupt void bsp_CPUTimer_2_isr(void)
{
    g_iTimer2ISRCnt++;

    //Interrupt service


    //Timer1 interrupt ack
    //直接确认，无需PIE


    /* Clear the interrupt flag
     * Enable the reload
     * */
    CpuTimer2Regs.TCR.bit.TIF=1;  //清除中断标志位
    CpuTimer2Regs.TCR.bit.TRB=1;  //使能重载
}
