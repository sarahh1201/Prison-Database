#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "V4_StaffDatabaseFunctions.h"

using namespace std;



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

	staff1 = staffLogin("name3", "pass3");
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