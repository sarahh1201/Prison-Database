#ifndef CUSTOMIZE_H
#define CUSTOMIZE_H
#include <iostream>
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

//colourCode = 34 for blue 

//Change the colour of the text using the ANSI colour escape codes
void colourize(const string& text, int colourCode) {
    cout << "\033[" << colourCode << "m" << text << "\033[0m";
}

void midBorders(const string& text) {
    int width = 24; // Border width includes 4 spaces on each side of the text

    // Print text with borders
    cout << "| " << text << setw(width-text.length()) << setfill(' ') << left << right << '|' << endl;
}

void topBorders(const string& text) {
    int width = 24; // Border width includes 4 spaces on each side of the text

    // Print top border
    cout << '+' << string(width, '-') << '+' << endl;

    // Print text with borders
    cout << "| " << text << setw(width-text.length()) << setfill(' ') << left << right << '|' << endl;
}

void bottomBorders(const string& text) {
    int width = 24; // Border width includes 4 spaces on each side of the text

    // Print text with borders
    cout << "| " << text << setw(width-text.length()) << setfill(' ') << left << right << '|' << endl;

    // Print bottom border
    cout << '+' << string(width, '-') << '+' << endl;
}

void allBorders(const string& text) {
    int width = 24; // Border width includes 4 spaces on each side of the text

    // Print top border
    cout << '+' << string(width, '-') << '+' << endl;

    // Print text with borders
    cout << "| " << text << setw(width-text.length()) << setfill(' ') << left << right << '|' << endl;

    // Print bottom border
    cout << '+' << string(width, '-') << '+' << endl;
}

#endif