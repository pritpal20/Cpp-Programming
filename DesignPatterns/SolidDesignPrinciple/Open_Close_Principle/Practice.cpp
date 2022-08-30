#include <iostream>
#include <vector>
using namespace std;
enum class Color {green,red,blue,yellow};

enum class Size {small,medium,large};


struct Product
{
	string name;
	Color color;
	Size size;
};

template <typename T> struct Specification
{
	virtual ~Specification() = default;
	virtual bool is_satisfied(T* item) const = 0;
};

class ProductFilter 
{
public : 
	
	vector<Product*> FilterByColor(vector<Product*> item,Color color)
	{
		vector<Product*> result;
		for(auto &e: item)
		{
			if(e->color == color)
			{
				result.push_back(e);
			}
		}
		return result;
	}

	vector<Product*> FilterBySize(vector<Product*> item,Size size)
	{
		vector<Product*> result;
		for(auto &e: item)
		{
			if(e->size == size)
			{
				result.push_back(e);
			}
		}
		return result;
	}

	vector<Product*> FilterByColorandSize(vector<Product*> item,Color color,Size size)
	{
		vector<Product*> result;
		for(auto &e: item)
		{
			if(e->color == color && e->size == size)
			{
				result.push_back(e);
			}
		}
		return result;
	}
};


struct ColorSpecification : public Specification<Product>
{
	Color color;

	ColorSpecification(Color _color) : color(_color)
	{

	}

	bool is_satisfied(Product* item) const override
	{
		if (item->color == color)
			return true;

		return false;
	}
};

struct SizeSpecification : public Specification<Product>
{
	Size size;

	SizeSpecification(Size _size) : size(_size)
	{

	}

	bool is_satisfied(Product* item) const override
	{
		if (item->size == size)
			return true;

		return false;
	}
};



int main(int argc, char const *argv[])
{
	Product apple{"apple",Color::green,Size::small};
	Product tree{"Tree",Color::green,Size::large};
	Product house{"House",Color::blue,Size::large};

	vector<Product*> all{&apple,&tree,&house};

	for(auto &e : all)
		cout << e->name << endl;

	ColorSpecification green(Color::green);

	ProductFilter pf;

	vector<Product*> ret =  pf.FilterByColor(all,Color::green);

	for(auto &e : ret)
		cout << e->name << " is green color " << endl;


	vector<Product*> ret2 =  pf.FilterBySize(all,Size::large);

	for(auto &e : ret2)
		cout << e->name << " is large size " << endl;

	vector<Product*> ret3 =  pf.FilterByColorandSize(all,Color::green,Size::small);

	for(auto &e : ret3)
		cout << e->name << " is green and small size " << endl;





	return 0;
}