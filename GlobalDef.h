#ifndef __GLOBALDEF__
#define __GLOBALDEF__
#include <iostream>
#include <array>
#include <vector>
#include <list>
#include <deque>
#include <map>
#include <cstring>


typedef std::list<std::string> :: iterator listiterator;

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

int* generateUniqueNumbersArray(int count)
{
	srand(time(NULL));
	std::map<int,bool> cache ;
	int* A = new int[count];
	for(int i = 0 ; i < count ; i++ )
	{
		while(true)
		{
			int random_no = rand() % count + 1 ;
			if (cache.find(random_no) == cache.end() )
			{
				A[i] = random_no;
				cache.insert({random_no,true});
				break;
			}
			else
				continue;
		}
	}
	return A;
}

int* generateArray(int count)
{
	srand(time(NULL));
	int* A = new int[count];
	
	for(int i = 0 ; i < count ; i++ )
	{
		int random_no = rand() % count + 1 ;
		A[i] = random_no;
	}
	return A;
}


template<size_t N> void PrintArray(int (&arr)[N])
{

	cout << "{ ";
	fo(i,N)
	{

		cout << arr[i]  << " " ;
	}
	cout << "}" << endl;
}

template<size_t N> void print_array(int (&a)[N])
{
	cout << "[" ;
	fo(i,N)
	{
		cout << a[i] ;
		if (i != N -1)
			cout << ", ";
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

void print_array(int *a,int start,int end)
{
	cout << "{" ;
	range(i,start,end+1)
	{
		cout << a[i] << " ";
	}
	cout << "}" << endl;
}

void print_array(int *a,int N)
{
	cout << "[" ;
	fo(i,N)
	{
		cout << a[i] ;
		if (i != N -1)
			cout << ", ";
	}
	cout << "]" << endl;
}

template <class T>
void swap(T &a,T &b)
{
	T temp = a;
	a = b;
	b = temp;
}


template <class T,size_t n>
void PrintArray(const std::array<T,n>& arr)
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

template <class T>
void print(const std::vector<T>& v)
{
	UINT N = v.size();
	cout << "[" ;
	fo(i,N)
	{
		cout << v[i]  ;
		if (i != N-1) 
			cout << "," ;
	}
	cout << "]\n" ;
}

template <class T>
void print(const std::list<T>& lst)
{
	UINT N = lst.size();
	cout << "[" ;
	for(const auto &item : lst)
	{
		cout << item << ",";
	}
	cout << "]\n" ;
}

template <class T>
void print(const std::deque<T> deq)
{
	cout << "[";
	for(auto it = deq.begin();it != deq.end();++it)
	{
		cout << *it << "," ;
	}
	cout << "]" << endl;
	
	// for(auto &item : deq)
	// {
	// 	cout << item << "," ;
	// }
}

#endif