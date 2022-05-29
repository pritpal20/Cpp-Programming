#include <iostream>
#include "../GlobalDef.h"

void print_array(int*,int);
void FillArray( int** ptr,int N)
{
	*ptr = new int[N];

	int* temp = *ptr;
	fo(i,N)
	{
		*temp = 10;
		temp++;
	}

	LOG(*ptr);
	print_array(*ptr,N);
	LOG(*ptr);

}

void print_array(int* ptr,int N)
{
	cout << "[" ;
	fo(i,N)
	{
		cout << *ptr ;
		if (i != N -1)
			cout << ", ";

		ptr++;
	}
	cout << "]" << endl;
}

int main(int argc, char const *argv[])
{
	

	int *ptr = NULL;

	FillArray(&ptr,10);
	LOG(ptr);

	print_array(ptr,10);
	return 0;
}