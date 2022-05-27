#include <iostream>
#include <memory>

class MyClass
{
public:
	MyClass()
	{
		std::cout << "Myclass object created \n";
	}
	~MyClass()
	{
		std::cout << "Myclass object destroyed \n";
	}

	void PrintHello()
	{
		std::cout << "Hello " << std::endl;
	}
	
};


int main(int argc, char const *argv[])
{
	{
		std::unique_ptr<MyClass> obj1( new MyClass("Object 1"));
		std::unique_ptr<MyClass> obj2  = std::make_unique<MyClass>();
		obj1->PrintHello();
	}

	return 0;
}