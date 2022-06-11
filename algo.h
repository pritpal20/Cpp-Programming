#include "GlobalDef.h"
#include <memory>

namespace mergesort
{

	void merge(ArrayInt A,ArrayInt left,ArrayInt right,UINT n,UINT nL,UINT nR)
	{

		UINT i = 0,j =0;
		UINT k = 0;

		while( i < nL && j < nR )
		{
			if( left[i] <= right[j])
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

	}

	UINT middle(UINT N)
	{
		return int (N / 2);
	}

	void split(ArrayInt A,ArrayInt left,ArrayInt right,UINT nL,UINT nR)
	{
		int k = 0;

		fo(i,nL)
		{
			left[i] = A[k++];
		}

		fo(i,nR)
		{
			right[i] = A[k++];
		}

	}

	ArrayInt merge_sort(int* A,UINT N)
	{
		if( N == 1 )
			return A;

		UINT mid = middle(N);

		UINT nL = mid;
		UINT nR = N - mid;

		int left[nL];
		int right[nR];
		split(A,left,right,nL,nR);

		merge_sort(left,nL);
		merge_sort(right,nR);

		merge(A,left,right,N,nL,nR);

		return A;
	}

}


namespace insertion
{

	void sort(ArrayInt A,UINT N)
	{
		for(int i = 0;i < N ; i++)
		{
			for(int j = i +1; j > 0 ; j--)
			{
				if( A[j] < A[j-1])
				{
					swap(A[j],A[j-1]);
				}
				else
					break;
			}
		}
	}

}

namespace selection
{
	void sort(ArrayInt A,UINT N)
	{
		fo(i,N-1)
		{	
			int min_index = i;
			for(int j = i+1;j < N ; j++)
			{
				if (A[j] < A[min_index])
				{
					min_index = j;
				}
			}
			if (i != min_index)
			{
				swap(A[i],A[min_index]);
			}
		}
	}

}