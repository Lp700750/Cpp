#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class Day
{
	/*
	1.静态成员变量存放于数据区，属于整个类所共有，不属于某一个类对象所私有
	2.静态成员变量和成员函数可以访问静态成员变量和成员函数，但是不能访问非静态成员函数和成员变量
	3.非静态成员函数和成员变量可以访问静态或者非静态成员函数和静态变量
	*/
public:
	Day(int hour=10)
		:_hour(hour)
	{}
	void print()
	{
		std::cout << _hour <<"-"<<_minute<< std::endl;
		_print();
	}
	static void _print()
	{
		//Day::print();
		std::cout << _minute << std::endl;
		//std::cout << Day::_hour << std::endl;
	}

private:
	int _hour;
	static int _minute;
};
int Day::_minute = 20;
int main()
{
	//int Day::_minute = 10;
	Day d;
	d.print();
	d._print();

	return 0;
}