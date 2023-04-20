//Timer0.c
#include <REGX52.H>

//Function Definition
/**
  * @brief 定时器0初始化
  * @param  无
  * @retval 1ms
  */
void Timer0_Init()	//1毫秒@12.000MHz	
{
	TMOD &= 0xF0;	//设置定时器模式	
	TMOD |= 0x01;	//设置定时器模式	
	TL0 = 0x66;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	TF0 = 0;        //清除TF0标志 
	TR0 = 1;		//定时器0开始计时
	
	ET0=1;
	EA=1;
	PT0=0;
}
