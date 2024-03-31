#ifndef CUSTOMIZE_H
#define CUSTOMIZE_H
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
using namespace std;

//Clears the terminal but keeps the program running
void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//Change the colour of the text using the ANSI colour escape codes
void colourize(const string& text, int colourCode) {
    cout << "\033[" << colourCode << "m" << text << "\033[0m";
}

void midBorders(const string& text) {
    int width = 24; // Border width 

    // Print text with borders
    cout << "| " << text << setw(width-text.length()) << setfill(' ') << left << right << '|' << endl;
}

void topBorders(const string& text) {
    int width = 24; // Border width 

    // Print top border
    cout << '+' << string(width, '-') << '+' << endl;

    // Print text with borders
    cout << "| " << text << setw(width-text.length()) << setfill(' ') << left << right << '|' << endl;
}

void bottomBorders(const string& text) {
    int width = 24; 

    // Print text with borders
    cout << "| " << text << setw(width-text.length()) << setfill(' ') << left << right << '|' << endl;

    // Print bottom border
    cout << '+' << string(width, '-') << '+' << endl;
}

void allBorders(const string& text) {
    int width = 24; // Border width 

    // Print top border
    cout << '+' << string(width, '-') << '+' << endl;

    // Print text with borders
    cout << "| " << text << setw(width-text.length()) << setfill(' ') << left << right << '|' << endl;

    // Print bottom border
    cout << '+' << string(width, '-') << '+' << endl;
}

void displayBlocks() {
    string filename = "blockInfo.txt";
    ifstream file(filename);
    if (file.is_open()) {
        // header columns with ANSI codes
        cout << "\n+--------------------+" << endl;
        cout << "|  \033[1;36mBlock Capacities\033[0m  |"<< endl;
        cout << "+--------------------+" << endl;

        // read file -- in terms if lines
        string line;
        int total =0;
        while (getline(file, line)) { // Read each line from the file
            cout << line << endl; // Output the line to the console


        //Calculates the prisoner total 
            size_t colon_pos = line.find(':');
            size_t slash_pos = line.find('/');

        if (colon_pos != string::npos && slash_pos != string::npos) {
            // Extract the substring between ':' and '/'
            string value_str = line.substr(colon_pos + 2, slash_pos - colon_pos - 2);
            
            // Convert the substring to an integer and add it to the total
            istringstream iss(value_str);
            int value;
            if (iss >> value) {
                total += value;
            }
            }
        }   
        colourize("\nNo. Prisoners: ",36);
        cout << total<<endl;

        // close file
        file.close();
        }
    else{
        // error message
        cerr << "Failed to open file: " << filename << endl;
}
}
#endif