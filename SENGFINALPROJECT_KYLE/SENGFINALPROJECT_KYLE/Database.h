#ifndef DATABASE_H
#define DATABASE_H

#include "User.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//this class is a container for all of the user objects
//it contains general information about users, facilitates addition and subraction of users, and permits file read/write

class Database
{
private:
	vector<User> users;
	int userCount;
	string fileName;
public:
	Database();

	//!valid file name!
	Database(string fileName); //reads user info from file and saves it to the users vector

	int login() const; //facilitates login (returns -1 on invalid credentials)

	//!valid index check!
	User* getUser(int index);

	int getUserCount() const;

	void incrementUserCount();

	void addUser(const User& user);

	//!valid index!
	void deleteUser(int index);

	//!valid file name (create file if non-existent)!
	void saveDatabase();

	void setFileName(string fileName);
};
#endif // !DATABASE_H
