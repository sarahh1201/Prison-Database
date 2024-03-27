#ifndef USER_H
#define USER_H
#include <string>
#include <fstream>
#include <vector>
using namespace std;


const int permissionsMax = 10;//permissions bool size
const int maxIndices = 5;//max number of columns per user in text file
const int maxUsernameFileIndex = 3;//max number of columns in username files
const int inmateMaxIndices = 9;

int inmateCount = 20;//default starter value to edit
int staffCount = 20;//default starter value to edit
int managerCount = 5;//default starter value to edit

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
	~User()
	{
	
	
	}

public:

	void save();//save updated user data to the files

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

private:
	void Check(string entry); //Check password
};
#endif
