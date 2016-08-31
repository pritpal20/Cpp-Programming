/* This programs takes the number as args and returns the square root of number or 
 * Sum of numbers depending on the option selected
 * I have used Pthread in program to demonstrate Multithreading;
 * Version : 1.0
 * Date : 31/08/2016
 * Author : pritpal20@gmail.com
 * */

#include <stdlib.h>
#include <iostream>
#include <vector>
#include <pthread.h>
#include <math.h>

using namespace std;

#define MAX_SIZE 10

void* squareroot(void* args)
{
	long int *num = (long int*) args;
	//printf("Thread Created %d \n",*num);
	double n = sqrt(*num);
	printf("Square root of %d is %f \n",*num,n);
}

void* getSumofNum(void* args)
{
	long int *num = (long int*) args;
	
	int sum = 0;
	for(int i = 1; i <= *num ; i++)
	{
		sum+=i;
	}
	
	printf("Sum of number %d is  %d \n",*num,sum);
	
}

int main(int argc,char* argv[])
{
	if(argc < 2 )
	{
		cout <<"usage : ./squareroot num1 num2 ... numN" << endl;
		exit(1);
	}
	
	char option = 'R';
	
	cout << "Type R for square root and S for Sum of numbers " << endl;
	cin>>option;
	
	void* (*funcp)(void*);
	
	if(option == 'R')
	{
		funcp = squareroot;
	}
	else
		funcp = getSumofNum;
	
	pthread_t t1[10];
	
	vector<long int> v1;
	for(int i = 1; i < argc ; i++)
	{
		v1.push_back(atoi(argv[i]));
	}
	
	unsigned int i = 0;
	
	while(i < v1.size() )
	{
		int rc = pthread_create(&t1[i],NULL,funcp,(void*)&v1[i]);
		
		if ( rc < 0)
		{
			cout << "Error creating thread " << endl;
		}
		i++;
	}
	
	unsigned int j = 0;
	while(j < v1.size() )
	{
		pthread_join(t1[j],NULL);
		j++;
	}
	
	
	
	return 0;
}
