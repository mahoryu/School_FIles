/***********************
 * File: money.cpp
 ***********************/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

#include "money.h"

/*****************************************************************
 * Function: prompt
 * Purpose: Asks the user for values for dollars and cents
 *   and stores them.
 ****************************************************************/
void Money :: prompt()
{
   int dollars;
   int cents;

   cout << "Dollars: ";
   cin >> dollars;

   cout << "Cents: ";
   cin >> cents;

   setDollars(dollars);
   setCents(cents);
}

/*****************************************************************
 * Function: display
 * Purpose: Displays the value of the money object.
 ****************************************************************/
void Money :: display() const 
{
   cout << "$" << getDollars() << ".";
   cout << setfill('0') << setw(2) << getCents();
}

inline void Money :: setDollars(int dollars)
{
   this->dollars = abs(dollars);
}

inline void Money :: setCents(int cents)
{
   this->cents = abs(cents);
}
