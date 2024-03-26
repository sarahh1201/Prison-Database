#include "User.h"

User::User()
{
	firstname = "errorfirstname";
	lastname = "errorlastname";
	username = "errorusername";
	password = "7777";
	govID = "errorgovID";
	userID = "erroruserID";
	userIndex = 0;
}
//basic constructor, checks if user has permission to create a new user
/*User& User::createUser(bool canCreateUser)
{
	try {
	return User();
   }
	//catch()ACCESS ERROR: CANNOT CREATE USER
}*/
//constructor with inputted parameters
/*User User::createUser(bool canCreateUser, string firstName, string lastName, string govID, string userID)
{
	//try{
	this->firstname = firstName;
	this->lastname = lastName;
	this->govID = govID;
	this->userID = userID;
	//}
	//catch() ACCESS ERROR: CANNOT CREATE USER
}*/

//destructor
User::~User()
{

}
//delete a user profile
void User::deleteUser(bool canCreateUser)
{

}



void User::save()//incomplete
{
	string data;

	/*ifstream input("Staff_Data.txt");
	for (int i = 0; i <= userIndex; i = i + maxIndices)//iterate for every row until the staff index is reached
	{
		string unused;//throwaway string to iterate inputs
		if (i == userIndex)//if the current index is the desired staff row
		{
			for (int j = 0; j < 5; j++)//iterate thrugh columns
				if (j == fieldIndex)//if current column is the correct field index
					input >> data;//take input into data string
				else//if incorrect column, put data into unused datafield;
					input >> unused;
		}
		for (int j = 0; j < 5; j++)//while i does not equal the staff index, throw away each column entry
			input >> unused;
	}
	input.close();
	*/

	ofstream output;
	output.open("Staff_Data.txt", ios::ate);//opens file to output onto it, appends to end of file
}
//accessors
string User::getFirstname()
{
	return firstname;
}
string User::getLastname()
{
	return lastname;
}
string User::getUsername()
{
	return username;
}
string User::getGovID()
{
	return govID;
}
string User::getUserID()
{
	return userID;
}
string User::getPassword()
{
	return password;
}
int User::getUserIndex()
{
	return userIndex;
}

//mutators
void User::setFirstname(string firstName)
{
	this->firstname = firstName;
}
void User::setLastname(string lastName)
{
	this->lastname = lastName;
}
void User::setUsername(string userName)
{
	this->username = userName;
}
void User::setGovID(string govID)
{
	this->govID = govID;
}
void User::setUserID(string userID)
{
	this->userID = userID;
}

