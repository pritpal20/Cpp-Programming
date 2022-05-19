#include <iostream>

class Example
{
public:

	Example(int var)
	{
		std::cout << "Example constructed 2" << std::endl;
	}

	Example()
	{
		std::cout << "Example constructed 1" << std::endl;
	}
	
};

class MyClass
{
	Example E1;
	int &var ;
	int a ;
public:
	//Constr
	MyClass() :E1(8),var(a)
	{

	}

	//Constr
	MyClass(Example e1 ) :E1(e1),var(a)
	{
		
	}

	//Copy constructor 
	/*
		initialization list used initialize const member variable 
	*/
	MyClass(const MyClass&  rhs ) :E1(rhs.E1),var(a),a(rhs.a)
	{
		
	}
	~MyClass()
	{

	}
	
};

int main()
{
	Example E1;
	MyClass C1(E1);


	return 0;
}