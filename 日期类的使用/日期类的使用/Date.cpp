#define _CRT_SECURE_NO_WARNINGS 1
#include"Date.h"
void Date::print()
{
	cout << _year << '-' << _month << '-' << _day  << endl;
}
void Date::setDate(size_t year, size_t month, size_t day)
{
	_year = year;
	_month = month;
	_day = day;
}