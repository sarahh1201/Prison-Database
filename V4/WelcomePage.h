#ifndef WELCOMEPAGE_H
#define WELCOMEPAGE_H

#include "Customize.h"
#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>
#include "V4_Staff.h"
#include "V4_Inmate.h"

using namespace std;

//Welcome screen and different user views
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

            cout << "Name: ";
            cin >> name; 
            cout << "Password: ";
            cin >> password;
            //Call login function

            if (view==1)
            {
                Inmate user; 
                prisonerView(name);
                user.inmateLogin(name,password);
            }
            else if(view==2)
            {
                Staff user;
                staffView(name);
                user.staffLogin(name,password);
            }
            else if(view==3)
            {
                Staff user;
                managerView(name);
                user.staffLogin(name,password);
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

    //Manager selection menu
    cout << "\nSelect an option: " <<endl;
    cout << "1. Prisoner info";
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
        case 1: //Personal info
        {
            clearScreen();
            //Function

            cout << "Enter 1 to go back: ";
            int exit;
            cin>>exit;
        
                while(exit!=1) 
                {
                    clearScreen();
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }
                if(exit==1)
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
             cin>>exit;
        
                while(exit!=1) 
                {
                    clearScreen();
                    displaySchedule(filename);
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }
                if(exit==1)
                {
                    clearScreen();
                    prisonerView(user);
                }

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

    cout << "\nNo. Prisoners: " << prisoners << endl; //Number of prisoners

    //Cell Block Information
    cout << "\nCell Block Capacities" << endl;
    for (int i = 0; i < 4; i++) {
        cout << "Block " << (char) blocks[0][i] << ": " << blocks[1][i] << endl;
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
            cin>>exit;
            
                while(exit!=1) 
                {
                    clearScreen();
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }

                    if(exit==1)
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
            cin>>exit;
            
                while(exit!=1) 
                {
                    clearScreen();
                    displaySchedule(filename);
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }

                    if(exit==1)
                {
                    clearScreen();
                    staffView(user);
                }

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

        cout << "\nNo. Prisoners: " << prisoners << endl; //Number of prisoners

        //Cell Block Information
        cout << "\nCell Block Capacities" << endl;
        for (int i = 0; i < 4; i++) {
            cout << "Block " << (char) blocks[0][i] << ": " << blocks[1][i] << endl;
        }

        //Manager selection menu
        cout << "\nSelect an option: " << endl;
        cout << "1. View Schedule"
             << "\n2. Personal info"
             << "\n3. Prisoner info"
             << "\n4. Manage People"
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
            case 1:
            {
            clearScreen();
                string filename = "ManagerSchedule.txt";
                displaySchedule(filename);

                cout << "Enter 1 to go back: ";
                int exit;
                cin>>exit;
            
                while(exit!=1) 
                {
                    clearScreen();
                    displaySchedule(filename);
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }
                if(exit==1)
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
                cin>>exit;
            
                while(exit!=1) 
                {
                    clearScreen();
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }
                if(exit==1)
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
                cin>>exit;
            
                while(exit!=1) 
                {
                    clearScreen();
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }
                if(exit==1)
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
                << "\n2. Staff"<<endl;
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
                cin>>exit;
            
                while(exit!=1) 
                {
                    clearScreen();
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }
                if(exit==1)
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
                cin>>exit;
            
                while(exit!=1) 
                {
                    clearScreen();
                    cout << "Invalid input!" <<endl;
                    cout << "Enter 1 to go back: ";
                    cin >> exit;
                }
                if(exit==1)
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
                    welcome();
                    break;
            }
            }
        }    


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
#endif