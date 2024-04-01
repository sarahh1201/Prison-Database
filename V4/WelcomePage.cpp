#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "V4_Staff.h"
#include "V4_Inmate.h"
#include "V4_User.h"
#include "Customize.h"

using namespace std;

void createStaffDataFile()
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
        if (i % 2 == 0)
            ss << "A";
        else
            ss << "B";
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
void createInmateDataFile(int numberOfAccounts)
{
    vector<string> v1;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        ss << i;
        v1.push_back(ss.str());
    }

    vector<string> v2;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        ss << "lawyerName" << i;
        v2.push_back(ss.str());
    }

    vector<string> v3;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        ss << "sentenceLength" << i;
        v3.push_back(ss.str());
    }

    vector<string> v4;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        ss << "probationDate" << i;
        v4.push_back(ss.str());
    }

    vector<string> v5;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        ss << "incarDate" << i;
        v5.push_back(ss.str());
    }

    vector<string> v6;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        ss << "cellNum" << i;
        v6.push_back(ss.str());
    }

    vector<string> v7;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        ss << "cellBlock" << i;
        v7.push_back(ss.str());
    }

    vector<string> v8;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        ss << "roommateID" << i;
        v8.push_back(ss.str());
    }

    vector<string> v9;
    for (int i = 0; i < numberOfAccounts; i++)
    {
        stringstream ss;
        if (i % 2 != 0)//uneven index is assigned schedule group A
            ss << "C" << i;
        else
            ss << "D" << i;
        v9.push_back(ss.str());
    }

    string temp;

    ofstream output;
    output.open("Inmate_Data.txt");
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

        temp = v6.at(i);
        output << temp;
        output << ' ';

        temp = v7.at(i);
        output << temp;
        output << ' ';

        temp = v8.at(i);
        output << temp;
        output << ' ';

        temp = v9.at(i);
        output << temp;
        output << ' ';
    }
    output.close();
}
void createUsernameFiles()
{
    vector<string> v1;//index
    for (int i = 0; i < 20; i++)
    {
        stringstream ss;
        ss << i;
        v1.push_back(ss.str());
    }

    vector<string> v2;//username
    for (int i = 0; i < 20; i++)
    {
        stringstream ss;
        ss << "name" << i;
        v2.push_back(ss.str());
    }

    vector<string> v3;//password
    for (int i = 0; i < 20; i++)
    {
        stringstream ss;
        ss << "pass" << i;
        v3.push_back(ss.str());
    }

    string temp;

    ofstream output;//staff username file
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

    output.open("Inmate_Usernames.txt");//inmate username file
    for (int i = 0; i < static_cast<int>(v1.size()); i++)//put into file rotating vectors
    {
        temp = v1.at(i);
        output << temp;
        output << ' ';

        temp = v2.at(i);
        output << 'I';//inmate username template is Iname#
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
void welcome();
void prisonerView(string& user, Inmate& object);
void staffView(string& user, Staff& object, bool edited);
void displaySchedule(string filename, string scheduleType);


int main()
{
    createStaffDataFile();
    createInmateDataFile(20);
    createUsernameFiles();
    createUserFile(0);
    createUserFile(1);
    welcome();
    return 0;
}

//Welcome screen and different user views
void welcome()
{
    bool edited = false;
    //Main welcome page
    allBorders("Welcome!");
    cout << endl;
    topBorders("1. Login");
    bottomBorders("2. Exit");

    int option;
    cin >> option;

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
        topBorders("1. Prisoner");
        bottomBorders("2. Staff");
        cin >> view;

        while (option != 1 && option != 2)
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
            if (user.getUserID() != "erroruserID")
                prisonerView(name, user);
            else if (user.getUserID() == "erroruserID")
            {
                cout << "\nUsername or password incorrect. Enter any key to continue.";
                string cont;
                cin >> cont;
            }
            clearScreen();
            break;
        }
        else if (view == 2)
        {
            Staff user;
            user = user.staffLogin(name, password);
            if (user.getUserID() != "erroruserID")
                staffView(name, user, edited);
            else if (user.getUserID() == "erroruserID")
            {
                cout << "\nUsername or password incorrect. Enter any key to continue.";
                string cont;
                cin >> cont;
            }
            clearScreen();
            break;
        }

        break;
    }
    case 2: // Exits the program
    {
        exit(0);
        break;
    }
    }
    welcome();
}
void prisonerView(string& user, Inmate& object)
{
    clearScreen();
    colourize("Welcome ", 34), colourize(user, 34), colourize("!", 34);
    cout << endl;

    //Manager selection menu
    allBorders("Select an option:");
    cout << endl;
    topBorders("1. Prisoner info");
    midBorders("2. View schedule");
    bottomBorders("3. Logout");

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
        cout << "Account Information"
            << "\n1. Username: " << user
            << "\n2. First Name:" << object.getFirstname()
            << "\n3. Last Name:" << object.getLastname()
            << "\n4. Government ID: " << object.getGovID()
            << "\n5. User ID:" << object.getUserID()
            << "\n6. Lawyer Name:" << object.getLawyerName()
            << "\n7. Probation Date:" << object.getProbationDate()
            << "\n8. Incarceration Date:" << object.getIncarDate()
            << "\n9. Cell Number:" << object.getCellNum()
            << "\n10. Cell Block:" << object.getCellBlock()
            << "\n11. Roommate ID:" << object.getRoommateID()
            << "\n12. Schedule Group:" << object.getScheduleGroup()
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
        }
        break;
    }
    case 2: //View schedule
    {
        clearScreen();
        displaySchedule("Schedule.txt", object.getScheduleGroup());

        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            displaySchedule("Schedule.txt", object.getScheduleGroup());
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }
        if (exit == 1)
        {
            clearScreen();
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
    prisonerView(user, object);
}
void staffView(string& user, Staff& object, bool edited)
{
    clearScreen();
    colourize("Welcome ", 36), colourize(user, 36), colourize("!", 36);

    displayBlocks(); //Cell block info
    cout << endl;

    //Manager selection menu
    allBorders("Select an option:");
    cout << endl;
    topBorders("1. View schedule");
    midBorders("2. View User Info");
    midBorders("3. Edit User Info");
    bottomBorders("4. Logout");

    cout << "Option: ";
    int option;
    cin >> option;

    while (option < 1 || option>4) {
        cout << "Invalid input." << endl;
        cin >> option;
    }

    switch (option) {
    case 1: //View Schedule
    {
        clearScreen();
        displaySchedule("Schedule.txt", object.getScheduleGroup());

        cout << "Enter 1 to go back: ";
        int exit;
        cin >> exit;

        while (exit != 1)
        {
            clearScreen();
            displaySchedule("Schedule.txt", object.getScheduleGroup());
            cout << "Invalid input!" << endl;
            cout << "Enter 1 to go back: ";
            cin >> exit;
        }

        if (exit == 1)
        {
            clearScreen();
        }

        break;
    }
    case 2: //View User Info
    {

        cout << "Account Information"
            << "\nUsername: " << user
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
        }
        break;
    }
    case 3://Edit User Info
    {

        clearScreen();

        cout << "Select an option: "
            << "\n1. Edit Personal Data"
            << "\n2. Edit Inmate Data"
            << "\n3. Edit Staff Data"
            << "\n4. Delete an account"
            << "\n5. Create an account"
            << "\n6. Return" << endl;

        cout << "Option: ";
        cin >> option;

        while (option < 1 || option>6) {
            cout << "Invalid input. Please enter a valid option. " << endl;
            cin >> option;
        }
        switch (option)//Choose Account type to edit
        {
        case 1: //Edit personal data
        {
            clearScreen();
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
                    {
                        object.setUsername(data);
                        edited = true;
                    }
                    else
                        cout << "Username " << data << " is already in use.";
                    break;
                }
                case 2://First name
                {
                    cout << "Please enter your first name: ";
                    cin >> data;
                    object.setFirstname(data);
                    edited = true;
                    break;
                }
                case 3://Last name
                {
                    cout << "Please enter your last name: ";
                    cin >> data;
                    object.setLastname(data);
                    edited = true;
                    break;
                }
                case 4://Government ID
                {
                    cout << "Please enter new Government ID Number: ";
                    cin >> data;
                    object.setGovID(data);
                    edited = true;
                    break;
                }
                case 5://User ID
                {
                    cout << "Please enter new User ID: ";
                    cin >> data;
                    object.setUserID(data);
                    edited = true;
                    break;
                }
                case 6://Position
                {
                    cout << "Please enter new Position: ";
                    cin >> data;
                    object.setPosition(data);
                    edited = true;
                    break;
                }
                case 7://Schedule Group
                {
                    cout << "Please enter new Schedule Group: ";
                    cin >> data;
                    object.setScheduleGroup(data);
                    edited = true;
                    break;
                }
                case 8://-----------------------------------Return------------------------
                {     
                clearScreen();
                break;
                }
                }
            break;
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
                clearScreen();
                cout << "Select an option:";
                cout << "\n1. Username: " << data;
                cout << "\n2. First Name:" << object.getUserInfo(1, inmateIndex, 1);
                cout << "\n3. Last Name:" << object.getUserInfo(1, inmateIndex, 2);
                cout << "\n4. Government ID: " << object.getUserInfo(1, inmateIndex, 3);
                cout << "\n5. User ID:" << object.getUserInfo(1, inmateIndex, 4);
                cout << "\n6. Lawyer Name:" << object.getInmateInfo(inmateIndex, 1);
                cout << "\n7. Probation Date:" << object.getInmateInfo(inmateIndex, 2);
                cout << "\n8. Incarceration Date:" << object.getInmateInfo(inmateIndex, 3);
                cout << "\n9. Cell Number:" << object.getInmateInfo(inmateIndex, 4);
                cout << "\n10. Cell Block:" << object.getInmateInfo(inmateIndex, 5);
                cout << "\n11. Roommate ID:" << object.getInmateInfo(inmateIndex, 6);
                cout << "\n12. Schedule Group:" << object.getInmateInfo(inmateIndex, 7);
                cout << "\n13. Return" << endl;

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
                    break;
                }
                }
            }
            else
            {
                cout << "\nUsername does not exist. " << endl;
                int a;
                cout << "\nEnter a number to continue.";
                cin >> a;
            }
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
                    << "\n6. Position:" << object.getStaffInfo(staffInd, 1)
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
                    staffView(user, object, edited);
                    break;
                }
                }
            }
            else
                cout << "\nUsername does not exist. " << endl;
            break;
        }
        case 4://delete an account
        {
            clearScreen();

            cout << "Enter the type of account you are deleting. (1: Inmate, 2: Staff 3: Exit): ";
            int accType;
            cin >> accType;
            while (accType > 3 || accType < 1)
            {
                cout << "\nInvalid input. Please try again: ";
                cin >> accType;
            }
            if (accType == 3)
                staffView(user, object, edited);

            cout << "\nEnter the username of the account: ";
            string deleteAcc;
            cin >> deleteAcc;

            cout << "Are you sure you want to delete " << deleteAcc << "? (y/n)";
            char ans;
            cin >> ans;

            while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N')
            {
                cout << "\nInvalid Input: Please enter again." << endl;
                cin >> ans;
            }
            if (ans == 'y' || ans == 'Y')
            {
                object.deleteAccount(deleteAcc, (accType - 1));
            }
            break;
        }
        case 5://create an account
        {
            clearScreen();

            if (edited)
            {
                char ans;
                cout << "\nAny changes must be saved before deleting an account. Would you like to save any changes? (y/n)" << endl;
                cin >> ans;
                while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N')
                {
                    cout << "\nInvalid Input: Please enter again." << endl;
                    cin >> ans;
                }
                if (ans == 'y' || ans == 'Y')
                {
                    object.save(user);
                    cout << "\nSaved successfully.";
                }
                edited = false;
            }

            cout << "\nPlease enter the type of account you are creating. (1: Inmate, 2: Staff, 3: Exit): ";
            int accType;
            cin >> accType;
            string temp;
            while (accType < 1 || accType>3)
            {
                cout << "\nInvalid input. Please try again.";
                cin >> accType;
            }
            if (accType == 3)
                staffView(user, object, edited);
            object.createAccount(accType - 1);
            break;
        }
        case 6: //Return to staff view
        {
            clearScreen();
            break;
        }
        }
        break;
    }
    case 4: //Logout
    {
        clearScreen();
        if (edited)
        {
            char ans;
            cout << "\nWould you like to save any changes? (y/n)" << endl;
            cin >> ans;
            while (ans != 'y' && ans != 'n' && ans != 'Y' && ans != 'N')
            {
                cout << "\nInvalid Input: Please enter again." << endl;
                cin >> ans;
            }
            if (ans == 'y' || ans == 'Y')
            {
                object.save(user);
                cout << "\nSaved successfully.";
            }
            edited = false;
        }

        object.~Staff();
        return;
        break;
    }
    }
    staffView(user, object, edited);
}

// display schedule for the specific range
void displaySchedule(string filename, string scheduleType) {
    // set values based on schedule type
    int startLine;
    int endLine;


    char st[10];//character array to reassign string, larger than original string to prevent errors

    strcpy_s(st, scheduleType.c_str());

    switch (st[0]) {
    case 'A': {
        // staff schedule 1
        startLine = 0;
        endLine = 7;
        break;
    }
    case 'B': {
        // staff schedule 2
        startLine = 8;
        endLine = 15
            ;
        break;
    }
    case 'C': {
        // inmate schedule 1
        startLine = 16;
        endLine = 23
            ;
        break;
    }
    case 'D': {
        // inmate schedule 2
        startLine = 25;
        endLine = 32;
        break;
    }
    default: {
        // error message
        cerr << "Invalid schedule type" << endl;
        return;
    }
    }

    // open the file
    ifstream file(filename);

    if(file.is_open()) {
        // header columns with ANSI codes
        cout << "-------------------------------------------------------------" << endl;
        cout << "| \033[1;36mHour\033[0m   | \033[1;36mTask\033[0m                                        |" << endl;// display header
        cout << "-------------------------------------------------------------" << endl;

        // read file -- in terms if lines
        string line;
        int count = 0;
        while (getline(file, line)) {
            // skip line
            if (count < startLine) {
                count++;
                continue;
            }
            // stop displaying lines
            if (count > endLine) {
                break;
            }
            // hour and task information from the line and display with ANSI codes 
            // convert string into int
            int hour = stoi(line.substr(0, 2));
            // display with ANSI color codes
            cout << "| \033[3m" << setw(5) << left << hour << "\033[0m | \033[1;33m" << line.substr(8) << "\033[0m |"
                << endl;
            cout << "-------------------------------------------------------------" << endl;
            count++; // loop until all desired lines of the txt are displayed 
        }

        // close file
        file.close();
    }
    else {
        // error message
        cerr << "Failed to open file: " << filename << endl;
    }
}
