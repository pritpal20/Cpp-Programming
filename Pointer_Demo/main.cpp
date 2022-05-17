
#include <iostream>
#include <cstring>

#define LOG(x) std::cout << x << std::endl

void IncrementByOne(int a )
{
	a++;
}

int main()
{
	int a = 10;

	void* ptr = &a;

	std::cout << &a << std::endl;
	std::cout << ptr << std::endl;
	std::cout << *(int*)ptr << std::endl;
	std::cout << &ptr << std::endl;


	/*Double pointer */

	char*  Buffer = new char[50];

	memset(Buffer,'\0',50); 
	memcpy(Buffer,"Pritpal Chhabra",sizeof("Pritpal Chhabra")); 

	// stores address of a pointer
	char** buf_ptr = &Buffer;

	std::cout << &Buffer << std::endl;
	std::cout << *Buffer << std::endl;
	std::cout << buf_ptr << std::endl;


	//Reference Demo 

	int b = 10;

	IncrementByOne(b);

	LOG(b);


	return 0;
}