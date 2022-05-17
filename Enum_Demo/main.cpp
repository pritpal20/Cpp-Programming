#include <iostream>
#include "../GlobalDef.h"

// #define LOG(x) std::cout << x << std::endl


// I have include the below enum in global def 
// enum ReturnType : unsigned int
// {
// 	SUCCESS = 0,FAIL = 1
// };

int main()
{
	ReturnType ret = SUCCESS;

	LOG(ret);
	return ret;
}