#include <REGX52.H>

//Function Definition
/**
  * @brief 串口初始化 4800bps@11.0592MHz
  * @param  无
  * @retval 无
  */

void UART_Init()  //初始化
{
	SCON = 0x50; //0101 0000  第二个1是REN，置1才能接收
	PCON |= 0x80; 
	
	TMOD &= 0x0F;	//设置定时器1模式  0000 1111
	TMOD |= 0x20;	//设置定时器1模式  0010 0000
	TL1 = 0xF4;		//设定定时初值
	TH1 = 0xF4;		//设定定时器重装值
	ET1 = 0;		//禁止定时器1中断
	TR1 = 1;		//启动定时器1
	EA=1;      //启动所有中断
	ES=1;      //启动串口中断

}

//Function Definition
/**
  * @brief 串口发送一个字节数据
  * @param  Byte 要发送一个字节数字
  * @retval 无
  */

void UART_SendByte(unsigned char Byte) //只发送，不接收 
{
	SBUF = Byte;
  while(TI==0); //发送成功跳出循环，TI变为1
	TI = 0;    //重置为0
}
