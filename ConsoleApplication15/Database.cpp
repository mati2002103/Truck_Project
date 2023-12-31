#include <iostream>
#include "Database.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/sqlstring.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

database database::instance;
database::database() 
{
    
}
database& database::get()
{
        return instance;
}


void database::dbconnect()
{
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("db4free.net:3306", "orka12", "12345678");
        stmt = con->createStatement();
        std::cout << "Ok";
    }
    catch (sql::SQLException& e) {
        std::cerr << "B��d SQL: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Inny b��d: " << e.what() << std::endl;
    }
    
}

void database::adduser(std::string login, std::string password, int permission)
{
    try {

        bool databaseExists = false;
        sql::ResultSet* res = stmt->executeQuery("SHOW DATABASES");
        while (res->next()) {
            if (res->getString("Database").compare("truckproject") == 0) {
                databaseExists = true;
                break;
            }
        }
        stmt->execute("USE truckproject");
        std::string state = "INSERT INTO `Users` (`login`, `password`, `role`) VALUES('" + login + "','" + password + "','" + std::to_string(permission) + "')";
        std::cout << state;
        stmt->execute(state);

        
     }
        catch (sql::SQLException& e) {
            std::cerr << "B��d SQL: " << e.what() << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Inny b��d: " << e.what() << std::endl;
        }
        
}

bool database::userexist(std::string login)
{
    con->setSchema("truckproject");
    std::string state = "SELECT * FROM `Users` WHERE `login` = \""+login+"\"";
    res = stmt->executeQuery(state);
    // Sprawd�, czy istnieje rekord
    if (res->next()) {
        std::cout << "Rekord istnieje." << std::endl;
        return true;
    }
    else {
        std::cout << "Rekord nie istnieje." << std::endl;
        return false;
    } 
}

bool database::checkpassword(std::string login, std::string password)
{
    if (userexist(login))
    {
        std::string state = "SELECT * FROM `Users` WHERE `login` = \"" + login + "\" AND `password` = \""+password+"\"";
        res = stmt->executeQuery(state);
        if (res->next()) {
            std::cout << "Haslo poprawne" << std::endl;
            return true;
        }
        else {
            std::cout << "Niepoprawne haslo" << std::endl;
            return false;
        }
    }
    else
    {
        std::cout << "Nie ma takiego urzytkownika";
        return false;
    }


}

int database::checkrole(std::string login)
{
    con->setSchema("truckproject");
    std::string state = "SELECT `role` FROM `Users` WHERE `login` = \"" + login + "\"";
    res = stmt->executeQuery(state);
    int rola = 0;
    if (res->next()) {
        rola = res->getInt("role");
        std::cout << "Numer roli dla loginu " << login << " to: " << rola << std::endl;
    }
    else {
        std::cout << "Login nie istnieje lub nie ma przypisanej roli." << std::endl;
    }
    return rola;
}
