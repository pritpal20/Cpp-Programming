#include <iostream>
#include "../GlobalDef.h"
#include <memory>

void* operator new(size_t n)
{
	cout << "Bytes allocated : " << n << endl;
	void *ptr = malloc(n);

	LOG(ptr);

	cout << "========================" << endl;

	return ptr; 
}

void operator delete(void* ptr,size_t n)
{
	cout << "Bytes deallocated : " << n << endl;
	LOG(ptr);

	free(ptr);

}

struct Demo
{
	int x;int y;int z;

	Demo(int _x,int _y,int _z) :x(_x),y(_y),z(_z)
	{
		cout << "Object constructed \n";
	}

	Demo(const Demo& obj) : x(obj.x),y(obj.y),z(obj.z) 
	{
		cout << "Copy constructed \n";

	}
};



int main(int argc, char const *argv[])
{
	std::unique_ptr<Demo> D1 = std::make_unique<Demo>(1,2,3) ;
	Demo* d2 = new Demo(*D1);

	delete d2;
	return 0;
}