#pragma once
#include<iostream>
namespace Lp700
{
	//1.创建节点
	template<class T>
	struct ListNode
	{
		ListNode(const T& value=T())
			:prev(nullptr)
			,next(nullptr)
			,data(value)
		{}

		ListNode<T>* prev;
		ListNode<T>* next;
		T data;
	};
	//2.创建迭代器
	template<class T,class Ref,class Ptr>
	class list_iterator
	{
	//public:
		//typedef list_iterator<T, T&, T*>
		typedef ListNode<T>* pNode;
		typedef list_iterator<T, Ref, Ptr> self;
	public:
		list_iterator(pNode x = nullptr)
			:pNode(x)
		{}
		list_iterator(const self& li)
			:pNode(li.pNode)
		{}
		self& operator++()
		{
			pointer = pointer->next;
			return (*this);
		}
		self operator++(int)
		{
			pNode tmp(pointer);
			pointer = pointer->next;
		}
		self& operator--()
		{
			pointer = pointer->prev;
			return (*this);
		}
		self operator--(int)
		{
			pNode tmp(pointer);
			pointer = pointer->prev;
		}
		T& operator*()
		{
			return pointer->data;
		}
		T* operator->()
		{
			return &(pointer->data);
		}
		bool operator==(const self& li)
		{
			return pointer == li.pointer;
		}
		bool operator!=(const self& li)
		{
			return pointer != li.pointer;
		}
	private:
		pNode pointer;
	};
	//3.创建容器
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef ListNode<T>* pNode;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&,const T*> const_iterator;
	public:
		list()
		{
			//创造出来一个头节点
			CreatPhead();
		}
		list(int n, const T& value)
		{
			CreatPhead();
			for (int i = 0; i < n; i++)
			{
				push_back(value);
			}
		}
		template<class iterator>
		list(iterator first,iterator last)
			:_pNode(nullptr)
		{
			CreatPhead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		iterator begin()
		{ 
			return iterator(_pNode->next);
			//_pNode->next是一个ListNode<T>*类型
			//iterator是一个list_iterator<T,Ref,Ptr>类型
		}
		iterator end()
		{
			return iterator(_pNode);
		}
		void push_back(const T& value)
		{
			Node* node = new Node;
			node->data = value;
			_pNode->prev->next = node;
			node->prev = _pNode->prev;
			node->next = _pNode;
			_pNode->prev = node;
		}
	private:
		void CreatPhead()
		{
			_pNode = new Node;
			_pNode->prev = _pNode;
			_pNode->next = _pNode;
		}
	private:
		pNode _pNode;
	};
}
