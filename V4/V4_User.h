#pragma once
#ifndef V4_USER_H
#define V4_USER_H
#include <string>
#include <fstream>
#include <vector>
#include <iostream>
#include <sstream>

using namespace std;

const int permissionsMax = 10;//permissions bool size
const int maxIndices = 5;//max number of columns per user in text file
const int maxUsernameFileIndex = 3;//max number of columns in username files
const int managerMaxIndices = 3;//max number of columns in manager data file
const int staffMaxIndices = 3;//max number of columns in staff data file
const int inmateMaxIndices = 9;//max number of columns in manager data file

class User
{
protected:
	int inmateCount = 20;//default starter value to edit
	int staffCount = 20;//default starter value to edit
	int managerCount = 5;//default starter value to edit
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

	string getUserInfo(int userFileNumber, int memberIndex, int fieldIndex);

	string staffGetUsername(int userFileNumber, int memberIndex);
	int staffGetUserIndex(int userFileNumber, string data);


	void setUserInfo(int userFileNumber, int memberIndex, int fieldIndex, string newData);
	void setUsernameInfo(int userFileNumber, int memberIndex, int fieldIndex, string newData);

	string getInmateInfo(int inmateIndex, int fieldIndex);
	void setInmateInfo(int inmateIndex, int fieldIndex, string newData);

	bool newUsername(int userFileNumber, string username);

	/*
	int findUserIndex(int userFileNumber, string username)
	{
		string usernameFile;
		switch (userFileNumber)//decide which file to pull from
		{
		case 0: {
			usernameFile += "Staff_Usernames.txt";
			break;
		}
		case 1: {
			usernameFile += "Inmate_Usernames.txt";
			break;
		}
		}

		string inUsername;

		//find username
		ifstream input(usernameFile);//open the usernames and password file (order of info is index, username, password)
		int position = 0;
		int index = 0;
		while (getline(input, inUsername, ' '))
		{
			if ((position % maxUsernameFileIndex) == 1)//skip every entry that is not usernames 
				if (inUsername == username)//if the usernames match
				{
					//return = true;//set match to true to allow loop to continue once
				}
			position++;
		}
		return -1;
	}
	*/

private:
	void Check(string entry); //Check password
};
#endif
