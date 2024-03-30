#ifndef STAFF_H
#define STAFF_H

#include "User.h"
#include <iostream>
#include <string>

using namespace std;

class Staff : public User
{
private:
	bool adminPrivlege;
	double hourlyWage;
	int weeklyHours;
public:
	Staff()
	{
		setName("staff");
		setUsername("default");
		setPassword("default");
		hourlyWage = 0.0;
		weeklyHours = 0;
		adminPrivlege = false;

	}

	//!valid ints!
	Staff(const string& name, const string& username, const string& password, double hourlyWage, int weeklyHours, bool adminPrivlege)
	{
		setName(name);
		setUsername(username);
		setPassword(password);
		this->hourlyWage = hourlyWage;
		this->weeklyHours = weeklyHours;
		this->adminPrivlege = adminPrivlege;
	}

	double getHourlyWage()
	{
		return hourlyWage;
	}

	//!valid double!
	void setHourlyWage(double hourlyWage)
	{
		this->hourlyWage = hourlyWage;
	}

	int getWeeklyHours()
	{
		return weeklyHours;
	}

	bool getAdminPrivlege()
	{
		return adminPrivlege;
	}

	void setAdminPrivlege(bool adminPrivlege)
	{
		this->adminPrivlege = adminPrivlege;
	}

	//!valid double!
	void setWeeklyHours(int weeklyHours)
	{
		this->weeklyHours = weeklyHours;
	}

	friend ostream& operator<<(ostream& out, const Staff& staff)
	{
		out << staff.getName() << ' ' << staff.getUsername() << ' ' << staff.getPassword() << ' ' << staff.hourlyWage << ' ' << staff.weeklyHours << ' ' << staff.adminPrivlege << '\n';

		return out;
	}

	//!valid values!
	friend istream& operator>>(istream& in, Staff& staff)
	{
		string name;
		string username;
		string password;

		in >> name >> username >> password >> staff.hourlyWage >> staff.weeklyHours >> staff.adminPrivlege;

		staff.setName(name);
		staff.setUsername(username);
		staff.setPassword(password);

		return in;
	}

};

#endif // !STAFF_H
