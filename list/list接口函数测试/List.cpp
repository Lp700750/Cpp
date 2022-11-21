#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<list>
void test1()
{
	//List的构建
	std::list<int> L1;
	std::list<int>L2(5, 10);
	std::list<int>L3(L2);
	std::list<int>L4(L2.begin(), L2.end());
}
void test2()
{
	//erase迭代器失效
	int arry[] = { 1,2,3,4,5,6,7,8,9 };
	std::list<int> L1(arry, arry + sizeof(arry) / sizeof(arry[0]));
	auto it = L1.begin();
	while (it != L1.end())
	{
		//迭代器失效
		L1.erase(it);
		it++;
		//erase之后该节点的迭代器失效，将不能够继续使用
		
		//改正后
		L1.erase(it++);
	}
}
int main()
{
	//test1();
	test2();
	return 0;
}