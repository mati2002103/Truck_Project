#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/sqlstring.h>
#include <cppconn/prepared_statement.h>

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("tcp://127.0.0.1:3306", "root", "");
        stmt = con->createStatement();

        // Sprawdzenie, czy baza danych już istnieje
        bool databaseExists = false;
        sql::ResultSet* res = stmt->executeQuery("SHOW DATABASES");
        while (res->next()) {
            if (res->getString("Database").compare("projekt_truck4") == 0) {
                databaseExists = true;
                break;
            }
        }
        delete res;

        if (!databaseExists) {
            stmt->execute("CREATE DATABASE projekt_truck4");
            stmt->execute("USE projekt_truck4");
            stmt->execute("CREATE TABLE IF NOT EXISTS drivers (id INT AUTO_INCREMENT PRIMARY KEY, name VARCHAR(255), Truck TEXT)");
        }

       // Teraz możemy dodać rekordy do tabeli drivers
       // stmt->execute("INSERT INTO drivers (name, Truck) VALUES ('Tomek', 'Scania')");

        delete stmt;
        delete con;
    }
    catch (sql::SQLException& e) {
        std::cerr << "Błąd SQL: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Inny błąd: " << e.what() << std::endl;
    }

    return 0;
}
