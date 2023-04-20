#include <REGX52.H>
#include "Delay.h"

sbit RCK=P3^5;  //RCLK 上升沿锁存
sbit SCK=P3^6;  //SRCLK 上升沿移位
sbit SER=P3^4;  //SER

#define MATRIX_LED_PORT     P0

//Function Definition
/**
  * @brief 74HC595写入一个字节
  * @param  要写入的字节
  * @retval 无
  */


void _74HC595_WriteByte(unsigned char Byte) 
{
	unsigned char i;
	for (i=0;i<8;i++)  
	{
		SER=Byte&(0x80>>i);  //1000 0000 
	  SCK=1;
	  SCK=0;
	}
	RCK=1;
	RCK=0;
}


//Function Definition
/**
  * @brief 点阵屏初始化
  * @param  无
  * @retval 无
  */
void MatrixLED_Init()
{
	SCK=0; //刚开始是高电平，所以要置0，使其为低电平
	RCK=0;
}

//Function Definition
/**
  * @brief LED点阵屏显示一列数据
  * @param  Column 要选择的列，范围：0~7，0在最左边
  * @param  Data 选择列显示的数据，高位在上，1位亮，0位灭
  * @retval 无          
  */

void MatrixLED_ShowColumn(unsigned char Column,Data)
{
	_74HC595_WriteByte(Data);  //Data==Byte
	MATRIX_LED_PORT=~(0x80>>Column); //0选中，1不选中
  Delay(1); //延迟
  MATRIX_LED_PORT=0xFF;  //全灭  消影
}
