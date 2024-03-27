#include "V4_User.h"
using namespace std;
//#include "EntryException.h"

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
/*
void User::Check(string entry) //Should be comparing the inputed password to the actual password
{
	if (entry != entry) //If the password is wrong it would be thrown
		throw EntryException(entry);
}
*/