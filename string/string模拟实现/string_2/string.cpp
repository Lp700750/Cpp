#define _CRT_SECURE_NO_WARNINGS 1
#include"string.h"
//构造函数
Lp700::string::string(const char* pStr)
{
	_size = strlen(pStr);
	_capacity = _size;
	_pStr = new char[_capacity + 1];
	strcpy(_pStr, pStr);
}
//析构函数
Lp700::string::~string()
{
	//只有在是非空指针下析构函数才有意义
	if (this != nullptr)
	{
		delete[] _pStr;
		_pStr = nullptr;
	}
}
//拷贝构造
Lp700::string::string(const string& s)
	:_pStr(nullptr),
	_size(0),
	_capacity(0)
{
	string tmpStr(s._pStr);
	swap(tmpStr);
}
//交换函数
void Lp700::string::swap(string& s)
{
	std::swap(_pStr,s._pStr);
	std::swap(_size, s._size);
	std::swap(_capacity, s._capacity);
}
//赋值构造
Lp700::string& Lp700::string::operator=(string& s)
{
	if (this != &s)
	{
		swap(s);
	}
	return *this;
}
//首元素指针
Lp700::string::iterator Lp700::string::begin()
{
	return _pStr;
}
//尾元素指针
Lp700::string::iterator Lp700::string::end()
{
	return _pStr+_size;
}
//尾部添加一个字符
void Lp700::string::push_back(char c)
{
	if (_size == _capacity)
	{
		//开辟的空间不够，需要扩容
		_capacity = 2 * _capacity;
		reserve(_capacity);
		_pStr[_size++] = c;
		_pStr[_size] = '\0';
	}
}
//开辟空间
void Lp700::string::reserve(int n)
{
	if (n > _capacity)
	{
		char* newStr = new char[n];
		strcpy(newStr, _pStr);
		delete[] _pStr;
		_pStr = newStr;
		_capacity = n;
	}
}
//清空内容
void Lp700::string::clear()
{
	_size = 0;
	_pStr[_size] = '\0';
}
//返回c字符串
const Lp700::string::iterator Lp700::string::c_str()const
{
	return _pStr;
}
//字符串的长度
int Lp700::string::size()
{
	return _size;
}
//字符串的长度
int Lp700::string::length()
{
	return _size;
}
//开辟空间的大小
int Lp700::string::capacity()
{
	return _capacity;
}
//调整字符串的大小
void Lp700::string::resize(int n, char c)
{
	if (n < _size)
	{
		_size = n;
		_pStr[_size] = '\0';
	}
	else
	{
		if(n>_capacity)
		{
			reserve(n);
		}
		memset(_pStr + _size, c, n - _size);
		_size = n;
		_pStr[_size] = '\0';
	}
}