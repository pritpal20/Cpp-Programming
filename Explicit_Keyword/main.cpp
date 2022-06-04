#include <iostream>
#include "..\GlobalDef.h"
#include <memory>

struct Demo
{
	std::string m_Name;
	int m_Age;

	explicit Demo(const std::string Name,int age):  m_Name(Name),m_Age(age)
	{
		cout << "object created \n" ;
	}
	~Demo()
	{
		cout << "object destroyed \n" ;
	}
};

int main(int argc, char const *argv[])
{

	//! NO IMPLICIT CONVERSION BCOZ of EXPLICIT keyword before CONSTRUCTOR
	//! remove explicit keyword and the code should work 
	Demo d = {"Pritpal",2};

	LOG(d.m_Name);
	LOG(d.m_Age);
}