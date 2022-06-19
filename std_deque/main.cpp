#include <iostream>
#include "../GlobalDef.h"
#include <deque>

using namespace std;

typedef deque<int> DequeInt;

typedef DequeInt :: iterator deque_iterator;

int main(int argc, char const *argv[])
{	

	int x[] = {3,2,5,6,7,10,0,1};
	DequeInt d;

	for(auto &item : x)
	{
		d.push_front(item);

	}

	auto it = d.begin();
	print(d);
	d.erase(it+4);
	d.pop_front();
	d.pop_back();
	print(d);

	return 0;
}