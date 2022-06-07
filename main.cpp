#include "GlobalDef.h"


ArrayInt merge(ArrayInt A,ArrayInt left,ArrayInt right,UINT N,UINT nL,UINT nR)
{

	int i,j;
	i = j = 0;
	int k = 0;
	while( i < nL && j < nR)
	{
		if (left[i] <= right[j] )
		{
			A[k++] = left[i++];
		}
		else
			A[k++] = right[j++];
	}

	while( i < nL)
	{
		A[k++] = left[i++];
	}

	while( j < nR)
	{
		A[k++] = right[j++];
	}

	return A;
}

void split(int* A,int* left, int* right, UINT N,UINT nL,UINT nR)
{
	UINT k = 0;
	fo(i,nL)
	{
		left[i] = A[k++]; 
	}

	fo(i,nR)
	{
		right[i] = A[k++]; 
	}
}


int* sort(ArrayInt A,UINT N)
{
	if (N == 1)
		return A;

	UINT mid = int (N / 2);

	UINT nL = mid;
	UINT nR = N - mid;

	int left[nL];
	int right[nR];

	split(A,left,right,N,nL,nR);

	sort(left,nL);
	sort(right,nR);

	merge(A,left,right,N,nL,nR);

}
int main(int argc, char const *argv[])
{
	int A[] = {2,1,4,6,3,5,8,9,0,1,100,-100,50,7,7,0};

	LOG(A);

	int N = sizeof(A) / sizeof(int);

	PrintArray(A,N);
	sort(A,N);
	PrintArray(A,N);
	LOG(A);

	return 0;
}