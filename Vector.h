#pragma once
#include<iostream>
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
			:_Start(nullptr),
			_Finish(nullptr),
			_EndofStorage(nullptr)
		{}

		template<class inputiterator>
		Vector(inputiterator first, inputiterator last)
			: _Start(nullptr),
			_Finish(nullptr),
			_EndofStorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				first++;
			}
		}

		void Swap(Vector<T>& v)
		{
			std::swap(_Start, v._Start);
			std::swap(_Finish, v._Finish);
			std::swap(_EndofStorage, v._EndofStorage);
		}

		//拷贝构造
		Vector(const Vector<T>& v1)
			:_Start(nullptr),
			_Finish(nullptr),
			_EndofStorage(nullptr)
		{
			Vector<T> tmp(v1.begin(), v1.end());
			Swap(tmp);
		}

		//赋值重载
		Vector<T>& operator=(Vector<T> v)
		{
			Swap(v);
			return *this;
		}

		//析构函数
		~Vector()
		{
			if (_Start)
			{
				delete[] _Start;
				_Start = _Finish = _EndofStorage = nullptr;
			}
		}

		const_iterator begin()
		{
			return _Start;
		}

		const_iterator end()
		{
			return _Finish;
		}

		const T& operator[](size_t)const
		{
			assert(i < size());
			return _Start[i];
		}

		//添加空间
		void reserve(size_t n)
		{
			size_t sz = size();
			if (n > capacity())
			{
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0, i < sz, i++)
					{
						tmp[i] = _Start[i];
					}
				}
			}
			delete[]_Start;
			_Start = tmp;
			_Finish = _Start + sz;
			_EndofStorage = _Start + n;
		}
		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_Finish = _Start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}
				while (_Finish != _Start + n)
				{
					*_Finish = val;
					_Finish++;
				}
			}
		}

		iterator insert(iterator pos, const T& v)
		{
			assert(pos >= _Start && pos <= Finish);
			if (_Finish == _EndofStorage)
			{
				size_t sz = pos - _Start;
				reserve(capacity() == 0 ? 4 : 2 * capacity());
				pos = _Start + sz;
			}
			iterator end = _Finsih - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				end--;
			}
			*pos = v;
			_Finish++;
			return pos;
		}
		iterator erase(iterator pos)
		{
			assert(pos >= _Start && pos <= _Finish);
			iterator end = pos + 1;
			while (end <= Finish)
			{
				*(end - 1) = *end;
				end++;
			}
			_Finish--;
			return pos;
		}
	private:
		iterator _Start;
		iterator _Finish;
		iterator _EndofStorage;
	};
}
