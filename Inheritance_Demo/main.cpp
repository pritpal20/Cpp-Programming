#include <iostream>
#include <fstream>
#include <sstream>
// #include "../GlobalDef.h"

class BaseClass 
{
protected:
	int var1,var2;

public :
	BaseClass():var1(10),var2(20)
	{
		std::cout << "Base class constructed [default] " << std::endl ;
	}

	BaseClass(int _var1,int _var2) : var1(_var1),var2(_var2)
	{
		std::cout << "Base class constructed [param] " << std::endl ;
	}


	virtual ~BaseClass()
	{
		std::cout << "Base class object destroyed " << std::endl ;
	}

	virtual void printVar()
	{
		std::cout << "var1 = " << var1 << ", var2 = " << var2 <<   std::endl;
	}
};

class DerivedClass : public BaseClass
{
	
protected:
	int var3;
public :

	DerivedClass() : BaseClass(),var3(30)
	{
		std::cout << "DerivedClass class constructed [default]" << std::endl ;
		// this->var3 = 30;
	}

	DerivedClass(int _var1,int _var2,int _var3) : BaseClass(_var1,_var2),var3(_var3)
	{
		std::cout << "DerivedClass class constructed [param]" << std::endl ;
		// this->var3 = 30;
	}

	void printVar() override
	{
		std::cout << "[" << var1 << "," << var2 << ","<< var3 ;
		std::cout << "]" <<  std::endl;
	}

	DerivedClass& operator<<(std::sstream s ,const DerivedClass &obj)
	{
		s << obj.var1 << " " << obj.var2 << " " << obj.var3 << endl;
		return obj;
	}

	~DerivedClass()
	{
		std::cout << "DerivedClass class object destroyed " << std::endl ;
	}
};

int main(int argc, char const *argv[])
{
	
	DerivedClass *D1 = new DerivedClass(1,2,3);
	// B1.printVar();
	// DerivedClass D1;

	D1->printVar();

	BaseClass* D2 = dynamic_cast<BaseClass*>(D1);

	D2->printVar();

	delete D1;

	return 0;
}