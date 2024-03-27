#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <ctime>

using namespace std;

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


// Test
/*int main() {
    string filename = "ManagerSchedule.txt";
    displaySchedule(filename);
    return 0;
}
*/