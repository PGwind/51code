#include <REGX52.H>

//引脚定义
sbit XPT2046_CS=P3^5;
sbit XPT2046_DCLK=P3^6;
sbit XPT2046_DIN=P3^4;
sbit XPT2046_DOUT=P3^7;

/**
  * @brief  ZPT2046读取AD值
  * @param  Command 命令字，范围：头文件内定义的宏，结尾的数字表示转换的位数
  * @retval AD转换后的数字量，范围：8位为0~255，12位为0~4095
  */
unsigned int XPT2046_ReadAD(unsigned char Command)
{
	unsigned  char i;
	unsigned int ADValue=0;
	XPT2046_DCLK=0;
	XPT2046_CS=0;
	
	for(i=0;i<8;i++)
	{
		XPT2046_DIN=Command&(0x80>>i);
		XPT2046_DCLK=1;
		XPT2046_DCLK=0;
	}

	for(i=0;i<16;i++)
	{
		
	  XPT2046_DCLK=1;
		XPT2046_DCLK=0;
		if(XPT2046_DOUT) {ADValue|=(0x8000>>i);}
	}
	XPT2046_CS=1;
	if(Command&0x08)
	{
		return ADValue>>8; //8位显示
	}
	else return ADValue>>4; //12位显示
}