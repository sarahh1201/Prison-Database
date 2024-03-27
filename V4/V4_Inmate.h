#pragma once
#ifndef V4_INMATE_H
#define V4_INMATE_H
#include <string>
#include "V4_User.h"

using namespace std;

class Inmate : public User
{
protected:
	string lawyerName;
	string sentenceLength;
	string probationDate;
	string incarDate;//incaceration date
	string cellNum;
	string cellBlock;
	string roommateID;
	string scheduleGroup;
	//bool privileges[permissionsMax];//inmate specific privileges

public:

	//~Inmate();
	//void deleteInmate(bool canCreateInmate);
	//string remainingSentence();//permissions bool name required
	Inmate(int userIndex, string userData[], string inmateData[]);

	string getLawyerName();
	string getSentenceLength();
	string getProbationDate();
	string getIncarDate();//incarceration date
	string getCellNum();
	string getCellBlock();
	string getRoommateID();
	string getScheduleGroup();

	void setLawyerName(string lawyerName);
	void setSentenceLength(string sentenceLength);
	void setProbationDate(string probationDate);
	void setIncarDate(string incarDate);//incarceration date
	void setCellNum(string cellNum);
	void setCellBlock(string cellBlock);
	void setRoommateID(string roommateID);
	void setScheduleGroup(string scheduleGroup);
};
#endif
