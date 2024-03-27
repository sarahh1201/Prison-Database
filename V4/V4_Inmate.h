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

	
	Inmate inmateLogin(string username, string password)
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

	}

	//hasnt been tested, will also need to loop back to login screen. 
	void inmateLogOut(Inmate* currentInmate)//delete the current object and return to login menu
	{
		delete currentInmate;
	}

};
#endif
