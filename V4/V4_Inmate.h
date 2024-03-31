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
	Inmate();
	~Inmate() {};
	//void deleteInmate(bool canCreateInmate);
	//string remainingSentence();//permissions bool name required
	Inmate(int userIndex, string userData[], string inmateData[]);

	void save();

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
	
	Inmate inmateLogin(string username, string password);
	void operator=(Inmate newInmate)
	{
		userIndex = newInmate.getUserIndex();
		scheduleGroup = newInmate.getScheduleGroup();
		firstname = newInmate.getFirstname();
		lastname = newInmate.getLastname();
		username = newInmate.getUsername();
		password = newInmate.getPassword();
		govID = newInmate.getGovID();
		userID = newInmate.getUserID();

		lawyerName = newInmate.getLawyerName();
		sentenceLength = newInmate.getSentenceLength();
		probationDate = newInmate.getProbationDate();
		incarDate = newInmate.getIncarDate();;//incaceration date
		cellNum = newInmate.getCellNum();
		cellBlock = newInmate.getCellBlock();
		roommateID = newInmate.getRoommateID();
	}
};
#endif
