#include <REGX52.H>
#include "Delay.h"
#include "UART.h"

unsigned char Sec;

void main()
{
	UART_Init(); //初始化
	
	while(1)
	{
		UART_SendByte(Sec); //发送 16进制格式
		Sec++;
		Delay(1000);
	}
}