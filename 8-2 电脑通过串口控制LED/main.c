#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

void main()
{
	UART_Init();

	while(1)
	{
		
	}
}

void UART_Routine() interrupt 4 //串口中断号为4
{ //RI：接收中断请求标志位 
	if(RI==1) //RI=1向主机请求中断响
	{
		P2=~SBUF; 
	  UART_SendByte(SBUF);		
		RI=0;//应中断后必须用软件复位，即RI=0  
	}
}