#include <iostream>
#include "../GlobalDef.h"

class BaseClass 
{
protected:
	int var1,var2;

public :
	BaseClass()
	{
		std::cout << "Base class constructed " << std::endl ;
		var1 = 10;
		var2 = 20;
	}

	virtual ~BaseClass()
	{
		std::cout << "Base class destroyed " << std::endl ;
	}

	virtual void printVar()
	{
		std::cout << "var1 = " << var1 << " var2 = " << var2 <<  std::endl;
	}
};

class DerivedClass : public BaseClass
{
	
protected:
	int var3;
public :

	DerivedClass()
	{
		std::cout << "DerivedClass class constructed " << std::endl ;
		this->var1 = 10;
		this->var2 = 20;
		this->var3 = 30;
	}

	void printVar() override
	{
		std::cout << "var1 = " << var1 << " var2 = " << var2 << " var3 = "<< var3 << std::endl;
	}

	~DerivedClass()
	{
		std::cout << "DerivedClass class destroyed " << std::endl ;
	}
};


int main()
{
	
	BaseClass *D1 = new DerivedClass();
	// B1.printVar();
	// DerivedClass D1;

	D1->printVar();

	delete D1;

	return SUCCESS;
}