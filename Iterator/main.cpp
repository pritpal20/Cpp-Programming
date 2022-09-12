#include <iostream>
#include <map>
#include <vector>

using namespace std;

template <typename T>
void _print(T x )
{
	cerr << x ;
}

#ifndef ONLINE_JUDGE
#define debug(x) cerr << #x <<" = "; _print(x); cerr << endl;
#else
#define debug(x)
#endif

int main(int argc, char const *argv[])
{
	#ifndef ONLINE_JUDGE
	freopen("Error.txt", "w", stderr);
	#endif

	using str_map = map<string,int>;
	str_map my_map;

	my_map.insert({"Pritpal",1});
	my_map.insert({"Chhabra",2});

	for(auto& kv : my_map)
	{
		auto key = kv.first;
		auto value = kv.second;

		cout << "Key = " << key << " value = " << value << endl;
	}

	//using C++ 17 
	for(auto [key,value] : my_map)
		cout << "Key = " << key << " value = " << value << endl;

	vector<int> v{1,2,3,4,5};

	for(auto i : v)
	{
		debug(i);
	}

	cout << endl;

	debug("Pritpal");

	return 0;
}
