#include <iostream>

class MyClass
{

	public :
		static int a ;
		static int b ;
		int c ;
		MyClass(int var ) : c(var)
		{

		}

		MyClass() : c(0) 
		{

		}

		friend std::ostream& operator <<(std::ostream& stream,const MyClass& obj)
		{
			stream << "a = " << obj.a << ", b = " << obj.b << ", c = " << obj.c << std::endl;
		}
};

int MyClass::a;
int MyClass::b;

int main()
{
	
	MyClass A1;
	MyClass::a = 5;
	MyClass::b = 6;

	std::cout << A1 ;

	MyClass B1(10);
	std::cout << B1 ;


	return 0;
}