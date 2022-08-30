#ifndef DRINKFACTORY_HPP
#define DRINKFACTORY_HPP
#include <map>
#include "hotdrinkfactory.hpp"
#include <functional>

using namespace std;
#pragma once

class drinkfactory
{
	map<string,unique_ptr<hotdrinkfactory>> hotfactories; 

public : 
	drinkfactory()
	{
		hotfactories["tea"] = make_unique<teafactory>();
		hotfactories["coffee"] = make_unique<coffeefactory>();
	}

	unique_ptr<hotdrink> make_drink(const string& name)
	{
		auto drink = hotfactories[name]->make();
		drink->prepare(200);
		return drink;
	}
};


#endif // DRINKFACTORY_HPP
