#ifndef STAFF_H
#define STAFF_H
#include <string>
#include "User.h"

using namespace std;


const int staffMaxIndices = 3;//max number of fields in staff data file
class Staff : public User
{
protected:
	string position;
	string scheduleGroup;

public:
	Staff();
	//Staff(bool canCreateStaff);
	//Staff(all user data fields);
	Staff(bool canCreateStaff, int staffIndex, string userData[], string staffData[]);
	//~Staff();
	//void deleteStaff(bool canCreateStaff);
	string getPosition();
	string getScheduleGroup();

	void operator=(Staff newStaff)
	{
		position = newStaff.getPosition();
		scheduleGroup = newStaff.getScheduleGroup();
		firstname = newStaff.getFirstname();
		lastname = newStaff.getLastname();
		username = newStaff.getUsername();
		password = newStaff.getPassword();
		govID = newStaff.getGovID();
		userID = newStaff.getUserID();
		userIndex = newStaff.getUserIndex();
	}
};
#endif

