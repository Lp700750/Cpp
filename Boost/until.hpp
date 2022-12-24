#pragma once
#include<iostream>
#include<string>
#include<boost/algorithm/string.hpp>
namespace until
{
	class FileTool
	{
	public:
		static bool ReadFile(const std::string &filePath,std::string *outContent)
		{
			std::ifstream in(filePath,std::ios::in);
			if(!in.is_open())
			{
				std::cerr<<"open file:"<<filePath<<"error"<<std::endl;
				return false;
			}
			std::string boostStr;
			while(std::getline(in,boostStr))
			{
				outContent+=boostStr;	
			}
			return true;	
		}
	};
	class stringUntil
	{
	public:
		void split(const std::string &targetFile,std::vector<std::string>* outFile,std::string reparator)
		{
			boost::split(*outFile,targetFile,boost::is_any_of(reparator),boost::token_compress_on);
		}
	};
}
