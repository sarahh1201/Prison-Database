e "Customize.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

void welcome();
void prisonerView(string& user);
void staffView(string& user);
void managerView(string& user);

int main()
{
    welcome();

    return 0;
}
// added
// Function to get current date and time
string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // Format for date and time, using 24-hour format
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

void displaySchedule(const string& filename) {
    // Get the current date and time
    string currentDateTime = getCurrentDateTime();

    // Get the current hour
    time_t now = time(0);
    tm *ltm = localtime(&now);
    int currentHour = ltm->tm_hour;

    ifstream file(filename);
    if (file.is_open()) {
        cout << "Current as of: " << currentDateTime << endl; // Display current date and time
        cout << "-------------------------------------------------------------" << endl;
        cout << "| " << setw(5) << left << "Time" << " | " << setw(40) << left << "Tasks"  << endl;
        cout << "-------------------------------------------------------------" << endl;
        string line;
        int count = 0; // Counter for the number of time blocks displayed
        bool display = false; // Flag to track if display has started
        while (getline(file, line) && count < 8) {
            int hour = stoi(line.substr(0, 2));
            if (!display && hour >= currentHour) {
                display = true;
            }
            if (display && count < 8) {
                cout << "| " << setw(5) << left << line.substr(0, 5) << " | " << setw(40) << left << line.substr(8)  << endl;
                cout << "-------------------------------------------------------------" << endl;
                count++;
            }
        }
        file.close();
    } else {
        cerr << "Failed to open file: " << filename << endl;
    }
}
//end add
void welcome()
{
    //Main welcome page
    cout << "Welcome!" <<endl;
    cout << "1. Login " <<endl;
    cout << "2. Exit " <<endl;

    int option;
    cin >> option;

    while (option!=1&&option!=2)
    {
        cout << "Invalid input." <<endl;
        cin >> option;
    }

    switch(option)
    {
        case 1: //Outputs the Login Page
        {
            clearScreen();
            int view;
            cout << "1. Prisoner \n2. Staff \n3. Manager" << endl;
            cin >> view;

            while (option!=1&&option!=2&&option!=3)
            {
                cout << "Invalid input." <<endl;
                cin >> view;
            }

            string name, password;
            clearScreen();

            //Call login function here & delete the following 4 lines
            cout << "Name: ";
            cin >> name;
            cout << "Password: ";
            cin >> password;

            if (view==1)
            {
                prisonerView(name);
            }
            else if(view==2)
            {
                staffView(name);
            }
            else if(view==3)
            {
                managerView(name);
            }

            break;
        }
        case 2: // Exits the program
        {
            exit(0);
            break;
        }
    }
}
void prisonerView(string& user)
{
    clearScreen();
    colourize("Welcome ",34), colourize(user,34), colourize("!",34);
    cout << endl;

    //cout << "Welcome " << user << "!" <<endl;

    //Manager selection menu
    cout << "\nSelect an option: " <<endl;
    cout << "\n1. Prisoner info";
    cout << "\n2. View schedule"
         << "\n3. Logout"
         << endl;

    cout << "Option: ";
    int option;
    cin >> option;

    while (option!=1&&option!=2&&option!=3)
    {
        cout << "Invalid input." <<endl;
        cin >> option;
    }

    switch(option)
    {
        case 1: //Prisoner info
        {
            clearScreen();
            //Call prisoner function
            break;
        }
        case 2: //View schedule
        {
            clearScreen();
            string filename = "ManagerSchedule.txt";
            displaySchedule(filename);
            break;
        }
        case 3: //Logout
        {
            clearScreen();
            welcome();
            break;
        }
    }
}
void staffView(string& user) {
    clearScreen();
    colourize("Welcome ", 34), colourize(user, 34), colourize("!", 34);

    int prisoners = 3600;
    int blocks[2][4] = {{65,   66,   67,  68},
                        {1000, 1000, 700, 900}};

    cout << "No. Prisoners: " << prisoners << endl; //Number of prisoners

    //Cell Block Information
    cout << "\nCell Block Capacities" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Block " << (char) blocks[0][i] << ": " << blocks[1][i] << endl;
    }

    //Manager selection menu
    cout << "\nSelect an option: " << endl;
    cout << "\n1. Prisoner info"
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
            break;
        }
        case 2: //View schedule
        {
            clearScreen();
            string filename = "ManagerSchedule.txt";
            displaySchedule(filename);
            break;
        }
            case 3: //Logout
            {
                clearScreen();
                welcome();
                break;
            }
        }
    }
    void managerView(string &user) {
        clearScreen();
        colourize("Welcome ", 34), colourize(user, 34), colourize("!", 34);

        int prisoners = 3600;
        int blocks[2][4] = {{65,   66,   67,  68},
                            {1000, 1000, 700, 900}};

        cout << "No. Prisoners: " << prisoners << endl; //Number of prisoners

        //Cell Block Information
        cout << "\nCell Block Capacities" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "Block " << (char) blocks[0][i] << ": " << blocks[1][i] << endl;
        }

        //Manager selection menu
        cout << "\nSelect an option: " << endl;
        cout << "1. Prisoner info"
             << "\n2. Edit Prisoner info"
             << "\n3. Edit User info"
             << "\n4. View Schedule"
             << "\n5. Logout"
             << endl;

        cout << "Option: ";
        int option;
        cin >> option;

        while (option != 1 && option != 2 && option != 3 && option != 4 && option != 5) {
            cout << "Invalid input." << endl;
            cin >> option;
        }

        switch (option) {
            case 1: //Prisoner info
            {
                clearScreen();
                //Call prisoner function
                break;
            }
            case 2: //Edit prisoner info
            {
                clearScreen();
                //Call edit prisoner function
                break;
            }
            case 3: //Edit user info
            {
                clearScreen();
                //Call edit user function
                break;
            }
            case 4: //View schedule
            {
                clearScreen();
                string filename = "ManagerSchedule.txt";
                displaySchedule(filename);
                break;
            }
                case 5: //Logout of account and returns user back to welcome page
                {
                    clearScreen();
                    welcome();
                    break;
                }
            }
        }
