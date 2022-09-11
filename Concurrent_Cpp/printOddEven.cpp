#include <iostream>
#include <thread>

using namespace std;

/* 
!!! Prints even or odd number in the range(count) 
*/
template <typename EvenOrOdd>
void Print(int count,EvenOrOdd args)
{
	for (int i = 0; i < count; ++i)
	{
		if(args(i))
			printf("thread : [%d] count : [%d] \n",std::this_thread::get_id(),i);
	}
	return;
}


int main(int argc, char const *argv[])
{
	auto even = [](int x ){

		return x % 2 == 0 ? true : false;

	};

	auto odd = [](int x ){

		return x % 2 == 0 ? false : true;

	};

	Print(100,even);

	// std::thread t1(Print,100,asc);
	//t1.join();
	return 0;
}
