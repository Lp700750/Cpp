#define _CRT_SECURE_NO_WARNINGS 1
#include"GetDate.h"
GetDate::GetDate(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void GetDate::print()
{
	cout << _year << "-" << _month << "-" << _day << endl;
}

int GetDate::GetMonthDay(int year, int month)
{
	int GetDay[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (2 == month)
	{
		if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0))
			GetDay[month]++;
	}
	return GetDay[month];
}

bool GetDate::operator>(const GetDate& d)
{
	if (_year > d._year)
		return true;
	else if (_year == d._year&&_month > d._month)
		return true;
	else if (_year == d._year&&_month == d._month&&_day > d._day)
		return true;
	else
		return false;
}

bool GetDate::operator<(const GetDate& d)
{
	if (_year < d._year)
		return true;
	else if (_year == d._year&&_month < d._month)
		return true;
	else if (_year == d._year&&_month == d._month&&_day < d._day)
		return true;
	else
		return false;
}

bool GetDate::operator==(const GetDate& d)
{
	return _year == d._year&&_month&&d._month&&_day&&d._day;
}

GetDate& GetDate::operator+=(int day)
{
	_day += day;
	if (_day > GetMonthDay(_year, _month))
	{
		_day = _day - GetMonthDay(_year, _month);
		_month += 1;
		if (_month > 12)
		{
			_month -= 12;\
			_year++;
		}
	}
	return *this;
}