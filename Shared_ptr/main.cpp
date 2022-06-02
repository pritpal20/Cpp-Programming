#include <iostream>
#include <memory>
#include "shared_pointer.h"
#include "../GlobalDef.h"

class MyClass
{
private:
	int var;
public:
	MyClass(int _var = 10) : var(_var)
	{
		cout<< "Myclass object created \n";
	}
	~MyClass()
	{
		cout << "Myclass object destroyed \n";
	}

	int& operator*()
	{
		return var;
	}

	int get() const
	{
		return this->var;
	}	

	friend std::ostream& operator<<(std::ostream& stream,const MyClass& obj)
	{
		stream << obj.var << endl;
		return stream;
	}
};


int main(int argc, char const *argv[])
{
	
	{
		my_shared_ptr::Shared_ptr<MyClass> p(new MyClass(20));
		//counter is 0 after first instance of shared ptr 
		MyClass C2 = *p;
		cout << *p ;
		cout << C2 ;

		my_shared_ptr::Shared_ptr<MyClass> ptr(p);
		//counter is 1 after first instance of shared ptr 

		my_shared_ptr::Shared_ptr<MyClass> ptr2 = p;
		//counter is 2 after first instance of shared ptr 

		cout <<"shared counter val " << p.use_count() << endl;

		cout << p->get() << endl;
		MyClass C1 = p->get(); 
	}

	return 0;
}