#ifndef HOTDRINKFACTORY_HPP
#define HOTDRINKFACTORY_HPP
#include "hotdrink.hpp"


struct hotdrinkfactory
{
	virtual unique_ptr<hotdrink> make() const = 0;
};

struct teafactory : public hotdrinkfactory
{
	virtual unique_ptr<hotdrink> make()  const
	{
		return make_unique<tea>();
	}
};


struct coffeefactory : public hotdrinkfactory
{
	virtual unique_ptr<hotdrink> make()  const
	{
		return make_unique<coffee>();
	}
};

#endif // HOTDRINKFACTORY_HPP
