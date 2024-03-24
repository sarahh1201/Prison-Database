#ifndef STAFFDATABASEFUNCTIONS_H
#define STAFFDATABASEFUNCTIONS_H
#include <string>
#include <fstream>
#include "Staff.h"
#include <vector>
using namespace std;



string getStaffInfo(bool canGetStaffInfo, int staffIndex, int fieldIndex)//staff index= file row, field index= file column
{
	string data = "ERROR: NO DATA FOUND (getStaffInfo)";//assigned a string to ensure that something is returned
	//try {
		ifstream input("Staff_Data.txt");//open the staff data file
		for (int i = 0; i <= staffIndex; i=i+maxIndices)//iterate for every row until the staff index is reached
		{
			string unused;//throwaway string to iterate inputs
			if (i == staffIndex)//if the current index is the desired staff row
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
	//}
	//catch() FILE ACCESS EXCEPTION (incorrect permissions)
	//catch() staff index out of range (tries to iterate past end of file)

	return data;
}
void setStaffInfo(bool canSetStaffInfo, int staffIndex, int fieldIndex, string newData)
{
	vector<string> v1;//vector for first half of data
	string temp;//string to put input into vector
	vector<string> v2;//vector for second half of data

//Save all of the data into vectors to update it
	//save first half of data to a vector
	ifstream input("Staff_Data.txt");
	for (int i = 0; i <= staffIndex; i = i + maxIndices)//iterate for every row until the staff index is reached
	{
		for (int j = 0; j < maxIndices; j++)//iterate through columns
		{
			if (i != staffIndex)//if it is not the correct index yet, put the data into the vector
			{
				input >> temp;
				v1.push_back(temp);
			}
			else if (i == staffIndex)//if it equals the staff index
				if (j == fieldIndex)//check if the column index is correct
					break;//break out of inner loop, the next loop will end
		}
	}
	input.close();

	//save second half of data to a vector
	int index = 0;
	ifstream input("Staff_Data.txt");
	while (getline(input, temp, ' '))//go through every entry of the file
	{
		if(index/maxIndices>=staffIndex)//finds the current staffindex, if it is greater or equal move on
			if ((index - staffIndex*maxIndices)> fieldIndex)//compares the column indices, if it is greater then move on
			{
				v2.push_back(temp);
			}
		index++;//iterate index counter after logic has passed
	}
	input.close();


	//recreate staff data file
	ofstream output;
	output.open("Staff_Data.txt");
	for (int i = 0; i < v1.size(); i++)//put all of v1 back into the staff data file
	{
		temp = v1.at(i);
		output << temp;
	}
	output << newData;//put the new info into the file
	for (int i = 0; i < v2.size(); i++)//put all of v2 back into the end staff data file
	{
		temp = v2.at(i);
		output << temp;
	}
	output.close();
}

//login functions NOT COMPLETE, UNCLEAR WHAT END GOAL IS
Staff login(string username, string password)
{
	ifstream input("Staff_Usernames.txt");//open the usernames and password file (order of info is index, username, password)
	//look for the username
	int i = 1;
	string inUsername;
	int staffIndex;
	while (getline(input,inUsername,' '))
	{
		string inPassword;
		i++;
		if((i/3)%2==0)//skip every entry that is not usernames 
			if (inUsername == username)//if the usernames match
			{
				input >> inPassword;//take in the next entry into passwords
				i++;
				//try{ make the below a compare function that throws the excpetion
				if (inPassword == password)//if the passwords match
				{


				}
				//}
				//catch() PASSWORDS DONT MATCH

			}
	}
	input.close();

}
#endif
