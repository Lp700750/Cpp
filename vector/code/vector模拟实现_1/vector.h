#pragma once
#include<iostream>
namespace Lp700
{
	template<class T>
	class vector
	{
		typedef T* iterator;
	public:
		vector()
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{}
		void push_back(const T& value)
		{
			if (finish == end_of_storage)
			{
				int _capacity = capacity();
				_capacity = 0 ? 4 : 2 * _capacity;
				reserve(_capacity);
			}
			start[size()] = value;
			finish++;
		}
		vector(int n, const T& value = T())
			:start(nullptr),
			finish(nullptr),
			end_of_storage(nullptr)
		{
			reserve(n);
			for (int i = 0; i < n; i++)
			{
				start[i] = value;
			}
		}
		int capacity()
		{
			return end_of_storage - start;
		}
		int size()
		{
			return finish - start;
		}
		void reserve(int n)
		{
			if (n > capacity())
			{
				int old_size = size();
				T* tmp = new T[n];

				if (start)
				{
					for (int i = 0; i < old_size; i++)
					{
						tmp[i] = start[i];
					}
				}
				start = tmp;
				finish = start + old_size;
				end_of_storage = start + n;
			}

		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}
