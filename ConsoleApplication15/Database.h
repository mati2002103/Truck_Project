#pragma once
class database
{
public:
	void dbconnect();
	void adduser(std::string login, std::string password, int permission);
	bool userexist(std::string login);
	bool checkpassword(std::string login, std::string password);
	int checkrole(std::string login);

};