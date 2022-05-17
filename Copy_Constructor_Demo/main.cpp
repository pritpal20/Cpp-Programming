#include <iostream>
extern int global_var;

#include "MyString.h"

using namespace std;


int main(int argc, char const *argv[])
{
	MyString *str1= new MyString("Pritpal");
	


	MyString *str2 = str1;
	// str2[0] = 'L';

	// global_var++;
	// cout << "*********** global_var "<< global_var <<  endl;
	cout << "str1 -> " << *str1 << endl;
	cout << "str2 -> " << *str2 << endl;

	delete str1;
	// delete str2;

	cout << "After delete \n";
	return 0;
}