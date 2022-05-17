#ifndef _THIS-POINTER_H
#define _THIS-POINTER_H

#include <iostream>
using namespace std;

class A
{
	int x;
  public:
    A() { x = 10;}
    void fun() 
    {
		
		cout << "this pointer b4 delete " << this << endl;
		cout<<x << endl;
		delete this;

		/* Invalid: Undefined Behavior */
		cout << "this pointer after delete " << this << endl;
		cout<<x << endl;
    }
	
};


class B
{
public:
    B(int);
    ~B();
    int *pi;
};

B::B(int i)
{
    pi = new int(i);
}

B::~B()
{
	 delete pi;
}

#endif
