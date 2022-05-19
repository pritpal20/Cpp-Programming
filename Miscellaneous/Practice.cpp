#include <iostream>
#include <vector>
using namespace std;

  
int main()
{
    std::vector<int> a = {0, 1, 2, 3, 4, 5};     

    auto i = a.begin();

    while( i != a.end())
    	cout << *i << " " 	;
    cout << endl;
    return 0;
}