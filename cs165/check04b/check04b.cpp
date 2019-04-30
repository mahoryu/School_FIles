/*********************************************************************
 * File: check04b.cpp
 * Purpose: contains the main method to exercise the Date class.
 *********************************************************************/

#include "date.h"

#include <iostream>
using namespace std;

int main()
{
   // prompt for month, day, year
   int month;
   int day;
   int year;

   cout << "Month: ";
   cin  >> month;
   cout << "Day: ";
   cin  >> day;
   cout << "Year: ";
   cin  >> year;
   cout << endl;
   
   // create a Date object
   Date date;
   
   // set its values
   date.set(month, day, year);
   
   // call each display function
   date.displayAmerican();
   date.displayEuropean();
   date.displayISO();

   return 0;
}
