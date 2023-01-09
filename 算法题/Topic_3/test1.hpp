//给定一个字符串 s 和一个整数 k，从字符串开头算起，
//每计数至 2k 个字符，就反转这 2k 字符中的前 k 个字符
//Jolly.Roger

#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution
{
public:
	string reverseStr(string s, int k)
	{
		int i = s.size() / (2 * k);
		int j = s.size() % (2 * k);
		string::iterator ptr1 = s.begin();
		//如果只有一个字符串的时候
		if (1 == s.size())
		{
			return s;
		}
		//处理完整的2k的字符串
		while (i)
		{
			int cnt = 2 * k;
			reverse(ptr1, ptr1 + k);
			while (cnt)
			{
				ptr1++;
				cnt--;
			}
			i--;
		}
		//处理最后的0-2k个字符
		if (j > 0 && j < k)
		{
			reverse(ptr1, ptr1 + j);
		}
		else if (j >= k)
		{
			reverse(ptr1, ptr1 + k);
		}
		return s;
	}
};

