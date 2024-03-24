#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "Staff.h"

using namespace std;

class Manager : public Staff
{
    Manager(bool canCreateManager);
    //Manager(bool canCreateManager, all user datafields);
    //Manager(bool canCreateManager, all user fields, all staff fields);
    ~Manager();
    void deleteManager(bool canCreateManager);

};
#endif
