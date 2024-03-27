#include "Manager.h"



Manager::Manager(bool canCreateStaff, int staffIndex, string userData[], string managerData[])
{
	//manager fields (same as a staff object)
	position = managerData[1];
	scheduleGroup = managerData[2];
	//user fields
	this->userIndex = userIndex;
	firstname = userData[1];
	lastname = userData[2];
	username = "username";//default settings, if changed then username will be updated
	password = "password";//default setting, if changed then username will be updated
	govID = userData[3];
	userID = userData[4];
}

void Manager::deleteAccount(string username, int accountType)
{

	string usernameFile, userFile, dataFile;
	int maxDataIndex;
	switch (accountType)//decide which file to pull from
	{
	case 0: {
		usernameFile += "Inmate_Usernames.txt";
		userFile += "Inmate_Users.txt";
		dataFile += "Inmate_Data.txt";
		maxDataIndex = inmateMaxIndices;
		break;
	}
	case 1: {
		usernameFile += "Staff_Usernames.txt";
		userFile += "Staff_Users.txt";
		dataFile += "Staff_Data.txt";
		maxDataIndex = staffMaxIndices;
		break;
	}
	case 2: {
		usernameFile += "Manager_Usernames.txt";
		userFile += "Manager_Users.txt";
		dataFile += "Manager_Data.txt";
		maxDataIndex = managerMaxIndices;
		break;
	}
	}

	ifstream input(usernameFile);//open the usernames and password file (order of info is index, username, password)
	int position = 0;
	int index = 0;
	string inUsername;
	bool match = false;
	//find user index
	while (getline(input, inUsername, ' '))
	{
		if ((position % maxUsernameFileIndex) == 1)//skip every entry that is not usernames 
			if (inUsername == username)//if the usernames match
			{
				index = position / maxUsernameFileIndex;
				input.close();
				match = true;
				break;
			}
		position++;
	}
	input.close();

	if (!match)//if no match was found, exit delete function
	{
		cout << "\nUsername "<<username<< "does not exist on file. Failed to delete account.";
		return;
	}

	switch (accountType)
	{
	case 0: {inmateCount--; break; }
	case 1: {staffCount--; break; }
	case 2: {managerCount--; break; }
	}

	input.open(dataFile);

	vector<string> v1;//vector for first half of data
	string temp;//string to put input into vector
	vector<string> v2;//vector for second half of data

//save first half of data to vector
	for (int i = 0; i < index; i++)//iterate for every row until the staff index is reached
	{
		for (int j = 0; j < maxDataIndex; j++)//iterate through columns
		{
			input >> temp;
			v1.push_back(temp);
			v1.push_back(" ");//append a space after every entry
		}
	}
	//throw away the line that is being deleted
	for (int i = 0; i < maxDataIndex; i++)
	{
		input >> temp;//throw away the line that is being deleted
	}
	//save second half of data to vector
	position = index * maxDataIndex; //current position index 
	while (getline(input, temp, ' '))
	{
		if ((position % maxDataIndex) == 0)//if the index field is reached, correct the index
		{
			stringstream ss;
			int p = position / maxDataIndex;
			ss << p;
			v2.push_back(ss.str());
			v2.push_back(" ");//append space after
		}
		else//save regular data
		{
			v2.push_back(temp);
			v2.push_back(" ");//append space after entry
		}
		position++;
	}
	input.close();

	//recreate data file
	ofstream output;
	output.open(dataFile);
	//put all of v1 back into the data file
	for (int i = 0; i < v1.size(); i++)
	{
		temp = v1.at(i);
		output << temp;
	}
	//put all of v2 back into the end data file
	for (int i = 0; i < v2.size(); i++)
	{
		temp = v2.at(i);
		output << temp;
	}
	output.close();

	input.open(userFile);

	v1.clear();//clear vector for first half of data
	v2.clear();//clear vector for second half of data

//save first half of data to vector
	for (int i = 0; i < index; i++)//iterate for every row until the index is reached
	{
		for (int j = 0; j < maxIndices; j++)//iterate through columns
		{
			input >> temp;
			v1.push_back(temp);
			v1.push_back(" ");//append a space after every entry
		}
	}
	//throw away the line that is being deleted
	for (int i = 0; i < maxIndices; i++)
	{
		input >> temp;//throw away the line that is being deleted
	}
	//save second half of data to vector
	int i = index * maxIndices;
	while (getline(input, temp, ' '))
	{
		if ((i % maxIndices) == 0)//if the index field is reached, correct the index
		{
			stringstream ss;
			ss << i;
			v2.push_back(ss.str());
			v2.push_back(" ");//append space after
		}
		else//save regular data
		{
			v2.push_back(temp);
			v2.push_back(" ");//append space after entry
		}
		i++;
	}
	input.close();

	//recreate user file
	output.open(userFile);
	//put all of v1 back into the user file
	for (int i = 0; i < v1.size(); i++)
	{
		temp = v1.at(i);
		output << temp;
	}
	//put all of v2 back into the end user file
	for (int i = 0; i < v2.size(); i++)
	{
		temp = v2.at(i);
		output << temp;
	}
	output.close();
}

void Manager::createAccount(int accountType)
{
	string usernameFile;
	switch (accountType)//decide which file to pull from
	{
	case 0: {
		usernameFile += "Inmate_Usernames.txt";
		break;
	}
	case 1: {
		usernameFile += "Staff_Usernames.txt";
		break;
	}
	case 2: {
		usernameFile += "Manager_Usernames.txt";
		break;
	}
	}

	
	string inUsername;
	bool match = false;
	string newUsername;
	cout << "\nPlease enter the username of the new account: ";
	cin >> newUsername;
	//find user index
	do
	{
		ifstream input(usernameFile);//open the usernames and password file (order of info is index, username, password)
		int position = 0;
		int index = 0;
		match = false;//reset match boolean
		while (getline(input, inUsername, ' '))
		{
			if ((position % maxUsernameFileIndex) == 1)//skip every entry that is not usernames 
				if (inUsername == newUsername)//if the usernames match
				{
					match = true;//set match to true to allow loop to continue once
					char c;
					cout << "\nUsername " << newUsername << " is already in use. Would you like to cancel account creation? (y/n)";
					cin >> c;
					if (c == 'y')
					{
						cout << "\nExiting account creation.";
						input.close();
						return;
					}
					else if (c == 'n')
					{
						cout << "\nPlease enter a new username: ";
						cin >> newUsername;
						input.close();//close file
						break;
					}
				}
			position++;
		} 
	} while (match);

	cout << "\nPlease enter a password: ";
	string p;
	cin >> p;

	string userData[maxIndices];
	cout << "\nPlease enter the first name: ";
	cin>>userData[1];
	cout << "\nPlease enter the last name: ";
	cin >> userData[2];
	cout << "\nPlease enter the government ID number: ";
	cin >> userData[3];
	cout << "\nPlease enter the user ID number: ";
	cin >> userData[4];

	vector<string> objectData;
	string userFile, dataFile;
	string temp;
	int maxDataIndex;
	switch (accountType)//decide which file to pull from
	{
	case 0: {
		userFile += "Inmate_Users.txt";
		dataFile += "Inmate_Data.txt";
		inmateCount++;
		userData[0] = inmateCount-1;
		stringstream ss;
		ss << (inmateCount - 1);
		objectData.push_back(ss.str());
		cout << "\nPlease enter the inmate's representative's last name: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the inmate's sentence length in months: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the inmate's probation date (mm/dd/yyyy): ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the inmate's incarceration date: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the inmate's cell number: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the inmate's cell block: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the inmate's roommate ID: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the inmate's schedule group: ";
		cin >> temp;
		objectData.push_back(temp);
		break;
	}
	case 1: {
		userFile += "Staff_Users.txt";
		dataFile += "Staff_Data.txt";
		staffCount++;
		userData[0] = staffCount-1;
		stringstream ss;
		ss << (staffCount - 1);
		objectData.push_back(ss.str());
		cout << "\nPlease enter the staff member's position name: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the staff schedule group: ";
		cin >> temp;
		objectData.push_back(temp);
		
		break;
	}
	case 2: {
		userFile += "Manager_Users.txt";
		dataFile += "Manager_Data.txt";
		managerCount++;
		userData[0] = managerCount-1;
		stringstream ss;
		ss << (managerCount - 1);
		objectData.push_back(ss.str());
		cout << "\nPlease enter the manager's position name: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the manager's schedule group: ";
		cin >> temp;
		objectData.push_back(temp);

		break;
	}
	}

	create(userData, objectData, newUsername, p, usernameFile, userFile, dataFile);
}
