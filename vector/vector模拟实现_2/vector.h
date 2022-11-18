#pragma once
#include<iostream>
namespace Lp700
{
	template<class T>
	class vector
	{
		typedef T* iterator;
	public:
		//无参数构造函数
		vector()
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{}
		//有参数的构造函数
		vector(int n,const T& value=T())
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			reserve(n);
			while (n)
			{
				push_back(value);
				n--;
			}
		}
		//拷贝构造
		vector(const vector<T>& v)
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			reserve(v.end_of_storage);
		}
		//容器的容量大小
		int size()
		{
			return finish - start;
		}
		//容器的空间大小
		int capacity()
		{
			return end_of_storage - start;
		}
		//调整容器空间大小
		void reserve(int n)
		{
			if (n > capacity())
			{
				int _size = size();

				//_capacity == 0 ? 1 : n;
				//哪怕是等于0,在这里面提出来也是没有意义的,此处只关心扩容的空间

				T* _start = new T[n];
				for (int i = 0; i < _size ; i++)
				{
					_start[i] = start[i];
				}
				start = _start;
				finish = start + _size;
				end_of_storage = start + n;
			}
		}
		//尾部插入
		void push_back(const T& value)
		{
			//空间不够扩容
			if (finish == end_of_storage)
			{
				//需要扩多少容量
				int _capacity = capacity();
				_capacity == 0 ? 1 : 2 * _capacity;
				//扩容
				reserve(_capacity);
			}
			//在尾部添加数据
			int _size = size();
			start[_size] = value;
			//start[size()] = value;
			++finish;
			//start[size()] = '\0';
			//start[_size] = '\0';
		}
		//打印里面的成员
		void print()
		{
			int n = size();
			for (int i = 0; i < n; i++)
			{
				std::cout << start[i] << " ";
			}
			printf("\n");
		}
		//析构函数
		~vector()
		{
			delete[] start;
			start = finish = end_of_storage = nullptr;
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}
