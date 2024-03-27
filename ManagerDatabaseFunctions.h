#ifndef MANAGERDATABASEFUNCTIONS_H
#define MANAGERDATABASEFUNCTIONS_H
#include <string>
#include <fstream>
#include "Manager.h"
#include <vector>
#include "UserDatabaseFunctions.h"
using namespace std;

string getManagerInfo(bool canGetManagerInfo, int managerIndex, int fieldIndex)//manager index= file row, field index= file column
{
	string data = "ERROR: NO DATA FOUND (getManagerInfo)";//assigned a string to ensure that something is returned
	//try {
	ifstream input("Manager_Data.txt");//open the manager data file
	for (int i = 0; i <= managerIndex; i = i++)//iterate for every row until the manager index is reached
	{
		string unused;//throwaway string to iterate inputs
		if (i == managerIndex)//if the current index is the desired manager row
		{
			for (int j = 0; j < managerMaxIndices; j++)//iterate thrugh columns
				if (j == fieldIndex)//if current column is the correct field index
					input >> data;//take input into data string
				else//if incorrect column, put data into unused datafield;
					input >> unused;
		}
		for (int j = 0; j < managerMaxIndices; j++)//while i does not equal the manager index, throw away each column entry
			input >> unused;
	}
	input.close();
	//}
	//catch() FILE ACCESS EXCEPTION (incorrect permissions)
	//catch() staff index out of range (tries to iterate past end of file)

	return data;
}

void setManagerInfo(bool canSetManagerInfo, int managerIndex, int fieldIndex, string newData)
{
	vector<string> v1;//vector for first half of data
	string temp;//string to put input into vector
	vector<string> v2;//vector for second half of data

//try{
//Save all of the data into vectors to update it
	//save first half of data to a vector
	ifstream input("Manager_Data.txt");
	for (int i = 0; i <= managerIndex; i = i++)//iterate for every row until the staff index is reached
	{
		for (int j = 0; j < managerMaxIndices; j++)//iterate through columns
		{
			if (i != managerIndex)//if it is not the correct index yet, put the data into the vector
			{
				input >> temp;
				v1.push_back(temp);
				v1.push_back(" ");//append a space after every entry
			}
			else if (i == managerIndex)//if it equals the manager index
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
	input.open("Manager_Data.txt");
	while (getline(input, temp, ' '))//go through every entry of the file
	{
		if (index / managerMaxIndices >= managerIndex)//finds the current staffindex, if it is greater or equal move on
			if ((index - managerIndex * managerMaxIndices) > fieldIndex)//compares the column indices, if it is greater then move on
			{
				v2.push_back(temp);
				v2.push_back(" ");//append a space after every entry
			}
		index++;//iterate index counter after logic has passed
	}
	input.close();


	//recreate manager data file
	ofstream output;
	output.open("Manager_Data.txt");
	for (int i = 0; i < static_cast<int>(v1.size()); i++)//put all of v1 back into the manager data file
	{
		temp = v1.at(i);
		output << temp;
	}
	output << newData;//put the new info into the file
	output << ' ';
	for (int i = 0; i < static_cast<int>(v2.size()); i++)//put all of v2 back into the end manager data file
	{
		temp = v2.at(i);
		output << temp;
	}
	output.close();
	//}
	//catch() ACCESS DENIED: MISSING EDIT PERMISSIONS
}

Manager managerLogin(string username, string password)
{
	ifstream input("Manager_Usernames.txt");//open the usernames and password file (order of info is index, username, password)
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
				//try{ make the below a compare function that throws the excpetion
				if (inPassword == password)//if the passwords match
				{
					int index = i / maxUsernameFileIndex;
					input.close();
					string userData[maxIndices];
					string managerData[managerMaxIndices];


					for (int j = 0; j < maxIndices; j++)
						userData[j] = getUserInfo(true, 0, index, j);


					for (int j = 0; j < managerMaxIndices; j++)
						managerData[j] = getManagerInfo(true, index, j);

					return Manager(true, index, userData, managerData);
				}
				//}
				//catch() PASSWORDS DONT MATCH
			}
		i++;
	}
	input.close();
}

void create(string userData[], vector<string> objectData, string username, string password, string usernameFile, string userFile, string dataFile)
{
	string userIndex;
	ofstream output;
	output.open(usernameFile, ios::ate);
	output << userData[0]<<" " << username<<" " << password<< " ";
	output.close();

	output.open(userFile, ios::ate);
	for (int i = 0; i < maxIndices; i++)
		output << userData[i] << " ";
	output.close();

	output.open(dataFile, ios::ate);
	for (int i = 0; i < static_cast<int>(objectData.size()); i++)
		output << objectData.at(i) << " ";
	output.close();
}

//hasnt been tested, will also need to loop back to login screen. 
void logOut(Manager* currentManager)//delete the current object and return to login menu
{
	delete currentManager;
}

#endif
