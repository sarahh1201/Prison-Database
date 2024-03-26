#include "Staff.h"

Staff::Staff()
{
	position="N/A";
	scheduleGroup="N/A";
}
Staff::Staff(bool canCreateStaff, int userIndex, string userData[], string staffData[])
{
	//staff fields
	position = staffData[1];
	scheduleGroup = staffData[2];
	//user fields
	this->userIndex = userIndex;
	firstname = userData[1];
	lastname = userData[2];
	username = "username";//default settings, if changed then username will be updated
	password = "password";//default setting, if changed then username will be updated
	govID = userData[3];
	userID = userData[4];
}

string Staff::getPosition()
{
	return position;
}
string Staff::getScheduleGroup()
{
	return scheduleGroup;
}
