#pragma once
#include<iostream>
//#include<string>
#include<assert.h>
using namespace std;
namespace Lp700
{
	template<class T>
	class Vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		Vector()
			:start(nullptr)
			,finish(nullptr)
			,end_of_storage(nullptr)
		{}
		//经典写法
		Vector(const Vector<T>& v)
		{
			start = new T[v.capacity()];
			finish = start + v.size();
			end_of_storage + v.capacity();

			memcpy(start, v.start, v.size() * sizeof(T));
		}
		//现在写法
		template<class Ipout_iterator>
		Vector(Ipout_iterator args1, Ipout_iterator args2)
			:start(nullptr)
			, finish(nullptr)
			, end_of_storage(nullptr)
		{
			while (args1 != args2)
			{
				push_back(*args1);
				++args;
			}
		}
		void Swap(Vector<int>& v)
		{
			std::swap(start, v.start);
			std::swap(finish, v.finish);
			std::swap(end_of_storage, v.end_of_storage);
		}
		Vector(const Vector<int>& v)
			:start(nullptr)
			, finish(nullptr)
			, end_of_storage(nullptr)
		{
			//问题1，为什么要重新定义一个函数的模板？
			Vector<T> tmp(v.begin(), v.end());
			Swap(tmp);
		}
		Vector<T>& operator=(Vector<T> v)
		{
			swap(v);
			return *this;
		}
		~Vector()
		{
			if (start)
			{
				delete[] start;
				start = finish = end_of_storage = nullptr;
			}
		}
		const_iterator begin() const
		{
			return start;
		}
		const_iterator end()const
		{
			return finish;
		}
		iterator begin()
		{
			return start;
		}
		iterator end()
		{
			return finish;
		}
		const T& operator[](size_t n)
		{
			assert(n < size());
			return start[n];
		}
		size_t size()const
		{
			return finish - start;
		}
		size_t capacity()const
		{
			return end_of_storage - start;
		}
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t len = size();
				T* tmp = new T[n];
				if (start)
				{
					memcpy(start, tmp);
					delete[] start;
				}
				start = tmp;
				finish = start + len;
				end_of_storage = start + n;
			}
		}
		void resize(size_t n, const T& args = T())
		{
			if (n < size())
			{
				finish = start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (finish != (start + n))
				{
					*finish = args;
					++finish;
				}
			}
		}
		void push_back(const T& x)
		{
			if (finish == end_of_storage)
			{
				reserve(capacity() == 0 ? 4 : 2 * capacity());
			}
			*finish = x;
			++finish;
		}
		void pop_back()
		{
			assert(finish > start);
			--finish;
		}
	private:
		iterator start;
		iterator finish;
		iterator end_of_storage;
	};
}
