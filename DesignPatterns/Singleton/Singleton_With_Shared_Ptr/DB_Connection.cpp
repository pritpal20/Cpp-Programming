#include "DB_Connection.hpp"

int main(int argc, char const *argv[])
{
	std::shared_ptr<DBConnection> obj_db = DBConnection::get_Instance();

	obj_db->Connect();
	obj_db->Connect();

	std::shared_ptr<DBConnection> obj_db2 = DBConnection::get_Instance();
	obj_db2->Connect();
	return 0;
}