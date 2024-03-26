#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "Staff.h"
using namespace std;

const int managerMaxIndices = 3;

class Manager : public Staff
{
    Manager(bool canCreateStaff, int staffIndex, string userData[], string staffData[]);

    ~Manager()
    {

   }
 

};
#endif
