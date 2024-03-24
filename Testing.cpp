#include <iostream>
#include <string>
#include <fstream>
using namespace std;

int main()
{
	ifstream input("Staff_Usernames.txt");
	//look for the username
	int i = 0;
	string inUsername;
	while (getline(input,inUsername))
	{
		string inPassword;
	
		i++;
		if (i % 2 == 0)//skip every second entry (the passwords)
			if (inUsername == username)//if the usernames match
			{
				input >> inPassword;//take in the next entry into passwords
				if (inPassword == password)//if the passwords match
				{

				}
			}
	}
	
	return 0;
}