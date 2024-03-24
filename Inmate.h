#ifndef INMATE_H
#define INMATE_H
#include <string>
#include "User.h"

using namespace std;

class Inmate : public User
{
protected:
	string lawyerName;
	string sentenceLength;
	string probationDate;
	string incarDate;//incaceration date
	int cellNum;
	char cellBlock;
	string roommateID;
	char scehduleGroup;
	bool privileges[];//inmate specific privileges

public:
	Inmate(bool canCreateInmate);
	//Immate(bool canCreateInmate, string ) constructors with all parameters will be coded last to prevent unecessary programming
	~Inmate();
	void deleteInmate(bool canCreateInmate);
	string remainingSentence();//permissions bool name required
};
#endif
