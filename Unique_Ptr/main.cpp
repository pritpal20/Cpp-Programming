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
	
};


int main(int argc, char const *argv[])
{
	{
		std::unique_ptr<MyClass> obj( new MyClass());

		// std::unique_ptr<MyClass> obj2(obj);
	}
	
	return 0;
}