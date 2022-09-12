#include <iostream>
#include <cstring>

using namespace std ;

char* func()
{
   char str[8];
   strcpy(str,"Hello!");
   return(str); 
}

int main()
{
	char *str = func();
	cout << str << endl;	
	return 0;
}