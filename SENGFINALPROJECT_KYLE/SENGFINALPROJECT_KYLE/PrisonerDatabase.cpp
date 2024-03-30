#include "PrisonerDatabase.h"

using namespace std;

//!valid file name!
PrisonerDatabase::PrisonerDatabase(string fileName) //reads prisoner info from file and saves it to the prisoners vector
{
	this->fileName = fileName;

	ifstream prisonersFile(fileName);
	string currFileLine;

	while (getline(prisonersFile, currFileLine)) //dual finction: checks if there is a next line and saves it to currFIleLine
	{
		istringstream iss(currFileLine); //converts the current line of the file to an istream such that the >> operator can be used

		prisoners.push_back(Prisoner()); //adds a default prisoner to the prisoners vector

		iss >> prisoners[prisoners.size() - 1]; //writes the current line of the file to the prisoner that was just created
	}
	prisonerCount = prisoners.size();

	prisonersFile.close();
}

int PrisonerDatabase::login() const //facilitates login (returns -1 on invalid credentials)
{
	string userername;
	string password;

	cout << "Enter username: ";
	cin >> userername;

	int prisonerIndex = findPrisonerIndexbyUsername(userername);

	cout << "Enter password: ";
	cin >> password;

	//control blocks written like this to keep from an erronious attempt to access prisoners[-1]
	if (prisonerIndex != -1) //if no username match was found,,,
		if (password == prisoners[prisonerIndex].getPassword()) //if password matches, return index found in username search,,,
			return prisonerIndex;

	return -1; //if no username match or passwords not match, return -1
}

int PrisonerDatabase::findPrisonerIndexbyUsername(string username) const
{
	for (int i = 0; i < prisoners.size(); i++)
		if (username == prisoners[i].getUsername())
			return i;

	return -1;
}

int PrisonerDatabase::findPrisonerIndexbyName(string name) const
{
	for (int i = 0; i < prisoners.size(); i++)
		if (name == prisoners[i].getName())
			return i;

	return -1;
}

//!valid index check!
Prisoner* PrisonerDatabase::getPrisoner(int index)
{
	return &prisoners[index];
}

int PrisonerDatabase::getPrisonerCount() const
{
	return prisonerCount;
}

void PrisonerDatabase::addPrisoner(const Prisoner& prisoner)
{
	prisoners.push_back(prisoner);

	prisonerCount = prisoners.size();
}

//!valid index!
void PrisonerDatabase::deletePrisoner(int index)
{
	prisoners[index] = prisoners[prisoners.size() - 1];

	prisoners.pop_back();

	prisonerCount = prisoners.size();
}

//!valid file name (create file if non-existent)!
void PrisonerDatabase::saveDatabase()
{
	ofstream out(fileName, ofstream::trunc); //saves the whole file from scratch; inefficient, but 100x simpler everywhere.

	for (int i = 0; i < prisoners.size(); i++)
		out << prisoners[i];

	out.close();
}

//!valid file name (create file if non-existent)!
void PrisonerDatabase::setFileName(string fileName)
{
	this->fileName = fileName;
}