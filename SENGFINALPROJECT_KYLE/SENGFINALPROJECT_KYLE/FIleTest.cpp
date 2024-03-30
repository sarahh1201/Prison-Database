#include "PrisonerDatabase.h"

using namespace std;

int main()
{
	PrisonerDatabase test("PrisonerDataFile.txt");

	test.addPrisoner(Prisoner());

	test.deletePrisoner(1);

	for (int i = 0; i < test.getPrisonerCount(); i++)
		cout << test.getPrisoner(i)->getRemainingSentanceYrs() << endl;

	test.saveDatabase("PrisonerDataFile.txt");

	return 0;
}