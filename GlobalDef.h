#ifndef __GLOBALDEF__
#define __GLOBALDEF__
#include <iostream>
#include <array>

#define fo(i,n) for(UINT i = 0 ; i < n ; i++)
#define fo1(i,n) for(int j = i ; j < n ; j++)

#define Fo(i,n) for(int i = 0;i < n ; i++)
#define range(i,s,n) for(int i = s;i < n ; i++)

#define cout std::cout
#define endl std::endl

#define LOG(x) cout << (#x) << " = " <<  x << endl
#define LOG2(x,y) cout << (#x) << " = " <<  x << " ," <<(#y) << " = " << y << endl
enum ReturnType : int
{
	ERROR = -1,SUCCESS = 0,FAIL = 1
};

typedef int* ArrayInt;

typedef unsigned int UINT;


template<size_t N> void PrintArray(int (&arr)[N])
{

	cout << "[";
	fo(i,N)
	{

		cout << arr[i] ;
		if (i != N-1) 
			cout << "," ;
	}
	cout << "]" << endl;
}

void PrintArray(int* arr,UINT N)
{
	cout << "[";
	fo(i,N)
	{

		cout << arr[i] ;
		if (i != N-1) 
			cout << "," ;
	}
	cout << "]" << endl;
}


void swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}


template <class T,size_t n>
void PrintArray(std::array<T,n> arr)
{
	UINT N = arr.size();
	cout << "[";
	fo(i,N)
	{

		cout << arr[i] ;
		if (i != N-1) 
			cout << "," ;
	}
	cout << "]" << endl;

	// return nullptr;
}

#endif