#include "sorting-algo.h"

using namespace algo;

void Print(int A[])
{
	int arr_size = sizeof(A)/sizeof(*A);
	cout << "size of array = " << arr_size << endl;
}

int main(int argc,char* argv[] )
{
	int count = 10;
	if( argc > 1 ) 
	{ 
		count = atoi(argv[1]);
	}
	
	srand(time(NULL));
	
	//int A[10] = {1,2,3,4,5,6,7,8,9,0};
	
	int *A = generateArray(count);
	
	printArray(A,count);
	mergesort(A,count);
	printArray(A,count);
	
}