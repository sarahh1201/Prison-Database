#include "V4_Staff.h"
#include "V4_StaffDatabaseFunctions.h"
void create(string userData[], vector<string> objectData, string username, string password, string usernameFile, string userFile, string dataFile)
{
	string userIndex;
	ofstream output;
	output.open(usernameFile, ios::app);
	output << userData[0] << " " << username << " " << password << " ";
	output.close();

	output.open(userFile, ios::app);
	for (int i = 0; i < maxIndices; i++)
		output << userData[i] << " ";
	output.close();

	output.open(dataFile, ios::app);
	output << userData[0] << " ";
	for (int i = 0; i < static_cast<int>(objectData.size()); i++)
		output << objectData.at(i) << " ";
	output.close();
}

Staff::Staff()
{
	position = "N/A";
	scheduleGroup = "N/A";
}
Staff::Staff(int userIndex, string userData[], string staffData[])
{
	//staff fields
	position = staffData[1];
	scheduleGroup = staffData[2];
	//user fields
	this->userIndex = userIndex;
	firstname = userData[1];
	lastname = userData[2];
	username = "username";//default settings, if changed then username will be updated
	password = "password";//default setting, if changed then username will be updated
	govID = userData[3];
	userID = userData[4];
}

string Staff::getPosition()
{
	return position;
}
string Staff::getScheduleGroup()
{
	return scheduleGroup;
}

void Staff::setScheduleGroup(string scheduleGroup)
{
	this->scheduleGroup = scheduleGroup;
}
void Staff::setPosition(string position)
{
	this->position = position;
}

void Staff::deleteAccount(string username, int accountType)
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
		cout << "\nUsername " << username << "does not exist on file. Failed to delete account. Enter 1 to exit.";
		int go;
		cin >> go;
		return;
	}

	switch (accountType)
	{
	case 0: {inmateCount--; break; }
	case 1: {staffCount--; break; }
	}

	input.open(dataFile);//--------------------------------------------------------------SAVE AND RECREATE ACCOUNT TYPE DATA FILE---------------

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
	position = (index+1) * maxDataIndex; //current position index 
	while (getline(input, temp, ' '))
	{
		if ((position % maxDataIndex) == 0)//if the index field is reached, correct the index
		{
			stringstream ss;
			input >> temp;
			int p = position / maxDataIndex;
			ss << p;
			v2.push_back(ss.str());
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

	input.open(userFile);//-----------------------------------------SAVE AND RECREATE USER DATA FILE----------------------------------------

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
		input >> temp;
	}
	//save second half of data to vector
	int i = (index+1) * maxIndices;
	while (getline(input, temp, ' '))
	{
		if ((i % maxIndices) == 0)//if the index field is reached, correct the index
		{
			input >> temp;
			stringstream ss;
			ss << i/maxIndices;
			v2.push_back(ss.str());
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

	//---------------------------------------------------------------------------------SAVE AND RECREATE USERNAME FILE---------------------------------
	input.open(usernameFile);
	v1.clear();//clear vector for first half of data
	v2.clear();//clear vector for second half of data

//save first half of data to vector
	for (int i = 0; i < index; i++)//iterate for every row until the index is reached
	{
		for (int j = 0; j < maxUsernameFileIndex; j++)//iterate through columns
		{
			input >> temp;
			v1.push_back(temp);
			v1.push_back(" ");//append a space after every entry
		}
	}
	//throw away the line that is being deleted
	for (int i = 0; i < maxUsernameFileIndex; i++)
	{
		input >> temp;
	}
	//save second half of data to vector
	int u = (index + 1) * maxUsernameFileIndex;
	while (getline(input, temp, ' '))
	{
		if ((i % maxIndices) == 0)//if the index field is reached, correct the index
		{
			input >> temp;
			stringstream ss;
			ss << u / maxUsernameFileIndex;
			v2.push_back(ss.str());
		}
		else//save regular data
		{
			v2.push_back(temp);
			v2.push_back(" ");//append space after entry
		}
		u++;
	}
	input.close();

	//recreate user file
	output.open(usernameFile);
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
void Staff::createAccount(int accountType)
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
	cin >> userData[1];
	cout << "\nPlease enter the last name: ";
	cin >> userData[2];
	cout << "\nPlease enter the government ID number: ";
	cin >> userData[3];
	cout << "\nPlease enter the user ID number: ";
	cin >> userData[4];

	vector<string> objectData;
	string userFile, dataFile;
	string temp;
	switch (accountType)//decide which file to pull from
	{
	case 0: {
		userFile += "Inmate_Users.txt";
		dataFile += "Inmate_Data.txt";
		inmateCount++;
		stringstream ss;
		ss << (inmateCount - 1);
		userData[0] = ss.str();

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
		stringstream ss;
		ss << (staffCount - 1);
		userData[0] = ss.str();

		cout << "\nPlease enter the staff member's position name: ";
		cin >> temp;
		objectData.push_back(temp);
		cout << "\nPlease enter the staff schedule group: ";
		cin >> temp;
		objectData.push_back(temp);
		break;
	}
	}
	
	create(userData, objectData, newUsername, p, usernameFile, userFile, dataFile);
}

Staff Staff::staffLogin(string username, string password)
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
string Staff::getStaffInfo(int staffIndex, int fieldIndex)//staff index= file row, field index= file column
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
void Staff::setStaffInfo(int staffIndex, int fieldIndex, string newData)

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

void Staff::save(string username)
{
	int userIndex = staffGetUserIndex(0, username);
	if (userIndex == -1)
	{
		cout << "Staff Error encountered. Please log out or correct username. Did not successfully save.";
		return;
	}

	//save username if it has been updated
	if (getUsername() != "username")
	{
		if (getUsername() == "errorusername")//default username, error has occured if present
		{
			cout << "\nStaff Error encountered. Please log out or correct username. Did not successfully save.";
			return;
		}
		setUsernameInfo(0, userIndex, 1, getUsername());
	}

	//save password if it has been updated
	if (getPassword() != "password")
	{
		if (getUsername() == "errorpassword")//default password, error has occured if present
		{
			cout << "\nStaff Error encountered. Please log out or correct password. Did not successfully save.";
			return;
		}
		setUsernameInfo(0, userIndex, 2, getPassword());
	}

	setStaffInfo(userIndex, 1, getPosition());
	setStaffInfo(userIndex, 2, getScheduleGroup());

	setUserInfo(0, userIndex, 1, getFirstname());
	setUserInfo(0, userIndex, 2, getLastname());
	setUserInfo(0, userIndex, 3, getGovID());
	setUserInfo(0, userIndex, 4, getUserID());

	cout << "\nSaved";
}

void Staff::operator=(Staff newStaff)
{
	userIndex = newStaff.getUserIndex();
	position = newStaff.getPosition();
	scheduleGroup = newStaff.getScheduleGroup();
	firstname = newStaff.getFirstname();
	lastname = newStaff.getLastname();
	username = newStaff.getUsername();
	password = newStaff.getPassword();
	govID = newStaff.getGovID();
	userID = newStaff.getUserID();

}
