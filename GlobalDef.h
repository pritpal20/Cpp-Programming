#ifndef __GLOBALDEF__
#define __GLOBALDEF__

#define LOG(x) std::cout << (#x) << " = " <<  x << std::endl

enum ReturnType : unsigned int
{
	SUCCESS = 0,FAIL = 1
};


#endif