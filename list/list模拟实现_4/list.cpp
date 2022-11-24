#define _CRT_SECURE_NO_WARNINGS 1
#include"list.hpp"
int main()
{
	Lp700::list<int> l1(4, 10) ;
	Lp700::list<int> l2(l1.begin(), l1.end());
	Lp700::list<int> l3(l1);
	std::cout << l3.back() << std::endl;
	Lp700::list<int> l4(5, 8);
	std::cout << l4.front() << std::endl;
	l4.push_front(1);
	std::cout << l4.front() << std::endl;
	l4 = l1;
	std::cout << l3.size() << std::endl;
	l3.pop_back();
	std::cout << l3.size() << std::endl;

	return 0;
}