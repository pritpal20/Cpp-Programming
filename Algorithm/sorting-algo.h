#ifndef SORTING-ALGO_H
#define SORTING-ALGO_H
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>

using namespace std;

namespace algo
{
	int* generateArray(int count)
	{
		//srand(time(NULL));
		int* A = new int[count];
		for(int i = 0 ; i < count ; i++ )
		{
			int random_no = rand() % count + 1 ;
			A[i] = random_no;
		}
		return A;
	}
	
	void printArray(int *A,int n)
	{
		for(int i = 0 ; i < n ; i++)
		{
			cout << *A << " " ;
			A++;
		}
		cout << endl;
	}
	
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
	
	void split(int *A,int *_Aleft,int* _Aright,int n)
	{
		int mid = n/2 ;
		int left = mid;
		int right = n -mid;
		int k = 0;
		int *Aleft = new int[left];
		int *Aright = new int[right];
		for(int i = 0 ; i < left ; i++ )
		{
			Aleft[i] = A[k++];
		}
		for(int i = 0 ; i < right ; i++ )
		{
			Aright[i] = A[k++];
		}
		
		//printArray(Aleft,left);
		//printArray(Aright,right);
	}
	
	void merge(int *A,int *Aleft,int *Aright,int n,int nL,int nR)
	{
		int k = 0;
		int i ,j ;
		i = j = 0;
		
		while( i < nL && j < nR)
		{
			if( Aleft[i] <= Aright[j])
			{
				A[k++] = Aleft[i++];
			}
			else
			{
				A[k++] = Aright[j++];
			}
		}
		
		while(i < nL )
		{
			A[k++] = Aleft[i++];
		}
		while(j < nR )
		{
			A[k++] = Aright[j++];
		}
		
	}
	
	void mergesort(int *A,int n)
	{
		static int t = 0;
		if( n < 2 ) return ;
		int mid = n/2;
		int nL = mid;
		int nR = n - mid;
		int L[nL];
		int R[nR];
		int k = 0;
		
		for(int i = 0 ; i < nL ; i++ )
		{
			L[i] = A[k];
			cout<< setw(t) << "A[" << k << "] = " << A[k] << " L [" << i << "] = " << L[i] << endl;;
			k++;
		}
		cout << "---------- " << endl;
		for(int i = 0 ; i < nR ; i++ )
		{
			R[i] = A[k];
			cout << setw(t) << "A[" << k << "] = " << A[k] << " R [" << i << "] = " << R[i] << endl; 
			k++;
		}
		cout << "---------- " << endl;
		mergesort(L,nL);
		mergesort(R,nR);
		merge(A,L,R,n,nL,nR);
		t++;
	}
	
};
#endif