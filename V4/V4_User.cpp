#include "V4_User.h"
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

string User::getUserInfo(int userFileNumber, int memberIndex, int fieldIndex)
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
string User::staffGetUsername(int userFileNumber, int memberIndex)
{
	string data = "ERROR: NO DATA FOUND (staffgetUsername)";//assigned a string to ensure that something is returned
	//try {
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
	ifstream input(filename);//open the correct user data file
	for (int i = 0; i <= memberIndex; i++)//iterate for every row until the user index is reached
	{
		string unused;//throwaway string to iterate inputs
		if (i == memberIndex)//if the current index is the desired user row
		{
			for (int j = 0; j < maxUsernameFileIndex; j++)//iterate through columns
				if (j == 1)//if current column is the correct field index
					input >> data;//take input into data string
				else//if incorrect column, put data into unused datafield;
					input >> unused;
		}
		for (int j = 0; j < maxUsernameFileIndex; j++)//while i does not equal the user index, throw away each column entry
			input >> unused;
	}
	input.close();
	//}
	//catch() FILE ACCESS EXCEPTION (incorrect permissions)
	//catch() staff index out of range (tries to iterate past end of file)

	return data;
}
int User::staffGetUserIndex(int userFileNumber, string user)
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
	while (getline(input, inUsername, ' '))
	{
		if ((position % maxUsernameFileIndex) == 1)//skip every entry that is not usernames 
			if (inUsername == user)//if the usernames match
			{
				return position / maxUsernameFileIndex;
			}
		position++;
	}
	return -1;
}

void User::setUserInfo(int userFileNumber, int memberIndex, int fieldIndex, string newData)
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
void User::setUsernameInfo(int userFileNumber, int memberIndex, int fieldIndex, string newData)
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

string User::getInmateInfo(int inmateIndex, int fieldIndex)//inmate index= file row, field index= file column
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
				{
					input >> data;//take input into data string
				}
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
void User::setInmateInfo(int inmateIndex, int fieldIndex, string newData)
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

bool User::newUsername(int userFileNumber, string username)//return true if username does not exsit on file
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
	bool match = true;
	ifstream input(usernameFile);//open the usernames and password file (order of info is index, username, password)
	int position = 0;
	while (getline(input, inUsername, ' '))
	{
		if ((position % maxUsernameFileIndex) == 1)//skip every entry that is not usernames 
			if (inUsername == username)//if the usernames match
			{
				input.close();
				match = false;//set match to true to allow loop to continue once
			}
		position++;
	}
	input.close();
	return match;
}

/*
void User::Check(string entry) //Should be comparing the inputed password to the actual password
{
	if (entry != entry) //If the password is wrong it would be thrown
		throw EntryException(entry);
}
*/
