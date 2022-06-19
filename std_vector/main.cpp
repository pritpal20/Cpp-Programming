#include <iostream>
#include <vector>
#include "../GlobalDef.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
#define LOG(x) cout << #x << " " << x << endl;

int main(int argc, char const *argv[])
{
	vector<int> v;

	vector<string> v2 = {"Pritpal","Chhabra"};

	for(auto i = 0; i < 10 ; i++)
	{
		v.push_back(i);
	}

	fo(i,10)
	{
		char temp[10] ;
		itoa(i,(char*)temp,16);

		//inserting at the beginning
		v2.insert(v2.begin(),temp);
	}
	auto it= v2.begin();

	//deleting "Pritpal" from vector 
	v2.erase(it+10);
	print(v);
	print(v2);
	return 0;
}