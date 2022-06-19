#include <iostream>
#include "../GlobalDef.h"
#include <stack>

using namespace std;

typedef stack<int> stackInt;


int main(int argc, char const *argv[])
{	

	int x[]{3,2,5,6,7,10,0,1};
	stackInt s;

	for(auto &item : x)
	{
		s.push(item);

	}

	cout <<"[" ;
	while(!s.empty())
	{
		int i = s.top();
		cout << i << "," ;
		s.pop();
	}
	cout <<"]" << endl;

	return 0;
}