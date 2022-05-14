#pragma once
#include "nanodbc/nanodbc.h"

class DatabaseHandler {
	std::unique_ptr<nanodbc::connection> connection;
	DatabaseHandler();
public:
	~DatabaseHandler();
	static DatabaseHandler& getInstance();
	void connectDB();
	void disconnectDB();
	std::vector<std::vector<std::string>> executeQuery(const std::string& inputQuery);
};