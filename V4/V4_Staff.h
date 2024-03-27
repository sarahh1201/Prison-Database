#pragma once
#ifndef V4_STAFF_H
#define V4_STAFF_H
#include <string>
#include <sstream>
#include "V4_User.h"

using namespace std;


class Staff : public User
{
public:
	string position;
	string scheduleGroup;

	Staff();
	Staff(int staffIndex, string userData[], string staffData[]);
	~Staff() {}
	string getPosition();
	string getScheduleGroup();
	void deleteAccount(string username, int accountType);
	void createAccount(int accountType);

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

