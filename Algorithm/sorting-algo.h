#ifndef SORTING-ALGO_H
#define SORTING-ALGO_H
#include <iostream>

using namespace std;

namespace algo
{
	
	int partition(int *A,int start , int end)
	{
		int Pivot = A[end];
		int pIndex = start;
		
		for(int i = start ; i <= end - 1 ; i++)
		{
			if(A[i] < Pivot)
			{
				//swap A[i] and A[pIndex]
				int temp = A[i];
				A[i] = A[pIndex];
				A[pIndex] = temp;
				pIndex++;
			}
		}
		
		int temp = A[pIndex];
		A[pIndex] = A[end];
		A[end] = temp;
		
		return pIndex;
	}
	
	void quicksort(int *A,int start , int end)
	{
		if(start < end )
		{
			int pIndex = partition(A,start,end);
			quicksort(A,start,pIndex - 1);
			quicksort(A,pIndex + 1,end);
		}
		
	}
	
	
};
#endif