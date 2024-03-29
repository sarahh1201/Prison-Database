#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "V4_Staff.h"
#include "V4_Inmate.h"
#include "V4_User.h"
#include "Customize.h"

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


void displaySchedule(string filename)
{
    cout << "\ndisplaySchedule to be implemented" << endl;
}

//different user views
void prisonerView(string& user, Inmate& object)
{
    clearScreen();
    colourize("Welcome ", 34), colourize(user, 34), colourize("!", 34);
    cout << endl;

    //Manager selection menu
    cout << "\nSelect an option: " << endl;
    cout << "1. Prisoner info";
    cout << "\n2. View schedule"
        << "\n3. Logout"
        << endl;

    cout << "Option: ";
    int option;
    cin >> option;

    while (option != 1 && option != 2 && option != 3)
    {
        cout << "Invalid input." << endl;
        cin >> option;
    }

    switch (option)
    {
    case 1: //Personal info
    {
        clearScreen();
        //Function

        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }
        if (exit == 1)
        {
            clearScreen();
            prisonerView(user, object);
        }
        break;
    }
    case 2: //View schedule
    {
        clearScreen();
        string filename = "InmateSchedule.txt";
        displaySchedule(filename);


        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            displaySchedule(filename);
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }
        if (exit == 1)
        {
            clearScreen();
            prisonerView(user, object);
        }

        break;
    }
    case 3: //Logout
    {
        clearScreen();
        object.~Inmate();
        return;
        break;
    }
    }
}
void staffView(string& user, Staff& object) {
    clearScreen();
    colourize("Welcome ", 34), colourize(user, 34), colourize("!", 34);

    int prisoners = 3600;
    int blocks[2][4] = { {65,   66,   67,  68},
                        {1000, 1000, 700, 900} };

    cout << "\nNo. Prisoners: " << prisoners << endl; //Number of prisoners

    //Cell Block Information
    cout << "\nCell Block Capacities" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Block " << (char)blocks[0][i] << ": " << blocks[1][i] << endl;
    }

    //--------------------------------------------------------------------Staff Selection Menu 1--------------------------------------------------------------------------------------
    cout << "\nSelect an option: " << endl;
    cout << "1. Prisoner info"
        << "\n2. View Schedule"
        << "\n3. View User Info"
        << "\n4. Edit User Info"
        << "\n5. Logout"
        << endl;

    cout << "Option: ";
    int option;
    cin >> option;

    while (option <1 ||option>5) {
        cout << "Invalid input." << endl;
        cin >> option;
    }

    switch (option) {
    case 1: //----------------------------Prisoner info
    {
        clearScreen();
        //Call prisoner function
        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }

        if (exit == 1)
        {
            clearScreen();
            staffView(user, object);
        }
        break;
    }
    case 2: //----------------------------View Schedule
    {
        clearScreen();
        string filename = "StaffSchedule.txt";
        displaySchedule(filename);

        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            displaySchedule(filename);
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }

        if (exit == 1)
        {
            clearScreen();
            staffView(user, object);
        }

        break;
    }
    case 3://-----------------------------View User Info
    {
        cout << "Account Information"
            << "\nUsername: "<< user
            << "\nFirst Name: " << object.getFirstname()
            << "\nLast Name: " << object.getLastname()
            << "\nGovernment ID: " << object.getGovID()
            << "\nUser ID: " << object.getUserID()
            << "\nPosition: " << object.getPosition()
            << "\nSchedule Group: " << object.getScheduleGroup()
            << "\nEnter 1 to return" << endl;
            int exit;
            cin >> exit;

            while (exit != 1)
            {
                clearScreen();
                cout << "Invalid input!" << endl;
                cout << "Enter 1 to go back: ";
                cin >> exit;
            }

            if (exit == 1)
            {
                clearScreen();
                staffView(user, object);
            }
        break;
    }
    case 4: //----------------------------Edit Info
    {
        clearScreen();

        cout << "Select an option: "
            << "\n1. Edit Personal Data"
            << "\n2. Edit Inmate Data"
            << "\n3. Edit Staff Data"
            << "\n4. Return" << endl;

        cout << "Option: ";
        cin >> option;

        while (option != 1 && option != 2 && option != 3 && option != 4) {
            cout << "Invalid input. Please enter a valid option. " << endl;
            cin >> option;
        }
        switch (option)//Choose Account type to edit
        {
        case 1: //Edit personal data
        {
            char ans = 'x';
            do {
                cout << "Select a field to edit: "
                    << "\n1. Username"
                    << "\n2. First Name: " << object.getFirstname()
                    << "\n3. Last Name: " << object.getLastname()
                    << "\n4. Government ID: " << object.getGovID()
                    << "\n5. User ID: " << object.getUserID()
                    << "\n6. Position: " << object.getPosition()
                    << "\n7. Schedule Group: " << object.getScheduleGroup()
                    << "\n8. Return" << endl;

                cout << "Option: ";
                cin >> option;

                while (option > 8 || option < 1)
                {
                    cout << "Invalid input. Please enter a valid option. " << endl;
                    cin >> option;
                }

                string data;
                switch (option)//Choose Edit Field
                {
                case 1://Username
                {
                    cout << "Please enter your new username: ";
                    cin >> data;
                    if (object.newUsername(0, data))
                        object.setUsername(data);
                    else
                        cout << "Username " << data << " is already in use.";
                    staffView(user, object);
                    break;
                }
                case 2://First name
                {
                    cout << "Please enter your first name: ";
                    cin >> data;
                    object.setFirstname(data);
                    staffView(user, object);
                    break;
                }
                case 3://Last name
                {
                    cout << "Please enter your last name: ";
                    cin >> data;
                    object.setLastname(data);
                    staffView(user, object);
                    break;
                }
                case 4://Government ID
                {
                    cout << "Please enter new Government ID Number: ";
                    cin >> data;
                    object.setGovID(data);
                    staffView(user, object);
                    break;
                }
                case 5://User ID
                {
                    cout << "Please enter new User ID: ";
                    cin >> data;
                    object.setUserID(data);
                    staffView(user, object);
                    break;
                }
                case 6://Position
                {
                    cout << "Please enter new Position: ";
                    cin >> data;
                    object.setPosition(data);
                    staffView(user, object);
                    break;
                }
                case 7://Schedule Group
                {
                    cout << "Please enter new Schedule Group: ";
                    cin >> data;
                    object.setScheduleGroup(data);
                    staffView(user, object);
                    break;
                }
                case 8://-----------------------------------Return-------------------------------CURRENT TESTING POINT-------------------
                {        cout << "\nWould you like to save any changes? (y/n)" << endl;
                cin >> ans;
                while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N')
                {
                    cout << "\nInvalid Input: Please enter again." << endl;
                    cin >> ans;
                }
                if (ans == 'y' || ans == 'Y')
                {object.save();}
                    clearScreen();
                    staffView(user, object);
                    break;
                }
                }
                break;
            } while (ans != 'y' || ans != 'Y' || ans!='n' || ans!='N');
        }
        case 2: //Edit inmate data
        {
            clearScreen();
            cout << "Enter username of account: ";
            string data;
            cin >> data;
           
            //Edit inmate data 
            if (!object.newUsername(1, data))
            {
                int inmateIndex = object.staffGetUserIndex(1, data);
                cout << "Select an option: "
                    << "\n1. Username: " << object.staffGetUsername(1, inmateIndex)
                    << "\n2. First Name:" << object.getUserInfo(1, inmateIndex, 1)
                    << "\n3. Last Name:" << object.getUserInfo(1, inmateIndex, 2)
                    << "\n4. Government ID: " << object.getUserInfo(1, inmateIndex, 3)
                    << "\n5. User ID:" << object.getUserInfo(1, inmateIndex, 4)
                    << "\n6. Lawyer Name:" <<object.getInmateInfo(inmateIndex, 1)
                    << "\n7. Probation Date:" << object.getInmateInfo(inmateIndex, 2)
                    << "\n8. Incarceration Date:" << object.getInmateInfo(inmateIndex, 3)
                    << "\n9. Cell Number:" << object.getInmateInfo(inmateIndex, 4)
                    << "\n10. Cell Block:" << object.getInmateInfo(inmateIndex, 5)
                    << "\n11. Roommate ID:" << object.getInmateInfo(inmateIndex, 6)
                    << "\n12. Schedule Group:" << object.getInmateInfo(inmateIndex, 7)
                    << "\n13. Return" << endl;

                cout << "Option: ";
                cin >> option;

                while (option > 13 || option < 1)
                {
                    cout << "Invalid input. Please enter a valid option. " << endl;
                    cin >> option;
                }

                //Choice of inmate Edits
                switch (option)
                {
                case 1://Username
                {
                    cout << "Please enter the new username: ";
                    cin >> data;
                    object.setUsernameInfo(1, inmateIndex, 1, data);
                    break;
                }
                case 2://First name
                {
                    cout << "Please enter first name: ";
                    cin >> data;
                    object.setUserInfo(1, inmateIndex, 1, data);
                    break;
                }
                case 3://Last name
                {
                    cout << "Please enter last name: ";
                    cin >> data;
                    object.setUserInfo(1, inmateIndex, 2, data);
                    break;
                }
                case 4://Government ID
                {
                    cout << "Please enter new Government ID Number: ";
                    cin >> data;
                    object.setUserInfo(1, inmateIndex, 3, data);
                    break;
                }
                case 5://User ID
                {
                    cout << "Please enter new User ID: ";
                    cin >> data;
                    object.setUserInfo(1, inmateIndex, 4, data);
                    break;
                }
                case 6://Lawyer last name
                {
                    cout << "Please enter new lawyer last name: ";
                    cin >> data;
                    object.setInmateInfo(inmateIndex, 1, data);
                    break;
                }
                case 7://Probation Date
                {
                    cout << "Please enter new probation date: ";
                    cin >> data;
                    object.setInmateInfo(inmateIndex, 2, data);
                    break;
                }
                case 8://Incarceration Date
                {
                    cout << "Please enter new incarceration date: ";
                    cin >> data;
                    object.setInmateInfo(inmateIndex, 3, data);
                    break;
                }
                case 9://Cell Number
                {
                    cout << "Please enter new cell number: ";
                    cin >> data;
                    object.setInmateInfo(inmateIndex, 4, data);
                    break;
                }
                case 10://Cell Block
                {
                    cout << "Please enter new cell block: ";
                    cin >> data;
                    object.setInmateInfo(inmateIndex, 5, data);
                    break;
                }
                case 11://Roommate ID
                {
                    cout << "Please enter new Roommate ID: ";
                    cin >> data;
                    object.setInmateInfo(inmateIndex, 6, data);
                    break;
                }
                case 12://Schedule Group
                {
                    cout << "Please enter new schedule group: ";
                    cin >> data;
                    object.setInmateInfo(inmateIndex, 7, data);
                    break;
                }
                case 13://Return
                {
                    clearScreen();
                    staffView(user, object);
                    break;
                }
                }
            }
            else
                cout << "\nUsername does not exist. " << endl;
            break;
        }
        case 3: //Edit staff data
        {
            clearScreen();
            cout << "Enter username of account: ";
            string data;
            cin >> data;

            //Edit staff data 
            if (!object.newUsername(0, data))
            {
                int staffInd = object.staffGetUserIndex(0, data);
                cout << "Select an option: "
                    << "\n1. Username: " << object.staffGetUsername(0, staffInd)
                    << "\n2. First Name:" << object.getUserInfo(0, staffInd, 1)
                    << "\n3. Last Name:" << object.getUserInfo(0, staffInd, 2)
                    << "\n4. Government ID: " << object.getUserInfo(0, staffInd, 3)
                    << "\n5. User ID:" << object.getUserInfo(0, staffInd, 4)
                    << "\n6. Position:" << object.getStaffInfo(staffInd,1)
                    << "\n7. Schedule Group:" << object.getStaffInfo(staffInd, 2)
                    << "\n8. Return" << endl;

                cout << "Option: ";
                cin >> option;

                while (option > 8 || option < 1)
                {
                    cout << "Invalid input. Please enter a valid option. " << endl;
                    cin >> option;
                }

                //Choice of staff Edits
                switch (option)
                {
                case 1://Username
                {
                    cout << "Please enter the new username: ";
                    cin >> data;
                    object.setUsernameInfo(0, staffInd, 1, data);
                    break;
                }
                case 2://First name
                {
                    cout << "Please enter first name: ";
                    cin >> data;
                    object.setUserInfo(0, staffInd, 1, data);
                    break;
                }
                case 3://Last name
                {
                    cout << "Please enter last name: ";
                    cin >> data;
                    object.setUserInfo(0, staffInd, 2, data);
                    break;
                }
                case 4://Government ID
                {
                    cout << "Please enter new Government ID Number: ";
                    cin >> data;
                    object.setUserInfo(0, staffInd, 3, data);
                    break;
                }
                case 5://User ID
                {
                    cout << "Please enter new User ID: ";
                    cin >> data;
                    object.setUserInfo(0, staffInd, 4, data);
                    break;
                }
                case 6://Position
                {
                    cout << "Please enter new position: ";
                    cin >> data;
                    object.setInmateInfo(staffInd, 1, data);
                    break;
                }
                case 7://Schedule Group
                {
                    cout << "Please enter new schedule group: ";
                    cin >> data;
                    object.setInmateInfo(staffInd, 2, data);
                    break;
                }
                case 8://Return
                {
                    clearScreen();
                    staffView(user, object);
                    break;
                }
                }
            }
            else
                cout << "\nUsername does not exist. " << endl;
            break;
        }
        case 4: //Return to staff view
        {
            clearScreen();
            staffView(user, object);
            break;
        }
        }
    }
    case 5: //Logout
    {
        clearScreen();
        object.~Staff();
        return;
        break;
    }
    }
}
void managerView(string& user) {
    clearScreen();
    colourize("Welcome ", 34), colourize(user, 34), colourize("!", 34);

    int prisoners = 3600;
    int blocks[2][4] = { {65,   66,   67,  68},
                        {1000, 1000, 700, 900} };

    cout << "\nNo. Prisoners: " << prisoners << endl; //Number of prisoners

    //Cell Block Information
    cout << "\nCell Block Capacities" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Block " << (char)blocks[0][i] << ": " << blocks[1][i] << endl;
    }

    //Manager selection menu
    cout << "\nSelect an option: " << endl;
    cout << "1. View Schedule" << "\n2. Personal info" << "\n3. Prisoner info" << "\n4. Manage People" << "\n5. Logout" << endl;

    cout << "Option: ";
    int option;
    cin >> option;

    while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5) {
        cout << "Invalid input." << endl;
        cin >> option;
    }

    switch (option) {
    case 1:
    {
        clearScreen();
        string filename = "ManagerSchedule.txt";
        displaySchedule(filename);

        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            displaySchedule(filename);
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }
        if (exit == 1)
        {
            clearScreen();
            managerView(user);
        }

        break;
    }
    case 2: //Personal info
    {
        //Personal info function
        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }
        if (exit == 1)
        {
            clearScreen();
            managerView(user);
        }
        break;
    }
    case 3: //Prisoner info
    {
        //Call prisoner function

        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }
        if (exit == 1)
        {
            clearScreen();
            managerView(user);
        }

        break;
    }
    case 4: // Manage People
    {
        clearScreen();
        int manage;
        cout << "1. Prisoners"
            << "\n2. Staff" << endl;
        cin >> manage;

        while (manage != 1 && manage != 2) {
            cout << "Invalid input." << endl;
            cin >> manage;
        }

        switch (manage)
        {
        case 1:
        {
            clearScreen();
            // Prisoners

            cout << "Enter 1 to go back: ";
            int exit;
            cin >> exit;

            while (exit != 1)
            {
                clearScreen();
                cout << "Invalid input!" << endl;
                cout << "Enter 1 to go back: ";
                cin >> exit;
            }
            if (exit == 1)
            {
                clearScreen();
                managerView(user);
            }
            break;
        }
        case 2:
        {
            clearScreen();
            //Staff

            cout << "Enter 1 to go back: ";
            int exit;
            cin >> exit;

            while (exit != 1)
            {
                clearScreen();
                cout << "Invalid input!" << endl;
                cout << "Enter 1 to go back: ";
                cin >> exit;
            }
            if (exit == 1)
            {
                clearScreen();
                managerView(user);
            }
            break;
        }

        default:
        {
            clearScreen();
            managerView(user);
            break;
        }
        }

        //Call edit function
        break;
    }
    case 5: //Logout of account and returns user back to welcome page
    {
        clearScreen();
        return;
        break;
    }
    }
}

int main()
{
    //testing functions
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

        staff1.~Staff();

//actual program
        bool inProgram = true;
        while (inProgram)//Welcome screen loop
        {
            //Main welcome page
            cout << "Welcome!" << endl;
            cout << "1. Login " << endl;
            cout << "2. Exit " << endl;

            int option;
            cin >> option;

            //Ensure valid option input
            while (option != 1 && option != 2)
            {
                cout << "Invalid input." << endl;
                cin >> option;
            }

            switch (option)
            {
            case 1: //Outputs the Login Page
            {
                clearScreen();
                int view;
                cout << "1. Prisoner \n2. Staff \n3. Manager" << endl;
                cin >> view;

                while (option != 1 && option != 2 && option != 3)
                {
                    cout << "Invalid input. Please enter a valid option" << endl;
                    cin >> view;
                }

                string name, password;
                clearScreen();

                cout << "Name: ";
                cin >> name;
                cout << "Password: ";
                cin >> password;
           
                //Call login function
                if (view == 1)
                {
                    Inmate user;
                    user = user.inmateLogin(name, password);
                    prisonerView(name, user);
                }
                else if (view == 2)
                {
                    Staff user;
                    user = user.staffLogin(name, password);
                    staffView(name, user);
                }
                else if (view == 3)
                {
                    Staff user;
                    user = user.staffLogin(name, password);
                    managerView(name);
                }

                break;
            }
            case 2: // Exits the program
            {
                inProgram = false;
                exit(0);
                break;
            }
            }
      }
       
	return 0;
}
