class database
{
public :
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
