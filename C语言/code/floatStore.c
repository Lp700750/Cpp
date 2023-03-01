#define _CRT_SECURE_NO_WARNINGS 1
#include<stdio.h>
int main()
{
	//float a = 5.0;
	//printf("%lf\n", a);
	//void test
	int a[3][2] = { {1,2},{3,4},{5,6} };
	int* p;
	p = a+1;
	printf("%d", p[0]);

	return 0;
}