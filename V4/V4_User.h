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
const int managerMaxIndices = 3;
const int staffMaxIndices = 3;//max number of fields in staff data file
const int inmateMaxIndices = 9;

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

	string getUserInfo(int userFileNumber, int memberIndex, int fieldIndex)
	{
		string data = "ERROR: NO DATA FOUND (getUserInfo)";//assigned a string to ensure that something is returned
		//try {
		string filename;
		//try{
		switch (userFileNumber)//decide which file to pull from
		{
		case 0: {
			filename += "Staff_Users.txt"; break;
		}
		case 1: {
			filename += "Inmate_Users.txt"; break;
		}
		}
		//}
		//catch (FILE NUMBER OUT OF RANGE)
		ifstream input(filename);//open the correct user data file
		for (int i = 0; i <= memberIndex; i++)//iterate for every row until the user index is reached
		{
			string unused;//throwaway string to iterate inputs
			if (i == memberIndex)//if the current index is the desired user row
			{
				for (int j = 0; j < maxIndices; j++)//iterate through columns
					if (j == fieldIndex)//if current column is the correct field index
						input >> data;//take input into data string
					else//if incorrect column, put data into unused datafield;
						input >> unused;
			}
			for (int j = 0; j < maxIndices; j++)//while i does not equal the user index, throw away each column entry
				input >> unused;
		}
		input.close();
		//}
		//catch() FILE ACCESS EXCEPTION (incorrect permissions)
		//catch() staff index out of range (tries to iterate past end of file)

		return data;
	}

	void setUserInfo(int userFileNumber, int memberIndex, int fieldIndex, string newData)
	{

		string filename;
		//try{
		switch (userFileNumber)//decide which file to pull from
		{
		case 0: {
			filename += "Staff_Users.txt"; break;
		}
		case 1: {
			filename += "Inmate_Users.txt"; break;
		}
		}
		//}
		//catch (FILE NUMBER OUT OF RANGE)

		vector<string> v1;//vector for first half of data
		string temp;//string to put input into vector
		vector<string> v2;//vector for second half of data

	//try{
	//Save all of the data into vectors to update it
		//save first half of data to a vector
		ifstream input(filename);
		for (int i = 0; i <= memberIndex; i++)//iterate for every row until the staff index is reached
		{
			for (int j = 0; j < maxIndices; j++)//iterate through columns
			{
				if (i != memberIndex)//if it is not the correct index yet, put the data into the vector
				{
					input >> temp;
					v1.push_back(temp);
					v1.push_back(" ");//append a space after every entry
				}
				else if (i == memberIndex)//if it equals the staff index
				{
					if (j == fieldIndex)//check if the column index is correct
						break;//break out of inner loop, the next loop will end
					else if (j != fieldIndex)
					{
						input >> temp;
						v1.push_back(temp);
						v1.push_back(" ");//append a space after every entry
					}
				}

			}
		}
		input.close();

		//save second half of data to a vector
		int index = 0;
		input.open(filename);
		while (getline(input, temp, ' '))//go through every entry of the file
		{
			if (index / maxIndices >= memberIndex)//finds the current staffindex, if it is greater or equal move on
				if ((index - memberIndex * maxIndices) > fieldIndex)//compares the column indices, if it is greater then move on
				{
					v2.push_back(temp);
					v2.push_back(" ");//append a space after every entry
				}
			index++;//iterate index counter after logic has passed
		}
		input.close();


		//recreate staff data file
		ofstream output;
		output.open(filename);
		for (int i = 0; i < static_cast<int>(v1.size()); i++)//put all of v1 back into the staff data file
		{
			temp = v1.at(i);
			output << temp;
		}
		output << newData;//put the new info into the file
		output << ' ';
		for (int i = 0; i < static_cast<int>(v2.size()); i++)//put all of v2 back into the end staff data file
		{
			temp = v2.at(i);
			output << temp;
		}
		output.close();
		//}
		//catch() ACCESS DENIED: MISSING EDIT PERMISSIONS
	}

	void setUsernameInfo(int userFileNumber, int memberIndex, int fieldIndex, string newData)
	{

		string filename;
		//try{
		switch (userFileNumber)//decide which file to pull from
		{
		case 0: {
			filename += "Staff_Usernames.txt"; break;
		}
		case 1: {
			filename += "Inmate_Usernames.txt"; break;
		}
		}
		//}
		//catch (FILE NUMBER OUT OF RANGE)

		vector<string> v1;//vector for first half of data
		string temp;//string to put input into vector
		vector<string> v2;//vector for second half of data

	//try{
	//Save all of the data into vectors to update it
		//save first half of data to a vector
		ifstream input(filename);
		for (int i = 0; i <= memberIndex; i++)//iterate for every row until the staff index is reached
		{
			for (int j = 0; j < maxUsernameFileIndex; j++)//iterate through columns
			{
				if (i != memberIndex)//if it is not the correct index yet, put the data into the vector
				{
					input >> temp;
					v1.push_back(temp);
					v1.push_back(" ");//append a space after every entry
				}
				else if (i == memberIndex)//if it equals the staff index
				{
					if (j == fieldIndex)//check if the column index is correct
						break;//break out of inner loop, the next loop will end
					else if (j != fieldIndex)
					{
						input >> temp;
						v1.push_back(temp);
						v1.push_back(" ");//append a space after every entry
					}
				}

			}
		}
		input.close();

		//save second half of data to a vector
		int index = 0;
		input.open(filename);
		while (getline(input, temp, ' '))//go through every entry of the file
		{
			if (index / maxUsernameFileIndex >= memberIndex)//finds the current staffindex, if it is greater or equal move on
				if ((index - memberIndex * maxUsernameFileIndex) > fieldIndex)//compares the column indices, if it is greater then move on
				{
					v2.push_back(temp);
					v2.push_back(" ");//append a space after every entry
				}
			index++;//iterate index counter after logic has passed
		}
		input.close();


		//recreate staff data file
		ofstream output;
		output.open(filename);
		for (int i = 0; i < static_cast<int>(v1.size()); i++)//put all of v1 back into the staff data file
		{
			temp = v1.at(i);
			output << temp;
		}
		output << newData;//put the new info into the file
		output << ' ';
		for (int i = 0; i < static_cast<int>(v2.size()); i++)//put all of v2 back into the end staff data file
		{
			temp = v2.at(i);
			output << temp;
		}
		output.close();
		//}
		//catch() ACCESS DENIED: MISSING EDIT PERMISSIONS
	}

	string getInmateInfo(int inmateIndex, int fieldIndex)//inmate index= file row, field index= file column
	{
		string data = "ERROR: NO DATA FOUND (getInmateInfo)";//assigned a string to ensure that something is returned
		//try {
		ifstream input("Inmate_Data.txt");//open the inamte data file
		for (int i = 0; i <= inmateIndex; i = i++)//iterate for every row until the inmate index is reached
		{
			string unused;//throwaway string to iterate inputs
			if (i == inmateIndex)//if the current index is the desired inmate row
			{
				for (int j = 0; j < inmateMaxIndices; j++)//iterate thrugh columns
					if (j == fieldIndex)//if current column is the correct field index
						input >> data;//take input into data string
					else//if incorrect column, put data into unused datafield;
						input >> unused;
			}
			for (int j = 0; j < inmateMaxIndices; j++)//while i (row) does not equal the inmate index, throw away each column entry
				input >> unused;
		}
		input.close();
		//}
		//catch() FILE ACCESS EXCEPTION (incorrect permissions)
		//catch() staff index out of range (tries to iterate past end of file)

		return data;
	}

	void setInmateInfo(int inmateIndex, int fieldIndex, string newData)
	{

		vector<string> v1;//vector for first half of data
		string temp;//string to put input into vector
		vector<string> v2;//vector for second half of data

	//try{
	//Save all of the data into vectors to update it
		//save first half of data to a vector
		ifstream input("Inmate_Data.txt");
		for (int i = 0; i <= inmateIndex; i++)//iterate for every row until the staff index is reached
		{
			for (int j = 0; j < inmateMaxIndices; j++)//iterate through columns
			{
				if (i != inmateIndex)//if it is not the correct index yet, put the data into the vector
				{
					input >> temp;
					v1.push_back(temp);
					v1.push_back(" ");//append a space after every entry
				}
				else if (i == inmateIndex)//if it equals the staff index
				{
					if (j == fieldIndex)//check if the column index is correct
						break;//break out of inner loop, the next loop will end
					else if (j != fieldIndex)
					{
						input >> temp;
						v1.push_back(temp);
						v1.push_back(" ");//append a space after every entry
					}
				}

			}
		}
		input.close();

		//save second half of data to a vector
		int index = 0;
		input.open("Inmate_Data.txt");
		while (getline(input, temp, ' '))//go through every entry of the file
		{
			if (index / inmateMaxIndices >= inmateIndex)//finds the current staffindex, if it is greater or equal move on
				if ((index - inmateIndex * inmateMaxIndices) > fieldIndex)//compares the column indices, if it is greater then move on
				{
					v2.push_back(temp);
					v2.push_back(" ");//append a space after every entry
				}
			index++;//iterate index counter after logic has passed
		}
		input.close();


		//recreate inmate data file
		ofstream output;
		output.open("Inmate_Data.txt");
		for (int i = 0; i < v1.size(); i++)//put all of v1 back into the inmate data file
		{
			temp = v1.at(i);
			output << temp;
		}
		output << newData;//put the new info into the file
		output << ' ';
		for (int i = 0; i < v2.size(); i++)//put all of v2 back into the end inmate data file
		{
			temp = v2.at(i);
			output << temp;
		}
		output.close();
		//}
		//catch() ACCESS DENIED: MISSING EDIT PERMISSIONS
	}

private:
	void Check(string entry); //Check password
};
#endif
