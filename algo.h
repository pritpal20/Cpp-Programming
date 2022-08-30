#include "GlobalDef.h"
#include <memory>

void reverse(std::string& in_str)
{
	int N = in_str.length() - 1;

	for(int i = 0,j = N ; i < j ;i++,j--)
	{
		swap(in_str[i],in_str[j]);
	}
}

bool IsPalindrome(std::string in_str)
{
	std::string temp = in_str;

	reverse(temp);

	if( !strcmp(temp.c_str(),in_str.c_str()) )
	{
		return true;
	}

	return false;
}

namespace fib
{
	long long look_up[90]{0};

	long long fibonacci(int n )
	{
		if(n <= 1)
			return n;

		if (look_up[n] != 0)
			return look_up[n];

		look_up[n] = ( fibonacci(n-1) + fibonacci(n-2) );

		return look_up[n];
	}
}