#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
#include<assert.h>
class Test1
{
public:
	Test1(int capacity=10)
	{
		_ptr = (int*)malloc(capacity*sizeof(int));
		assert(_ptr);
		//_ptr = ptr;
		_size = 0;
		//_size=size;
		_capacity = capacity;
	}
	void print()
	{
		std::cout << "Test1()" << std::endl;
	}
	/*~Test1()
	{
		free(_ptr);
		_ptr = nullptr;
		_size = _capacity = 0;
		std::cout << "~Test1()" << std::endl;
	}*/
private:
	int* _ptr;
	int _size;
	int _capacity;
};
class Test2
{
public:
	Test2()
	{}
	void print()
	{
		std::cout << "Test2" << std::endl;
	}
	~Test2()
	{
		_t.~Test1();
	}
private:
	Test1 _t;
};
int main()
{
	Test2 t2;
	t2.print();

	return 0;
}