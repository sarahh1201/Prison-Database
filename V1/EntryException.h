#ifndef ENTRYEXCEPTION
#define ENTRYEXCEPTION
#include <iostream>
#include <stdexcept>
#include <string>
using namespace std;

class EntryException: public logic_error
{
public:
    EntryException(string entry): logic_error("Invalid entry")
    {
        this->entry=entry;
    }

    string getEntry() const
    {
        return entry;
    }

private:
    string entry;
};
#endif