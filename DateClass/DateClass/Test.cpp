#define _CRT_SECURE_NO_WARNINGS 1
#include"GetDate.h"
#include<iostream>
#include<stdbool.h>
using namespace std;
int main()
{
	GetDate d (2022, 2, 28);
	GetDate d1(2022, 2, 27);
	d.print();
	int Day=d.GetMonthDay(2020, 2);
	cout << Day << endl;
	cout<<(d > d1)<<endl;
	GetDate&d2 = d.operator+=(1);
	d2.print();

	return 0;
}