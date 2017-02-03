#include <iostream>
#include <math.h>

using namespace std ;

int sum(int a , int b )
{
	return a + b;
}

int diff(int a,int b)
{
	return a - b ;
}

int calc(int a ,int b ,int (*f)(int,int))
{
	return (*f)(a,b);
}

int main()
{ 
	int sum = calc(10,5,sum);
	return 0;
}