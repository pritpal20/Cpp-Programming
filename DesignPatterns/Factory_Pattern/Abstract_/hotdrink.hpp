#ifndef HOTDRINK_HPP
#define HOTDRINK_HPP

#include <iostream>
#include <memory>

using namespace std;


struct hotdrink
{
	virtual ~hotdrink() {}

	virtual void prepare(int volume) = 0;
};

struct tea : public hotdrink
{
	~tea()
	{

	}

	void prepare(int volume) override
	{
		cout << "Take tea bag , boil water , pour " << volume << " ml \n";
		cout << "Add some lemon \n";
	}
};

struct coffee : public hotdrink
{
	~coffee()
	{

	}

	void prepare(int volume) override
	{
		cout << "Grind some beans , boil water , pour " << volume << " ml \n";
		cout << "Add some milk \n";
	}
};




#endif // HOTDRINK_HPP
