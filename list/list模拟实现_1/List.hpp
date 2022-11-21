#pragma once
#include<iostream>
namespace Lp700
{
	//1.创建节点
	template <class T>
	struct ListNode
	{
		//构造函数(保证每一个节点都是经过初始化的  ListNode<T> ln())
		ListNode(const T& _data = T())
			:prev(nullptr),
			next(nullptr),
			data(_data)
		{}

		ListNode<T>* prev;
		ListNode<T>* next;
		T data;
	};
	//2.创建迭代器
	//3.创建List类
}