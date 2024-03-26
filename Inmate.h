#ifndef INMATE_H
#define INMATE_H
#include <string>
#include "User.h"

using namespace std;

const int inmateMaxIndices = 8;

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
	string scheduleGroup;
	//bool privileges[permissionsMax];//inmate specific privileges

public:
	//Inmate(bool canCreateInmate);
	//Immate(bool canCreateInmate, string ) constructors with all parameters will be coded last to prevent unecessary programming
	//~Inmate();
	//void deleteInmate(bool canCreateInmate);
	//string remainingSentence();//permissions bool name required

	string getLawyerName();
	string getSentenceLength();
	string getProbationDate();
	string getIncarDate();//incarceration date
	int getCellNum();
	char getCellBlock();
	string getRoommateID();
	string getScheduleGroup();

	void setLawyerName(string lawyerName);
	void setSentenceLength(string sentenceLength);
	void setProbationDate(string probationDate);
	void setIncarDate(string incarDate);//incarceration date
	void setCellNum(int cellNum);
	void setCellBlock(char cellBlock);
	void setRoommateID(string roommateID);
	void setScheduleGroup(string scheduleGroup);
};
#endif
