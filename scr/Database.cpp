#include "Database.h"
#include "nanodbc/nanodbc.h"
#include <iostream>

DatabaseHandler& DatabaseHandler::getInstance()
{
	static DatabaseHandler instance{};
	return instance;
}

void DatabaseHandler::connectDB()
{
	nanodbc::connection connection{"SQLDB", "Login_Server", "123"};
	std::cout << "CONNECTED! " << connection.driver_name() <<std::endl;
	auto result{ nanodbc::execute(connection, "SELECT * FROM CONTACTS")};
	std::cout << result.columns() << " " << std::endl;
	try {
		result.next();
		std::cout << result.get<std::string>(0);
		/*env = odbc::Environment::create();
		conn = env->createConnection();
		try {
			conn->connect("SQLDB", "Login_Server", "123");
			conn->setAutoCommit(false);
			odbc::PreparedStatementRef psInsert = conn->prepareStatement("USE Messenger");
			psInsert->executeQuery();
		}
		catch (odbc::Exception ex) {
			std::cout << ex.what();
		}*/
	}
	catch (std::exception ex) {
		std::cout << ex.what();
	}
	std::cout << std::endl;
}

void DatabaseHandler::disconnectDB()
{
}

std::vector<std::vector<std::string>> DatabaseHandler::executeQuery(const std::string& inputQuery, size_t dataCount)
{

	return {};
}
