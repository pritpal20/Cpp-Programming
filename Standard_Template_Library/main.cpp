#include <iostream>
#include <vector>
#include "../GlobalDef.h"
using namespace std;
#define LOG(x) cout << #x << " " << x << endl;

int main(int argc, char const *argv[])
{
	vector<int> v;

	for(int i = 0;i<10 ; i++)
	{
		v.push_back(i);
	}
	print(v);
	return 0;
}