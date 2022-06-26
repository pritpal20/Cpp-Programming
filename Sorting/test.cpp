#include <iostream>
#include "../GlobalDef.h"
#include "mysorting_algo.h"

int main(int argc, char const *argv[])
{
	int N = 50;
	int* arr = mysort::generateUniqueNumbersArray(N);

	PrintArray(arr,N);

	// mysort::mergesort(arr,N);
	// mysort::insertion_sort(arr,N);
	// mysort::quicksort(arr,0,N-1);
	// mysort::bubblesort(arr,N);
	mysort::selection_sort(arr,N);

	PrintArray(arr,N);

	return SUCCESS;
}