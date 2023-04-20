#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

int KeyNum;
int Password,Count;

void main()
{
	LCD_Init();
	LCD_ShowString(1,1,"PassWord:");
	while(1)
	{
		KeyNum=MatrixKey();
		if (KeyNum)
		{
			if(KeyNum<=10)
			{
				if(Count<4)
				{
					Password*=10;
					Password+=KeyNum%10;
					Count++;
				}
			}

			LCD_ShowNum(2,1,Password,4);
		}
		if(KeyNum==11)  
		{
			if (Password==2345)
			{
				LCD_ShowString(1,12,"OK");
				Password=0;
				Count=0;
				LCD_ShowNum(2,1,Password,4);
			}
			else
      {
        LCD_ShowString(1,12,"ERROR");
				//Delay(2000);
				Password=0;
				Count=0;
				LCD_ShowNum(2,1,Password,4);
				//LCD_ShowString(1,12,"    ");
      }
		}
		if (KeyNum==12)
		{
		   	Password=0;
				Count=0;
		    LCD_ShowString(1,12,"     ");
				LCD_ShowNum(2,1,Password,4);
		}
	}
}                      