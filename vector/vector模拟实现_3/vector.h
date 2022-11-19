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
		vector(int n, const T& value = T())
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
			reserve(v.capacity());
			for (int i = 0; i < v.size(); i++)
			{
				start[i] = v.start[i];
			}
			finish = start + v.size();
		}
		//赋值重载
		vector<T>& operator=(vector<T>& v)
		{
			swap(v);
			return *this;
		}
		//交换数据
		void swap(vector<T>& v)
		{
			std::swap(start,v.start);
			std::swap(finish,v.finish);
			std::swap(end_of_storage,v.end_of_storage);
		}
		//容器的容量大小
		int size()const
		{
			return finish - start;
		}
		//容器的空间大小
		int capacity()const
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
				for (int i = 0; i < _size; i++)
				{
					_start[i] = start[i];
				}
				start = _start;
				finish = start + _size;
				end_of_storage = start + n;
			}
		}
		//调整容器的容量大小
		void resize(int n, T value = T())
		{
			//缩小容量
			if (n < size())
			{
				finish -= 2;
			}
			//扩大容量
			else
			{
				//先要判断现有的容量是否需要扩容
				if (n > capacity())
				{
					reserve(n);
				}
				//填充增添的数据
				for (int i = size(); i < n; i++)
				{
					start[i] = value;
				}
				finish = start + n;
			}
		}
		//随机位置进行插入
		iterator insert(iterator pos, const T& value)
		{
			//计算插入位置到起点的距离，防止后面迭代器失效用
			int oldSize_iterator = pos - start;

			//判断是否需要扩容
			if (finish == end_of_storage)
			{
				int _num = (capacity() == 0 ? 1 : 2 * capacity());
				reserve(_num);
				pos = start + oldSize_iterator;
			}
			
			//开始将值往后移
			iterator end = finish - 1;
			while (pos != end)
			{
				*(end + 1) = *end;
				--end;
			}
			//开始进行替换值
			*pos = value;
			++finish;
			return pos;
		}
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
		//尾部插入
		void push_back(const T& value)
		{
			//空间不够扩容
			if (finish == end_of_storage)
			{
				//需要扩多少容量
				int _capacity = (capacity() == 0 ? 1 : 2 * capacity());
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
		//尾部删除
		void pop_back()
		{
			if (start != finish)
			{
				--finish;
			}
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

