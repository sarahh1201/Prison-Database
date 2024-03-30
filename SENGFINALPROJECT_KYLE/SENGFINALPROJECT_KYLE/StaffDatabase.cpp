#include "StaffDatabase.h"

using namespace std;

//!valid file name!
StaffDatabase::StaffDatabase(string fileName) //reads staff info from file and saves it to the staffs vector
{
	this->fileName = fileName;

	ifstream staffsFile(fileName);
	string currFileLine;

	while (getline(staffsFile, currFileLine)) //dual finction: checks if there is a next line and saves it to currFIleLine
	{
		istringstream iss(currFileLine); //converts the current line of the file to an istream such that the >> operator can be used

		staffs.push_back(Staff()); //adds a default staff to the staffs vector

		iss >> staffs[staffs.size() - 1]; //writes the current line of the file to the staff that was just created
	}
	staffCount = staffs.size();

	staffsFile.close();
}

int StaffDatabase::login() const //facilitates login (returns -1 on invalid credentials)
{
	string username;
	string password;

	cout << "Enter username: ";
	cin >> username;

	int staffIndex = findStaffIndexbyUsername(username);  //searches database for inputted username (returns -1 on no match)

	cout << "Enter password: ";
	cin >> password;

	//control blocks written like this to keep from an erronious attempt to access staffs[-1]
	if (staffIndex != -1) //if no username match was found,,,
		if (password == staffs[staffIndex].getPassword()) //if password matches, return index found in username search,,,
			return staffIndex;

	return -1; //if no username match or passwords not match, return -1
}

int StaffDatabase::findStaffIndexbyUsername(string username) const
{
	for (int i = 0; i < staffs.size(); i++)
		if (username == staffs[i].getUsername())
			return i;

	return -1;
}

int StaffDatabase::findStaffIndexbyName(string name) const
{
	for (int i = 0; i < staffs.size(); i++)
		if (name == staffs[i].getName())
			return i;

	return -1;
}

//!valid index check!
Staff* StaffDatabase::getStaff(int index)
{
	return &staffs[index];
}

int StaffDatabase::getStaffCount() const
{
	return staffCount;
}

void StaffDatabase::addStaff(const Staff& staff)
{
	staffs.push_back(staff);

	staffCount = staffs.size();
}

//!valid index!
void StaffDatabase::deleteStaff(int index)
{
	staffs[index] = staffs[staffs.size() - 1];

	staffs.pop_back();

	staffCount = staffs.size();
}

//!valid file name (create file if non-existent)!
void StaffDatabase::saveDatabase()
{
	ofstream out(fileName,ofstream::trunc);

	for (int i = 0; i < staffs.size(); i++)
		out << staffs[i];

	out.close();
}


//!valid file name (create file if non-existent)!
void StaffDatabase::setFileName(string fileName)
{
	this->fileName = fileName;
}