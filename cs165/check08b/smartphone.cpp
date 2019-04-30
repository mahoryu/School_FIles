/*******************
 * smartphone.cpp
 *******************/

#include "smartphone.h"
#include "phone.h"

// TODO: Put your SmartPhone methods here
void SmartPhone :: prompt()
{
   promptNumber();
   cout << "Email: ";
   cin.ignore();
   getline(cin, email);
}

void SmartPhone :: display()
{
   Phone::display();
   cout << email << endl;
}
