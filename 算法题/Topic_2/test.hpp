//反转字符串当中的单词
//Jolly.Roger

#pragma once
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
class Solution
{
	//Let's take LeetCode contest
	//s'teL ekat edoCteeL tsetnoc
public:
	string reverseWords(string s)
	{
		//方法1
		//string::iterator ptr1 = s.begin();
		//string::iterator ptr2 = s.begin();
		//while (ptr2 != s.end())
		//{
		//	if ((*ptr2) == ' ')
		//	{
		//		reverse(ptr1, ptr2);
		//		ptr1 = ptr2 + 1;
		//	}
		//	ptr2++;
		//}
		//reverse(ptr1, ptr2);
		//return s;

		//方法2
		//string desStr;
		//int des = 0;
		//string::iterator ptr1 = s.begin();
		//string::iterator ptr2 = s.begin();
		//while (ptr2 != s.end())
		//{
		//	if ((*ptr2) == ' ')
		//	{
		//		string midStr = s.substr(des, (ptr2 - ptr1));
		//		reverse(midStr.begin(), midStr.end());
		//		desStr.append(midStr);
		//		//desStr+=' ';
		//		desStr.push_back(' ');
		//		des += (ptr2 - ptr1) + 1;
		//		ptr1 = (ptr2 + 1);
		//	}
		//	ptr2++;
		//}
		//string midStr = s.substr(des, size_t(ptr2 - ptr1));
		//reverse(midStr.begin(), midStr.end());
		//desStr.append(midStr);
		//return desStr;
	}
};
