#include <iostream>
#include "../GlobalDef.h"
#include <mutex>

std::mutex mtx1;
namespace sig
{
	class Singleton
	{
	private:

		int connect = false;
		Singleton()
		{	
			cout << "Object created " << endl;
		}

	public:
		
		static Singleton* get_instance()
		{
			static Singleton* obj = NULL;

			if (obj == NULL)
			{
				mtx1.lock();
				if (obj == NULL)
				{
					obj = new Singleton();
				}
				mtx1.unlock();
			}

			return obj;

		}
		
		Connect()
		{
			if (connect == false )
			{
				cout << "Connected to database \n";
				connect = true;
			}

			return 0;
		}

		~Singleton()
		{
			cout <<"Object destroyed \n";
		}
	};

};

int main(int argc, char const *argv[])
{
	
	sig::Singleton* obj1 = sig::Singleton::get_instance();

	sig::Singleton* obj2 = sig::Singleton::get_instance();

	obj2->Connect();
	obj1->Connect();
	LOG(obj1);
	LOG(obj2);
	return 0;
}