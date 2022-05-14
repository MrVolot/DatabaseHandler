#include "Database.h"
#include "nanodbc/nanodbc.h"
#include <iostream>
#include <iterator>
#include <algorithm>
#include <memory>

DatabaseHandler::DatabaseHandler() = default;

DatabaseHandler::~DatabaseHandler()
{
	if (connection != nullptr) {
		disconnectDB();
	}
}

DatabaseHandler& DatabaseHandler::getInstance()
{
	static DatabaseHandler instance{};
	return instance;
}

void DatabaseHandler::connectDB()
{
	connection.reset(new nanodbc::connection{ "SQLDB", "Login_Server", "123" });
	if (connection == nullptr) {
		throw std::exception("Error connection to database");
	}
	std::cout << "CONNECTED! " << connection->driver_name() <<std::endl;
}

void DatabaseHandler::disconnectDB()
{
	connection->disconnect();
}

std::vector<std::vector<std::string>> DatabaseHandler::executeQuery(const std::string& inputQuery)
{
	auto result{ nanodbc::execute(*connection, inputQuery) };
	if (inputQuery.find("SELECT") != std::string::npos) {
		std::vector<std::vector<std::string>> vectorToReturn{};
		int i{};
		while (result.next()) {
			std::vector<std::string> tmpVec;
			for (int j{ 0 }; j < result.columns(); j++) {
				tmpVec.push_back(result.get<std::string>(j, "null"));
			}
			vectorToReturn.push_back(tmpVec);
			i++;
		}
		return vectorToReturn;
	}
	return {};
}