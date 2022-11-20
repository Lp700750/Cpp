#define _CRT_SECURE_NO_WARNINGS 1
#include"vector.hpp"
int main()
{
	//Lp700::vector<int> v2;
	//v2.push_back(1);
	//v2.push_back(2);
	//v2.push_back(4);
	//v2.push_back(4);
	//v2.print(); 
	//int* pos = v2.find(3);
	//v2.erase(pos);
	//v2.print();
	//auto it = v2.begin();
	//while (it != v2.end())
	//{
	//	if (*it % 2 == 0)
	//	{
	//		v2.erase(it);
	//	}
	//	else
	//		it++;
	//}
	//v2.print();
	int ret[] = { 1,2,3,4 };
	Lp700::vector<int> v3(ret, ret + (sizeof(ret) / sizeof(ret[0])));
	v3.print();

	return 0;
}