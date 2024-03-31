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
	void setPosition(string position);
	void setScheduleGroup(string scheduleGroup);
	void deleteAccount(string username, int accountType);
	void createAccount(int accountType);

	void save(string username);

	//login functions, after login CHECK username FOR "errorusername"
	Staff staffLogin(string username, string password);

	string getStaffInfo(int staffIndex, int fieldIndex);
	void setStaffInfo(int staffIndex, int fieldIndex, string newData);

	void operator=(Staff newStaff);
};
#endif

