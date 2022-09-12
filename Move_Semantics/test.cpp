#include <iostream>
#include "test.h"

int main(int argc, char const *argv[])
{
	
	String src = "Pritpal";
	std::cout << "Src : ";
	src.print();

	String dest ;
	dest = std::move(src);

	std::cout << "Des : ";
	dest.print();

	std::cout << "Src : ";
	src.print();
	return SUCCESS;
}