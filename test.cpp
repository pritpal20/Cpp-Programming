#include "GlobalDef.h"
#include <memory>
#include "algo.h"


int main(int argc, char const *argv[])
{
	int B[] = {2,1,4,5,3,2,4,6,8,0};

	LOG(B);

	mergesort::merge_sort(B,10);

	LOG(B);
	PrintArray(B,10);

	return SUCCESS;
}