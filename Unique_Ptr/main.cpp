#include <iostream>
#include <memory>
#include <cstring>

class MyClass
{
private:
	char* _name;
	unsigned int size;
public:
	MyClass(char* name) : size(strlen(name))
	{
		_name = new char[size + 1];
		strcpy(_name,name);
		std::cout << _name << " created \n";
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
		std::unique_ptr<MyClass> obj1( new MyClass("obj1 "));
		// std::unique_ptr<MyClass> obj2  = std::make_unique<MyClass>("obj2");
		obj1->PrintHello();
	}

	return 0;
}