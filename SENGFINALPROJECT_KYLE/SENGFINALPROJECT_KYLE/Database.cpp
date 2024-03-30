#include "Database.h"

using namespace std;

Database::Database()
{
	fileName = "DefaultDatabaseFileName.txt";

	userCount = 0;

	ifstream usersFile(fileName);
	string currFileLine;

	while (getline(usersFile, currFileLine)) //dual finction: checks if there is a next line and saves it to currFIleLine
	{
		istringstream iss(currFileLine); //converts the current line of the file to an istream such that the >> operator can be used

		users.push_back(User()); //adds a default user to the users vector

		iss >> users[users.size() - 1]; //writes the current line of the file to the user that was just created
	}
	userCount = users.size();

	usersFile.close();
}

//!valid file name!
Database::Database(string fileName) //reads user info from file and saves it to the users vector
{
	this->fileName = fileName;

	userCount = 0;

	ifstream usersFile(fileName);
	string currFileLine;

	while (getline(usersFile, currFileLine)) //dual finction: checks if there is a next line and saves it to currFIleLine
	{
		istringstream iss(currFileLine); //converts the current line of the file to an istream such that the >> operator can be used

		users.push_back(User()); //adds a default user to the users vector

		iss >> users[users.size() - 1]; //writes the current line of the file to the user that was just created
	}
	userCount = users.size();

	usersFile.close();
}

int Database::login() const //facilitates login (returns -1 on invalid credentials)
{
	string userername;
	string password;

	int userIndex = -1;

	cout << "Enter username: ";
	cin >> userername;

	for (int i = 0; i < users.size(); i++) //searches database for inputted username
		if (userername == users[i].getUsername())
		{
			userIndex = i;
			break; //breaks loop on find for efficiency
		}

	cout << "Enter password: ";
	cin >> password;

	//control blocks written like this to keep from an erronious attempt to access users[-1]
	if (userIndex != -1) //if no username match was found,,,
		if (password == users[userIndex].getPassword()) //if password matches, return index found in username search,,,
			return userIndex;

	return -1; //if no username match or passwords not match, return -1
}

//!valid index check!
User* Database::getUser(int index)
{
	return &users[index];
}

int Database::getUserCount() const
{
	return userCount;
}

void Database::incrementUserCount()
{
	userCount++;
}

void Database::addUser(const User& user)
{
	users.push_back(user);

	userCount = users.size();
}

//!valid index!
void Database::deleteUser(int index)
{
	users[index] = users[users.size() - 1];

	users.pop_back();

	userCount = users.size();
}

//!valid file name (create file if non-existent)!
void Database::saveDatabase()
{
	ofstream out(fileName, ofstream::trunc); //saves the whole file from scratch; inefficient, but 100x simpler everywhere.

	for (int i = 0; i < users.size(); i++)
		out << users[i];

	out.close();
}

//!valid file name (create file if non-existent)!
void Database::setFileName(string fileName)
{
	this->fileName = fileName;
}