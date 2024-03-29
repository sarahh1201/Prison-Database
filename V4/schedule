#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

int NumberOne;
int NumberTwo;

// display schedule for the specific range
void displaySchedule(string filename, int startLine, int endLine) {
    // open the file
    ifstream file(filename);
    if (file.is_open()) {
        // header columns with ANSI codes
        cout << "-------------------------------------------------------------" << endl;
        cout << "| \033[1;36mHour\033[0m   | \033[1;36mTask\033[0m                                        |" << endl;
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
            int hour = stoi(line.substr(0, 2));
            cout << "| \033[3m" << setw(5) << left << hour << "\033[0m | \033[1;33m" << line.substr(8) << "\033[0m |"
                 << endl;
            cout << "-------------------------------------------------------------" << endl;
            count++;
        }

        // close file
        file.close();
    } else {
        // error message
        cerr << "Failed to open file: " << filename << endl;
    }
}

int main() {
    string filename = "Schedule.txt";

    // set values for NumberOne and NumberTwo
    switch //( add conditions for the schedule groups ) {
        case 0: {
         // staff schedule 1
            NumberOne = 0;
            NumberTwo = 8;
            break;
        }
        case 1: {
        // staff schedule 2
            NumberOne = 9;
            NumberTwo = 17;
            break;
        }
        case 2: {
            // inmate schedule 1
            NumberOne = 18;
            NumberTwo = 26;
            break;
        }
        case 3: {
            // inmate schedule 2
            NumberOne = 27;
            NumberTwo = 35;
            break;
        }
        default: {
            // error message
            cout << "Invalid" << endl;
            return 1; // exit with error code
        }
    }

    // call displaySchedule with lines to display
    displaySchedule(filename, NumberOne, NumberTwo);

    return 0;
}
