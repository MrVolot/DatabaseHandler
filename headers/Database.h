#pragma once
#include "nanodbc/nanodbc.h"

class DatabaseHandler {
	DatabaseHandler() = default;
public:
	static DatabaseHandler& getInstance();
	void connectDB();
	void disconnectDB();
	std::vector<std::vector<std::string>> executeQuery(const std::string& inputQuery, size_t dataCount);
	//bool searchUser(const std::string& login);
	//credentialsStatus checkPassword(const std::string& login, const std::string& password);
	//credentialsStatus registerNewUser(const std::string& login, const std::string& password);
	//credentialsStatus authUser(const std::string& login, const std::string& hash);
};