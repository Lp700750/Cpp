#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class Day
{
public:
	Day(int hour=18,int minute=2,int second=59)
	{
		std::cout << "Day()" << std::endl;
		_hour = hour;
		_minute = minute;
		_second = second;
	}
private:
	int _hour;
	int _minute;
	int _second;
};
class test_Date
{
public:
	test_Date(int year=2022,int month=11,int day=2)
	{
		_year = year;
		_month = month;
		_day = day;
	}

	void print()
	{
		std::cout << _year <<"-"<<_month<<"-"<<_day<< std::endl;
	}
private:
	int _year;
	int _month;
	int _day;
	Day _d;
};
int main()
{
	//test_Date d1;
	test_Date d2(2022, 11, 3);
	//d1.print();
	d2.print();
	return 0;
}