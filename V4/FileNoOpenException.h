#ifndef FILENOOPENEXCEPTION
#define FILENOOPENEXCEPTION
#include <iostream>
#include <stdexcept>
#include <string>
#include <fstream>
using namespace std;

//MAKE SURE YOU PASS THE FILE NAME NOT THE FSTREAM
class FileNoOpenException : public invalid_argument
{
public:
    FileNoOpenException(const string& fileAddress) : invalid_argument("File could not be opened")
    {
        this->fileAddress = fileAddress;
    }

    string getFileAddress() const
    {
        return fileAddress;
    }

private:
    string fileAddress;
};
#endif