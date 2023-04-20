#ifndef __MATRIX_LED_H_
#define __MATRIX_LED_H_

void MatrixLED_Init();
void _74HC595_WriteByte(unsigned char Byte);
void MatrixLED_ShowColumn(unsigned char Column,Data);

#endif
