#ifndef INMATEDATABASEFUNCTIONS_H
#define INMATEDATABASEFUNCTIONS_H
#include "Inmate.h"
#include <string>
#include <fstream>
#include "UserDatabaseFunctions.h"

using namespace std;

string getInmateInfo(bool canGetInmateInfo, int inmateIndex, int fieldIndex)//inmate index= file row, field index= file column
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
void setInmateInfo(bool canSetInmateInfo, int inmateIndex, int fieldIndex, string newData)
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

Inmate logInfo(string username, string password)
{
		ifstream input("Inmate_Usernames.txt");//open the usernames and password file (order of info is: index, username, password)
		//look for the username
		int i = 0;
		string inUsername;
		int staffIndex;
		bool match = false;
		while (getline(input, inUsername, ' '))
		{

			string inPassword;
			if ((i % maxUsernameFileIndex) / 1 == 1)//skip every entry that is not usernames 
				if (inUsername == username)//if the usernames match
				{
					input >> inPassword;//take in the next entry into passwords
					i++;
					//try{ make the below a compare function that throws the excpetion
					if (inPassword == password)//if the passwords match
					{
						int index = i / maxUsernameFileIndex;
						input.close();
						string userData[maxIndices];
						string inmateData[inmateMaxIndices];


						for (int j = 0; j < maxIndices; j++)
							userData[j] = getUserInfo(true, 0, index, j);


						for (int j = 0; j < inmateMaxIndices; j++)
							inmateData[j] = getInmateInfo(true, index, j);

						return Inmate(true, index, userData, inmateData);
					}
					//}
					//catch() PASSWORDS DONT MATCH
				}
			i++;
		}
		input.close();
	
}
#endif

