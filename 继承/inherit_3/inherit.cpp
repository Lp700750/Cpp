#define _CRT_SECURE_NO_WARNINGS 1
#include"inherit.hpp"
int main()
{
	Lp700::D d1;
	d1.B::a = 1;
	d1.C::a = 2;
	d1.b = 3;
	d1.c = 4;
	d1.d = 5;


	return 0;
}