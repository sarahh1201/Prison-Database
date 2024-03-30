#include "StaffDatabase.h"
#include "PrisonerDatabase.h"

using namespace std;

int main()
{
	PrisonerDatabase Staff_Database("StaffDataFile.txt");

	Prisoner test;

	Staff_Database.addPrisoner(test);

	cout << Staff_Database.getPrisonerCount() << endl;

	Staff_Database.setFileName("test.txt");

	Staff_Database.saveDatabase();

	return 0;
}