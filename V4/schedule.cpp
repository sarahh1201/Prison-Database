#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

// display schedule for the specific range
void displaySchedule(string filename, char scheduleType, int startLine, int endLine) {
    // set values based on schedule type
    switch (scheduleType) {
        case '0': {
            // staff schedule 1
            startLine = 0;
            endLine = 7;
            break;
        }
        case '1': {
            // staff schedule 2
            startLine = 8;
            endLine = 150
                    ;
            break;
        }
        case '2': {
            // inmate schedule 1
            startLine = 16;
            endLine = 232
                    ;
            break;
        }
        case '3': {
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
    if (file.is_open()) {
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
    } else {
        // error message
        cerr << "Failed to open file: " << filename << endl;
    }
}

int main() {
    char scheduleType;
    cout << "Enter schedule type (0-3): ";
    cin >> scheduleType;

    // call displaySchedule with lines to display
    displaySchedule("Schedule.txt", scheduleType, 0, 0);

    return 0;
}

