#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
class New
{
public:
	New(int day=11)
		:_day(day)
	{}

	~New()
	{}
private:
	int _day;
};
int main()
{
	New* n1 = new New(10);
	delete n1;

	New* n2 = new New[10];
	delete[] n2;

	return 0;
}