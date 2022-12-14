#pragma once
#include<iostream>
#include<vector>
namespace Lp700
{
	enum status
	{
		EXIST,
		EMPTY,
		DELETE
	};
	template<class key,class value>
	struct HashData
	{
		std::pair<key, value> _p;
		status _status;
	};
	template<class key,class value>
	class hash
	{
	public:
		hash(int capacity = 10)
			:_hash(capacity)
			, _size(0)
		{
			for (int i = 0; i < capacity; i++)
			{
				_hash[i]._status = EMPTY;
			}
		}
		void insert(const std::pair<key, value>& p)
		{
			//构建哈希函数
			int start = p.first%_hash.size();
			//构建偏移量
			int i = 0;
			start = start + i;
			while (_hash[start]._status == EXIST)
			{
				++i;
				start += i;
				//防止在数组里面找到尾还没有找到
				start = start % _hash.capacity();
			}
			_hash[start]._p = p;
			_hash[start]._status = EXIST;
		}
	private:
		std::vector<HashData<key, value>> _hash;
		size_t _size;
	};
}