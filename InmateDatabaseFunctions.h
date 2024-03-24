
#ifndef INMATEDATABASEFUNCTIONS_H
#define INMATEDATABASEFUNCTIONS_H
#include "Inmate.h"
#include <string>

using namespace std;

string getInmateInfo(bool canGetInmateInfo, int inmateIndex, int fieldIndex);
void setInmateInfo(bool canSetInmateInfo, int inmateIndex, int fieldIndex);
Inmate login();
#endif
