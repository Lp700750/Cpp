#pragma once
#include<iostream>
#include<algorithm>
#include<cassert>
namespace Lp700
{
	//1.创建节点
	template<class T>
	struct ListNode
	{
		ListNode(const T& value = T())
			:prev(nullptr)
			, next(nullptr)
			, data(value)
		{}

		ListNode<T>* prev;
		ListNode<T>* next;
		T data;
	};
	//2.创建迭代器
	template<class T,class Ref,class Ptr>
	class list_iterator
	{
		typedef ListNode<T>* pNode;
		typedef list_iterator<T,Ref, Ptr> self;
	public:
		list_iterator(pNode p=nullptr)
			:pointer(p)
		{}
		list_iterator(const self& l)
			:pointer(l.pointer)
		{}
		self operator=(const self& l)
		{
			pointer = l.pointer;
		}
		self& operator++()
		{
			pointer = pointer->next;
			return *this;
		}
		self operator++(int)
		{
			self tmp(*this);
			pointer = pointer->next;
			return tmp;
		}
		self& operator--()
		{
			pointer = pointer->prev;
			return *this;
		}
		self operator--(int)
		{
			self tmp(*this);
			pointer = pointer->prev;
			return tmp;
		}
		bool operator==(const self& l)
		{
			return l.pointer == pointer;
		}
		bool operator!=(const self& l)
		{
			return l.pointer != pointer;
		}
		Ref operator*()
		{
			return pointer->data;
		}
		Ptr operator->()
		{
			return &(pointer->data);
		}
	//private:
		pNode pointer;
	};
	//3.创建list
	template<class T>
	class list
	{
		typedef ListNode<T> Node;
		typedef ListNode<T>* pNode;
		typedef list_iterator<T, T&, T*> iterator;
		typedef list_iterator<T, const T&, const T*> const_iterator;
	public:
		list()
			:pointer(nullptr)
		{
			CreatHead();
		}
		list(int n, const T& value)
		{
			CreatHead();
			for (int i = 0; i < n; i++)
			{
				push_back(value);
			}
		}
		void swap(list<T>& tmp)
		{
			std::swap(pointer->data, tmp.pointer->data);
			std::swap(pointer->prev, tmp.pointer->prev);
			std::swap(pointer->next, tmp.pointer->next);
		}
		list(const list<T>& l)
			:pointer(nullptr)
		{
			CreatHead();
			list<T> tmp(l.begin(), l.end());
			//swap(tmp);
			std::swap(pointer, tmp.pointer);
		}
		list<T>& operator=(list<T> tmp)//list<T> tmp  直接对传入的值进行拷贝构造
		{                                    //赋值完毕后该tmp直接被回收
			//swap(tmp);
			std::swap(pointer, tmp.pointer);
			return *this;
		}
		int size()const
		{
			int list_num = 0;
			const_iterator start = begin();
			while (start != end())
			{
				list_num++;
				++start;
			}
			return list_num;
		}
		void push_back(const T& value)
		{
			Node* newPointer = new Node;
			pointer->prev->next = newPointer;
			newPointer->prev = pointer->prev;
			newPointer->next = pointer;
			pointer->prev = newPointer;
			newPointer->data = value;
		}
		void pop_back()
		{
			pNode _tail_list = pointer->prev->prev;
			pointer->prev = _tail_list;
			_tail_list->next = pointer;
		}
		void push_front(const T& value)
		{
			pNode head = pointer->next;
			insert(iterator(head), value);
		}
		void pop_front()
		{
			pNode head = pointer->next;
			erase(iterator(head));
		}
		template<class iterator>
		list(iterator first,iterator last)
		{
			CreatHead();
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		iterator begin()
		{
			return iterator(pointer->next); 
		}
		iterator end()
		{
			return iterator(pointer);
		}
		const_iterator begin()const
		{
			return const_iterator(pointer->next);
		}
		const_iterator end()const
		{
			return const_iterator(pointer);
		}
		void clear()
		{
			iterator it = begin();
			while (it != end())
			{
				erase(it++);
				//++it;
			}
		}
		iterator insert(iterator pos, const T& value)
		{
			pNode Next = pos.pointer->next;
			pNode Prev = pos.pointer->prev;
			pNode pointer = new Node(value);
			//pointer->data = value;
			Prev->next = pointer;
			pointer->prev = Prev;
			pointer->next = Next;
			Next->prev = pointer;
			return iterator(pointer);
		}
		iterator erase(iterator pos)
		{
			assert(pos != end());
			pNode newpos = pos.pointer->next;
			pos.pointer->prev->next = pos.pointer->next;
			pos.pointer->next->prev = pos.pointer->prev;
			delete pos.pointer;
			return iterator(newpos);
		}
		T& front()
		{
			return pointer->next->data;
		}
		T& back()
		{
			return pointer->prev->data;
		}
		~list()
		{
			clear();
			delete pointer;
			pointer = nullptr;
		}
	private:
		//给头节点搭配关系
		void CreatHead()
		{
			pointer = new Node;
			pointer->next = pointer;
			pointer->prev = pointer;
		}
	private:
		//定义头节点指针
		pNode pointer;
	};
}
