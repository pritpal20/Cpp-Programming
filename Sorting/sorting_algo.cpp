#include "mysorting_algo.h"

using namespace mysort;
int main(int argc, char const *argv[])
{
	int a[] = {-100,10,2,3,-20,5,4,1,-1,0,-2,4};

	mysort::print_array(a);
	mysort::selection_sort(a); 
	mysort::print_array(a); 

	return 0;
}