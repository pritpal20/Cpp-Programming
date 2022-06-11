#include "../GlobalDef.h"
#include <iostream>
// #include <array>


int main(int argc, char const *argv[])
{

	std::array<char,5> arr = {'a','b','c','d','e'};

	std::array<int,5> arr1 = {1,2,3,4,5};
	PrintArray(arr1);

	LOG(arr.size());

	LOG(*(arr.end() - 1));
	return 0;
}