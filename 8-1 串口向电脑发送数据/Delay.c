//Delay.c
//Function Definition
/**
  * @brief 延迟函数
  * @param  无
  * @retval 1ms
  */
void Delay(unsigned int xms)		//@11.0592MHz
{
	unsigned char i, j;
	while(xms)
	{
			i = 2;
			j = 199;
			do
			{
				while (--j);
			} while (--i);	
			xms--;
	}
} 
	