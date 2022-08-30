#include <iostream>
#include "drinkfactory.hpp"

using namespace std;

void PrepareDrink(hotdrink* drink,int volume)
{
	drink->prepare(volume);
}

int main(int argc, char const *argv[])
{
	
	drinkfactory df;

	auto tea = df.make_drink("tea");

	return 0;
}