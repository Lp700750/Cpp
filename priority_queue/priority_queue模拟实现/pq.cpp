#define _CRT_SECURE_NO_WARNINGS 1
#include"pq.hpp"
int main()
{
	Lp700::priority_queue<int> pq;
	pq.push(1);
	pq.push(6);
	pq.push(8);
	pq.push(2);
	pq.push(5);
	while (!pq.empty())
	{
		std::cout << pq.top();
		pq.pop();
	}

	return 0;
}