#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
struct bit
{
	char a : 3;
	char b : 4;
	char c : 5;
	char d : 4;
};
int main()
{
	struct bit s;
	printf("s=%d", sizeof(s));

	return 0;
}