#include <iostream>
#include <thread>

using namespace std;

/* 
!!! Prints even or odd number in the range(count) 
*/
template <typename OrderBy>
void Print(int count,OrderBy order)
{
	for (int i = 0; i < count; ++i)
	{
		if(order(i))
			printf("thread : [%d] count : [%d] \n",std::this_thread::get_id(),i);
	}
	return;
}


int main(int argc, char const *argv[])
{
	auto asc = [](int x ){

		return x % 2 == 0 ? true : false;

	};

	Print(100,asc);
	return 0;
}
