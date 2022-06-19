#include <iostream>
#include <set>
#include <unordered_set>

using namespace std;

typedef set<int> int_set;
typedef multiset<int> int_multiset;

typedef unordered_set<int> int_unordered_set;
typedef unordered_multiset<int> int_unordered_multiset;


int main(int argc, char const *argv[])
{
	int arr[]{3,2,5,9,10,7,8,3,2,5,9,10,7,8};

	int_set s1;

	for(auto &item : arr)
	{
		cout << "inserting ... " << item << endl;
		s1.insert(item);
	}

	cout << "[ ";
	for(auto it : s1)
	{
		cout << it << " ";
	}
	cout << "]\n";

	int arr2[]{10,9};

	for(auto &item : arr2)
	{
		cout << "Deleting ..." << item << endl;
		s1.erase(item);
	}

	cout << "[ ";
	for(auto it : s1)
	{
		cout << it << " ";
	}
	cout << "]\n";
	return 0;
}