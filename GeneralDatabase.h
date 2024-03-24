
#ifndef GENERALDATABASE_H
#define GENERALDATABASE_H
#include <string>
#include "InmateDatabaseFunctions.h"
#include "StaffDatabaseFunctions.h"

using namespace std;

//general info for stats pages like inmate numbers, satisfaction, etc
double getGeneralInfo(bool canGetGeneralInfo, int fieldIndex);
void setGeneralInfo(bool canSetGeneralInfo, int fieldIndex);
#endif
