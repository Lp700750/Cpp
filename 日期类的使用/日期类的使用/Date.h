#pragma once
#include<iostream>
using namespace std;
class Date
{
public:
	void print();
	void setDate(size_t year, size_t month, size_t day);
private:
	size_t _year;
	size_t _month;
	size_t _day;
};
