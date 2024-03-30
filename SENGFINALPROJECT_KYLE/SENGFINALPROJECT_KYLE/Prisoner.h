#ifndef PRISONER_H
#define PRISONER_H

#include "User.h"
#include <iostream>
#include <string>

using namespace std;

class Prisoner : public User
{
private:
	int sentenceYrs;
	int incarceratedYrs;
	int cellNumber;
	char cellBlock;
public:
	Prisoner()
	{
		setName("prisoner");
		setUsername("default");
		setPassword("default");
		sentenceYrs = 0;
		incarceratedYrs = 0;
		cellNumber = -1;
		cellBlock = '@';
	}

	//!valid ints!
	Prisoner(const string& name, const string& username, const string& password, int sentenceYrs, int incarceratedYrs, int cellNumber, char cellBlock)
	{
		setName(name);
		setUsername(username);
		setPassword(password);
		this->sentenceYrs = sentenceYrs;
		this->incarceratedYrs = incarceratedYrs;
		this->cellNumber = cellNumber;
		this->cellBlock = cellBlock;
	}

	int getSentenceYrs() const
	{
		return sentenceYrs;
	}

	int getIncarceratedYrs() const
	{
		return incarceratedYrs;
	}

	int getRemainingSentence() const
	{
		return sentenceYrs - incarceratedYrs;
	}

	int getCellNumber() const
	{
		return cellNumber;
	}

	char getCellBlock() const
	{
		return cellBlock;
	}

	//!valid int!
	void setSentenceYrs(int sentenceYrs)
	{
		this->sentenceYrs = sentenceYrs;
	}

	//!valid int!
	void setIncarceratedYrs(int incarceratedYrs)
	{
		this ->incarceratedYrs = incarceratedYrs;
	}

	//vald values!
	void setCell(int cellNumber, char cellBlock)
	{
		this->cellNumber = cellNumber;
		this->cellBlock = cellBlock;
	}

	friend ostream& operator<<(ostream& out, const Prisoner& prisoner)
	{
		out << prisoner.getName() << ' ' << prisoner.getUsername() << ' ' << prisoner.getPassword() << ' ' << prisoner.sentenceYrs << ' ' << prisoner.incarceratedYrs << ' ' << prisoner.cellBlock << ' ' << prisoner.cellNumber << '\n';
	
		return out;
	}

	//!valid values!
	friend istream& operator>>(istream& in, Prisoner& prisoner)
	{
		string name;
		string username;
		string password;

		in >> name >> username >> password >> prisoner.sentenceYrs >> prisoner.incarceratedYrs >> prisoner.cellBlock >> prisoner.cellNumber;

		prisoner.setName(name);
		prisoner.setUsername(username);
		prisoner.setPassword(password);

		return in;
	}

};

#endif // !PRISONER_H