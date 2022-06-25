#include <iostream>
#include "../GlobalDef.h"
#include "mysorting_algo.h"

int main(int argc, char const *argv[])
{
	int arr[]{4,1,5,9,7,0,1,3,2};

	int N = sizeof(arr) / sizeof(int);

	mergesort::print_array(arr,0,N-1);

	quicksort::quicksort(arr,0,8);

	// PrintArray(arr,N);

	return SUCCESS;
}