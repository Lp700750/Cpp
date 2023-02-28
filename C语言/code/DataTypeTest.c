#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	//char a = -1;
	//11111111 11111111 11111111 11111111 -1;
	//00000000 00000000 00000000 11111111
	//00000000 00000000 00000000 11111110 ·´Âë
	//01111111 11111111 11111111 00000001 Ô­Âë
	
	//signed char b = -1;
	//unsigned char c = -1;
	//printf("a=%d\n", a);
	//printf("b=%d\n", b);
	//printf("c=%d\n", c);

	//char ch = 'a';
	//printf("%d,%c\n", ch, ch);
	char ch = 128;
	printf("%u\n", ch);

	return 0;
}