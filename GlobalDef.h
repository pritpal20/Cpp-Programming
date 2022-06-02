#ifndef __GLOBALDEF__
#define __GLOBALDEF__


#define fo(i,n) for(int i = 0 ; i < n ; i++)
#define fo1(i,n) for(int j = i ; j < n ; j++)

#define Fo(i,n) for(int i = 0;i < n ; i++)
#define range(i,s,n) for(int i = s;i < n ; i++)

#define cout std::cout
#define endl std::endl

#define LOG(x) cout << (#x) << " = " <<  x << endl
enum ReturnType : int
{
	ERROR= -1,SUCCESS = 0,FAIL = 1
};


#endif