#pragma once
#include<iostream>
#include<vector>
#include<functional>
namespace Lp700
{
	//1.仿函数
	template<class T>
	struct less
	{
		bool operator()(const T& num1, const T& num2)
		{
			return num1 < num2;
		}
	};

	template<class T>
	struct greater
	{
		bool operator()(const T& num1, const T& num2)
		{
			return num1 > num2;
		}
	};
	//2.priority_queue模板
	template<class T,class Container=std::vector<T>,class Compare=less<T>>
	class priority_queue
	{
	public:
		priority_queue()
			:container()//调用容器的默认构造函数
		{}
		template<class iterator>
		priority_queue(iterator first, iterator last)
			:container(first,last)
		{
			int heap_size = container.size();
			int last_parent = (heap_size - 2) / 2;
			//从最后一个父节点开始进行调堆
			for (int i = last_parent; i > 0; i--)
			{
				adjustdown(i);
			}
		}
		//1.push
		void push(const T& value)
		{
			container.push_back(value);
			adjustup(container.size() - 1);
		}
		//2.pop
		void pop()
		{
			if (empty())
			{
				return;  
			}
			//首尾元素相换，queue遵守尾进头出
			std::swap(container.front(), container.back());
			container.pop_back();
			adjustdown(0);
		}
		//3.top
		const T& top()const
		{
			return container.front();
		}
		//4.empty
		bool empty()const //返回的是成员变量的内部函数
		{                 //为防止被篡改加入const设置权限
			return container.empty();
		}
		//5.size
		int size()const
		{
			return container.size();
		}
	private:
		void adjustup(int child)
		{
			Compare compare;
			int parent = (child - 1) / 2;
			while (child)
			{
				if (compare(container[parent] , container[child]))
				{
					std::swap(container[parent], container[child]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}
		void adjustdown(int parent)
		{
			//次数的孩子节点都是左孩子节点
			size_t child = 2 * parent + 1;
			Compare compare;
			while (child < container.size())
			{
				//判断右孩子是否是左右孩子当中最大者
				if ((child + 1) < container.size() && compare(container[child] , container[child + 1]))
				{
					//将最大者当中的右孩子赋值给孩子节点
					child++;
				}
				//判断父节点是否比孩子节点大
				if (compare(container[parent], container[child]))
				{
					std::swap(container[child], container[parent]);
					
					//继续向下进行调整为堆
					parent = child;
					child = 2 * child + 1;
				}
				else
				{
					break;
				}
			}
		}
	private:
		Container container;
	};
}


