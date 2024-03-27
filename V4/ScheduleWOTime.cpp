#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std;

void displaySchedule(string filename) {
    ifstream file(filename);
    if (file.is_open()) {
        cout << "-------------------------------------------------------------" << endl;
        string line;
        int count = 0; 
        bool display = false; 
        while (getline(file, line) && count < 8) {
            int hour = stoi(line.substr(0, 2));
            if (!display && hour >= 0) { 
                display = true;
            }
            if (display && count < 8) {
                cout << "| " << setw(5) << left << line.substr(0, 5) << " | " << setw(40) << left << line.substr(8) << endl;
                cout << "-------------------------------------------------------------" << endl;
                count++;
            }
        }
        file.close();
    } else {
        cerr << "Failed to open file: " << filename << endl;
    }
}

int main() {
    string filename = "ManagerSchedule.txt";
    displaySchedule(filename);
    return 0;
}
