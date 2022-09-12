#include <iostream>
#include <map>
#include "../GlobalDef.h"


int main(int argc, char const *argv[])
{
	int N = 10;
	int* arr = generateArray(N);

	print_array(arr,N);

	std::map<int,int> count_mp;

	range(i,0,N)
	{

		if( count_mp.find(arr[i]) == count_mp.end())
		{
			count_mp.insert({arr[i],1});
		}
		else
		{
			count_mp[arr[i]]++;
		}
		
	}

	int k = 0;
	for(auto i : count_mp)
	{
		// cout << "key : " << i.first << " value " << i.second << endl;
		for(int j = 0; j < i.second ; j++)
		{
			arr[k++] = i.first;
		}
	}

	print_array(arr,N);
	return 0;
}