#pragma once
#include<assert.h>
#include<string.h>
#include<iostream>
#include<string>
namespace Lp700
{
	class _string
	{
	public:
		_string(const char* str = "");
		_string(const _string& s);
		_string& operator=(const _string& s);
		~_string();
	private:
		char* _str; 
	};
}
