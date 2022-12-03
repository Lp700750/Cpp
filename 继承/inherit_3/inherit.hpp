#pragma once
namespace Lp700
{
	class A
	{
	public:
		int a;
	};
	class B : virtual public A
	{
	public:
		int b;
	};
	class C : virtual public A
	{
	public:
		int c;
	};
	class D : public B, public C
	{
	public:
		int d;
	};
}
