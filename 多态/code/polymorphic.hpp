#pragma once
#include<iostream>
namespace Lp700
{
	class person
	{
	public:
		virtual void print()
		{
			std::cout << "È«¼Û" << std::endl;
		}
	};
	class student:public person
	{
	public:
		virtual void print()
		{
			std::cout << "°ë¼Û" << std::endl;
		}
	};
}
