#define _CRT_SECURE_NO_WARNINGS 1
#include"_string.h"
Lp700::_string::_string(const char* str)
{
	assert(nullptr != str);
	_str = new char[strlen(str) + 1];
	strcpy(_str, str);
}
//旧版本的拷贝构造
Lp700::_string::_string(const _string& s)
	:_str(new char[strlen(s._str)+1])
{
	strcpy(_str, s._str);
}
//新版本的拷贝构造
Lp700::_string::_string(const _string& s)
	:_str(nullptr)
{
	_string tmpStr(s._str);
	//tmpStr作为一个中间对象，出了作用域就会调用析构函数进行清理空间
	strcpy(_str, tmpStr._str);
}
//旧版本的赋值重载
Lp700::_string& Lp700::_string::operator=(const Lp700::_string& s)
{
	if (this != &s)
	{
		char* ptr = new char[strlen(s._str) + 1];
		strcpy(ptr, s._str);
		delete[] _str;
		_str = ptr;
	}
	return *this;
}
//新版本的复制重载
Lp700::_string& Lp700::_string::operator=(const Lp700::_string& s)
{
	if (this != &s)
	{
		_string tmpStr(s);
		std::swap(_str, tmpStr._str);
	}
	return *this;
}
Lp700::_string::~_string()
{
	if (_str)
	{
		delete _str;
		_str = nullptr;
	}
}