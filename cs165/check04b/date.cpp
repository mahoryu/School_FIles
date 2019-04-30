/********************************************************************
 * File: date.cpp
 * Purpose: Holds the implementation of the Date class methods.
 ********************************************************************/
#include "date.h"

// Put your method bodies here...
#include <iostream>
#include <cassert>
#include "date.h"
using namespace std;

void Date :: set(int month, int day, int year)
{
   this->month = month;
   this->day = day;
   this->year = year;
}

void Date :: displayAmerican()
{
   cout << month << "/"
        << day << "/"
        << year << "\n";
}

void Date :: displayEuropean()
{
   cout << day << "/"
        << month << "/"
        << year << "\n";
}

void Date :: displayISO()
{
   cout << year << "-"
        << month << "-"
        << day << "\n";
}
