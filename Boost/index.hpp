#pragma once
#include<iostream>
#include<string>
#include<vector>
#include"until.hpp"
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
		bool builtIndex(const std::string& input)
		{
			std::ifstream in(input,std::ios::in | std::ios::binary)
			if(!in.is_open())
			{
				std::cerr<<"open file:"<<input<<"error"<<std::endl;
				return false;
			}
			std::string line;
			int cnt=0;
			while(std::getline(in,line))
			{
				docinfo* doc=forwardIndex(line);
				if(nullptr==doc)
				{
					std::cerr<<"built error!"<<std::endl;
					continue;
				}
				invertedIndex(*doc);
				cnt++;
			}
		}
	private:
		bool forwardIndex(const std::string& line)
		{
			//1.字符串切分
			std::vector<std::string> fileResult;
			std::string separator="\3";
			until::stringUntil::split(line,&fileResult,separator);	
			if(fileResult.size()!=3)
			{
				return nullptr;
			}
			//2.字符串填充docinfo
			docinfo doc;
			doc.title=fileResult[0];
			doc.content=fileResult[1];
			doc.url=fileResult[2];
			doc.id=forwardIndex.size();
			//3.将信息填充到正派索引的数组当中
			forwardIndex.push_back(std::move(doc))
			return &forwardIndex.back();
		}
		bool invertedIndex(const docinfo& doc)
		{
			
		}
	};
}
