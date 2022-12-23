#pragma once
#include<iostream>
#include<string>
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
}
