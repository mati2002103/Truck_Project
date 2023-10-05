#include <iostream>
#include "Database.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/sqlstring.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
sql::mysql::MySQL_Driver* driver;
sql::Connection* con;
sql::Statement* stmt;
sql::ResultSet* res;
void database::dbconnect()
{
    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("db4free.net:3306", "orka12", "12345678");
        stmt = con->createStatement();
        std::cout <<std::endl<< "Ok";
    }
    catch (sql::SQLException& e) {
        std::cerr << "B³¹d SQL: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Inny b³¹d: " << e.what() << std::endl;
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
            std::cerr << "B³¹d SQL: " << e.what() << std::endl;
        }
        catch (std::exception& e) {
            std::cerr << "Inny b³¹d: " << e.what() << std::endl;
        }
        
}
       
