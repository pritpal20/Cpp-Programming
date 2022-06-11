#include "GlobalDef.h"
#include <memory>
#include "algo.h"


int main(int argc, char const *argv[])
{
	int B[] = {2,1,4,5,3,2,4,6,8,0};

	PrintArray(B);

	UINT N = sizeof(B) / sizeof(int);
	selection::sort(B,N);

	PrintArray(B);

	return SUCCESS;
}