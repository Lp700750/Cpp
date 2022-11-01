#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int Add(int a, int b)
{
	int z = 0;
	z = a + b;
	return z;
}
int main()
{
	int a = 10;
	int b = 20;
	int c = 0;
	c = Add(a, b);
	printf("%d\n", c);

	return 0;
}