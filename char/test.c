﻿#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>



int main() {
	//char -128~127
	//unsigned char 0~255
	unsigned char a = 200;
	//00000000000000000000000011001000
	//11001000 -a 截断
	unsigned char b= 100;
	//00000000000000000000000001100100
	//01100100 -b 截断
	unsigned char c = 0;
	c = a + b;
	//整形提升
	//00000000000000000000000011001000 a
	//00000000000000000000000001100100 b
	//00000000000000000000000100101100 c
	//00101100 -c 截断
	//00000000000000000000000000101100
	printf("%d %d", a + b, c);
	return 0;
	}



