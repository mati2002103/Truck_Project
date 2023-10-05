#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/sqlstring.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

int main() {
    sql::mysql::MySQL_Driver* driver;
    sql::Connection* con;
    sql::Statement* stmt;
    sql::ResultSet* res;

    try {
        driver = sql::mysql::get_mysql_driver_instance();
        con = driver->connect("db4free.net:3306", "orka12", "12345678");
        stmt = con->createStatement();
        // Sprawdzenie, czy baza danych już istnieje
       /* bool databaseExists = false;
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
            }*/

       // Teraz możemy dodać rekordy do tabeli drivers
       // stmt->execute("INSERT INTO drivers (name, Truck) VALUES ('Tomek', 'Scania')");
       /* stmt->execute("USE truckproject");
        stmt->execute("INSERT INTO drivers (id,name, Truck) VALUES (1,'Tomek', 'Scania')");*/
        stmt->execute("USE truckproject");
        res = stmt->executeQuery("SELECT id,name FROM drivers");
        while (res->next()) {
            // You can use either numeric offsets...
            std::cout << "id = " << res->getInt(1); // getInt(1) returns the first column
            // ... or column names for accessing results.
            // The latter is recommended.
            std::cout << ", name = '" << res->getString("name") << "'" << std::endl;
        }
       
    }
    catch (sql::SQLException& e) {
        std::cerr << "Błąd SQL: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Inny błąd: " << e.what() << std::endl;
    }
    delete stmt;
    delete con;
    delete res;
    return 0;
}
