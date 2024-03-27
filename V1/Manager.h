#ifndef MANAGER_H
#define MANAGER_H
#include <string>
#include "Staff.h"
#include "ManagerDatabaseFunctions.h";

using namespace std;

const int managerMaxIndices = 3;

class Manager : public Staff
{
    Manager(int staffIndex, string userData[], string staffData[]);

    ~Manager()
    {
		deleteAccount(username, 3);
		managerCount--;
	}
 
	void deleteAccount(string username, int accountType);

	void createAccount(int accountType);

};
#endif
