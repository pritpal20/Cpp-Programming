#include <iostream>
using namespace std;

#define LOG(x) cout << #x << " : " << x << endl; 

class MyClass
{
public : 
	int& m_ref;

	//valid for reference : 
	MyClass(int& _ref) : m_ref(_ref)
	{	
	}


	//Invalid for reference : 
	// Myclass(int _ref)
	// {	
	// 	ref = _ref;
	// }

	friend ostream& operator<<(ostream& stream, const MyClass &other)
	{
		stream << "ref = " << other.m_ref << endl; 
		return stream;
	}
};


int main(int argc, char const *argv[])
{
	
	//Not valid 
	//int& i = 100;

	int i = 10;

	MyClass obj(i);

	cout << obj << endl;
	return 0;
}
