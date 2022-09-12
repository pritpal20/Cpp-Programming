#include "def.h"

#include <vector>

int main() 
{

#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	freopen("Output.txt", "w", stdout);
#endif

	vector<int> v{2,5,2,6,7,1,9,0};

	int x = 10;
	debug(v);
	debug(x);

	cout << "x = " << x << endl;

	return 0;
}