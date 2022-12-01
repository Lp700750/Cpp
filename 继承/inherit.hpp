#pragma once
#include<iostream>
#include<string>
namespace Lp700
{
	class person
	{
	public:
		person(const char* str="Jolly.Roger")
			:name(str)
		{}
		void print()
		{
			std::cout << "name:" << name << std::endl;
			//std::cout << "age:" << age << std::endl;
		}
	protected:
		std::string name;
	};
	class student : public person
	{
	public:
		student(int _age=24)
			:age(_age)
		{}
		void print()
		{
			//std::cout << "name:" << name << std::endl;
			std::cout << "name:" << person::name << std::endl;
			//person::print();
		}
	private:
		//std::string name = "Zonda";
		int age;
	};
}
