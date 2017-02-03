#include <iostream>
#include <cstring>
#include <memory>

using namespace std;

void func()
{
	char *str = new char[20];
	
	auto_ptr<char> str1(str);
	strcpy(str,"Hello World !!");
	
}

int main()
{
	for(int i = 0 ; i < 10 ; i++ )
	{
		cout << "Allocating dynamic memory ... " << endl;
		func();
	}
	return 0;
}