#ifndef WELCOMESCREEN_PASSWORDEXCEPTION_H
#define WELCOMESCREEN_PASSWORDEXCEPTION_H

#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;



class PasswordException : public logic_error {
public:
    PasswordException(string entry): logic_error("Password does not match") {}
};

#endif // PASSWORDEXCEPTION_H

//throw PasswordException("Invalid password");