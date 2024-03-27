#ifndef RANGEEXCEPTION
#define RANGEEXCEPTION
#include <iostream>
#include <stdexcept>
using namespace std;

class RangeException: public logic_error
{
public:
    RangeException(int range): logic_error("Invalid entry") //Index out of range
    {
        this->range=range;
    }

    int getEntry() const
    {
        return range;
    }

private:
    int range;
};
#endif