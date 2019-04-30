/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
   int month;
   int day;
   int year;
   // prompt for month, day, year
   cout << "Month: ";
   cin  >> month;
   cout << "Day: ";
   cin  >> day;
   cout << "Year: ";
   cin  >> year;
   
   // create a Date object
   Date date;
   
   // set its values
   date.set(month, day, year);
   cout << endl;
   
   // call each display function
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
