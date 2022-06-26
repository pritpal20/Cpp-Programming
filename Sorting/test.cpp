#include <iostream>
#include "../GlobalDef.h"
#include "mysorting_algo.h"

int main(int argc, char const *argv[])
{
	int N = 50;
	int* arr = mysort::generateUniqueArray(N);

	PrintArray(arr,N);

	mysort::mergesort(arr,N);

	PrintArray(arr,N);

	return SUCCESS;
}