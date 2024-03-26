#include "Inmate.h"

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
int Inmate::getCellNum()
{
	return cellNum;
}
char Inmate::getCellBlock()
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
void Inmate::setCellNum(int cellNum)
{
	this->cellNum = cellNum;
}
void Inmate::setCellBlock(char cellBlock)
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
