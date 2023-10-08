class database
{
public :
	//Laczenie z baza danych
	void dbconnect();
	//Dodanie urzytkownika
	void adduser(std::string login, std::string password, int permission); 
	//Sprawdza czy istnieje taka nazwa urzytkownika
	bool userexist(std::string login);
};
