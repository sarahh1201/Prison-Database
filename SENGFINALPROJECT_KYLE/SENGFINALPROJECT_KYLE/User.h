#ifndef USER_H
#define USER_H

#include <string>

using namespace std;

class User
{
private:
	string name;
	string username;
	string password;

public:
	User()
	{
		name = "N/A";
		username = "default";
		password = "default";
	}

	User(const string& name, const string& username, const string& password)
	{
		this->name = name;
		this->username = username;
		this->password = password;
	}

	string getName() const
	{
		return name;
	}
	string getUsername() const
	{
		return username;
	}
	string getPassword() const
	{
		return password;
	}

	void setName(const string& name)
	{
		this->name = name;
	}

	void setUsername(const string& username)
	{
		this->username = username;
	}

	void setPassword(const string& password)
	{
		this->password = password;
	}

	/*friend ostream& operator<<(ostream& out, const User& user)
	{
		out << user.name << ' ' << user.username << ' ' << user.password << '\n';

		return out;
	}

	//!valid ints!
	friend istream& operator>>(istream& in, User& user)
	{
		in >> user.name >> user.username >> user.password;

		return in;
	}
	*/
};

#endif // !USER_H
