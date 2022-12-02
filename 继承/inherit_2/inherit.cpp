#define _CRT_SECURE_NO_WARNINGS 1
#include"inherit.hpp"
int main()
{
	Lp700::master m1;
	Lp700::master m2;
	Lp700::master m3;
	//m1.print();
	std::cout << Lp700::person::num << std::endl;
	Lp700::teacher t2;
	Lp700::master::num = 0;
	std::cout << Lp700::person::num << std::endl;
	//t2.print();

	return 0;
}
