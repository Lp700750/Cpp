#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.h"
int main()
{
	Lp700::vector<int> v1(4, 10);
	Lp700::vector<int> v4(v1);
	Lp700::vector<char> v2(4, 'C');
	Lp700::vector<int> v3(2, 5);
	v1.insert(v1.begin(), 8);
	v1.print();
	//v4.print();
	//v3 = v1;
	//v1.push_back(20);
	//v1.push_back(30);
	//v1.push_back(40);
	//v1.push_back(50);
	//v1.pop_back();
	//v2.push_back('A');
	//v2.push_back('D');
	//v2.push_back('B');
	//v2.pop_back();
	//std::cout << v2.capacity()<<std::endl;
	//std::cout << v2.size() << std::endl;
	//v2.reserve(10);
	//v2.resize(7, 'F');
	//std::cout << v2.capacity() << std::endl;
	//std::cout << v2.size() << std::endl;
	//v1.print();
	//v2.print();

	return 0;
}