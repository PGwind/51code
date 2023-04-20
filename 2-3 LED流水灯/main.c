#include <REGX52.H>

void Delay500ms()		//@11.0592MHz 500ms????
{
	unsigned char i, j, k;
    
	i = 4;
	j = 129;
	k = 119;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}

void main()
{
		while(1)
		{
			P2 = 0xFE; //1111 1110
			Delay500ms();
			P2 = 0xFD; //1111 1101
			Delay500ms();
			P2 = 0xFB; //1111 1011
			Delay500ms();
			P2 = 0xF7; //1111 0111
			Delay500ms();
			P2 = 0xEF; //1110 1111
			Delay500ms();
			P2 = 0xDF; //1101 1111
			Delay500ms();
			P2 = 0xBF; //1011 1111
			Delay500ms();
			P2 = 0x7F; //0111 1111
			Delay500ms();
		}
}