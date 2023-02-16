#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
void test1()
{
	std::vector<int> v1;
	std::vector<int> v2(4, 10);
	std::vector<int> v3(v1);
	std::vector<char> v4;
	std::vector<char> v5(10, 'a');
	std::vector<std::string> v6(10, "hello Jolly.Roger");
	std::vector<std::vector<int>> v7(10, v2);
	std::vector<std::vector<char>> v8(10, v5);
	for (auto e : v2)
	{
		std::cout << e << " ";
	}
}
void test2()
{
	std::vector<int> v1;
	std::vector<int> v2(4, 10);
	std::vector<int> v3(v1);
	std::cout << v1.capacity() << std::endl;
	std::cout << v2.capacity() << std::endl;
	std::cout << v1.size()<< std::endl;
	std::cout << v2.size() << std::endl;
	v2.reserve(6);
	std::cout << v2.capacity() << std::endl; 
}
void test3()
{
	std::vector<int> v1(4, 10);
	v1.push_back(5);
	v1.push_back(5);
	v1.push_back(7);
	v1.pop_back();
	for (auto e : v1)
	{
		std::cout << e << " ";
	}
}
void test4()
{
	std::vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);
	v1.push_back(5);
	v1.push_back(6);
	v1.push_back(7);
	v1.push_back(8);
	v1.push_back(9);
	v1.push_back(10);
	//std::vector<int>::iterator ptr = std::find(v1.begin(), v1.end() - 1, 5);
	auto ptr = std::find(v1.begin(), v1.end() - 1, 5);
	//find返回的是查找的值的前一个指针
	v1.erase(ptr);

	//v1.insert(ptr, 4, 0);
	//std::vector<int> v2(4, 0);
	//v1.swap(v2);
	//std::cout << v2[1] << std::endl;
}
int main()
{
	//test1();
	//test2();
	//test3();
	test4();

	return 0;
}