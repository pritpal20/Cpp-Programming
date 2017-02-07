#include "sorting-algo.h"

using namespace algo;

int main()
{
	int A[] = {10,7,2,1,8,6,3,5,4,1,4,6,9,8};
	cout << "Hello World \n" ;
	
	int end = sizeof(A)/sizeof(A[1]);
	for(int i = 0 ; i < end ; i++ )
		cout << A[i] << " " ;
	cout << endl;
	
	quicksort(A,0,end-1);
	
	for(int i = 0 ; i < end ; i++ )
		cout << A[i] << " " ;
	cout << endl;
}