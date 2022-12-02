#pragma once
#include<iostream>
#include<string>
namespace Lp700
{
	class person
	{
	public:
		person()
		{
			++num;
		}
	protected:
		std::string school = "MIT";
	public:
		static int num;
	};
	int person::num = 0;
	class master:public person
	{
	public:
		void print()
		{
			std::cout << "information:" <<person::school<<"_"<<name
				<<"_"<<gender<<"_"<<age << std::endl;
		}
	protected:
		std::string name = "Jolly.Roger";
		std::string gender = "male";
		size_t age = 24;
	};
	class teacher:public person
	{
	public:
		void print()
		{
			std::cout << "information:" << person::school << "_" << name
				<< "_" << gender << "_" << age << std::endl;
		}
	protected:
		std::string name = "lily";
		std::string gender = "female";
		size_t age = 42;
	};
}
