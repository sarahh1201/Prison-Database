#include "StaffDatabase.h"
#include "PrisonerDatabase.h"
#include <stdlib.h>

using namespace std;

static PrisonerDatabase Prisoner_Database("PrisonerDataFile.txt");
static StaffDatabase Staff_Database("StaffDataFile.txt");
static string theVoid;

void addPrisoner()
{
	string name;
	string username;
	string password;
	int sentenceYrs;
	int incarceratedYrs = 0;
	int cellNumber;
	char cellBlock;

	cout << "Please enter prisoner's name: ";
	cin >> name;

	cout << "Please enter prisoner's sentance in years: ";
	cin >> sentenceYrs;

	cout << "Please enter prisoner's time incarcerated (default = 0): ";
	cin >> incarceratedYrs;

	cout << "Please enter prisoner's cell block: ";
	cin >> cellBlock;

	cout << "Please enter prisoner's cell number: ";
	cin >> cellNumber;

	cout << "Please enter prisoner's username: ";
	cin >> username;

	cout << "Please enter prisoner's password: ";
	cin >> password;

	Prisoner_Database.addPrisoner(Prisoner(name, username, password, sentenceYrs, incarceratedYrs, cellNumber, cellBlock));
}

void removePrisoner()
{
	int toRemoveIndex;

	cout << "Please enter the index of the prisoner you would like to remove: ";
	cin >> toRemoveIndex;

	Prisoner_Database.deletePrisoner(toRemoveIndex);
}

void getPrisonerInfo()
{
	int prisonerIndex;
	int dataFieldIndex;

	cout << "Please enter the index of the prisoner who's info you wish to access: ";
	cin >> prisonerIndex;

	system("CLS");

	cout << "\nWhich datafield would you like to access?";
	cout << "\n    1.  Name\n    2.  Username\n    3.  Password\n    4.  Sentence length\n    5.  Years incarcerated\n    6.  Cell";
	cout << "\n\nSelection: ";
	cin >> dataFieldIndex;

	system("CLS");

	switch (dataFieldIndex)
	{
	case 1:
		cout << "The name of user #" << prisonerIndex << " is: " << Prisoner_Database.getPrisoner(prisonerIndex)->getName();
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 2:
		cout << "The username of user #" << prisonerIndex << " is: " << Prisoner_Database.getPrisoner(prisonerIndex)->getUsername();
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 3:
		cout << "The password of user #" << prisonerIndex << " is: " << Prisoner_Database.getPrisoner(prisonerIndex)->getPassword();
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 4:
		cout << "The sentence length user #" << prisonerIndex << " is: " << Prisoner_Database.getPrisoner(prisonerIndex)->getSentenceYrs() << " years";
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 5:
		cout << "User #" << prisonerIndex << " has been incarcerated for: " << Prisoner_Database.getPrisoner(prisonerIndex)->getName() << " years";
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 6:
		cout << "The cell of user #" << prisonerIndex << " is: " << Prisoner_Database.getPrisoner(prisonerIndex)->getCellBlock() << "-" << Prisoner_Database.getPrisoner(prisonerIndex)->getCellNumber();
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	default:
		break;
	}
}

void setPrisonerInfo()
{
	{
		int prisonerIndex;
		int dataFieldIndex;
		string toIn;
		string toIn2;

		cout << "Please enter the index of the prisoner who's info you wish to change: ";
		cin >> prisonerIndex;

		system("CLS");

		cout << "Which datafield would you like to change?";
		cout << "\n    1.  Name\n    2.  Username\n    3.  Password\n    4.  Sentence length\n    5.  Years incarcerated\n    6.  Cell";
		cout << "\n\nSelection: ";
		cin >> dataFieldIndex;

		system("CLS");

		switch (dataFieldIndex)
		{
		case 1:
			cout << "Please enter new name: ";
			cin >> toIn;
			Prisoner_Database.getPrisoner(prisonerIndex)->setName(toIn);
			break;

		case 2:
			cout << "Please enter new username: ";
			cin >> toIn;
			Prisoner_Database.getPrisoner(prisonerIndex)->setUsername(toIn);
			break;

		case 3:
			break;

		case 4:
			cout << "Please enter new sentence length: ";
			cin >> toIn;
			Prisoner_Database.getPrisoner(prisonerIndex)->setSentenceYrs(stoi(toIn));
			break;

		case 5:
			cout << "Please enter new incarceration duration: ";
			cin >> toIn;
			Prisoner_Database.getPrisoner(prisonerIndex)->setIncarceratedYrs(stoi(toIn));
			break;

		case 6:
			cout << "Please enter new cell block: ";
			cin >> toIn;
			cout << "Please enter new cell number: ";
			cin >> toIn2;
			Prisoner_Database.getPrisoner(prisonerIndex)->setCell(stoi(toIn2),toIn[0]);
			break;

		default:
			break;
		}
	}
}

void findPrisonerIndex()
{
	int prisonerIndex;
	int findTypeIndex;
	string toFind;

	cout << "Would you like to find the prisoner index by:";
	cout << "\n    1.  Name\n    2.  Username";
	cout << "\n\nSelection: ";
	cin >> findTypeIndex;

	system("CLS");

	cout << "Please enter your query: ";
	cin >> toFind;

	system("CLS");

	if (--findTypeIndex)
	{
		prisonerIndex = Prisoner_Database.findPrisonerIndexbyUsername(toFind);

		cout << toFind << "'s prisoner index is: " << ((prisonerIndex != -1) ? string{char(prisonerIndex + 48)} : "not found");

		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
	}
	else
	{
		prisonerIndex = Prisoner_Database.findPrisonerIndexbyName(toFind);

		cout << toFind << "'s prisoner index is: " << ((prisonerIndex != -1) ? string{ char(prisonerIndex - 48) } : "not found");

		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;

		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
	}

}

void addStaff()
{
	string name;
	string username;
	string password;
	bool adminPrivlege;
	double hourlyWage;
	int weeklyHours;

	cout << "Please enter staff member's name: ";
	cin >> name;

	cout << "Please enter staff member's username: ";
	cin >> username;

	cout << "Please enter staff member's password: ";
	cin >> password;

	cout << "Please enter staff member's hourly wage: $";
	cin >> hourlyWage;

	cout << "Please enter staff member's weekly hours: ";
	cin >> weeklyHours;

	cout << "Please enter 1 if staff has admin privlege and 0 if not: ";
	cin >> adminPrivlege;

	Staff_Database.addStaff(Staff(name, username, password, hourlyWage, weeklyHours, adminPrivlege));
}

void removeStaff()
{
	int toRemoveIndex;

	cout << "Please enter the index of the staff member you would like to remove: ";
	cin >> toRemoveIndex;

	Staff_Database.deleteStaff(toRemoveIndex);
}

void getStaffInfo()
{
	int staffIndex;
	int dataFieldIndex;

	cout << "Please enter the index of the staff member who's info you wish to access: ";
	cin >> staffIndex;

	system("CLS");

	cout << "\nWhich datafield would you like to access?";
	cout << "\n    1.  Name\n    2.  Username\n    3.  Password\n    4.  Sentence length\n    5.  Years incarcerated\n    6.  Cell";
	cout << "\n\nSelection: ";
	cin >> dataFieldIndex;

	system("CLS");

	switch (dataFieldIndex)
	{
	case 1:
		cout << "The name of user #" << staffIndex << " is: " << Staff_Database.getStaff(staffIndex)->getName();
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 2:
		cout << "The username of user #" << staffIndex << " is: " << Staff_Database.getStaff(staffIndex)->getUsername();
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 3:
		cout << "The password of user #" << staffIndex << " is: " << Staff_Database.getStaff(staffIndex)->getPassword();
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 4:
		cout << "The hourly wage of user #" << staffIndex << " is: $" << Staff_Database.getStaff(staffIndex)->getHourlyWage();
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 5:
		cout << "User #" << staffIndex << " works " << Staff_Database.getStaff(staffIndex)->getWeeklyHours() << " hours every week";
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	case 6:
		cout << "User #" << staffIndex << (Staff_Database.getStaff(staffIndex)->getAdminPrivlege() ? " has " : " does not have ") << "admin privlege";
		cout << "\n\nType anything, then hit enter to continue: ";
		cin >> theVoid;
		break;

	default:
		break;
	}
}

void setStaffInfo()
{
	{
		int staffIndex;
		int dataFieldIndex;
		string toIn;

		cout << "Please enter the index of the staff member who's info you wish to change: ";
		cin >> staffIndex;

		system("CLS");

		cout << "Which datafield would you like to change?";
		cout << "\n    1.  Name\n    2.  Username\n    3.  Password\n    4.  Hourly wage\n    5.  Weekly hours\n    6.  Admin privlege";
		cout << "\n\nSelection: ";
		cin >> dataFieldIndex;

		system("CLS");

		switch (dataFieldIndex)
		{
		case 1:
			cout << "Please enter new name: ";
			cin >> toIn;
			Staff_Database.getStaff(staffIndex)->setName(toIn);
			break;

		case 2:
			cout << "Please enter new username: ";
			cin >> toIn;
			Staff_Database.getStaff(staffIndex)->setUsername(toIn);
			break;

		case 3:
			cout << "Please enter new password: ";
			cin >> toIn;
			Staff_Database.getStaff(staffIndex)->setPassword(toIn);
			break;

		case 4:
			cout << "Please enter new hourly wage: $";
			cin >> toIn;
			Staff_Database.getStaff(staffIndex)->setHourlyWage(stod(toIn));
			break;

		case 5:
			cout << "Please enter new amount of hours per week: ";
			cin >> toIn;
			Staff_Database.getStaff(staffIndex)->setWeeklyHours(stoi(toIn));
			break;

		case 6:
			cout << "Please enter 1 for admin privlege and 0 for no admin privlege: ";
			cin >> toIn;
			Staff_Database.getStaff(staffIndex)->setAdminPrivlege(stoi(toIn));
			break;

		default:
			break;
		}
	}
}

//excpt's, no comments
void findStaffIndex()
{
	string staffIndexString;
	int staffIndex;
	int findTypeIndex = -1;
	string toFind;

	cout << "Would you like to find the staff index by:";
	cout << "\n    1.  Name\n    2.  Username";
	cout << "\n\nSelection: ";
	cin >> staffIndexString;

	try
	{
		findTypeIndex = stoi(staffIndexString);
	}
	catch (invalid_argument&)
	{
		system("CLS");
		cout << "Invalid input \"" << staffIndexString << "\": press enter to continue";
		theVoid = getchar();
		theVoid = getchar();
	}

	system("CLS");

	if (findTypeIndex != -1)
		if (findTypeIndex > 2 || findTypeIndex < 1)
		{
			cout << "Index \"" << findTypeIndex << "\" out of range: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		else
		{
			cout << "Please enter your query: ";
			cin >> toFind;

			system("CLS");

			if (findTypeIndex == 1)
			{
				staffIndex = Staff_Database.findStaffIndexbyUsername(toFind);

				cout << toFind << "'s staff index is: " << ((staffIndex != -1) ? string{ char(staffIndex + 48) } : "not found");

				cout << "\n\nType anything, then hit enter to continue: ";
				theVoid = getchar();
				theVoid = getchar();
			}
			else if (findTypeIndex == 0)
			{
				staffIndex = Staff_Database.findStaffIndexbyName(toFind);

				cout << toFind << "'s staff index is: " << ((staffIndex != -1) ? string{ char(staffIndex - 48) } : "not found");

				cout << "\n\nType anything, then hit enter to continue: ";
				theVoid = getchar();
				theVoid = getchar();

				cout << "\n\nType anything, then hit enter to continue: ";
				theVoid = getchar();
				theVoid = getchar();
			}
		}
	

}

//excpt's, no comments
bool prisonerDashboard(Prisoner& user)
{
	string commandIndexString;
	int commandIndex = -1;
	string cellNumberIn;
	string cellBlockIn;

	cout << "Welcome to the prisoner dashboard!";
	cout << "\n\n    Name: " << user.getName() << "\n    Cell: " << user.getCellBlock() << "-" << user.getCellNumber() << "\n    Years Left: " << user.getRemainingSentence();
	cout << "\n\n\n\nWould You like to:\n    1.  Request a cell change\n    2.  Return home";
	cout << "\n\nSelection: ";
	cin >> commandIndexString;

	try
	{
		commandIndex = stoi(commandIndexString);
	}
	catch (exception&){}

	switch (commandIndex)
	{
	//!valid values!
	case 1:
		system("CLS");
		cout << "Please enter your desired new cell block: ";
		cin >> cellBlockIn;
		cout << "Please enter your desired new cell number: ";
		cin >> cellNumberIn;

		system("CLS");

		if (cellBlockIn.size() == 1)
		{
			if (isalpha(cellBlockIn[0]))
			{
				try
				{
					user.setCell(stoi(cellNumberIn), toupper(cellBlockIn[0]));

					cout << "Success! You will be relocated shortly to cell: " << user.getCellBlock() << "-" << user.getCellNumber();
					cout << "\n\nPress enter to continue";
				}
				catch (const invalid_argument&)
				{
					cout << "Invalid cell number \"" << cellNumberIn << "\": press enter to go back";
				}
			}
			else
				cout << "Invalid cell block\"" << cellBlockIn[0] << "\": press enter to go back";

		}
		else
			cout << "Cell block input \"" << cellBlockIn << "\" too long: press enter to go back";

		theVoid = getchar();
		theVoid = getchar();

		Prisoner_Database.saveDatabase();

		break;

	case 2:
		return false;

	default:
		break;
	}

	return true;
}

//excpt's, no comments
bool staffDashboard(Staff& user)
{
	string commandIndexString;
	int commandIndex = -1;

	cout << "Welcome to the staff dashboard!";
	cout << "\n\n    Name: " << user.getName() << "\n    Hourly: $" << user.getHourlyWage() << "\n    Weekly Hours: " << user.getWeeklyHours();
	cout << "\n\n\n\nWould you like to: (Actions 1-4 require a prisoner index, find one with Action 5 & Actions 6-9 require a prisoner index, find one with Action 10)";
	cout << "\n    1.  Add a prisoner\n    2.  Remove a prisoner\n    3.  See a prisoner's info\n    4.  Change a prisoner's info\n    5.  Find a prisoner's index";
	cout << "\n    6.  Add a staff member\n    7.  Remove a staff member\n    8.  See a staff member's info\n    9.  Change a staff member's info\n    10. Find a staff member's index";
	cout << "\n    11. SAVE and return to home";
	cout << "\n\nSelection: ";
	cin >> commandIndexString;

	try
	{
		commandIndex = stoi(commandIndexString);
	}
	catch (exception&) {}

	system("CLS");

	switch (commandIndex)
	{
	case 1:
		addPrisoner();
		break;
	case 2:
		if (Prisoner_Database.getPrisonerCount())
			removePrisoner();
		else
		{
			cout << "Not enough prisoners: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		break;
	case 3:
		if (Prisoner_Database.getPrisonerCount())
			getPrisonerInfo();
		else
		{
			cout << "Not enough prisoners: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		break;
	case 4:
		if (Prisoner_Database.getPrisonerCount())
			setPrisonerInfo();
		else
		{
			cout << "Not enough prisoners: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		break;
	case 5:
		if (Prisoner_Database.getPrisonerCount())
			findPrisonerIndex();
		else
		{
			cout << "Not enough prisoners: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		break;
	case 6:
		addStaff();
		break;
	case 7:
		if (Staff_Database.getStaffCount() > 1 && user.getAdminPrivlege())
			removeStaff();
		else if (user.getAdminPrivlege())
		{
			cout << "Not enough staff: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		else
		{
			cout << "You don't have the right to do this: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		break;
	case 8:
		if (user.getAdminPrivlege())
			getStaffInfo();
		else
		{
			cout << "You don't have the right to do this: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		break;
	case 9:
		if (user.getAdminPrivlege())
			setStaffInfo();
		else
		{
			cout << "You don't have the right to do this: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		break;
	case 10:
		if (user.getAdminPrivlege())
			findStaffIndex();
		else
		{
			cout << "You don't have the right to do this: press enter to go back";
			theVoid = getchar();
			theVoid = getchar();
		}
		break;
	case 11:
		Prisoner_Database.saveDatabase();
		Staff_Database.saveDatabase();
		return false;
	default:
		break;
	}

	return true;
}

//excpt's, no comments
int main()
{
	string prisonerOrStaffString;
	int prisonerOrStaff;
	int userIndex;

	while (true)
	{
		prisonerOrStaff = -1;

		system("CLS");

		cout << "Welcome to the home screen!";
		cout << "\n\nWould you like to sign in as: \n    1.  Prisoner\n    2.  Staff";
		cout << "\n\nSelection: ";
		cin >> prisonerOrStaffString;

		try
		{
			prisonerOrStaff = stoi(prisonerOrStaffString);
		}
		catch (exception&) {}

		system("CLS");

		if (prisonerOrStaff == 2)
		{
			cout << "Staff Login:\n\n";

			userIndex = Staff_Database.login();
			while (userIndex == -1)
			{
				system("CLS");
				cout << "Invalid login credentials; please try again\n\n";

				userIndex = Staff_Database.login();
			}

			do
				system("CLS");
			while (staffDashboard(*Staff_Database.getStaff(userIndex)));
		}
		else if (prisonerOrStaff == 1)
		{
			cout << "Prisoner Login:\n\n";

			userIndex = Prisoner_Database.login();
			while (userIndex == -1)
			{
				system("CLS");
				cout << "Invalid login credentials; please try again\n\n";

				userIndex = Prisoner_Database.login();
			}

			do
				system("CLS");
			while (prisonerDashboard(*Prisoner_Database.getPrisoner(userIndex)));
		}
	}

	return 0;
}