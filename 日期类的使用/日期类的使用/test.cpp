#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
int main()
{
	Date d1,d2;
	d1.setDate(2022, 9, 7);
	d2.setDate(2022, 9, 9);
	d1.print();
	d2.print();

	return 0;
}