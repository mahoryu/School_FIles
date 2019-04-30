/*********************
 * phone.cpp
 *********************/
#include <iostream>
#include <string>
using namespace std;
#include "phone.h"

// TODO: Put your phone class methods here...
void Phone :: promptNumber()
{
   cout << "Area Code: ";
   cin  >> areaCode;
   cout << "Prefix: ";
   cin  >> prefix;
   cout << "Suffix: ";
   cin  >> suffix;
   cin.clear();
   cin.ignore(256, '\n');
}

void Phone :: display()
{
   cout << "(" << areaCode << ")"
        << prefix << "-" << suffix
        << endl;
}
