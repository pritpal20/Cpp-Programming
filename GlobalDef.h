#ifndef __GLOBALDEF__
#define __GLOBALDEF__

#define LOG(x) std::cout << (#x) << " = " <<  x << std::endl

#define fo(i,n) for(int i = 0 ; i < n ; i++)

#define cout std::cout
#define endl std::endl

enum ReturnType : unsigned int
{
	SUCCESS = 0,FAIL = 1
};


#endif