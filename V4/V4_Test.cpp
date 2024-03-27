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
void prisonerView(string& user)
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
            prisonerView(user);
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
            prisonerView(user);
        }

        break;
    }
    case 3: //Logout
    {
        clearScreen();
        return;
        break;
    }
    }
}
void staffView(string& user) {
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
    cout << "1. Prisoner info"
        << "\n2. View Schedule"
        << "\n3. Logout"
        << endl;

    cout << "Option: ";
    int option;
    cin >> option;

    while (option != 1 && option != 2 && option != 3) {
        cout << "Invalid input." << endl;
        cin >> option;
    }

    switch (option) {
    case 1: //Prisoner info
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
            staffView(user);
        }
        break;
    }
    case 2: //View schedule
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
            staffView(user);
        }

        break;
    }
    case 3: //Logout
    {
        clearScreen();
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
                    cout << "Invalid input." << endl;
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
                    user.inmateLogin(name, password);
                    prisonerView(name);
                }
                else if (view == 2)
                {
                    Staff user;
                    user.staffLogin(name, password);
                    staffView(name);
                }
                else if (view == 3)
                {
                    Staff user;
                    user.staffLogin(name, password);
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
