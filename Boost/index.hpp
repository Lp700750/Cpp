#pragma once
#include<iostream>
#include<string>
#include<vector>
namespace lp700
{
	struct docInfo
	{
		std::string title;
		std::string content;
		std::string url;
		uint64_t id;
	};
	struct inform
	{
		uint64_t id;
		std::string word;
		int weight;

		inform()
			:weight(0)
		{}
	};
	class index
	{
	private:
		//正排索引
		std::string<docinfo> forwardIndex;
		//倒排索引
		std::unordered_map<std::string,inform> invertedIndex;
	public:
		index()
		{}
		~index()
		{}
	public:
		
		
	};
}
