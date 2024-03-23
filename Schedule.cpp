#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime> 

using namespace std;

// function to get current date and time
string getCurrentDateTime() {
    time_t now = time(0);
    tm *ltm = localtime(&now);

    // format for date and time
    char buffer[80];
    strftime(buffer, 80, "%Y-%m-%d %H:%M:%S", ltm);
    return string(buffer);
}

// display the schedule pulled from txt file
void displaySchedule(const string& filename) {
    // Get the current date and time
    string currentDateTime = getCurrentDateTime();

    ifstream file(filename);
    if (file.is_open()) {
        cout << "Current as of: " << currentDateTime << endl; // Display current date and time
        cout << "---------------------------------------------------" << endl;
        cout << "| " << setw(12) << left << "Time (24HR)" << " | " << setw(33) << left << "Tasks" << " |" << endl;
        cout << "---------------------------------------------------" << endl;
        string line;
        while (getline(file, line)) {
            cout << "| " << setw(12) << left << line.substr(0, 7) << " | " << setw(33) << left << line.substr(8) << " |" << endl;
            cout << "---------------------------------------------------" << endl;
        }
        file.close();
    } else {
        cerr << "Failed to open file: " << filename << endl;
    }
}


//test
int main() {
    string filename = "ManagerSchedule.txt";
    displaySchedule(filename);
    return 0;
}
