#ifndef __MYSORTING_ALGO
#define __MYSORTING_ALGO
#include <iostream>
#include<time.h>
#include <map>
#include "../GlobalDef.h"

namespace mysort
{
	int* generateUniqueNumbersArray(int count)
	{
		srand(time(NULL));
		std::map<int,bool> cache ;
		int* A = new int[count];
		for(int i = 0 ; i < count ; i++ )
		{
			while(true)
			{
				int random_no = rand() % count + 1 ;
				if (cache.find(random_no) == cache.end() )
				{
					A[i] = random_no;
					cache.insert({random_no,true});
					break;
				}
				else
					continue;
			}
		}
		return A;
	}
	
	template <class T>
	void swap(T &a,T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

	void bubblesort(int* arr,int N)
	{
		/*
		compares the first two element if the first element is greater than second 
		than swap the numbers 

		if no swaps are found in the iteration the while loop is exited
		*/

		while(true)
		{
			bool btemp = false;
			for(int i = 0 ;i < N -1 ; i++)
			{
				if (arr[i] > arr[i+1])
				{
					swap(arr[i],arr[i+1]);

					/*one more iteration else the while loop 
					will exit if no swap in a iteration*/
					btemp = true;
				}
			}
			if (btemp == false)
				break;
		}	
	}

	void selection_sort(int* arr,int N)
	{
		fo(i,N)
		{
			int min = i;
			fo1(j = i+1,N)
			{
				if(arr[min] > arr[j])
				{
					min = j;
				}

			}
			swap(arr[i],arr[min]);
		}
	}

	void insertion_sort(int* arr,int N)
	{
		/*
			https://www.geeksforgeeks.org/insertion-sort/
		*/
		for(int i = 1; i < N ; i++)
		{
			
			for(int j = i  ; j >0 ; j--)
			{
				if (arr[j] < arr[j-1])
				{
					swap(arr[j],arr[j-1]);
				}
				else
				{
					break;	
				}
			}
		}
	}

	//Quick sort 
	int partition(int* arr,int left ,int right)
	{
		int pivot = right;

		int i = 0;
		for (i = left; i < right; i++)
		{
			while(i < pivot && arr[pivot] < arr[i])
			{
				mysort::swap(arr[i],arr[pivot]);
				pivot--;
				mysort::swap(arr[i],arr[pivot]);	
			}
			if (pivot <= i)
            break;
		}
		return pivot;
	}

	void quicksort(int* arr,int left,int right)
	{
		if (right <= left)
        	return;
		int p = partition(arr,left,right);

		quicksort(arr,left,p-1);
		quicksort(arr,p,right);
	}

	int middle(int N )
	{

		return int( N / 2);
	}

	void split(ArrayInt A,ArrayInt left,ArrayInt right,int N,int &nL,int &nR)
	{
		int mid = middle(N);
		nL = mid;
		nR = N - mid ;
		left = new int[nL];
		right = new int[nR];
		int k = 0;

		fo(i,nL)
		{
			*left= A[k];
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

	void merge(ArrayInt A,ArrayInt left_arr,ArrayInt right_arr,int N ,int nL,int nR)
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

	ArrayInt mergesort(ArrayInt arr,int N)
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