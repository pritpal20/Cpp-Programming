#include <iostream>
#include <list>
#include "../GlobalDef.h"
#include <stdio.h>
#include <stdlib.h>
#include <string>

using namespace std;
#define LOG(x) cout << #x << " " << x << endl;

int main(int argc, char const *argv[])
{
	list<int> v;

	list<string> lst2 = {"Pritpal","Chhabra"};

	for(auto i = 0; i < 10 ; i++)
	{
		v.push_back(i);
	}

	fo(i,10)
	{
		char temp[10] ;
		itoa(i,(char*)temp,16);

		//inserting at the beginning
		lst2.push_front(temp);
	}
	print(v);
	// auto it = lst2.begin();
	// // typedef list<string> :: iterator listiterator;
	listiterator it = lst2.begin();

	//advancing iterator by 10 position
	advance(it, 10);
	lst2.erase(it);
	print(lst2);
	return 0;
}