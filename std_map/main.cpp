#include <iostream>
#include <map>


using namespace  std;

typedef map<int,string> my_map; 
typedef multimap<int,string> my_multimap; 

int main(int argc, char const *argv[])
{
	my_multimap m1;
	pair<int,string> p;

	int arr[]{1,2,3,6,4,5,1};

	string str_arr[]{"one","two","three","six","four","five","One"};

	int N = sizeof(arr) / sizeof(int);

	for(auto i = 0;i < N ;i++)
	{
		p.first = arr[i];
		p.second = str_arr[i];
		// m1.insert(p);
		m1.insert({arr[i],str_arr[i]});

	}

	//display the contenp of map/multimap :
	for(auto it = m1.begin();it !=m1.end();++it)
	{
		cout << it->first << " : " << it->second << endl;
	}

	// removing key 1 from the map
	m1.erase(1);

	cout << endl ;

	for(auto it = m1.begin();it !=m1.end();++it)
	{
		cout << it->first << " : " << it->second << endl;
	}

	auto item = 2;
	cout << "searching val store at : " << item << endl;
	auto it = m1.find(item);
	cout << it->second << endl;

	return 0;
}
