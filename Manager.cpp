#include "Manager.h"



Manager::Manager(bool canCreateStaff, int staffIndex, string userData[], string managerData[])
{
	//manager fields (same as a staff object)
	position = managerData[1];
	scheduleGroup = managerData[2];
	//user fields
	this->userIndex = userIndex;
	firstname = userData[1];
	lastname = userData[2];
	username = "username";//default settings, if changed then username will be updated
	password = "password";//default setting, if changed then username will be updated
	govID = userData[3];
	userID = userData[4];
}
