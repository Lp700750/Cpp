#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
//class Date
//{
//public:
//	//构造函数
//	Date(int year=2022,int month=11,int day=8)
//	{
//		_year = year;
//		_month = month;
//		_day = day;
//	}
//	//拷贝构造
//	Date(const Date& d)
//	{
//		_year = d._year;
//		_month = d._month;
//		_day = d._day;
//	}
//	void print()
//	{
//		std::cout << _year << "-" << _month << "-" << _day << std::endl;
//	}
//	//析构函数
//	~Date()
//	{}
//private:
//	int _year;
//	int _month;
//	int _day;
//};
class TestPtr
{
public:
	TestPtr(int capacity=10)
	{
		_ptr = (int*)malloc(capacity * sizeof(int));
		_size = 0;
		_capacity = capacity;
	}
	TestPtr(const TestPtr& t)
	{
		_ptr = t._ptr;
		_size = t._size;
		_capacity = t._capacity;
	}
	TestPtr& operator=(const TestPtr t)
	{
		if (this != &t)
		{
			_ptr = t._ptr;
			_size = t._size;
			_capacity = t._capacity;
		}
		return *this;
	}
	~TestPtr()
	{
		std::cout << "~TestPtr()" << std::endl;
		free(_ptr);
		_ptr = nullptr;
		_size = _capacity;
	}
private:
	int* _ptr;
	int _size;
	int _capacity;
};
class Date
{
public:
	Date(int year = 1998, int month = 8, int day = 8)
	{
		_year = year;
		_month = month;
		_day = day;
	}
	Date(const Date& d)
	{
		_year = d._year;
		_month = d._month;
		_day = d._day;
	}
	//"="
	Date& operator=(const Date& d)
	{
		if (this != &d)
		{
			_year = d._year;
			_month = d._month;
			_day = d._day;
		}
		return *this;
	}
	//日期"+"天数
	Date operator+(int day)
	{
		//精简版不考虑跨月和闰年情况
		_day += day;
		return *this;
	}
	void print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}
	~Date()
	{
		std::cout << "~Date()" << std::endl;
	}
private:
	int _year;
	int _month;
	int _day;
};
int main()
{
	//Date d1;
	//Date d2(1998, 8, 8);
	//Date d3(d1);
	//Date d4(d);
	//TestPtr t1;
	//TestPtr t2(20);
	//TestPtr t3(t1);
	//t3=t2;
	
	//Date d1;
	////Date d2(2022,11,8);
	////Date d3(d1);
	////d3 = d2;
	//Date d2;
	//d2 = d1 + 13;
	//d2.print();
	return 0;
}