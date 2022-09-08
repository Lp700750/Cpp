#pragma once
#include<iostream>
using namespace std;
class GetDate
{
public:
	//构造函数
	GetDate(int year, int month, int day);
	
	//打印
	void print();

	//获取一个月有几天
	int GetMonthDay(int year, int month);

	//操作符重载
	bool operator>(const GetDate& d);
	bool operator<(const GetDate& d);
	bool operator>=(const GetDate& d);
	bool operator<=(const GetDate& d);
	bool operator==(const GetDate& d);
	bool operator!=(const GetDate& d);

	GetDate& operator+=(int day);
	GetDate operator+(int day);
	GetDate& operator-=(int day);
	GetDate operator-(int day);
	GetDate& operator++();
	GetDate& operator++(int);


private:
	int _year;
	int _month;
	int _day;
};