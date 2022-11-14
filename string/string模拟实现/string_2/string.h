#pragma once
#include<iostream>
#include<cstring>
#include<cassert>
#include<algorithm>
namespace Lp700
{
	class string
	{
		typedef char* iterator;
	public:
		string(const char* pStr = "");
		string(const string& s);
		void swap(string& s);
		string& operator=( string& s);
		iterator begin();
		iterator end();
		void push_back(char c);
		void reserve(int n);
		void clear();
		int size();
		int length();
		int capacity();
		void resize(int n, char c = '\0');
		const iterator c_str()const;
		~string();
	private:
		int _capacity;
		int _size;
		char* _pStr;
	};
}

