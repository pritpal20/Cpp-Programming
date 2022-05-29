#ifndef __MERGESORT__
#define __MERGESORT__
#include <iostream>
#include "..\GlobalDef.h"

namespace mergesort
{
	template<size_t N> void print_array(int (&a)[N])
	{
		cout << "[" ;
		fo(i,N)
		{
			cout << a[i] ;
			if (i != N -1)
				cout << ", ";
		}
		cout << "]" << endl;
	}

	void print_array(int *a,int N)
	{
		cout << "[" ;
		fo(i,N)
		{
			cout << a[i] ;
			if (i != N -1)
				cout << ", ";
		}
		cout << "]" << endl;
	}

	int middle(int N )
	{

		return int( N / 2);
	}

	void split(int* A,int* left,int* right,int N,int &nL,int &nR)
	{
		int mid = middle(N);
		nL = mid;
		nR = N - mid ;
		left = new int[nL];
		right = new int[nR];
		int k = 0;
		// cout << "nL = " << nL << endl;
		fo(i,nL)
		{
			*left= A[k];
			// cout << "*L " << *left << endl;
			k++;
			left++;
		}
		fo(i,nR)
		{
			*right = A[k];
			k++;
			right++;
		}
	}

	void merge(int* A,int* left_arr,int* right_arr,int N ,int nL,int nR)
	{

		int i = 0,j = 0,k =0;

		while(i < nL && j < nR)
		{
			if( left_arr[i] < right_arr[j])
			{
				A[k++] = left_arr[i++];
			}
			else
				A[k++] = right_arr[j++];
		}

		while(i < nL )
		{
			
			A[k++] = left_arr[i++];
		}

		while(j < nR )
		{
			
			A[k++] = right_arr[j++];
		}

	}

	int* mergesort(int* arr,int N)
	{

		if( N == 1)
			return arr;
		int mid = middle(N);

		int nL = mid;
		int nR = N - mid ;
		int L[nL];
		int R[nR];
		int k = 0;
		fo(i,nL)
		{
			L[i] = arr[k];
			k++;
		}
		fo(i,nR)
		{
			R[i] = arr[k];
			k++;
		}

		mergesort(L,nL);
		mergesort(R,nR);
		merge(arr,L,R,N,nL,nR);
	}

}
#endif

using namespace mergesort;

int main(int argc, char const *argv[])
{
	int arr[] = {4,3,2,1,5,6,7,8,0};

	mergesort::mergesort(arr,9);

	print_array(arr);
	return 0;
}
