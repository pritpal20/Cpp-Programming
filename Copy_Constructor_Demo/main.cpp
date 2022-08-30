#include <iostream>
extern int global_var;

#include "MyString.h"

using namespace std;


int main(int argc, char const *argv[])
{
	MyString *str1= new MyString("Pritpal");
	
	MyString str2(*str1);

	

	delete str1;
	
	return 0;
}