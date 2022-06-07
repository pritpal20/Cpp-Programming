#include <map>
#include <memory>
#include <iostream>

using namespace std;
template <typename T,typename Key>
class SingletonDataBase
{
private :
	static map<Key,shared_ptr<T>> instances;

public :

	static shared_ptr<T> get_instance(const Key& key )
	{

		if( const auto it = instances.find(key);it != instances.end() )
				return it->second;

		auto instance = make_shared<T>();
		instances[key] = instance;
		return instance;
	}

protected:
  	SingletonDataBase() = default;
  	virtual ~SingletonDataBase() = default;
};

template <typename T,typename Key>
map<Key,shared_ptr<T>>SingletonDataBase<T,Key>::instances;

class Printer
{
public:
  Printer()
  {
    ++Printer::totalInstanceCount;
    cout << "A total of " <<
      Printer::totalInstanceCount <<
      " instances created so far\n";
  }
private:
  static int totalInstanceCount;
};
int Printer::totalInstanceCount = 0;



int main(int argc, char const *argv[])
{
	typedef SingletonDataBase<Printer,string> mt;
	auto obj1 = mt::get_instance("Prit");
	auto obj2 = mt::get_instance("Raj");
	auto obj3 = mt::get_instance("Prit");
	auto obj4 = mt::get_instance("Chhabra");
	auto obj5 = mt::get_instance("Chhabra");
	return 0;
}