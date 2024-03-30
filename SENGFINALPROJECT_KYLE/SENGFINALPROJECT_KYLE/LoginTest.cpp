#include "Database.h"
#include "PrisonerDatabase.h"

using namespace std;

int main()
{
	PrisonerDatabase userDatabase;
	int userIndex = -1;

	while (userIndex == -1)
	{
		userIndex = userDatabase.login();
	}

	Prisoner curr = *(userDatabase.getPrisoner(userIndex));

	cout << curr.getName() << " " << curr.getRemainingSentanceYrs();
}