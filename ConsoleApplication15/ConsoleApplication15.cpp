#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/sqlstring.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include "Database.h"
#include "Drivers.h"

int main() {

    database bazadanych;
    bazadanych.dbconnect();
    bazadanych.checkpassword("maciek", "maciek12");
    bazadanych.checkrole("maciek");
    //bazadanych.adduser("maciek", "maciek12", 1);
    Drivers kierowca1;
    kierowca1.dbconnect();
    kierowca1.addDriver(2, "Tomek1", "Kowalski1", "3124/412/142", "2025-10-10",NULL);
    std::string a;
    std::cin >> a;
    return 0;
}
