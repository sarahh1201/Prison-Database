#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "V4_Staff.h"
#include "V4_Inmate.h"
#include "V4_User.h"

using namespace std;

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

int main()
{
	createTextFile();
	cout << "Text File" << endl;
	createUsernameFile();
	cout << "Username File" << endl;
	createUserFile(0);
	cout << "User File" << endl;
	Staff staff1;
	cout << "Staff object" << endl;

	staff1 = staff1.staffLogin("name3", "pass3");
	cout << "Updated Staff Object" << endl;

	cout << "First name: " << staff1.getFirstname() << endl;
	cout << "Last name: " << staff1.getLastname() << endl;

	cout << "Position: " << staff1.getPosition() << endl;
	cout << "Schedule: " << staff1.getScheduleGroup() << endl;

	cout << "Gov ID: " << staff1.getGovID() << endl;
	cout << "User ID: " << staff1.getUserID() << endl;
	cout << "User Index: " << staff1.getUserIndex() << endl;
	cout << "Username: " << staff1.getUsername() << endl;
	cout << "Password: " << staff1.getPassword() << endl;

	return 0;
}
