#include <REGX52.H>
#include "Delay.h"
#include "Key.h"
#include "Nixie.h"
#include "Buzzer.h"

sbit Buzzer=P2^5;

unsigned char KeyNum;
unsigned int i;

void main()
{
	 Nixie(1,0);
	while(1)
	{
		KeyNum=Key();
		if(KeyNum)
		{
			for(i=0; i<100; i++)
			{
				Buzzer=!Buzzer;
				Delay(1);
			}
			Buzzer_Time(100);
			Nixie(1,KeyNum);
		}
	}
}
