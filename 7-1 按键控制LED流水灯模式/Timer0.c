#include <REGX52.H>

//Function Definition
/**
  * @brief 
  * @param  
  * @retval 
  */
void Timer0_Init()		//1??@11.0592MHz
{
	TMOD &= 0xF0;		//???????
	TMOD |= 0x01;		//???????
	TL0 = 0x66;		//??????
	TH0 = 0xFC;		//??????
	TF0 = 0;		//??TF0??
	TR0 = 1;		//???0????
	
	ET0=1;
	EA=1;
	PT0=0;
}
