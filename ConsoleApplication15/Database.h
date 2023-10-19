#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/sqlstring.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
class database
{
private:
	sql::Statement* stmt;
	sql::ResultSet* res;
	sql::mysql::MySQL_Driver* driver;
	sql::Connection* con;
	database();
	
	
	
public :
	static database instance;
	static database& get();
	//Laczenie z baza danych
	void dbconnect();
	//Dodanie urzytkownika
	void adduser(std::string login, std::string password, int permission); 
	//Sprawdza czy istnieje taka nazwa urzytkownika
	bool userexist(std::string login);
	//Sprawdzenie has³a
	bool checkpassword(std::string login, std::string password);
	//Zwraca numer roli
	int checkrole(std::string login);
};
