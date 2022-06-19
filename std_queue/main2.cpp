#include <iostream>
#include "../GlobalDef.h"
#include <queue>

using namespace std;

typedef priority_queue<int> QueueInt;

/*
Example of priority queue
*/

int main(int argc, char const *argv[])
{	

	int x[]{3,2,5,6,7,10,0,1};
	QueueInt q;

	for(auto &item : x)
	{
		cout << "Pushing ... <" << item << "> into the queue" << endl;
		q.push(item);

	}

	cout <<"[ " ;
	while(!q.empty())
	{
		int i = q.top();
		cout << i << " " ;
		q.pop();
	}
	cout <<"]" << endl;

	return 0;
}