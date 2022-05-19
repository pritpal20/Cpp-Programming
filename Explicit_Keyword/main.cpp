#include <iostream>
#include "../GlobalDef.h"


class Myclass
{	
private:
	mutable int m_random_num;

public:

	explicit Myclass(int var ) : m_random_num(var)
	{

	}

	int get() const
	{
		return ++m_random_num;
	}
};

void PrintValue(const Myclass& obj)
{
	std::cout << obj.get() << std::endl;
}

int main(int argc, char const *argv[])
{
	Myclass C1(8);

	PrintValue(C1);

	return SUCCESS;
}