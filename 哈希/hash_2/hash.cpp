#define _CRT_SECURE_NO_WARNINGS 1
#include"hash.hpp"
int main()
{
	Lp700::hash<int,int> h;
	std::pair<int, int> p(1,1);
	h.insert(p);

	return 0;
}