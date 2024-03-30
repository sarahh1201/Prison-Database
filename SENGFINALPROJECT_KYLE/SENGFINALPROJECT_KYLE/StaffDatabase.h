#ifndef STAFFDATABASE_H
#define STAFFDATABASE_H

#include "Staff.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//this class is a container for all of the staff objects
//it contains general information about staffs, facilitates addition and subraction of staffs, and permits file read/write

class StaffDatabase
{
private:
	vector<Staff> staffs;
	int staffCount;
	string fileName;
public:
	//!valid file name!
	StaffDatabase(string fileName); //reads staff info from file and saves it to the staffs vector

	int login() const; //facilitates login (returns -1 on invalid credentials)

	int findStaffIndexbyUsername(string username) const;

	int findStaffIndexbyName(string name) const;

	//!valid index check!
	Staff* getStaff(int index);

	int getStaffCount() const;

	void addStaff(const Staff& staff);

	//!valid index!
	void deleteStaff(int index);

	//!valid file name (create file if non-existent)!
	void saveDatabase();

	void setFileName(string fileName);
};
#endif // !DATABASE_H
