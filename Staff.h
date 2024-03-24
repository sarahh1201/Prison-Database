#ifndef STAFF_H
#define STAFF_H
#include <string>
#include "User.h"

using namespace std;

class Staff : public User
{
protected:
	string position;
	char scheduleGroup;

public:
	Staff();
	//Staff(bool canCreateStaff);
	//Staff(all user data fields);
	//Staff(all user data fields, all staff data fields);
	~Staff();
	void deleteStaff(bool canCreateStaff);
};
#endif
