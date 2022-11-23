#define _CRT_SECURE_NO_WARNINGS 1
#include"list.hpp"
#include<list>
int main()
{
	Lp700::list<int> l1(4, 10);
	//std::list<int> l2(4, 10);
	Lp700::list<int> l2(l1.begin(), l1.end());

	return 0;
}