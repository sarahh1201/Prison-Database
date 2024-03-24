#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <vector>
using namespace std;

const int maxIndices = 8;//the number of data fields per user
const int permissionsMax = 10;

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
	bool permissions[permissionsMax];
	//constructor
	User();
	//destructor
	~User();
public:

	//calls on constructor after checking if user has permission to create a new user
	User& createUser(bool canCreateUser);
	//calls on constructor with inputted parameters
	User createUser(bool canCreateUser, string firstName, string lastName, string govID, string userID);
	void save();//save updated user data to the files

	//delete a user profile
	void deleteUser(bool canCreateUser);

	//accessors
	string getFirstname();
	string getLastname();
	string getUsername();
	string getGovID();
	string getUserID();

	//mutators
	void setFirstname(string firstName);
	void setLastname(string lastName);
	void setUsername(string userName);
	void setGovID(string govID);
	void setUserID(string userID);

private:
	string getPassword();
	};
#endif
