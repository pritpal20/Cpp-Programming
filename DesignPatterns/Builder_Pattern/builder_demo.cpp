#include <iostream>
#include <vector>

using namespace  std ;

class HtmlElement
{
	string name;
	string text;
	vector<HtmlElement> elements;

	const size_t indent_size = 2;

public :

	HtmlElement() {}

	HtmlElement(const string& name_,const string& text_) : name(name_),text(text_)
	{

	}

	string str(size_t indent = 0) const
	{
		ostringstream oss;
		string i(indent_size*indent,' ');

		oss << i << "<" << name << ">" << endl;

		if(text.size() > 0 )
			oss << i  << text  << endl;

		for(const auto &elem : elements)
			elem.str(indent+1);

		oss << i << "</" << name << ">" << endl;

	}

};

int main(int argc, char const *argv[])
{
	
	return 0;
}