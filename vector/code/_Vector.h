#pragma once

namespace bit
{
	template<class T>
	class vector
	{
	public:
		typedef T* iterator;
		typedef const T* const_iterator;

		vector()
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{}

		// v2(v1)
		// 传统写法
		/*vector(const vector<T>& v)
		{
		_start = new T[v.capacity()];
		_finish = _start + v.size();
		_endofstorage = _start + v.capacity();

		memcpy(_start, v._start, v.size()*sizeof(T));
		// 这里也要一个个赋值跟reserve中一样
		}*/

		// 一个类模板的成员函数，又可以是一个函数模板
		template <class InputIterator>
		vector(InputIterator first, InputIterator last)
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			while (first != last)
			{
				push_back(*first);
				++first;
			}
		}
		 
		void swap(vector<T>& v)
		{
			std::swap(_start, v._start);
			std::swap(_finish, v._finish);
			std::swap(_endofstorage, v._endofstorage);
		}

		// v2(v1)
		// 现代写法
		//vector(const vector& v)
		vector(const vector<T>& v) // 推荐
			:_start(nullptr)
			, _finish(nullptr)
			, _endofstorage(nullptr)
		{
			vector<T> tmp(v.begin(), v.end());

			//this->swap(tmp);
			swap(tmp);
		}

		// v1 = v3
		// 现代写法
		// vector& operator=(vector v)
		vector<T>& operator=(vector<T> v) // 推荐
		{
			swap(v);

			return *this;
		}

		~vector()
		{
			if (_start)
			{
				delete[] _start;
				_start = _finish = _endofstorage = nullptr;
			}
		}

		const_iterator begin() const
		{
			return _start;
		}

		const_iterator end() const
		{
			return _finish;
		}

		iterator begin()
		{
			return _start;
		}

		iterator end()
		{
			return _finish;
		}

		const T& operator[](size_t i) const
		{
			assert(i < size());
			return _start[i];
		}

		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		size_t size() const
		{
			return _finish - _start;
		}

		size_t capacity() const
		{
			return _endofstorage - _start;
		}

		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					//memcpy(tmp, _start, sizeof(T)*size());
					for (size_t i = 0; i < sz; ++i)
					{
						// T 是int，一个一个拷贝没问题
						// T 是string， 一个一个拷贝调用是T的深拷贝赋值，也没问题
						tmp[i] = _start[i];
					}

					delete[] _start;
				}

				_start = tmp;
				// _finish = _start + size(); size（）有问题
				_finish = _start + sz;
				_endofstorage = _start + n;
			}
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity())
				{
					reserve(n);
				}

				while (_finish != _start + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		iterator insert(iterator pos, const T& x)
		{
			assert(pos >= _start);
			assert(pos <= _finish);

			// 满了就扩容
			if (_finish == _endofstorage)
			{
				// 扩容会导致pos失效，扩容需要更新一下pos
				size_t len = pos - _start;
				reserve(capacity() == 0 ? 4 : capacity() * 2);
				pos = _start + len;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;

			return pos;
		}

		iterator erase(iterator pos)
		{
			assert(pos >= _start);
			assert(pos < _finish);

			iterator begin = pos + 1;
			while (begin < _finish)
			{
				*(begin - 1) = *begin;
				++begin;
			}

			--_finish;

			return pos;
		}

		void push_back(const T& x)
		{
			if (_finish == _endofstorage)
			{
				// 扩容
				reserve(capacity() == 0 ? 4 : capacity() * 2);
			}
			*_finish = x;
			++_finish;
		}

		void pop_back()
		{
			assert(_finish > _start);

			--_finish;
		}
	private:
		iterator _start;
		iterator _finish;
		iterator _endofstorage;
	};

	void test_vector1()
	{
		vector<int> v;
		v.push_back(1);
		v.push_back(2);
		v.push_back(3);
		v.push_back(4);
		v.push_back(5);
		v.push_back(6);

		for (size_t i = 0; i < v.size(); ++i)
		{
			cout << v[i] << " ";
		}
		cout << endl;

		vector<int>::iterator it = v.begin();
		while (it != v.end())
		{
			cout << *it << " ";
			++it;
		}
		cout << endl;

		for (auto e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	class Solution {
	public:
		vector<vector<int>> generate(int numRows) {
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (size_t i = 0; i < numRows; ++i)
			{
				vv[i].resize(i + 1);
				vv[i][0] = vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] == 0)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}

			return vv;
		}
	};

	void test_vector2()
	{
		vector<vector<int>> vv = Solution().generate(5);
		for (size_t i = 0; i < vv.size(); ++i)
		{
			for (size_t j = 0; j < vv[i].size(); ++j)
			{
				cout << vv[i][j] << " ";
			}
			cout << endl;
		}
		cout << endl;

		int i = 0;
		int j = int();
		int k = int(10);
		int m(20);
	}

	void test_vector3()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);

		vector<int> v2(v1);
		for (auto e : v2)
		{
			cout << e << " ";
		}
		cout << endl;

		vector<int> v3;
		v3.push_back(10);
		v3.push_back(20);
		v3.push_back(30);

		v1 = v3;
		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector4()
	{
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(3);
		v1.push_back(4);
		vector<int>::iterator it = find(v1.begin(), v1.end(), 2);
		if (it != v1.end())
		{
			// 如果insert中发生了扩容，那么会导致it指向空间被释放
			// it本质就是一个野指针，这种问题，我们就叫迭代器失效
			v1.insert(it, 20);
		}
		// v1.insert(v1.begin(), -1);

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector5()
	{
		// 三种场景去测试
		// 1 2 3 4 5 -> 正常
		// 1 2 3 4   -> 崩溃
		// 1 2 4 5   -> 没删除完
		vector<int> v1;
		v1.push_back(1);
		v1.push_back(2);
		v1.push_back(4);
		v1.push_back(5);
		//v1.push_back(5);
		/*vector<int>::iterator it = find(v1.begin(), v1.end(), 2);
		if (it != v1.end())
		{
			v1.erase(it);
		}*/

		// 要求删除v1所有的偶数
		/*	vector<int>::iterator it = v1.begin();
			while (it != v1.end())
			{
			if (*it % 2 == 0)
			{
			v1.erase(it);
			}

			++it;
			}*/

			/*vector<int>::iterator it = v1.begin();
			while (it != v1.end())
			{
				if (*it % 2 == 0)
				{
					it = v1.erase(it);
				}
				else
				{
					++it;
				}
			}*/

		for (auto e : v1)
		{
			cout << e << " ";
		}
		cout << endl;
	}

	void test_vector6()
	{
		vector<string> v;
		v.push_back("111111111111111111111111");
		v.push_back("111111111111111111111111");
		v.push_back("1111111111");
		v.push_back("1111111111");
		v.push_back("1111111111");

		for (auto& e : v)
		{
			cout << e << " ";
		}
		cout << endl;
	}
}
