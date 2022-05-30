#include "mysorting_algo.h"
using namespace mergesort;

int main(int argc, char const *argv[])
{
	int arr[] = {4,3,2,1,5,6,7,8,0};

	mergesort::mergesort(arr,9);

	print_array(arr);
	return 0;
}
