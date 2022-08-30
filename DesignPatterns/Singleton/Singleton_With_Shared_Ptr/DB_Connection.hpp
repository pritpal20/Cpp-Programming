#pragma once
#include <iostream>
#include <memory>
#include <mutex>

using namespace std;


class DBConnection 
{
protected : 
	
	mutable bool IsConnected = false;
	DBConnection()
	{
		cout << "DB Object created \n";
	}
public:
	~DBConnection()
	{
		cout << "DB Object destroyed \n";
	}

	int Connect() const 
	{
		if(IsConnected == false)
		{
			IsConnected = true;
			cout << "Connected to DB \n";
		}
		else
			cout << "Already Connected to DB \n";

		return 0;
	}


	static std::shared_ptr<DBConnection> get_Instance() 
	{
		struct make_shared_enabler : public DBConnection 
		{

		};
		static shared_ptr<make_shared_enabler> 
			self_instance = std::make_shared<make_shared_enabler>();
		return self_instance;
	}
};