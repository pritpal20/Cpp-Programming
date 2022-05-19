#include <iostream>

class MyClass
{

public :
	MyClass()
	{
		std::cout << "MyClass object created " << std::endl;
	}

};


int main(int argc, char const *argv[])
{
	
	const int  var = 100;

	int *b = new int;

	*b = 2;
	b = (int*)(&var);

	std::cout << *b << var  << std::endl;

	return 0;
}