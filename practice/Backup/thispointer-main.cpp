#include <iostream>
#include "this-pointer.h"
#include <memory>

using namespace std ;

int main()
{
	A *a = new A;
	auto_ptr<A> a1(a);
	
	a1->fun();
	a1->fun();
	
	// B *b = new B(20);
	// auto_ptr<B> b1(b);
	return 0;
}