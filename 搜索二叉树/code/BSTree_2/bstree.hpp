#pragma once
#include<iostream>
namespace Lp700
{
	//创造节点
	template<class T>
	struct pNode
	{
		pNode(const T& value=T())
			:LeftPtr(nullptr)
			,RightPtr(nullptr)
			,data(value)
		{}

		pNode<T>* LeftPtr;
		pNode<T>* RightPtr;
		T data;
	};
	//搜索二叉树
	template<class T>
	class BSTree
	{
		typedef pNode<T> Node;
		typedef pNode<T>* iterator;
	public:
		BSTree()
			:pRoot(nullptr)
		{}
		//1.insert
		void insert(const T& value)
		{
			//1.空树
			if (pRoot == nullptr)
			{
				pRoot = new Node(value);
				return;
			}
			//2.非空树的插入
			iterator CurPtr = pRoot;
			iterator parent = nullptr;
			while (CurPtr)
			{
				parent = CurPtr;
				if (CurPtr->data > value)
				{
					CurPtr = CurPtr->LeftPtr;
				}
				else if (CurPtr->data < value)
				{
					CurPtr = CurPtr->RightPtr;
				}
				//相等的情况下插入不进去
				else
				{
					return;
				}
				CurPtr = new Node(value);
				if (parent->data > value)
				{
					parent->LeftPtr=CurPtr;
				}
				else
				{
					parent->RightPtr=CurPtr;
				}
			}
		}
		//2.find
		iterator find(const T& value)
		{
			iterator CurPtr = pRoot;
			while (CurPtr)
			{
				if (CurPtr->data > value)
				{
					CurPtr = CurPtr->LeftPtr;
				}
				else if (CurPtr->data < value)
				{
					CurPtr = CurPtr->RightPtr;
				}
				else
				{
					return CurPtr;
				}
			}
			return nullptr;
		}
		//3.erase
		void erase()
	private:
		iterator pRoot;
	};
}
