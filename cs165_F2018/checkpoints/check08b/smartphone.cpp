/*******************
 * smartphone.cpp
 *******************/

#include <iostream>
#include <string>

using namespace std;

#include "phone.h"
#include "smartphone.h"

// TODO: Put your SmartPhone methods here
void SmartPhone :: prompt()
{
   Phone::promptNumber();
   cout << "Email: ";
   getline(cin, email);
   cin.clear();
}

void SmartPhone :: display()
{
   Phone::display();
   cout << email << endl;
}
