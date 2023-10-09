#include <iostream>
#include "Drivers.h"
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/sqlstring.h>
#include <cppconn/resultset.h>
#include <cppconn/prepared_statement.h>

sql::mysql::MySQL_Driver* driver1;
sql::Connection* con1;
sql::Statement* stmt1;
sql::ResultSet* res1;
void Drivers::dbconnect()
{
    try {
        driver1 = sql::mysql::get_mysql_driver_instance();
        con1 = driver1->connect("db4free.net:3306", "orka12", "12345678");
        stmt1 = con1->createStatement();
        std::cout << "Ok";
    }
    catch (sql::SQLException& e) {
        std::cerr << "B³¹d SQL: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Inny b³¹d: " << e.what() << std::endl;
    }
    }


void Drivers::addDriver(int DriverID, std::string driverName, std::string driverSurname, std::string InternationalDrivingLicense,
                        std::string DrivingLicenseDateExpiring, int DriversTruckAssigned)
{
    try {

        bool databaseExists = false;
        sql::ResultSet* res = stmt1->executeQuery("SHOW DATABASES");
        while (res->next()) {
            if (res->getString("Database").compare("truckproject") == 0) {
                databaseExists = true;
                break;
            }
        }
       stmt1->execute("USE truckproject");
        std::string state = "INSERT INTO `Drivers` (`DriverID`, `driverName`, `driverSurname`, `driverLicense`, `licenseExpiring`, `TruckAssigned`) VALUES ('"+ std::to_string(DriverID) + "','" + 
                            driverName + "','" + driverSurname + "','" + InternationalDrivingLicense + "','" + DrivingLicenseDateExpiring + "','" + std::to_string(DriversTruckAssigned) + "')";
        std::cout << state;
       stmt1->execute(state);


    }
    catch (sql::SQLException& e) {
        std::cerr << "B³¹d SQL: " << e.what() << std::endl;
    }
    catch (std::exception& e) {
        std::cerr << "Inny b³¹d: " << e.what() << std::endl;
    }

}
