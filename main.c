/****************************************************************************
* 文 件 名: main.c
* 作    者: Amo [ www.amoMcu.com 阿莫单片机]
* 修    订: 2014-04-08
* 版    本: 1.0
* 描    述: 设置串口调试助手波特率：115200bps 8N1
*           串口调试助手给CC254x发字符串时，开发板会返回接收到的字符串
****************************************************************************/
#define LED2 P1_1       //定义P1.1口为LED2控制端
#include <uart.h>
#include <time.h>
#include <ADS1299.h>



void main(void)
{	
    InitTime(); 
    InitUart();                                //调用串口初始化函数   
    // GPIO初始化
    P0SEL &= ~0x51;     //  *0*0 ***0
    P0DIR |= 0x51;     //  *1*1 ***1
    
    P1SEL &= ~0xF1;     //  0000 ***0
    P1DIR &= ~0x81;     //  0111 ***0
    P1DIR |= 0x70;     //  0111 ***0
    
    
    U0CSR &= ~0x40;                           //禁止串口接收数据 
    
    Init_ADS1299();  ////////////////
	DelayUS(1);	
	START=1;
	DelayUS(15);

    UartSendString("program start\n", 14);     
    DelayMS(200);
        
    DRDY=0;
    
    
    UartSendString("Read_ADS1299()\r\n", 16); 
    if(DRDY!=0)
        UartSendString("DRDY invalid\r\n", 14);  
	while(1)  {
         
		Read_ADS1299();  //////////////if(DRDY==0),translate data in first channel 
	}
       
  

}
