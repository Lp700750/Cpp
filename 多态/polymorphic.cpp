#define _CRT_SECURE_NO_WARNINGS 1
#include"polymorphic.hpp"
void funct(Lp700::person& people)
{
	people.print();
}
int main()
{
	Lp700::person p;
	funct(p);
	Lp700::student s;
	funct(s);

	return 0;
}