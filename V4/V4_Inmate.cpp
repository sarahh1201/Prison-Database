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
Inmate::Inmate()
{
	lawyerName = "errorLawyerName";
	sentenceLength = "errorSentenceLength";
	probationDate = "errorProbationDate";
	incarDate = "errorIncarDate";//incaceration date
	cellNum = "errorCellNum";
	cellBlock = "errorCellBlock";
	roommateID = "errorRoommateID";
	scheduleGroup = "errorScheduleGroup";
}

void Inmate::save()
{

	int userIndex = getUserIndex();

	//save username if it has been updated
	if (getUsername() != "username")
	{
		if (getUsername() == "errorusername")//default username, error has occured if present
		{
			cout << "\nInmate Error encountered. Please log out or correct username. Did not successfully save.";
			return;
		}
		setUsernameInfo(1, userIndex, 1, getUsername());
	}

	//save password if it has been updated
	if (getPassword() != "password")
	{
		if (getUsername() == "errorpassword")//default password, error has occured if present
		{
			cout << "\nInmate Error encountered. Please log out or correct password. Did not successfully save.";
			return;
		}
		setUsernameInfo(1, userIndex, 2, getPassword());
	}

	setInmateInfo(userIndex, 1, getLawyerName());
	setInmateInfo(userIndex, 2, getSentenceLength());
	setInmateInfo(userIndex, 3, getProbationDate());
	setInmateInfo(userIndex, 4, getIncarDate());
	setInmateInfo(userIndex, 5, getCellNum());
	setInmateInfo(userIndex, 6, getCellBlock());
	setInmateInfo(userIndex, 7, getRoommateID());
	setInmateInfo(userIndex, 8, getScheduleGroup());

	setUserInfo(0, userIndex, 1, getFirstname());
	setUserInfo(0, userIndex, 2, getLastname());
	setUserInfo(0, userIndex, 3, getGovID());
	setUserInfo(0, userIndex, 4, getUserID());

	cout << "\nSaved";
}

Inmate Inmate::inmateLogin(string username, string password)
{
	ifstream input("Inmate_Usernames.txt");//open the usernames and password file (order of info is: index, username, password)
	//look for the username
	int i = 0;
	string inUsername;
	while (getline(input, inUsername, ' '))
	{
		string inPassword;
		if ((i % maxUsernameFileIndex) / 1 == 1)//skip every entry that is not usernames 
			if (inUsername == username)//if the usernames match
			{
				input >> inPassword;//take in the next entry into passwords
				i++;
				//try{ make the below a compare function that throws the excpetion
				if (inPassword == password)//if the passwords match
				{
					int index = i / maxUsernameFileIndex;
					input.close();
					string userData[maxIndices];
					string inmateData[inmateMaxIndices];

					for (int j = 0; j < maxIndices; j++)
						userData[j] = getUserInfo(0, index, j);

					for (int j = 0; j < inmateMaxIndices; j++)
						inmateData[j] = getInmateInfo(index, j);
					
					return Inmate(index, userData, inmateData);
				}
				//}
				//catch() PASSWORDS DONT MATCH
			}
		i++;
	}
	input.close();
	return Inmate();
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
