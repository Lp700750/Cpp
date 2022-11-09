#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//日期类的测试
//class Date
//{
//public:
//	//构造函数
//	Date(int year = 2022, int month = 11, int day = 11)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//打印函数
//	void print()const
//	{
//		std::cout << _year << "-" << _month << "-" << _day << std::endl;
//		_day = _day + 2;
//	}
//	//拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	//赋值重载
//	Date& operator=(const Date& d)
//	{
//		if (this != &d)
//		{
//			_year = d._year;
//			_month = d._month;
//			_day = d._day;
//		}
//		return *this;
//	}
//	//"+"重载
//	Date operator+(int day)
//	{
//		//暂时不考虑跨月和闰年
//		_day += day;
//		return *this;
//	}
//	//"+="重载
//	Date& operator+=(int day)
//	{
//		_day += day;
//		return *this;
//	}
//	//析构函数
//	~Date()
//	{
//		std::cout << "~Date()" << std::endl;
//	}
//private:
//	int _year;
//	int _month;
//	int _day;
//};


//初始化列表的测试
class Day
{
public:
	Day(int hour = 15)
		:_hour(hour)
	{}
private:
	int _hour;
};
class Date
{
public:
	Date(int year=2022,int month=11,int day=11)
	{
		_year = year;
		_month = month;
		_day = day;
	}
private:
	//Day _d;
	int _year;
	int _month;
	int _day;
	Day _d;
};
int main()
{
	Date d;
	//d.print();
	//Date d1 = d + 10;
	//d1.print();
	//d += 10;
	//d.print();
	//d.print();

	return 0;
}