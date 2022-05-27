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
		std::shared_ptr<MyClass> p = std::make_shared< MyClass>();
		
	}

	
	return 0;
}