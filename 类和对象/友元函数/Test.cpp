#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class Date
{
	friend std::ostream& operator<<(std::ostream& _cout, const Date& d);
public:
	Date(int year = 2022, int month = 11, int day = 11)
		:_year(year),
		_month(month),
		_day(day)
	{}
	//std::ostream& operator<<(std::ostream& _cout)
	//{
	//	_cout << _year << "-" << _month << "-" << _day;  
	//	return _cout;
	//}
	void print()
	{
		std::cout << _year << "-" << _month << "-" << _day << std::endl;
	}
	~Date()
	{}

private:
	int _year;
	int _month;
	int _day;
};
std::ostream& operator<<(std::ostream& _cout, const Date& d)
{
	_cout <<d._year << "-" << d._month << "-" <<d._day;
	return _cout;
}
int main()
{
	Date d;
	d.print();
	//d<<std::cout
	std::cout<<d;

	return 0;
}