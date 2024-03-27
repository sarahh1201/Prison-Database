#pragma once
#ifndef V4_STAFFDATABASEFUNCTIONS_H
#define V4_STAFFDATABASEFUNCTIONS_H
#include <string>
#include <fstream>
#include "V4_Staff.h"
#include <vector>
#include "V4_UserDatabaseFunctions.h"
#include <sstream>
using namespace std;



string getStaffInfo(/*bool canGetStaffInfo,*/ int staffIndex, int fieldIndex)//staff index= file row, field index= file column
{
	string data = "ERROR: NO DATA FOUND (getStaffInfo)";//assigned a string to ensure that something is returned
	//try {
	ifstream input("Staff_Data.txt");//open the staff data file
	for (int i = 0; i <= staffIndex; i++)//iterate for every row until the staff index is reached
	{
		string unused;//throwaway string to iterate inputs
		if (i == staffIndex)//if the current index is the desired staff row
		{
			for (int j = 0; j < staffMaxIndices; j++)//iterate thrugh columns
				if (j == fieldIndex)//if current column is the correct field index
					input >> data;//take input into data string
				else//if incorrect column, put data into unused datafield;
					input >> unused;
		}
		for (int j = 0; j < staffMaxIndices; j++)//while i does not equal the staff index, throw away each column entry
			input >> unused;
	}
	input.close();
	//}
	//catch() FILE ACCESS EXCEPTION (incorrect permissions)
	//catch() staff index out of range (tries to iterate past end of file)

	return data;
}

void setStaffInfo(/*bool canSetStaffInfo,*/ int staffIndex, int fieldIndex, string newData)
{
	vector<string> v1;//vector for first half of data
	string temp;//string to put input into vector
	vector<string> v2;//vector for second half of data

//try{
//Save all of the data into vectors to update it
	//save first half of data to a vector
	ifstream input("Staff_Data.txt");
	for (int i = 0; i <= staffIndex; i++)//iterate for every row until the staff index is reached
	{
		for (int j = 0; j < staffMaxIndices; j++)//iterate through columns
		{
			if (i != staffIndex)//if it is not the correct index yet, put the data into the vector
			{
				input >> temp;
				v1.push_back(temp);
				v1.push_back(" ");//append a space after every entry
			}
			else if (i == staffIndex)//if it equals the staff index
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
	input.open("Staff_Data.txt");
	while (getline(input, temp, ' '))//go through every entry of the file
	{
		if (index / staffMaxIndices >= staffIndex)//finds the current staffindex, if it is greater or equal move on
			if ((index - staffIndex * staffMaxIndices) > fieldIndex)//compares the column indices, if it is greater then move on
			{
				v2.push_back(temp);
				v2.push_back(" ");//append a space after every entry
			}
		index++;//iterate index counter after logic has passed
	}
	input.close();


	//recreate staff data file
	ofstream output;
	output.open("Staff_Data.txt");
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

void createTextFile()
{
	vector<string> v1;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << i;
		v1.push_back(ss.str());
	}

	vector<string> v2;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << "position" << i;
		v2.push_back(ss.str());
	}

	vector<string> v3;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << "schedule" << i;
		v3.push_back(ss.str());
	}
	string temp;

	ofstream output;
	output.open("Staff_Data.txt");
	for (int i = 0; i < static_cast<int>(v1.size()); i++)//put vectors into file
	{
		temp = v1.at(i);
		output << temp;
		output << ' ';

		temp = v2.at(i);
		output << temp;
		output << ' ';

		temp = v3.at(i);
		output << temp;
		output << ' ';
	}
	output.close();
}

void createUsernameFile()
{

	vector<string> v1;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << i;
		v1.push_back(ss.str());
	}

	vector<string> v2;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << "name" << i;
		v2.push_back(ss.str());
	}

	vector<string> v3;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << "pass" << i;
		v3.push_back(ss.str());
	}


	string temp;

	ofstream output;
	output.open("Staff_Usernames.txt");
	for (int i = 0; i < static_cast<int>(v1.size()); i++)//put into file rotating vectors
	{
		temp = v1.at(i);
		output << temp;
		output << ' ';

		temp = v2.at(i);
		output << temp;
		output << ' ';

		temp = v3.at(i);
		output << temp;
		output << ' ';
	}
	output.close();
}


//login functions, after login CHECK username FOR "errorusername"
Staff staffLogin(string username, string password)
{
	ifstream input("Staff_Usernames.txt");//open the usernames and password file (order of info is index, username, password)
	//look for the username
	int i = 0;
	string inUsername;
	while (getline(input, inUsername, ' '))
	{
		string inPassword;
		if ((i % maxUsernameFileIndex) / 1 == 1)//skip every entry that is not usernames 
			if (inUsername == username)//if the usernames match
			{
				input >> inPassword;//take in the next entry into passwords
				i++;
				if (inPassword == password)//if the passwords match
				{
					int index = i / maxUsernameFileIndex;
					input.close();
					string userData[maxIndices];
					string staffData[staffMaxIndices];


					for (int j = 0; j < maxIndices; j++)
						userData[j] = getUserInfo(/*true,*/ 0, index, j);


					for (int j = 0; j < staffMaxIndices; j++)
						staffData[j] = getStaffInfo(/*true,*/ index, j);

					return Staff(index, userData, staffData);
				}
			}
		i++;
	}
	input.close();
	return Staff();
}



//hasnt been tested, will also need to loop back to login screen. 
void staffLogOut(Staff* currentStaff)//delete the current object and return to login menu
{
	delete currentStaff;
}
#endif
