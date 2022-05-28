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
			for(int j = i+1; j < N ;j++)
			{
				if(arr[min] > arr[j])
				{
					min = j;
				}

			}
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

int main(int argc, char const *argv[])
{
	// int a[] = {-100,10,2,3,-20,5,4,1,-1,0,-2,4};
	int a[] = {1,0,2,3,4,5};

	mysort::print_array(a); 
	mysort::insertion_sort(a); 
	mysort::print_array(a); 

	return 0;
}