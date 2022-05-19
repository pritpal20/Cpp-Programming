#include <iostream>
#include "../GlobalDef.h"
#include <thread>
#include <mutex> 

static int var = 0;

std::mutex mtx;

void Somefunc(int i)
{
	std::cout << "ipp "  << i << std::endl;
	std::cout << "started thread id   "  << std::this_thread::get_id() << std::endl;
	while( i < 10 )
	{	
		i++;
		mtx.lock();
		std::cout << "Mutex lock taken by thread " << std::this_thread::get_id() << std::endl;
		var++;
		mtx.unlock();
		std::cout << "i = " << i << std::endl;
		_sleep(100);
	}
}


int main(int argc, char const *argv[])
{
	
	std::thread t1(Somefunc,0);
	std::thread t2(Somefunc,5);
	// Somefunc();

	t1.join();	
	t2.join();	
	return SUCCESS;
}