#include <REGX52.H>
#include "Timer0.h"
#include "Key.h"
#include "INTRINS.H"

unsigned char KeyNum,LEDMode;

void main()
{
	P2=0xFE;
    Timer0_Init();
	while(1)
	{
		KeyNum=Key();
		if (KeyNum)
		{
			if(KeyNum==1) 
			{
				LEDMode++;
				if(LEDMode>=2) LEDMode=0;
			}
			
		}
	}
}

void Timer0_Routine() interrupt 1
{
    static unsigned int T0Count;
	TL0 = 0x18;
	TH0 = 0xFC;
	T0Count++;
	if (T0Count>=500)
	{
		  T0Count=0;
		  if(LEDMode==0)
			  P2=_crol_(P2,1);  //向左移位，并且循环
		  if(LEDMode==1)
			  P2=_cror_(P2,1);  //向右移位，并且循环
	}

}