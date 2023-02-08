#pragma once
#include<iostream>
namespace Lp700
{
	template<class T>
	struct BSTNode
	{
		BSTNode(const T& value=T())
			:LeftPtr(nullptr)
			,RightPtr(nullptr)
			,data(value)
		{}

		BSTNode<T>* LeftPtr;
		BSTNode<T>* RightPtr;
		T data;
	};

	template<class T>
	class BSTree
	{
		typedef BSTNode<T> Node;
		typedef BSTNode<T>* iterator;
	public:
		BSTree()
			:pNode(nullptr)
		{}
		//1.insert
		void insert(const T& value)
		{
			//如果是空树的情况
			if (pNode == nullptr)
			{
				pNode = new Node;
				pNode->data = value;
				pNode->RightPtr = nullptr;
				pNode->LeftPtr = nullptr;
				return;
			}
			//非空树的插入
			iterator parent = nullptr;
			iterator CurNode = pNode;
			
			//查找空的位置插入
			while (CurNode)
			{
				//保留找到最终位置的父节点
				parent = pNode;
				//左节点
				if (CurNode->data > value)
				{
					CurNode = CurNode->LeftPtr;
				}
				//右节点
				else if (CurNode->data < value)
				{
					CurNode = CurNode->RightPtr;
				}
				//相等的时候就不用插入
				else
				{
					return;
				}
			}

			CurNode = new Node(value);
			if (parent->data > value)
			{
				parent->LeftPtr= CurNode;
			}
			else
			{
				parent->RightPtr= CurNode;
			}
		}
		//2.erase
		//3.find
	private:
		iterator pNode;
	};
}