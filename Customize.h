#ifndef CUSTOMIZE_H
#define CUSTOMIZE_H
#include <iostream>
using namespace std;

void clearScreen() {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
}

//colourCode = 34 for blue 

void colourize(const string& text, int colourCode) {
    cout << "\033[" << colourCode << "m" << text << "\033[0m";
}

#endif