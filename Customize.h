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

void colourize(const string& text, int colorCode) {
    cout << "\033[" << colorCode << "m" << text << "\033[0m";
}

#endif