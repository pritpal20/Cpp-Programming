#ifndef __MYSORTING_ALGO
#define __MYSORTING_ALGO
#include <iostream>
#include "../GlobalDef.h"

namespace mysort
{
	template <class T>
	void swap(T &a,T &b)
	{
		T temp = a;
		a = b;
		b = temp;
	}

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


	template<size_t N> void bubblesort(int (&arr)[N])
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

	template<size_t N> void selection_sort(int (&arr)[N])
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
			// cout << "min " << min << endl;
			swap(arr[i],arr[min]);
		}
	}

	template<size_t N> void insertion_sort(int (&arr)[N])
	{
		/*
			https://www.geeksforgeeks.org/insertion-sort/
		*/
		for(int i = 1; i < N ; i++)
		{
			cout << "********iteration " << i << " *************" << endl; 
			print_array(arr);
			cout << "arr[i] =  " <<arr[i] << endl ;
			for(int j = i  ; j >0 ; j--)
			{
				cout << "i = " << i << " j = " << j << endl;
				if (arr[j] < arr[j-1])
				{
					cout << "swap arr[j] =" << arr[j] << " with arr[j-1] =" << arr[j-1] << endl;
					swap(arr[j],arr[j-1]);
				}
				else
				{
					cout << "loop exited " << endl;
					break;	
				}
			}
			print_array(arr);
		}
	}
}

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

	void split(ArrayInt A,ArrayInt left,ArrayInt right,int N,int &nL,int &nR)
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