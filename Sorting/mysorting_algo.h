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

	void print_array(int *a,int start,int end)
	{
		cout << "{" ;
		range(i,start,end+1)
		{
			cout << a[i] << " ";
		}
		cout << "}" << endl;
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
//4,1,5,9,7,0,1,3,2 pivot = 8,i = 0
//1,1,5,9,7,0,2,3,4 pivot = 6,i = 1
//1,1,5,9,7,0,2,3,4 pivot = 6,i = 2
//1,1,0,9,7,2,5,3,4 pivot = 5,i = 3
//1,1,0,7,2,9,5,3,4 pivot = 4,i = 3
namespace quicksort
{
	int partition(int* arr,int left ,int right)
	{
		int pivot = right;

		int i = 0;
		for (i = left; i < right; i++)
		{
			cout << "=== start ===" << endl;
			mergesort::print_array(arr,left,right);
			LOG(i);
			LOG(pivot);
			while(i < pivot && arr[i] > arr[pivot])
			{
				mysort::swap(arr[i],arr[pivot]);
				pivot--;
				mysort::swap(arr[i],arr[pivot]);	
			}
        	mergesort::print_array(arr,left,right);
        	cout << "=== end ===" << endl;
			if (pivot <= i)
            break;
		}
		LOG(i);
		LOG(pivot);
		cout << "======= " << endl;
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
}
#endif