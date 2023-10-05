#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/sqlstring.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>
#include "Database.h"

int main() {

    database bazadanych;
    bazadanych.dbconnect();
    bazadanych.adduser("maciek", "maciek12", 1);
    return 0;
}
