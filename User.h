#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <vector>
using namespace std;


const int permissionsMax = 10;//permissions bool size
const int maxIndices = 5;//max number of columns per user in text file
const int maxUsernameFileIndex = 3;//max number of columns in username files

class User
{
protected:
	//general user info 
	string firstname;
	string lastname;
	string username;
	string password;
	string govID;
	string userID;
	int userIndex;
	//array of system permissions
	//bool permissions[permissionsMax];
	//constructor
	User();
	//destructor
	~User();

public:

	//calls on constructor after checking if user has permission to create a new user
	//User& createUser(bool canCreateUser);
	//calls on constructor with inputted parameters
	//User createUser(bool canCreateUser, string firstName, string lastName, string govID, string userID);
	void save();//save updated user data to the files

	//delete a user profile
	void deleteUser(bool canCreateUser);

	//accessors
	string getFirstname();
	string getLastname();
	string getUsername();
	string getGovID();
	string getUserID();
	string getPassword();
	int getUserIndex();

	//mutators
	void setFirstname(string firstName);
	void setLastname(string lastName);
	void setUsername(string userName);
	void setGovID(string govID);
	void setUserID(string userID);
};
#endif
