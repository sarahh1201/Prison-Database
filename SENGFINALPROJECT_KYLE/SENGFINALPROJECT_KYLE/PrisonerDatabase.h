#ifndef PRISONERDATABASE_H
#define PRISONERDATABASE_H

#include "Prisoner.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <sstream>

using namespace std;

//this class is a container for all of the prisoner objects
//it contains general information about prisoners, facilitates addition and subraction of prisoners, and permits file read/write

class PrisonerDatabase
{
private:
	vector<Prisoner> prisoners;
	int prisonerCount;
	string fileName;
public:
	//!valid file name!
	PrisonerDatabase(string fileName); //reads prisoner info from file and saves it to the prisoners vector

	int login() const; //facilitates login (returns -1 on invalid credentials)

	int findPrisonerIndexbyUsername(string username) const;

	int findPrisonerIndexbyName(string username) const;

	//!valid index check!
	Prisoner* getPrisoner(int index);

	int getPrisonerCount() const;

	void addPrisoner(const Prisoner& prisoner);

	void deletePrisoner(int index);

	//!valid file name (create file if non-existent)!
	void saveDatabase();

	void setFileName(string fileName);
};
#endif // !DATABASE_H
