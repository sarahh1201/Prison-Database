/*
#pragma once
#ifndef V4_USERDATABASEFUNCTIONS_H
#define V4_USERDATABASEFUNCTIONS_H
#include "V4_User.h"
//#include "RangeException.h"
#include <sstream>
#include <vector>


string getUserInfo( int userFileNumber, int memberIndex, int fieldIndex)
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

void setStaffInfo( int userFileNumber, int memberIndex, int fieldIndex, string newData)
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

void createUserFile(int userFileNumber)
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
		ss << "firstname" << i;
		v2.push_back(ss.str());
	}

	vector<string> v3;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << "lastname" << i;
		v3.push_back(ss.str());
	}

	vector<string> v4;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << "govID" << i;
		v4.push_back(ss.str());
	}

	vector<string> v5;
	for (int i = 0; i < 20; i++)
	{
		stringstream ss;
		ss << "userID" << i;
		v5.push_back(ss.str());
	}

	string temp;
	ofstream output;
	output.open(filename);
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

		temp = v4.at(i);
		output << temp;
		output << ' ';

		temp = v5.at(i);
		output << temp;
		output << ' ';
	}
	output.close();
}
#endif
*/
