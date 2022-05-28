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
			int min = arr[i];
			int idx = i;
			for(int j = i+1; j < N ;j++)
			{
				if(min > arr[j])
				{
					min = arr[j];
					idx = j;
				}

			}
			swap(arr[i],arr[idx]);
		}
	}

	template<size_t N> void print_array(int (&a)[N])
	{
		std::cout << "[" ;
		fo(i,N)
		{
			std::cout << a[i] ;
			if (i != N -1)
				std::cout << ", ";
		}
		std::cout << "]" << std::endl;
	}

}

int main(int argc, char const *argv[])
{
	int a[] = {2,3,5,4,1,-1,0,-2,4};

	mysort::print_array(a); 
	mysort::bubblesort(a); 
	mysort::print_array(a); 

	return 0;
}