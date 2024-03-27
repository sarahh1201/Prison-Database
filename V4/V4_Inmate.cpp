#include "V4_Inmate.h"

Inmate::Inmate(int userIndex, string userData[], string inmateData[])
{
	//inmate fields
	lawyerName = inmateData[1];
	sentenceLength = inmateData[2];
	probationDate = inmateData[3];
	incarDate = inmateData[4];//incaceration date
	cellNum = inmateData[5];
	cellBlock = inmateData[6];
	roommateID = inmateData[7];
	scheduleGroup = inmateData[8];
	//user fields
	this->userIndex = userIndex;
	firstname = userData[1];
	lastname = userData[2];
	username = "username";//default settings, if changed then username will be updated
	password = "password";//default setting, if changed then username will be updated
	govID = userData[3];
	userID = userData[4];
}

//accessors
string Inmate::getLawyerName()
{
	return lawyerName;
}
string Inmate::getSentenceLength()
{
	return sentenceLength;
}
string Inmate::getProbationDate()
{
	return probationDate;
}
string Inmate::getIncarDate()//incaceration date
{
	return incarDate;
}
string Inmate::getCellNum()
{
	return cellNum;
}
string Inmate::getCellBlock()
{
	return cellBlock;
}
string Inmate::getRoommateID()
{
	return roommateID;
}
string Inmate::getScheduleGroup()
{
	return scheduleGroup;
}

//mutators
void Inmate::setLawyerName(string lawyerName)
{
	this->lawyerName = lawyerName;
}
void Inmate::setSentenceLength(string sentenceLength)
{
	this->sentenceLength = sentenceLength;
}
void Inmate::setProbationDate(string probationDate)
{
	this->probationDate = probationDate;
}
void Inmate::setIncarDate(string incarDate)//incaceration date
{
	this->incarDate = incarDate;
}
void Inmate::setCellNum(string cellNum)
{
	this->cellNum = cellNum;
}
void Inmate::setCellBlock(string cellBlock)
{
	this->cellBlock = cellBlock;
}
void Inmate::setRoommateID(string roommateID)
{
	this->roommateID = roommateID;
}
void Inmate::setScheduleGroup(string scheduleGroup)
{
	this->scheduleGroup = scheduleGroup;
}