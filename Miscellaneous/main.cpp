#include <iostream>

void PrintName(std::string&& name)
{
	std::cout << name << std::endl;
}

void PrintName(std::string& name)
{
	std::cout << name << std::endl;
}

PrintVal(int& a)
{
	std::cout << a << std::endl;
}

PrintVal(int&& a)
{
	std::cout << a << std::endl;
}



int main(int argc, char const *argv[])
{
	
	std::string firstname = "Pritpal";
	std::string lastname = "Chhabra";

	PrintName(firstname);
	PrintName(firstname + lastname);

	int i = 10;
	PrintVal(10);
	return 0;
}