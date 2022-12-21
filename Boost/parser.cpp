#include<iostream>
#include<string>
#include<vector>
const std::string original="data/input/";
const std::string result="data/raw_html/raw_txt";
struct DocInfo
{
	std::string title;
	std::string content;
	std::string url;
}docinfo_t;
//第一步：将带有html的文件保存在文件夹里面
bool TransFunc1(const std::string& original,std::vector<std::string>* file);

//第二步：将文件夹里面的文件进行解析
bool AnanFunc(std::vector<std::string>* file,std::vector<docinfo_t>& docinfo);

//第三步：将解析好的文件保存在输出文件夹里面
bool TransFunc2(std::vector<docinfo_t>* docinfo,const std::string& result);
int main()
{
	std::vector<std::string> file;
	if(!TransFunc1(original,&file))
	{
		std::cerr<<"TransFunc1 error!"<<std::endl;
		return 1;
	}

	if(!AnanFunc(&file,docinfo))
	{
		std::cerr<<"AnanFunc error!<<"std::endl;
		return 2;
	}
	
	if(!TransFunc2(&docinfo,&result))
	{
		std::cerr<<"TransFunc2 error"<<std::endl;	
		return 3;
	}

	return 0;
}
bool TransFunc1(const std::string& original,std::vector<std::string>* file)
{
	
}
